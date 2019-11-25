#include <iostream>
#include <sstream>
#include <string>
#include <map>
#include <vector>

using namespace std;

// �ܾ� �и������ִ� �Լ�
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

	// Enter, Leave, Change ���� ��ɾ�� ID�� ���� Log / ID-Nickname�� ���� ���̺�
	vector<vector<string>> logs;
	map<string, string> tableIdNick;
	
	// ��ó�� : log�� tableIdNick�� �����Ѵ�.
	for (int i = 0; i < record.size(); i++)
	{
		// �޽��� �����ϱ�
		/* 0 : ��ɾ�(enter, leave, change)
		1 : ���� ���̵�
		2 : ���� �г���
		*/
		vector<string> elements = tokenize(record[i]);
		
		// �α�, ���̺� ������Ʈ
		vector<string> log = { elements[0], elements[1] };
		logs.push_back(log);
		// Leave�� ��� elememts�� 2���ۿ� ���� �Ϳ� ����.
		if (elements.size() == 3)
		{
			tableIdNick[elements[1]] = elements[2];
		}
	}

	// ��� : log�� id�� ���̺��� Nickname���� ��ġ�Ͽ� ����Ѵ�.
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
			 message = nick + "���� ���Խ��ϴ�.";
		}
		else
		{
			message = nick + "���� �������ϴ�.";
		}

		result.push_back(message);
	}

	return result;
}