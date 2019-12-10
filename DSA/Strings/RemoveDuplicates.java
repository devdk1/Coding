import java.util.Scanner;

public class RemoveDuplicates {
    public static String removeDups(String str) {
        int len = str.length();
        char[] ch = str.toCharArray();

        int tail = 1;
        for(int i = 1; i < len; i++) {
            int j;
            for(j = 0; j < tail; j++) {
                if(str.charAt(i) == str.charAt(j)) break;
            }
            if(j == tail) {
                ch[tail] = str.charAt(i);
                tail++;
            }
        }
        return String.valueOf(ch);
    }
    public static void main(String args[]) {
        Scanner sc = new Scanner(System.in);
        String str = sc.nextLine();
        System.out.println(removeDups(str));
        sc.close();
    }
}