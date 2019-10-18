#ifndef _JSON_H
#define _JSON_H

#include <iostream>
#include <string.h>
#include <stdint.h>
#include <limits.h>

using namespace std;

class MsgFromiFlytek
{

public:
	const char* keyName        = "\"name\":\"";
	const char* keyEmotion     = "\"emotion\":\"";
	const char* keyOrderFinish = "\"OrderFinish\":\"";

public:

	char name[24]       = "";
	char emotion[24]    = "";
	char OrderFinish[12] = "0";	
	char Json[PIPE_BUF+1];

	void extract_Json(const char* key, char* json, char* dest);
};

class MsgToiFlytek
{
public:

	char Json[PIPE_BUF+1];

	void generate_Json(string cmd, string name, string gender, uint16_t age, char* destinaton);

};

#endif