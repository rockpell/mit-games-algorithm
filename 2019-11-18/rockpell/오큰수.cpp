#include <iostream>
#include <stack>

using namespace std;

int findBigNum(stack<int>& container, int value)
{
	while (!container.empty())
	{
		if (value >= container.top()) // 스택의 가장 위의 값이 오큰수가 아닐 경우
		{
			container.pop();
		}
		else
		{
			return container.top();
		}
	}

	return -1; // 스택 내에 입력값보다 큰 수가 없다는 것을 의미
}

int main()
{
	int size = 0;
	int temp = 0;
	int* data;
	int* answers;
	stack<int> container;

	scanf_s("%d", &size);
	
	data = new int[size];
	answers = new int[size];

	for (int i = 0; i < size; i++)
	{
		scanf_s("%d", &data[i]);
	}
	
	answers[size - 1] = -1; // 가장 오른쪽 수는 항상 오큰수가 없다
	container.push(data[size - 1]);

	for (int i = size - 2; i >= 0; --i)
	{
		answers[i] = findBigNum(container, data[i]);
		container.push(data[i]);
	}

	for (int i = 0; i < size; i++)
	{
		printf("%d ", answers[i]);
	}
}