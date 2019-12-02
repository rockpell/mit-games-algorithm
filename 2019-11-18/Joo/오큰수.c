#include<stdio.h>

int main()
{
	int size = 0;
	scanf("%d",&size);
	int arr[size];
	int oken[size];		// 오큰수 저장해두는 배열 
	int big_num = 0;	// 가장큰값을 저장해두는 변수 
	for(int i = 0; i < size; i ++)
	{
		scanf("%d",&arr[i]);
	}
	// 위에서 값들을 입력받음 
	for(int i = size - 1; i >= 0; i--)
	{
		if(arr[i] >= big_num) 		// 다음값이 이전값들보다 크면 오큰값은 -1을 띄우고 다음으로 넘어감 
		{
			big_num = arr[i];
			oken[i] = -1;
			continue;
		}
		for(int j = i+1; j < size; j++)
		{
			if(arr[i] < arr[j])		// 큰수를 만나면 탈출 
			{
				oken[i] = arr[j];
				break;
			}
		}
	}
	// 밑에서 값을 출력함 
	for(int i = 0; i < size; i ++)
	{
		printf("%d ",oken[i]);
	} 
	return 0;
}
