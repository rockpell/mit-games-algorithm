public class Solution {
    public int solution(int n) {
        int ans = 0;
        while(true){
            ans += n%2;
            n = n/2;
            if(n == 0){
                break;
            }
        }
        
        // [실행] 버튼을 누르면 출력 값을 볼 수 있습니다.
        System.out.println(ans);

        return ans;
    }
}
