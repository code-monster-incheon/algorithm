
import java.util.Scanner;

public class Main {

    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);

        int testCount = sc.nextInt();


        for (int count = 0; count < testCount; count++) {
            String s = sc.next();
            sc.nextLine();
            String t = sc.next();


            int cnt = 0;

            int OToZ = 0;
            int mToZ = 0;
            int mToO = 0;
            int zToO = 0;

            for (int i = 0; i < s.length(); i++) {
                if (s.charAt(i) == '?' && t.charAt(i) == '1') {
                    mToO++;
                } else if (s.charAt(i) == '?' && t.charAt(i) == '0') {
                    mToZ++;
                } else if (s.charAt(i) == '1' && t.charAt(i) == '0') {
                    OToZ++;
                } else if (s.charAt(i) == '0' && t.charAt(i) == '1') {
                    zToO++;
                }
            }

            if (OToZ > zToO + mToO) {
                cnt = -1;
            } else {
                int diff = zToO - OToZ;


                if (diff < 0) {
                    cnt += zToO;
                    OToZ -= zToO;
                    cnt += 2 * OToZ;
                    cnt += mToO - OToZ;
                    cnt += mToZ;
                } else {
                    cnt += zToO;
                    cnt += mToO;
                    cnt += mToZ;
                }
            }
            System.out.printf("Case %d: %d\n", (count + 1), cnt);
        }

    }
}
