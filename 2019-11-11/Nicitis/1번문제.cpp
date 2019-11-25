#include <iostream>
#include <string>

using namespace std;

// ���� ����
enum type
{
	BOTH, JAVA, CPP, ERROR
};

type IsJavaOrCpp(string str)
{
	bool isCapital = false;
	bool isUnderbar = false;

	// Error : ù ���� �빮�� ����
	if (str[0] >= 'A' && str[0] < 'Z' + 1)
		return ERROR; // Error

	// Error : ù/������ ���� _ ����
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
				return ERROR; // Error : ����� ����
		}
	}

	// �˻�
	if (isCapital && isUnderbar) // Error : �빮�� _ �� �� ����
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

// _ + �ҹ��� => �빮��
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
				result.push_back(toupper(str[i + 1])); // �ҹ��� => �빮��
			}
			begin = i + 2; // i�� _ ����Ŵ -> �������� i + 2���� ����
			i++;
		}
	}
	if (begin <= str.length())
	{
		result = result + str.substr(begin, -1);
	}
	return result;
}

// �빮�� => _ + �ҹ���
string JavaToCpp(string str)
{
	string result = "";
	int begin = 0;
	for (int i = 0; i < str.length(); i++)
	{
		if (str[i] >= 'A' && str[i] < 'Z' + 1)
		{
			result = result + str.substr(begin, i - begin) + '_'; // (i - 1)��°���� ����
			result.push_back(tolower(str[i]));
			begin = i + 1; // i�� �빮�� ����Ŵ -> �������� �� �����ͺ��� ����
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
	case BOTH: // BOTH(�ҹ���)
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