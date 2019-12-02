import java.util.StringTokenizer;
import java.util.HashMap;
import java.util.ArrayList;

class Solution {
    public String[] solution(String[] record) {
        int a_length;
        int i_count = 0;
        int s_num;
        int a_count = 0;
        String s_str;
        String[] answer = {};
        StringTokenizer str;
        HashMap<String, Integer> id = new HashMap<>();
        ArrayList<String> nick = new ArrayList<>();
        
        a_length = record.length;
        
        for(int i = 0; i<a_length;i++){
            str = new StringTokenizer(record[i], " ");
            s_str = str.nextToken();
            if(s_str.equals("Enter")){
                id.put(str.nextToken(), i_count);
                nick.add(i_count++, str.nextToken());
                a_count++;
            }
            else if(s_str.equals("Leave")){
                a_count++;
                continue;
            }
            else if(s_str.equals("Change")){
                s_num = id.get(str.nextToken());
                nick.remove(s_num);
                nick.add(s_num, str.nextToken());
            }
            else{
                continue;
            }
        }
        
        answer = new String[a_count];
        a_count = 0;
        for(int i = 0; i<a_length;i++){
            str = new StringTokenizer(record[i], " ");
            s_str = str.nextToken();
            if(s_str.equals("Enter")){
                answer[a_count++] = nick.get(id.get(str.nextToken())) + "님이 들어왔습니다.";
                continue;
            }
           
            else if(s_str.equals("Leave")){
                answer[a_count++] = nick.get(id.get(str.nextToken())) + "님이 나갔습니다.";
                continue;
            } else{
                continue;
            }
        }
        
        
        return answer;
    }
}
