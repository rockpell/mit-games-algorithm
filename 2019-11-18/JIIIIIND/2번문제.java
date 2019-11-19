class Solution {
    public String[] solution(String[] record) {
        java.util.Map<String, String> dic = new java.util.HashMap<String, String>();
        int arraySize = 0;
        for(int i = 0; i < record.length; i++)
        {
            java.util.StringTokenizer st = new java.util.StringTokenizer(record[i]);

            switch(st.nextToken())
            {
                case "Enter":
                    dic.put(st.nextToken(), st.nextToken());
                    arraySize++;
                    break;
                case "Change":
                    String uid = new String(st.nextToken());
                    dic.remove(uid);
                    dic.put(uid, st.nextToken());
                    break;
                case "Leave":
                    arraySize++;
                    break;
            }
        }
        String[] answer = new String[arraySize];
        arraySize = 0;
        for(int i = 0; i < record.length; i++)
        {
            java.util.StringTokenizer st = new java.util.StringTokenizer(record[i]);
            switch(st.nextToken())
            {
                case "Enter":
                    answer[arraySize] = dic.get(st.nextToken())+"님이 들어왔습니다.";
                    arraySize++;
                    break;
                case "Leave":
                    answer[arraySize] = dic.get(st.nextToken())+"님이 나갔습니다.";
                    arraySize++;
                    break;
            }
        }
        return answer;
    }
}