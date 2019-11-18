#include <stdio.h>
#include <string.h>
#define aA ('a' - 'A')

int main(void)
{
	char str[101];
	int i, j;
	int underbar = 0, upper = 0, ex = 0, lower = 0;
	int err = 0;
	int where_bar = 0;
	int double_bar = 0;

	scanf("%s", str);

	for (i = 0; str[i] != '\0'; i++)
	{
		if (str[i] == '_')
		{
			underbar++;
			if(i - where_bar == 1 && where_bar != 0)
				double_bar++;
			where_bar = i;
		}
		/*

		if(str[i] == '_' && str[i] == '_')

			err++;

		*/
		else if ('A' <= str[i] && str[i] <= 'Z')
			upper++;
		else if ('a' <= str[i] && str[i] <= 'z')
			lower++;
		else
			ex++;
	}
 
	if ((ex > 0) || (upper > 0 && underbar > 0) || ('A' <= str[0] && str[0] <= 'Z') || double_bar > 0 || str[0] == '_' || str[strlen(str) - 1] == '_')	//err
		printf("Error!");

	else if (upper > 0)							//JAVA
	{
		for (i = 0; str[i] != '\0'; i++)
		{
			if ('A' <= str[i] && str[i] <= 'Z')
			{
				str[i] += aA;
				for (j = strlen(str); j >= i; j--)
				{
					str[j + 1] = str[j];
				}
				str[i] = '_';
				i++;
			}
		}
		printf("%s", str);
	}

	else if (underbar > 0)							//CPP
	{
		for (i = 0; str[i] != '\0'; i++)
		{
			if (str[i] == '_')
			{
				if (i != 0)
					str[i + 1] -= aA;
				for (j = i + 1; str[j] != '\0'; j++)
				{
					str[j - 1] = str[j];
				}
				str[j - 1] = '\0';
			}
		}
		printf("%s", str);
	}
	else if (lower == strlen(str))
		printf("%s", str);

	return 0;
}