import java.util.StringTokenizer;
import java.io.*;

public class Translate
{
    public Translate(String str) throws IOException
    {
        String result;
        if(cppCheck(str))
        {
            result = cppToJava(str);
        }
        else if(javaCheck(str))
        {
            result = javaToCpp(str);
        }
        else
        {
            //Error! 출력
            result = "Error!";
        }
        //출력
        BufferedWriter out = new BufferedWriter(new OutputStreamWriter(System.out));
        out.write(result+"\n");
        out.flush();
        out.close();
    }
    private boolean cppCheck(String str)
    {
        return str.matches("^[a-z]+(_[a-z]+)*$");
    }
    private boolean javaCheck(String str)
    {
        return str.matches("^[a-z]+([A-Z][a-z]*)*$");
    }
    private String cppToJava(String str)
    {
        String result = "";
        //cpp문법이니까 _단위로 자름
        //첫번째는 그냥 넣고 두번째부터 첫 문자는 대문자로 수정
        StringTokenizer st = new StringTokenizer(str, "_");
        result += st.nextToken();
        while(st.hasMoreTokens())
        {
            char[] array = st.nextToken().toCharArray();
            array[0] -= 32;
            result += new String(array);
        }
        return result;
    }
    private String javaToCpp(String str)
    {
        String result = "";
        //java니까 대문자 나오기 전까지는 그냥 넣고
        //대문자가 나오면 앞에 _붙이고 소문자로 수정
        for(int i = 0; i < str.length(); i++)
        {
            char ch = str.charAt(i);
            if((65 <= ch) && (ch <= 90))
            {
                //대문자
                ch+=32;
                result += "_";
                result += ch;
            }
            else if((97 <= ch)&&(ch <= 122))
            {
                //소문자
                result += ch;
            }
        }
        return result;
    }
}
