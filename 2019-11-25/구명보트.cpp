#include <vector>
#include <algorithm>

using namespace std;

/*
수정한 코드
이전 코드에서 2중 For문을 돌리면서
필요없는 요소를 많이 검사해서
시간 초과가 난 것 같습니다.
*/
int solution(vector<int> people, int limit)
{
	int answer = 0;
    // 보트에 태울 사람의 위치
	int l = 0, r = people.size() - 1;
    // 확인한 사람인지 저장하는 배열
	vector<bool> is_checked(people.size(), false);

	// 오름차순으로 정렬하고, 제일 몸무게가 낮은 사람부터 골라
    // 최대한 몸무게를 많이 채울 수 있는 방향으로 계산한다.
	std::sort(&people[0], &people[0] + people.size());
    
    for(int i = r; l < i; i--)
    {
        if (!is_checked[l]&& !is_checked[i] && people[l] + people[i] <= limit)
        {
            is_checked[l] = is_checked[i] = true;
            l++;
            r--;
            answer++;
        }
    }
    
    // 남은 사람마다 보트가 하나씩 필요
    for (int i = 0; i < people.size(); i++)
    {
        if (!is_checked[i])
            answer++;
    }

	return answer;
}
