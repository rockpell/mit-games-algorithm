#include <iostream>
using namespace std;

int solution(int n)
{
	/* Ǯ�̹� 1. ����Լ�
	nĭ �̵��ϴµ� �Ҹ�Ǵ� �ּ� ���͸� �Ҹ� f(n)�̶� �� ��,
	n�� Ȧ���� ��, f(n) = f(n - 1) + 1
	n�� ¦���� ��, f(n) = f(n / 2)
	*/

	if (n == 1)
		return 1;
	else if (n % 2 == 1)
		return solution(n - 1) + 1;
	else
		return solution(n / 2);

	/* Ǯ�̹� 2. ������
	f(n)�� n�� 0�� �� ������ 2�� ���� ��, �������� �հ� ����.
	for������ Ǯ �� �ִ�. ���� ���� ����.
	*/
}