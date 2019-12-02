import java.util.*;
class Solution {
    public int solution(int[] people, int limit) {
        int answer = 0;
        int len = people.length;   //people의 크기
        int save = 0;   //작은값의 순서
        PriorityQueue<Integer> minheap = new PriorityQueue<Integer>();  //정렬하기 위한 우선순위 큐

        //우선순위큐에 대입
        for(int i =0; i<len;i++){
            minheap.add(people[i]);
        }

        //정렬되게 배열 재조정
        for(int i =0; i<len;i++){
            people[i] = minheap.poll();
        }

        //큰값과 가장 작은 값의 합과 제한 비교후 증가
        while(save <= len-1){

            //초과할때 작은 값은 변화 없음
            if(people[save] + people[len-1] > limit){
                len--;
                answer++;
            }

            //초과하지 않을 때 작은값은 그 다음 작은값
            else{
                save++;
                len--;
                answer++;
            }


        }
        return answer;
    }
}
