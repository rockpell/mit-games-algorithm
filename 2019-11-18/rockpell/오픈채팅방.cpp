#include <iostream>
#include <sstream>
#include <string>
#include <vector>
#include <map>

using namespace std;

vector<string> splitString(string& text, char delimiter = ' ') // 기본적으로 공백을 기준으로 자름
{
	vector<string> result;
	string token;
	stringstream ss(text);

	while (getline(ss, token, delimiter)) {
		result.push_back(token);
	}
	return result;
}

vector<string> solution(vector<string> record)
{
	vector<string> answer;
	vector<pair<string, string>> commands; // command,id 를 저장  (command는 Enter, Leave로 구분)
	map<string, string> idMap; // id, nickName을 저장

	int size = record.size();

	for (int i = 0; i < size; i++)
	{
		vector<string> texts = splitString(record[i]);
		
		if (texts[0] == "Enter")
		{
			idMap[texts[1]] = texts[2]; // 입력된 id가 있으면 nickName을 변경, 없다면 추가
			commands.push_back(make_pair(texts[0], texts[1]));
		}
		else if (texts[0] == "Leave")
		{
			commands.push_back(make_pair(texts[0], texts[1]));
		}
		else if (texts[0] == "Change") // idMap에 저장된 nickName만 변경
		{
			idMap[texts[1]] = texts[2];
		}
	}

	for (auto& item : commands)
	{
		if (item.first == "Enter")
		{
			answer.push_back(idMap[item.second] + "님이 들어왔습니다.");
		}
		else if (item.first == "Leave")
		{
			answer.push_back(idMap[item.second] + "님이 나갔습니다.");
		}
	}

	return answer;
}
