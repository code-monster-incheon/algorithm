import java.util.ArrayList;
import java.util.List;
import java.util.Scanner;

public class Main {
    public static boolean isEqualsStr(String str)
    {
        char temp = str.charAt(0);
        for(int i = 1; i < str.length(); i++)
        {
            if(temp !=str.charAt(i))
            {
                return false;
            }

        }
        return true;
    }

    public static void main(String[] args)
    {
        Scanner sc = new Scanner(System.in);
        String str = sc.next();

        List<String> ret=  new ArrayList<>();
        for (int i = 0; i < str.length(); )
        {
            if (str.charAt(i) == 'X')
            {
                if(i  + 4 <= str.length())
                {
                    String fourStr = str.substring(i, i+4);
                    if(isEqualsStr(fourStr))
                    {
                        i += 4;
                        ret.add("AAAA");
                        continue;
                    }
                }

                if(i + 2 <= str.length())
                {
                    String twoStr = str.substring(i,i+2);
                    if(isEqualsStr(twoStr))
                    {
                        i += 2;
                        ret.add("BB");
                        continue;
                    }
                    else
                    {
                        System.out.println(-1);
                        return;
                    }
                }
                else
                {
                    System.out.println(-1);
                    return;
                }
            }
            else
            {
                ret.add(".");
                i++;
            }
        }

        for(String s : ret)
        {
            System.out.print(s);
        }
    }
}