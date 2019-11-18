#include<stdio.h>
#include<string.h>

typedef enum 
{
	java = 1,
	cpp = 2,
	error = 3,
	
}form_t;

int search(char* word)
{
	int cnt = strlen(word);
	int i = 0;
	int cpp_cnt = 0, java_cnt = 0;
	
	for(i = 0; i < cnt; i++)
	{
		if(word[i] == '_')	// cpp 문법 
		{
			if(i == 0)
			{
				return error;
			}
			if(word[i - 1] == '_')		// _ 중복 
			{
				return error;
			}
//			printf("%d 에서 _ 발견\n",i);
			cpp_cnt++;
		}
		if(word[i] >= 'A' && word[i] <= 'Z')	// java 문법 
		{
			if(i == 0)	// 첫글자 대문자 
			{
				return error;
			}
//			printf("%d 에서 대문자 발견\n",i);
			java_cnt++;
		}
	}
	if(word[cnt - 1] == '_')
	{
		return error;
	}
	if(cpp_cnt > 0 && java_cnt == 0)
	{
		return cpp;
	}
	else if(java_cnt > 0 && cpp_cnt == 0)
	{
		return java;
	}
	else if(cpp_cnt == 0 && java_cnt == 0)
	{
		return java;		// 아무거나 
	}
	else
	{
		return error;
	}
//	printf("java도 아니고 c++도 아니다.\n");
	return error;
}

void transword(char* word, form_t form, char* return_str)
{
	int cnt = strlen(word);
	int return_str_idx = 0;
	int i = 0;
	switch(form)
	{	
		case java:
			for(i = 0; i < cnt; i++)
			{
				if(word[i] >= 'A' && word[i] <= 'Z')
				{
					return_str[return_str_idx] = '_';
					return_str_idx++;
					return_str[return_str_idx] = word[i] + 32;
				}
				else
				{
					return_str[return_str_idx] = word[i];
				}
				return_str_idx++;
			}
			return_str[return_str_idx] = '\0';
			printf("%s",return_str);
			break;
		case cpp:
			for(i = 0; i < cnt; i++)
			{
				if(word[i] == '_')
				{
					i++;
					return_str[return_str_idx] = word[i] - 32;
				}
				else
				{
					return_str[return_str_idx] = word[i];
				}
				return_str_idx++;
			}
			return_str[return_str_idx] = '\0';
			printf("%s",return_str);
			break;
		case error:
			printf("Error!");
			break;
	}
}

int main()
{
	char result_str[101] = {0,};
	char _temp[101];
	scanf("%s",_temp);
	form_t form = java;
	form = search(_temp);
	transword(_temp, form, result_str);
	
	return 0;
}
