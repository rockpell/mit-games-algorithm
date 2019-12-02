import java.util.Arrays;

class Solution {
    public int[] solution(int n, int s) {
        int[] answer = new int[n];

        int number = 0;

        if((s/n) == 0)
            return new int[] {-1};

        int index = 0;
        for(int i = s; i > 0; i -= number)
        {
            number = i/n;
            answer[index] = number;
            n--;
            index++;
        }

        Arrays.sort(answer);
        return answer;
    }
}