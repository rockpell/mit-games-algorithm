class Solution {
    public int[] solution(int n, int s) {
        int[] answer = {};

        if(n > s)
        {
            answer = new int[1];
            answer[0] = -1;
        }
        else
        {
            answer = new int[n];

            for(int i = 0; i < n; i++) // 숫자를 일정하게 분배
            {
                answer[i] = s / n;
            }

            int remain = s % n; // 숫자의 합을 맞추기 위해 나머지를 구한다.

            for(int i = 0; i < remain; i++) // 오름차순으로 답을 반환해야하기 때문에 뒤에서부터 분배
            {
                ++answer[n - 1 - i];
            }
        }

        return answer;
    }
}