import java.util.Scanner;

public class Main {
	public static void main (String[] args) {
		Scanner scanner = new Scanner (System.in);
		String answer = "";
		char c;
        boolean java = false;
        boolean _c = false;
		String text = scanner.nextLine();
		if(text.charAt(0) <= 'Z'||text.charAt(0) == '_') {
			System.out.println("Error!");
			System.exit(0);
		}
        for(int i = 0; i< text.length() ;i++) {
            if(text.charAt(i) <= 'Z' && _c == false) {
				c = (char)(text.charAt(i)+32);
				answer += "_" + c; 
                java = true;
			}
            else if(text.charAt(i) == '_'){
               if(java == false && i < text.length() - 1 && text.charAt(i+1) != '_'){
                   i++;
                   if(text.charAt(i)<='Z') {
                	   java = true;
                   }
                   c = (char)(text.charAt(i) - 32);
                   answer += c;
               }
                else{
                    System.out.println("Error!");
			        System.exit(0);
                }
                _c = true;
            }
            else{
                answer += text.charAt(i);
            }
        }
        if(_c == true && java == true){
            System.out.println("Error!");
			System.exit(0);
        }
        else{
            System.out.println(answer);
			System.exit(0);
        }
		scanner.close();
	}
}
