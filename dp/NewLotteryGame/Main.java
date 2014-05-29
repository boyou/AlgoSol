import java.io.BufferedReader;
import java.io.InputStreamReader;
import java.io.IOException;



public class Main {


    public static void main(String[] args) throws IOException {
        BufferedReader in = new BufferedReader(
                new InputStreamReader(System.in));
        // no need to convert to integer
        String D = in.readLine();
        // but need to reverse ;)
        System.out.println(work(new StringBuilder(D).reverse().toString()));
        in.close();
    }

    private static long get(long[][][] dp, int i, int j, int k, int L) {
        return i >= 0 ? dp[i][j][k + L] : (j == 1 && k == 0 ? 1 : 0);
    }

    private static long work(String D) {
        long ret = 0;
        // L will also be used as the offset
        int L = D.length();
        long[][][] dp = new long[L][2][2 * L + 1];
        // corner cases can be covered here
        for (int i = 0; i < L; ++i) {
            for (int k = -i; k <= i; ++k) {
                for (int x = 4; x <= 7; x += 3) {
                    // smaller
                    if (x < D.charAt(i) - '0') {
                        dp[i][0][L + k + (x == 4 ? 1 : -1)] += get(dp, i - 1, 1, k, L);
                    } else if (x == D.charAt(i) - '0') {
                        dp[i][0][L + k + (x == 4 ? 1 : -1)] += get(dp, i - 1, 0, k, L);
                    }
                    // no restriction
                    dp[i][1][L + k + (x == 4 ? 1 : -1)] += get(dp, i - 1, 1, k, L);
                }
            }
            // for numbers whose length are smaller than D,
            // no further restriction needed since theri VALUE already smaller than D
            if (i < L - 1) {
                ret += get(dp, i, 1, -1, L) + get(dp, i, 1, 0, L) + get(dp, i, 1, 1, L);
            } else {
                ret += get(dp, i, 0, -1, L) + get(dp, i, 0, 0, L) + get(dp, i, 0, 1, L);
            }
        }
        return ret;
    }


}
