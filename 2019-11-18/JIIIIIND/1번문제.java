import java.io.*;
import java.util.ArrayList;
import java.util.Iterator;
import java.util.Stack;
import java.util.StringTokenizer;

public class Main {
    public static void main(String[] args) throws Exception
    {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        BufferedWriter wr = new BufferedWriter(new OutputStreamWriter(System.out));
        StringTokenizer st;

        int number = Integer.parseInt(br.readLine());

        ArrayList<Number> input = new ArrayList<>();
        Stack<Number> compares = new Stack<>();
        int[] output = new int[number];

        st = new StringTokenizer(br.readLine());
        int index = 0;
        while(st.hasMoreTokens())
        {
            input.add(new Number(Integer.parseInt(st.nextToken()), index));
            index++;
        }

        for(Number value : input)
            okunsu(value, compares, output);

        while(!compares.empty())
            output[compares.pop().GetIndex()] = -1;

        for(int value : output)
            wr.write(value+" ");
        wr.flush();
        wr.close();
    }

    private static void okunsu(Number number, Stack<Number> compare, int[] output)
    {
        while((!compare.isEmpty()) && (compare.peek().GetNumber() < number.GetNumber()))
        {
            output[compare.peek().GetIndex()] = number.GetNumber();
            compare.pop();
        }
        compare.push(number);
    }
}

class Number
{
    private int number;
    private int index;

    public Number(int number, int index)
    {
        this.number = number;
        this.index = index;
    }

    public int GetNumber(){return number;}
    public int GetIndex(){return index;}
}