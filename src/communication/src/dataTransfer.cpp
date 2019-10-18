
/*
* ROS Node: Data Transfer Centre, Connecting the Core & iFlytek.
*/
#include <fcntl.h>
#include <limits.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <sstream>
#include <iostream>
#include <string.h>
#include "ros/ros.h"
#include "std_msgs/String.h"

#include "../include/json.h"
#include "../../../devel/include/msgfile/VoiceOrder.h"
#include "../../../devel/include/msgfile/Core2Voice.h"


//联调时注释掉即可
#define SELF_TEST
#define FRONT_END

using namespace ros;
using namespace std;

MsgFromiFlytek msgFromiFlytek;
MsgToiFlytek msgToiFLytek;

//file description of named pipe
int pipe_fd_wr_iFlytek = -1;
int pipe_fd_rd_iFlytek = -1;
int pipe_fd_wr_frontEnd = -1;


/*该回调函数用于接收来自Core的Msg，并转发至iFlytek*/
void chatterCallback(const msgfile::Core2Voice::ConstPtr& msg){  

	msgToiFLytek.generate_Json(msg->cmd, msg->name, msg->gender, msg->age, msgToiFLytek.Json);

	cout << "[ 'dataTransfer->Callback' ]: " << msgToiFLytek.Json << endl;

	/*write()当FIFO写满时才阻塞，否则不阻塞并且返回错误！*/
	int res = write(pipe_fd_wr_iFlytek, msgToiFLytek.Json, strlen(msgToiFLytek.Json));

	if(res == -1) 
		;// fprintf(stderr, "Write error on pipe\n");
}


#ifdef FRONT_END
/*thread used to write to front end*/
void* _writeTofrontEnd(void* arg){

	/************** Create FIFO: RD_ONLY & BLOCKING ***************/
	const char *fifo_name = "/home/kevin/myfifo/ros_2_frontEnd";

	int res = 0;
	const int open_mode = O_WRONLY; //| O_NONBLOCK ;  

	if(access(fifo_name, F_OK) == -1)
	{
		res = mkfifo(fifo_name, 0777);
		if(res != 0)
		{
			fprintf(stderr, "Could not create fifo %s\n", fifo_name);
			exit(EXIT_FAILURE);
		}
	}
	pipe_fd_wr_frontEnd = open(fifo_name, open_mode);

	if(pipe_fd_wr_frontEnd == -1)    
		cout << "[ '_writeTofrontEnd' ] open err " << endl;
	else 
		cout << "[ '_writeTofrontEnd' ] open successfully!" << endl;

	const char* test = "test msg to front end!";

	while(1){

		int res = write(pipe_fd_wr_frontEnd, test, strlen(test));
		// if(res == -1) 
		// 	fprintf(stderr, "Write error to front end!\n");
	    // usleep(1000*500);
	}
}
#endif



/*thread used to write FIFO*/
void* _writeToiFLytek(void* arg){

	/************** Create FIFO: RD_ONLY & BLOCKING ***************/
	const char *fifo_name = "/home/kevin/myfifo/ros_2_iFlytek";

	int res = 0;
	const int open_mode = O_WRONLY; //| O_NONBLOCK ;  

	if(access(fifo_name, F_OK) == -1)
	{
		res = mkfifo(fifo_name, 0777);
		if(res != 0)
		{
			fprintf(stderr, "Could not create fifo %s\n", fifo_name);
			exit(EXIT_FAILURE);
		}
	}
	pipe_fd_wr_iFlytek = open(fifo_name, open_mode);

	if(pipe_fd_wr_iFlytek == -1)    
		cout << "[ '_writeToiFLytek' ] open err " << endl;
	else 
		cout << "[ '_writeToiFLytek' ] open successfully!" << endl;

#ifdef SELF_TEST
	while(1){
		string cmd    = "idle";
		string name   = "甘坤";
		string gender = "male";
		uint16_t age  = 24;
		cout << "[ '_writeToiFLytek' ] Input command: ";
		cin >> cmd;
		msgToiFLytek.generate_Json(cmd, name, gender, age, msgToiFLytek.Json);
		write(pipe_fd_wr_iFlytek, msgToiFLytek.Json, strlen(msgToiFLytek.Json));
	}
#endif
	
	while(1);
}


/*thread used to read FIFO & publish topic-> VoicePub*/
void* _readFromiFLytek(void* arg){

	ros::NodeHandle n;

	//publish数据,消息格式VoiceOrder.msg
	ros::Publisher chatter_pub = n.advertise<msgfile::VoiceOrder>("VoicePub", 1000);

	//msg transfered to Core
	msgfile::VoiceOrder msg2core;

	const char *fifo_name = "/home/kevin/myfifo/iFlytek_2_ros";
	int open_mode = O_RDONLY;
	char buffer[PIPE_BUF+1];
	int bytes_read = 0; 

	//Empty the buffer
	memset(buffer, '\0', sizeof(buffer));
 
	//RD_ONLY & BLOCKING
	pipe_fd_rd_iFlytek = open(fifo_name, open_mode);

	if(pipe_fd_rd_iFlytek == -1)  
		cout << "\t\t\t\t\t\t\t" << "[ '_readFromiFLytek' ] open  err !" << endl;
	else
		cout << "\t\t\t\t\t\t\t" << "[ '_readFromiFLytek' ] open  successfully !" << endl;

	while(1){

		//read operation blocked, wait until iFLytek:write_end.
		bytes_read = read(pipe_fd_rd_iFlytek, buffer, PIPE_BUF);

		if(bytes_read==-1){

			cout << "read err" << endl;
			close(pipe_fd_rd_iFlytek);

			pipe_fd_rd_iFlytek = open(fifo_name, open_mode);
			if(pipe_fd_rd_iFlytek == -1)   cout << " open err " << endl;
		}
		else if(bytes_read>0){

			buffer[bytes_read] = 0;
			strcpy(msgFromiFlytek.Json,buffer); 
		}
		else
			;

		cout << "\t\t\t\t\t" << "[ '_readFromiFLytek' ] get json from iFlytek: " << msgFromiFlytek.Json << endl;

		msgFromiFlytek.extract_Json(msgFromiFlytek.keyName, msgFromiFlytek.Json, msgFromiFlytek.name);
		msgFromiFlytek.extract_Json(msgFromiFlytek.keyEmotion, msgFromiFlytek.Json, msgFromiFlytek.emotion);
		msgFromiFlytek.extract_Json(msgFromiFlytek.keyOrderFinish, msgFromiFlytek.Json, msgFromiFlytek.OrderFinish);
		
		msg2core.name = msgFromiFlytek.name;
		msg2core.emotion = msgFromiFlytek.emotion;
		msg2core.OrderFinish = strcmp(msgFromiFlytek.OrderFinish,"1")==0 ? true : false;

		chatter_pub.publish(msg2core);
	}
}



int main(int argc, char** argv){

	ros::init(argc, argv, "dataTransfer");

	ros::NodeHandle n;

	/*Subscribe Jason topic:'core_voice',Core2Voice.msg*/
	ros::Subscriber chatter_sub = n.subscribe("core_voice", 1000, chatterCallback);

	ros::Rate loop_rate(100);
	
	//write FIFO thread
	pthread_t writeToiFLytek;

	//read FIFO thread
	pthread_t readFromiFLytek;

	//write FIFO thread
	pthread_t writeTofrontEnd;

	int ret = pthread_create(&writeToiFLytek, NULL, _writeToiFLytek, NULL);
	if (ret != 0) 
		printf("order pthread_create error: error_code = %d\n", ret);

	ret = pthread_create(&readFromiFLytek, NULL, _readFromiFLytek, NULL);
	if (ret != 0) 
		printf("getCmd pthread_create error: error_code = %d\n", ret);

	ret = pthread_create(&readFromiFLytek, NULL, _writeTofrontEnd, NULL);
	if (ret != 0) 
		printf("getCmd pthread_create error: error_code = %d\n", ret);

	while(1){

		msgfile::VoiceOrder test_msg;

		// chatter_pub.publish(test_msg);

		/*10ms，睡眠时间尽量短，spinOnce()函数调用频率高*/
		loop_rate.sleep();

		/*调用此函数时才会去执行回调函数，消息发送频率高于spinOnce调用频率时，注意消息池大小的合理设置！*/
		ros::spin();

	}

	return 0;

}