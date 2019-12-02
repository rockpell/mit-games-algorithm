class Solution {
  public int[] solution(int n, int s) {
      int[] answer = {};
      int save_r = s%n; //나머지 저장
      int save_q = s/n; //몫 저장
      int i = 0;    //중간값이 변화하는 부분 구별
      
      //최고의 집합이 존재하지 않을때
      if(save_q <1){
          answer =new int[1];   //집합의 크기 1
          answer[0] = -1;
      }
      
      //최고의 집합이존재할때
      else{
          answer = new int[n];  //집합의 크기 n
          while(i<n-save_r){
              answer[i] = save_q;   //몫을 먼저 저장 (오름차순으로)
              i++;
          }
          while(i<n){
              answer[i] = save_q+1; //몫에서 1더한 값저장
              i++;
          }
      }
      
      return answer;
  }
}
