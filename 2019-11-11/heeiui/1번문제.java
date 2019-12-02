import java.util.Scanner;

public class ex3613 {

	public static void main(String[] args) {
		Scanner scanner = new Scanner(System.in); 	
		boolean Java = false;
		boolean Cpp = false;
		String result = "";
		
		String str = scanner.nextLine();
		
		for(int i = 0; i < str.length(); i++)
		{
			if(((int)str.charAt(i) >= 65 && (int)str.charAt(i) <= 90) && Cpp == false)
			{ //대문자인 경우
				result += "_" + (char)(str.charAt(i) + 32);
				Java = true;
			}
			else if(str.charAt(i) == '_')
			{
				if(i < str.length() - 1 && str.charAt(i+1) != '_' && Java == false)
				{ //_가 두개가 아닐 때
					i++;
					if((int)str.charAt(i) >= 65 && (int)str.charAt(i) <= 90) {
						Java = true; }

					result += (char)(str.charAt(i) - 32);
				}
				else
				{
					System.out.println("Error!");
					System.exit(0);
				}
				Cpp = true;
			}
			else
			{
				result += str.charAt(i);
			}
		}
		if(((int)str.charAt(0) >= 65 && (int)str.charAt(0) <= 90) || str.charAt(0) == '_')
		{ //첫글자가 대문자거나 _일 때
			System.out.println("Error!");
			System.exit(0);
		}
		
		if(Cpp == true && Java == true)
		{ //둘다 true일 때
			System.out.println("Error!");
			System.exit(0);
		}
		else
		{
			System.out.println(result);
			System.exit(0);
		}
		scanner.close();
	}
}
		
	

	

