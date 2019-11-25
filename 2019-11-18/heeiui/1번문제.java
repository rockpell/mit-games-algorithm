import java.io.BufferedReader;
import java.io.BufferedWriter;
import java.io.IOException;
import java.io.InputStreamReader;
import java.io.OutputStreamWriter;
import java.util.Arrays;
import java.util.Stack;

public class Main {
	public static void main(String[] args) throws NumberFormatException, IOException {
		// TODO Auto-generated method stub
        BufferedReader bf = new BufferedReader(new InputStreamReader(System.in));
        BufferedWriter bw = new BufferedWriter(new OutputStreamWriter(System.out));
		
		int size = Integer.parseInt(bf.readLine());
		int[] array = new int[size];
		int[] ans = new int[size];
		String[] temp = bf.readLine().split(" "); 
		//입력받은 값을 공백 기준으로 잘라서 배열에 저장
		for(int i = 0; i < size; i++)
		{
			array[i] = Integer.parseInt(temp[i]);
			//int로 변환
		}
		
		Stack<Integer> s = new Stack<>();
		s.push(0);
		
		for(int i = 1; i < size; i++)
		{
			if(s.isEmpty()) //스택이 비어있으면
			{
				s.push(i);
				//인덱스 저장
			}
			while(!s.isEmpty() && array[s.peek()] < array[i])
			{ //스택이 비어있지않고, 숫자가 인덱스 가장 위쪽 숫자보다 크면
				//peek() : 해당 스택의 제일 상단에 있는 요소를 반환
				ans[s.pop()] = array[i];
				//정답 배열 스택의 가장 위쪽 숫자와 같은 인덱스에 i번째 숫자를 넣음
			}
			s.push(i);
			//다음에 비교할 숫자를 저장
		}
		
		while(!s.empty())
		{//반복문을 다 돌았는데 스택이 비어있지 않다면 빌 때까지
			ans[s.pop()] = -1;
			//스택에 쌓인 인덱스에 -1 저장
		}
		
		for(int i = 0; i < size; i++)
		{
			bw.write(ans[i] + " "); 
			//배열에 있는 값을 출력
		}
		bw.flush();
	}

}
