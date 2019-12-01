import java.util.Collections;
import java.util.ArrayList;


class Solution {
    public int solution(int[] people, int limit)
    {
        int answer = 0;
        ArrayList<Integer> boatPeople = new ArrayList<>();
        for(int value : people)
            boatPeople.add(value);
        //오름차순 정렬 됨
        Collections.sort(boatPeople);

        while(!boatPeople.isEmpty())
        {
            int first = boatPeople.get(boatPeople.size()-1);
            int nextIndex = -1;
            for(int i = 0; i < boatPeople.size()-1; i++)
            {
                if(boatPeople.get(i) + first <= limit)
                    nextIndex = i;
                else
                {
                    if(nextIndex >= 0)
                    {
                        boatPeople.remove(nextIndex);
                        nextIndex = -1;
                    }
                    break;
                }
            }
            if(nextIndex >= 0)
            {
                boatPeople.remove(nextIndex);
                boatPeople.remove(boatPeople.size()-1);
                answer++;
            }
            else
            {
                boatPeople.remove(boatPeople.size()-1);
                answer++;
            }
        }
        return answer;
    }
}