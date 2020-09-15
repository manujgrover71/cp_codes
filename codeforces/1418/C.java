// package cp;

import java.util.Scanner;

public class Main {
    public static void main(String[] args) {

        Scanner sc = new Scanner(System.in);

        int t = sc.nextInt();

        while(t-- > 0) {

            int n = sc.nextInt();

            int arr[] = new int[n+1];

            for(int i = 0; i < n; i++) {
                arr[i] = sc.nextInt();
            }

            int dp[][] = new int[n+5][2];
            dp[0][0] = arr[0];
            dp[0][1] = (int)1e9;
            dp[1][0] = arr[0] + arr[1];
            dp[1][1] = arr[0];

            for(int i = 2; i < n; i++) {
                dp[i][0] = Math.min(dp[i-1][1] + arr[i], dp[i-2][1] + arr[i-1] + arr[i]);
                dp[i][1] = Math.min(dp[i-1][0], dp[i-2][0]);
            }

            System.out.println(Math.min(dp[n-1][0], dp[n-1][1]));
        }

    }
}