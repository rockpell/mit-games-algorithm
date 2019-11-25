import java.util.StringTokenizer;
import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
public class Main {
	
	public static void main(String[] args) throws IOException {
		int type = 3;		//0�� ������ ����, 1�� Java����, 2�� C++����, 3�� �׳� ����...
		BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
		String input = br.readLine();
		StringBuffer sb = new StringBuffer("");
		for(int i=0; i<input.length();i++){
			if(i==0 && (input.charAt(i) == '_' || (int)input.charAt(i) <= (int)'Z' && (int)input.charAt(i) >= (int)'A') )
				{type = 0; break; }	//ù���ڰ� _�ų� �빮��
			if(i==input.length()-1 && input.charAt(i) == '_') {type = 0; break;}			//�������� _�� ��
			if(i>0)
			{
				if(input.charAt(i-1) == '_' && input.charAt(i) == '_') { type = 0; break; } 		// _�� ����
				if(input.charAt(i-1) == '_' && (int)input.charAt(i) <= (int)'Z' && (int)input.charAt(i) >= (int)'A' && type == 0) 
					{ type = 0; break; }	//_������ �빮��
			}
			
			if(input.charAt(i) == '_')		//_������ ��
			{
				if(type == 3) type = 2;		//ó�� �����°Ÿ� c++��������
				else if(type == 1) { type = 0; break; }				//java�����ε� c++���� ����
			}
			if((int)input.charAt(i) <= (int)'Z' && (int)input.charAt(i) >= (int)'A')		//�빮�� ������ ��
			{
				if(type == 3) type = 1;			//ó�� �����°Ÿ� java��������
				else if(type == 2) { type = 0; break; }				//c++�����ε� java���� ����
			}
		}
		switch(type)
		{
		case 0:			//��������
			System.out.println("Error!");
			break;
		case 1:			//java ������ ���
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
		case 2:			//c++ ������ ���
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
		case 3:			//�� ���ĺ�...
			System.out.println(input);
			break;
		}
	}

}
