import java.util.*;
// 1명씩 이동했을 때의 횟수에서 
// 가장 큰 무게의 사람과 가장 작은 무게의 사람이 건너갈 수 있는 경우의 횟수를 제외하면 최소값을 구할 수 있다.
class Solution {
    public int solution(int[] people, int limit) {
        int answer = 0;
        
        int frontIndex = 0;
        int rearIndex = people.length - 1;

        Arrays.sort(people);

        while(frontIndex < rearIndex){
            if(people[frontIndex] + people[rearIndex] <= limit){
                ++frontIndex;
                --rearIndex;
                ++answer;
            }
            else {
                --rearIndex;
            }
        }

        answer = people.length - answer;
        
        return answer;
    }
    
}