#include <string>
#include <vector>

using namespace std;

vector<int> solution(int n, int s)
{
	vector<int> answer;
	if (n > s) // 원소의 수가 집합의 합보다 큰 집합을 만들 수 없다.
	{
		answer.assign(1, -1);
	}
	else
	{
		// 집합의 합 s를 고르게 answer 변수에 분배하고, 합을 적절하게 맞춰주면서 오름차순으로 정렬해준다.
		int avg = s / n; // 정수 간의 연산이므로 '반내림'된 값이 평균으로 저장된다.
		int sum = avg * n;
		answer.assign(n, avg);

		// 시작 조건 : 현재 원소의 합 sum <= s
		// 뒤에 있는 원소부터 하나씩 더해간다.
		for (int i = n - 1; i >= 0 && sum != s; i--)
		{
			answer[i]++;
			sum++;
		}
	}
	return answer;
}