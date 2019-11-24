#include <iostream>
#include <vector>
#include <stack>

using namespace std;

int main()
{
	// 입출력 속도 최적화 코드
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	/* [문제 풀이]
	만약 5 2 4 7 이렇게 주어졌다면
	(괄호 안은 그에 대응하는 출력값(result 배열에 저장))
	[1] 5 입력
	stack : + 5(-1)
	결과 : -1 -1 -1 -1

	[2] 2 입력
	stack : 5(-1) + 2(-1)
	결과 : -1 -1 -1 -1

	[3] 4 입력
	stack : 5(-1) 2(4) + 4(-1)
	2 pop
	결과 : -1 4 -1 -1

	[4] 7 입력
	stack : 5(7) 4(7) 7(-1)
	4 pop 5 pop
	결과 : 7 4 7 -1
	(기존에 있던 4는 무시하고 그 왼쪽에 있는 걸 채움)
	*/

	stack<int> s;
	int n;
	
	cin >> n;
	
	// -1로 초기화된 코드
	vector<int> result(n, -1);

	for (int i = 0; i < n; i++)
	{
		int num, pos = i - 1;
		cin >> num;

		// 오른쪽 끝부터 조사하여, num보다 수가 작을 경우
		// (i-1)번째 원소부터 수가 매겨지지 않은 곳(-1)을 채운다.
		while (!(s.empty()) && num > s.top())
		{
			// 자료형의 범위를 벗어나지 않게 한다.
			// 오큰수가 이미 존재하는 원소는 뛰어넘는다.
			while (pos >= 0 && pos < n && result[pos] != -1)
			{
				pos--;
			}
			/* 디버깅용
			if (pos < 0 || pos >= n)
			{
				cout << "뭔가 이상하다!";
				return 987654321;
			}
			*/
			s.pop();
			result[pos] = num;
		}
		s.push(num);
	}

	// 출력
	for (int i = 0; i < n; i++)
	{
		cout << result[i] << " ";
	}

	return 0;
}