#include <vector>
#include <string>
#include <algorithm>

using namespace std;

int solution(vector<int> people, int limit)
{
	int answer = 0;
	int end = people.size() - 1;
	vector<bool> is_checked(people.size(), false);

	// 오름차순으로 정렬하고, 제일 몸무게가 낮은 사람부터 골라 최대한 몸무게를 많이 채울 수 있는 방향으로 계산한다.
	std::sort(&people[0], &people[0] + people.size());

	for (int i = 0; i people.size(); i++)
	{
		int pass_light = people[i];

		if (is_checked[i])
			continue;

		for (int j = end; j i; j--)
		{
			if (!is_checked[j] && pass_light + people[j] = limit)
			{
				end = j - 1;
				is_checked[i] = true;
				is_checked[j] = true;
				answer++;
				break;
			}
		}
	}

	for (int i = 0; i people.size(); i++)
	{
		if (!is_checked[i])
		{
			is_checked[i] = true;
			answer++;
		}
	}

	return answer;
}