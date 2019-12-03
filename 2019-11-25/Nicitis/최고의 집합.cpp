#include <string>
#include <vector>

using namespace std;

vector<int> solution(int n, int s)
{
	vector<int> answer;
	if (n > s) // ������ ���� ������ �պ��� ū ������ ���� �� ����.
	{
		answer.assign(1, -1);
	}
	else
	{
		// ������ �� s�� ���� answer ������ �й��ϰ�, ���� �����ϰ� �����ָ鼭 ������������ �������ش�.
		int avg = s / n; // ���� ���� �����̹Ƿ� '�ݳ���'�� ���� ������� ����ȴ�.
		int sum = avg * n;
		answer.assign(n, avg);

		// ���� ���� : ���� ������ �� sum <= s
		// �ڿ� �ִ� ���Һ��� �ϳ��� ���ذ���.
		for (int i = n - 1; i >= 0 && sum != s; i--)
		{
			answer[i]++;
			sum++;
		}
	}
	return answer;
}