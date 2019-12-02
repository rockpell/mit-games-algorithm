import java.util.HashMap;
import java.util.Map;
import java.util.List;
import java.util.ArrayList;

class Solution {
    public String[] solution(String[] record) {
        String[] answer = {};
        
        Map<String, String> userList = new HashMap<String, String>();
        List<CommandOrder> commandOrderList = new ArrayList<CommandOrder>();

        for(int i = 0; i < record.length; i++){
            String[] strings =  record[i].split(" ");
            if(strings.length > 2)
                userList.put(strings[1], strings[2]);
            if(!(strings[0].equals("Change")))
                commandOrderList.add(new CommandOrder(strings[0], strings[1]));
        }

        answer = new String[commandOrderList.size()];

        CommandOrder commandOrder;

        for(int i = 0; i < commandOrderList.size(); i++){
            commandOrder = commandOrderList.get(i);
            answer[i] = commandOrder.printLog(userList.get(commandOrder.uid));
        }
        
        return answer;
    }
}

class CommandOrder{
    public  String command;
    public  String uid;

    public CommandOrder(String command, String uid){
        this.command = command;
        this.uid = uid;
    }

    public String printLog(String nickname){
        String result;

        result = new StringBuilder().append(nickname)
                .append("님이 ").append(commandTranslate()).toString();

        return  result;
    }

    public String commandTranslate(){
        String result = "";
        if(command.equals("Enter")){
            result = "들어왔습니다.";
        }
        else if(command.equals("Leave")){
            result = "나갔습니다.";
        }
        return result;
    }
}
