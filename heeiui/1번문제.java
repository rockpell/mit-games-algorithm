import java.util.Scanner;

class ex3613 {

	public static void main(String[] args) {
		
		Scanner scanner = new Scanner(System.in); 
		String text = scanner.nextLine();
		
		for(int i = 0; i < text.length(); i++) //입력받은 변수명 길이만큼 탐색
		{	//int로 형변환해서 문자가 아스키코드로 A~Z 범위 안에 있으면 (대문자인 경우)
			if(65 <= (int)text.charAt(i) && (int)text.charAt(i) <= 90)
			{ 
				System.out.print('_'); 
				System.out.print((char)((int)text.charAt(i) + 32)); //+32(소문자)
			}
			//아래는 소문자인 경우
			else if(text.charAt(i) != '_') 
			{
				System.out.print(text.charAt(i)); 
			}
			
			else if(text.charAt(i) == '_') 
			{
				System.out.print((char)((int)text.charAt(i+1) - 32)); //_ 다음 문자에 -32(대문자)해줌
				i++;
			}
			
			else
			{
				System.out.print("Error!");
			}
		}
	}

}
