import java.util.ArrayList;
import java.util.Collections;
import java.util.Scanner;

public class Main {

    public static void main(String[] args) {

        Scanner sc = new Scanner(System.in);
        int t = sc.nextInt();

        while(t-- > 0) {

            int n = sc.nextInt();

            int arr[] = new int[n+1];
            int locked[] = new int[n+1];

            ArrayList<Integer> extras = new ArrayList<>();

            for(int i = 0; i < n; i++) {
                arr[i] = sc.nextInt();
            }

            for(int i = 0; i < n; i++) {
                locked[i] = sc.nextInt();
            }

            for(int i = 0; i < n; i++) {
                if(locked[i] != 1) {
                    extras.add(arr[i]);
                }
            }

            Collections.sort(extras, Collections.reverseOrder());

            int ind = 0;

            for(int i = 0; i < n; i++) {
                if(locked[i] == 1) {
                    System.out.print(arr[i] + " ");
                }else {
                    System.out.print(extras.get(ind) + " ");
                    ind++;
                }
            }
            System.out.println();
        }

    }

}
