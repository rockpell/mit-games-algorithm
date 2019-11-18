import java.util.StringTokenizer;
import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
public class Main {
	
	public static void main(String[] args) throws IOException {
		int type = 3;		//0은 변하지 않음, 1은 Java형식, 2는 C++형식, 3은 그냥 영어...
		BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
		String input = br.readLine();
		StringBuffer sb = new StringBuffer("");
		for(int i=0; i<input.length();i++){
			if(i==0 && (input.charAt(i) == '_' || (int)input.charAt(i) <= (int)'Z' && (int)input.charAt(i) >= (int)'A') )
				{type = 0; break; }	//첫글자가 _거나 대문자
			if(i==input.length()-1 && input.charAt(i) == '_') {type = 0; break;}			//마지막이 _인 것
			if(i>0)
			{
				if(input.charAt(i-1) == '_' && input.charAt(i) == '_') { type = 0; break; } 		// _가 연속
				if(input.charAt(i-1) == '_' && (int)input.charAt(i) <= (int)'Z' && (int)input.charAt(i) >= (int)'A' && type == 0) 
					{ type = 0; break; }	//_다음에 대문자
			}
			
			if(input.charAt(i) == '_')		//_나왔을 때
			{
				if(type == 3) type = 2;		//처음 나오는거면 c++형식으로
				else if(type == 1) { type = 0; break; }				//java형식인데 c++형식 나옴
			}
			if((int)input.charAt(i) <= (int)'Z' && (int)input.charAt(i) >= (int)'A')		//대문자 나왔을 때
			{
				if(type == 3) type = 1;			//처음 나오는거면 java형식으로
				else if(type == 2) { type = 0; break; }				//c++형식인데 java형식 나옴
			}
		}
		switch(type)
		{
		case 0:			//문제잇음
			System.out.println("Error!");
			break;
		case 1:			//java 형식일 경우
			for(int i = 0; i < input.length(); i++)
			{
				if((int)input.charAt(i) <= (int)'Z' && (int)input.charAt(i) >= (int)'A')
				{
					sb.append("_");
					sb.append((char)((int)input.charAt(i)+32));
				}
				else { sb.append(input.charAt(i)); }
			}
			System.out.println(sb.toString());
			break;
		case 2:			//c++ 형식일 경우
			StringTokenizer st = new StringTokenizer(input, "_");
			sb.append(st.nextToken());
			while(st.hasMoreElements())
			{
				String now = st.nextToken();
				sb.append((char)((int)now.charAt(0)-32));
				sb.append(now.substring(1,now.length()));
			}
			System.out.println(sb.toString());
			break;
		case 3:			//걍 알파벳...
			System.out.println(input);
			break;
		}
	}

}
