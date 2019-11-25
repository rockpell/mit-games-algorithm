#include <iostream>
#include <vector>
#include <stack>

using namespace std;

int main()
{
	// ����� �ӵ� ����ȭ �ڵ�
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	/* [���� Ǯ��]
	���� 5 2 4 7 �̷��� �־����ٸ�
	(��ȣ ���� �׿� �����ϴ� ��°�(result �迭�� ����))
	[1] 5 �Է�
	stack : + 5(-1)
	��� : -1 -1 -1 -1

	[2] 2 �Է�
	stack : 5(-1) + 2(-1)
	��� : -1 -1 -1 -1

	[3] 4 �Է�
	stack : 5(-1) 2(4) + 4(-1)
	2 pop
	��� : -1 4 -1 -1

	[4] 7 �Է�
	stack : 5(7) 4(7) 7(-1)
	4 pop 5 pop
	��� : 7 4 7 -1
	(������ �ִ� 4�� �����ϰ� �� ���ʿ� �ִ� �� ä��)
	*/

	stack<int> s;
	int n;
	
	cin >> n;
	
	// -1�� �ʱ�ȭ�� �ڵ�
	vector<int> result(n, -1);

	for (int i = 0; i < n; i++)
	{
		int num, pos = i - 1;
		cin >> num;

		// ������ ������ �����Ͽ�, num���� ���� ���� ���
		// (i-1)��° ���Һ��� ���� �Ű����� ���� ��(-1)�� ä���.
		while (!(s.empty()) && num > s.top())
		{
			// �ڷ����� ������ ����� �ʰ� �Ѵ�.
			// ��ū���� �̹� �����ϴ� ���Ҵ� �پ�Ѵ´�.
			while (pos >= 0 && pos < n && result[pos] != -1)
			{
				pos--;
			}
			/* ������
			if (pos < 0 || pos >= n)
			{
				cout << "���� �̻��ϴ�!";
				return 987654321;
			}
			*/
			s.pop();
			result[pos] = num;
		}
		s.push(num);
	}

	// ���
	for (int i = 0; i < n; i++)
	{
		cout << result[i] << " ";
	}

	return 0;
}