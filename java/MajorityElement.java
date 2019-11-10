import java.util.Scanner;

public class MajorityElement {
    public static int majorityElement(int arr[], int n) {
        int major = 0;
        int count = 0;

        for(int i = 0; i < n; i++) {
            if(count == 0) {
                major = arr[i];
                count = 1;
            } 
            else if(major == arr[i])
                count++;
            else
                count--; 
        }
        return major;
    }
    public static void main(String args[]) {
        Scanner sc = new Scanner(System.in);
        int n = sc.nextInt();
        int arr[] = new int[n];
        for(int i = 0; i < n; i++)
            arr[i] = sc.nextInt();
        System.out.println("Majority Element is : "+majorityElement(arr, n));
        sc.close();
    }
}