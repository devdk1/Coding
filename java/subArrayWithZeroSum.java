import java.util.*;

class subArrayWithZeroSum {
    public static boolean isExists(int arr[], int n) {
        Set<Integer> set = new HashSet<>();

        int sum = 0;
        set.add(0);
        for(int i = 0; i < n; i++) {
            sum += arr[i];

            if(set.contains(sum))
                return true;
            set.add(sum);
        }
        
        return false;
    }
    public static void main(String args[]) {
        Scanner scan = new Scanner(System.in);
        int n = scan.nextInt();
        int arr[] = new int[n];
        for(int i = 0; i < n; i++) 
            arr[i] = scan.nextInt();

        scan.close();
        if(subArrayWithZeroSum.isExists(arr, n)) System.out.println("Yes");
        else System.out.println("No");
    }
}