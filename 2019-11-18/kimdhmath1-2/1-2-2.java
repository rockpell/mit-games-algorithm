import java.util.Scanner;

public class Main {
	public static void main (String[] args) {
		Scanner scanner = new Scanner (System.in);
        boolean presence;
        int count = 0;
        int i;
        int size = scanner.nextInt();
        int[] array = new int[size];
        for(i = 0; i< size;i++){
            array[i] = scanner.nextInt();
        }
        
        while(true){
            presence = false;
            for(i=count; i<size;i++){
                 if(array[count] < array[i]){
                     System.out.print(array[i]+" ");
                     presence = true;
                     break;
                 }
            }
            if(size-1 == count){
                System.out.print(-1+" ");
                break;
            }
            else if(presence == false){
                System.out.print(-1+" ");
            }
            count++;
        }
    }
}
