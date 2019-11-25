import java.util.StringTokenizer;
import java.util.HashMap;

class Solution {
	public String[] solution(String[] record) {
		String[] answer = {};
		int ansCnt = 0; 
		int ansIdx = 0;
		int cmdCnt = record.length;
		StringTokenizer st;
		HashMap<String, String> ID = new HashMap<String, String>();
		
		for(int i = 0; i < cmdCnt; i++)
        {
			st = new StringTokenizer(record[i], " ");
			String cmd = st.nextToken();
			String userID = st.nextToken();
			String NickName;
			
			if(cmd.equals("Enter") || cmd.equals("Change")) 
            { //Enter 또는 Change일 경우 ID에 userID와 NickName을 맵핑
				NickName = st.nextToken();
				ID.put(userID, NickName);
			}
			
			if(cmd.equals("Enter") || cmd.equals("Leave"))
            { 
				ansCnt++;
            }
		}
			answer = new String[ansCnt];
    
		for(int i = 0; i < cmdCnt; i++) 
        {
			st = new StringTokenizer(record[i], " ");
			String cmd = st.nextToken();
			String userID = st.nextToken();
			String NickName;
			
			if(cmd.equals("Enter")) 
            {
				NickName = ID.get(userID);
				answer[ansIdx++] = NickName + "님이 들어왔습니다.";
			}
			else if(cmd.equals("Leave")) 
            {
				NickName = ID.get(userID);
				answer[ansIdx++] = NickName + "님이 나갔습니다.";
			}
		}
		
		return answer;
    }
}
