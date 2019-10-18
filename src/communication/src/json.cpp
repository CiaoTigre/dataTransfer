
#include "json.h"
#include <string>

using namespace std;


void MsgFromiFlytek::extract_Json(const char* key, char* json, char* dest){

	char* start = NULL;
	char* end   = NULL;

	/*extract dest from Json*/
	if(strstr(json, key)!=NULL){
		start = strstr(json, key);
		start += strlen(key);  

		for(end = start; *end != '\"' && *end!='\0'; ++end);
    	memcpy(dest, start, end-start);
    	dest[end-start] = 0;
	}
}

void MsgToiFlytek::generate_Json(string cmd, string name, string gender, uint16_t age, char* destinaton){

    string json;

    json = "{\"command\":\"" + cmd + "\",\"name\":\"" + name + "\",\"gender\":\"" + gender + "\",\"age\":\"" + to_string(age) + "\"}"; 

    strcpy(destinaton,json.c_str());

}