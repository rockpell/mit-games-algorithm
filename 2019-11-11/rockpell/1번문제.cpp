/*
문제 출처: https://www.acmicpc.net/problem/3613
*/

#include <iostream>
#include <string>
#include <regex>

using namespace std;

bool isCheckCpp(const string& input) 
{
	regex cppRegex("[a-z]+([_][a-z]+)*");
	
	if (regex_match(input, cppRegex))
	{
		return true;
	}

	return false;
}

bool isCheckJava(const string& input)
{
	regex javaRegex("[a-z]+[a-zA-Z]*");

	if (regex_match(input, javaRegex))
	{
		return true;
	}

	return false;
}

string convertCppToJava(string& input) // _소문자 한개를 대문자 한개로 변경
{
	string result;
	int size = input.size();

	for (int i = 0; i < size; i++)
	{
		if (input[i] == '_') // 소문자에서 대문자로 변경 위해 32 감산
		{
			result += input[i + 1] - 32;
			++i;
		}
		else
		{
			result += input[i];
		}
	}

	return result;
}

string convertJavaToCpp(string& input) // 대문자 한개를 _소문자로 변경
{
	string result;
	int size = input.size();

	for (int i = 0; i < size; i++)
	{
		if ('A' <= input[i] && input[i] <= 'Z') // 대문자에서 소문자로 변경 위해 32 가산
		{
			result += "_";
			result += input[i] + 32;
		}
		else
		{
			result += input[i];
		}
	}

	return result;
}

int main()
{
	string inputText;
	int size = 0;
	bool isCpp = false;
	bool isJava = false;

	std::getline(cin, inputText);

	isCpp = isCheckCpp(inputText);
	isJava = isCheckJava(inputText);
	
	if (isCpp)
	{
		printf("%s", convertCppToJava(inputText).c_str());
	}
	else if (isJava)
	{
		printf("%s", convertJavaToCpp(inputText).c_str());
	}
	else
	{
		printf("Error!");
	}
}