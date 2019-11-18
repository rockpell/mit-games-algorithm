#include <iostream>
#include <string>

using namespace std;

// 명명법 종류
enum type
{
	BOTH, JAVA, CPP, ERROR
};

type IsJavaOrCpp(string str)
{
	bool isCapital = false;
	bool isUnderbar = false;

	// Error : 첫 문자 대문자 금지
	if (str[0] >= 'A' && str[0] < 'Z' + 1)
		return ERROR; // Error

	// Error : 첫/마지막 문자 _ 금지
	if (str[0] == '_' || str[str.length() - 1] == '_')
		return ERROR; // Error

	// Java Style
	for (int i = 1; i < str.length(); i++)
	{
		if (str[i] >= 'A' && str[i] < 'Z' + 1)
		{
			isCapital = true;
			break;
		}
	}

	// C++ Style
	for (int i = 0; i < str.length(); i++)
	{
		if (str[i] == '_')
		{
			isUnderbar = true;
			if (i < str.length() - 1 && str[i + 1] == '_')
				return ERROR; // Error : 언더바 연속
		}
	}

	// 검사
	if (isCapital && isUnderbar) // Error : 대문자 _ 둘 다 있음
	{
		return ERROR; // Error
	}
	else if (isCapital)
	{
		return JAVA; // java
	}
	else if (isUnderbar)
	{
		return CPP; // cpp
	}
	return BOTH;
}

// _ + 소문자 => 대문자
string CppToJava(string str)
{
	string result = "";
	int begin = 0;
	for (int i = 0; i < str.length(); i++)
	{
		if (str[i] == '_')
		{
			result = result + str.substr(begin, i - begin);
			if (i < str.length() - 1 && str[i + 1] != '_')
			{
				result.push_back(toupper(str[i + 1])); // 소문자 => 대문자
			}
			begin = i + 2; // i가 _ 가리킴 -> 다음에는 i + 2부터 복사
			i++;
		}
	}
	if (begin <= str.length())
	{
		result = result + str.substr(begin, -1);
	}
	return result;
}

// 대문자 => _ + 소문자
string JavaToCpp(string str)
{
	string result = "";
	int begin = 0;
	for (int i = 0; i < str.length(); i++)
	{
		if (str[i] >= 'A' && str[i] < 'Z' + 1)
		{
			result = result + str.substr(begin, i - begin) + '_'; // (i - 1)번째까지 복사
			result.push_back(tolower(str[i]));
			begin = i + 1; // i가 대문자 가리킴 -> 다음에는 그 다음것부터 복사
		}
	}
	if (begin <= str.length())
	{
		result = result + str.substr(begin, -1);
	}
	return result;
}

int main()
{
	string strin;

	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	cin >> strin;

	switch (IsJavaOrCpp(strin))
	{
	case ERROR: // ERROR
		cout << "Error!";
		break;
	case BOTH: // BOTH(소문자)
		cout << strin;
		break;
	case JAVA: // JAVA
		cout << JavaToCpp(strin);
		break;
	case CPP: // C++
		cout << CppToJava(strin);
		break;
	}

	return 0;
}