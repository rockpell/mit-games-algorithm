#include <iostream>
#include <sstream>
#include <string>
#include <map>
#include <vector>

using namespace std;

// 단어 분리시켜주는 함수
vector<string> tokenize(const string& data, const char delimiter = ' ')
{
	vector<string> result;
	string token;
	stringstream ss(data);

	while (getline(ss, token, delimiter))
	{
		result.push_back(token);
	}

	return result;
}

vector<string> solution(vector<string> record)
{
	vector<string> result;

	// Enter, Leave, Change 같은 명령어와 ID가 적힌 Log / ID-Nickname이 적힌 테이블
	vector<vector<string>> logs;
	map<string, string> tableIdNick;
	
	// 전처리 : log와 tableIdNick을 구성한다.
	for (int i = 0; i < record.size(); i++)
	{
		// 메시지 분해하기
		/* 0 : 명령어(enter, leave, change)
		1 : 유저 아이디
		2 : 유저 닉네임
		*/
		vector<string> elements = tokenize(record[i]);
		
		// 로그, 테이블 업데이트
		vector<string> log = { elements[0], elements[1] };
		logs.push_back(log);
		// Leave의 경우 elememts가 2개밖에 없는 것에 주의.
		if (elements.size() == 3)
		{
			tableIdNick[elements[1]] = elements[2];
		}
	}

	// 출력 : log의 id를 테이블의 Nickname으로 대치하여 출력한다.
	for (int i = 0; i < record.size(); i++)
	{
		string command = logs[i][0];
		string nick = tableIdNick[logs[i][1]];
		string message;
		
		if (command == "Change")
		{
			continue;
		}
		else if (command == "Enter")
		{
			 message = nick + "님이 들어왔습니다.";
		}
		else
		{
			message = nick + "님이 나갔습니다.";
		}

		result.push_back(message);
	}

	return result;
}