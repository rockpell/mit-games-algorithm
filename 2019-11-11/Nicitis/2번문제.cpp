#include <iostream>
using namespace std;

int solution(int n)
{
	/* 풀이법 1. 재귀함수
	n칸 이동하는데 소모되는 최소 배터리 소모량 f(n)이라 할 때,
	n이 홀수일 때, f(n) = f(n - 1) + 1
	n이 짝수일 때, f(n) = f(n / 2)
	*/

	if (n == 1)
		return 1;
	else if (n % 2 == 1)
		return solution(n - 1) + 1;
	else
		return solution(n / 2);

	/* 풀이법 2. 나머지
	f(n)은 n이 0이 될 때까지 2로 나눌 때, 나머지의 합과 같다.
	for문으로 풀 수 있다. 위와 같은 원리.
	*/
}