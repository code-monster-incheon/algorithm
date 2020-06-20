import java.util.Scanner;

public class Main
{

    public static void main(String[] args)
    {

        Scanner sc = new Scanner(System.in);
        int p, w;
        String str,qwe;
        p = sc.nextInt();
        w = sc.nextInt();
        qwe = sc.nextLine();
        str = sc.nextLine();


        int number = 0;
        int ret = 0;


        for(int i = 0; i < str.length(); i++)
        {
            char t = str.charAt(i);

            if(t <= 'C' && t >= 'A')
            {
                int temp = t - 'A' + 1;

                if(number != 2)
                {
                    ret += p * temp;
                }
                else
                {
                    ret += w;
                    ret += p * temp;
                }

                number = 2;
            }
            else if(t <= 'F' && t >= 'D')
            {
                int temp = t - 'D' + 1;
                if(number != 3)
                {
                    ret += p * temp;
                }
                else
                {
                    ret += w;
                    ret += p * temp;
                }
                number = 3;
            }
            else if(t <= 'I' && t >= 'G')
            {
                int temp = t - 'G' + 1;
                if(number != 4)
                {
                    ret += p * temp;
                }
                else
                {
                    ret += w;
                    ret += p * temp;
                }
                number = 4;
            }
            else if(t <= 'L' && t >= 'J')
            {
                int temp = t - 'J' + 1;
                if(number != 5)
                {
                    ret += p * temp;
                }
                else
                {
                    ret += w;
                    ret += p * temp;
                }
                number = 5;
            }
            else if(t <= 'O' && t >= 'M')
            {
                int temp = t - 'M' + 1;
                if(number != 6)
                {
                    ret += p * temp;
                }
                else
                {
                    ret += w;
                    ret += p * temp;
                }
                number = 6;
            }
            else if(t <= 'S' && t >= 'P')
            {
                int temp = t - 'P' + 1;
                if(number != 7)
                {
                    ret += p * temp;
                }
                else
                {
                    ret += w;
                    ret += p * temp;
                }
                number = 7;
            }
            else if(t <= 'V' && t >= 'T')
            {
                int temp = t - 'T' + 1;
                if(number != 8)
                {
                    ret += p * temp;
                }
                else
                {
                    ret += w;
                    ret += p * temp;
                }
                number = 8;
            }
            else if(t <= 'Z' && t >= 'W')
            {
                int temp = t - 'W' + 1;
                if(number != 9)
                {
                    ret += p * temp;
                }
                else
                {
                    ret += w;
                    ret += p * temp;
                }
                number = 9;
            }
            else
            {
                number = 0;
                ret += p;
            }


        }

        System.out.println(ret);
    }
}
