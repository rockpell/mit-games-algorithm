import java.util.Arrays;

class Solution {
    public int solution(int[] people, int limit)
    {
        int answer = 0;

        Arrays.sort(people);

        int little = 0;
        int large = people.length-1;

        while(little <= large)
        {
            if((people[large] + people[little]) > limit)
            {
                large--;
            }
            else
            {
                little++;
                large--;
            }
            answer++;
        }

        return answer;
    }
}
