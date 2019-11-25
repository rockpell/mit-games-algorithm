import java.util.LinkedList;

public class solution {
	public String[] solving(String[] record) {
        String[] answer = {};
        int count = 0;		//들어오고 나갔다는 말이 몇번 나왔는지 확인용
        
        
        LinkedList<User> userList = new LinkedList<User>();
        
        count = inputData(record,userList,count);
        
        answer = new String[count]; 
        
        answer = printMessage(answer,record,userList);
        
        return answer;
    }
	
	private int inputData(String[] record, LinkedList<User> userList, int count)
	{
		boolean isAdded = false;
        for(int i = 0 ; i < record.length ; i++)
        {
        	String[] split = record[i].split(" ");
        	
        	if(split[0].equals("Change"))		//닉네임을 바꿨을 때
        	{
        		for(int j = 0; j < userList.size(); j++) //같은 아이디인 유저 찾아서 이름바꿔주기
        		{
        			if(userList.get(j).id.equals(split[1]))
        			{
        				userList.get(j).name = split[2];
        			}
        		}
        	}
        	else if(split[0].equals("Enter"))		//들어왔을 때
        	{
        		count++;
        		for(int j = 0; j < userList.size(); j++)	//들어온적 있는 유저면 이름만 바꿔줌
        		{
        			if(userList.get(j).id.equals(split[1]))
        			{
        				userList.get(j).name = split[2];
        				isAdded = true;
        				break;
        			}
        		}
        		if(!(isAdded))			//들어온적 없으면 새로 리스트에 추가
        			userList.add(new User(split[1],split[2]));
        		isAdded = false;
        	}
        	else if(split[0].equals("Leave"))
        		count++;
        }
        return count;
	}
	
	//답으로 출력할 메세지들 넣는 함수
	private String[] printMessage(String[] answer, String[] record, LinkedList<User> userList)
	{
        for(int i = 0 ; i < record.length ; i++)		//출력
        {
        	String[] split = record[i].split(" ");
        	
        	if(split[0].equals("Enter"))		//들어옴
        	{
        		for(int j = 0; j < userList.size(); j++)	//들어온적 있는 유저면 이름만 바꿔줌
        		{
        			if(userList.get(j).id.equals(split[1]))
        			{
        				answer[i] = userList.get(j).name + "님이 들어왔습니다.";
        				break;
        			}
        		}
        	}
        	else if(split[0].equals("Leave"))		//나감
        	{
        		for(int j = 0; j < userList.size(); j++)	//들어온적 있는 유저면 이름만 바꿔줌
        		{
        			if(userList.get(j).id.equals(split[1]))
        			{
        				answer[i] = userList.get(j).name + "님이 나갔습니다.";
        				break;
        			}
        		}
        	}
        }
        
        return answer;
	}
}

class User
{
    public String id;
    public String name;
    
    public User(String id, String name)
    {
    	this.id = id;
    	this.name = name;
    }
}