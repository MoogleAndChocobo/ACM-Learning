import java.util.Scanner;
import java.io.*;
import java.math.*;

public class Main {
	public static void main(String[] args) {
		Scanner sc = new Scanner(new BufferedInputStream(System.in));

		int t = sc.nextInt();
		for (int kase = 1; kase <= t; ++kase) {
			int n = sc.nextInt();
			if(n == 1 || n == 2) {
				System.out.println("1");
			} else {
				BigInteger a = new BigInteger("1");
				BigInteger ans = new BigInteger("1");
				for (int i = 3; i <= n; ++i) {
					BigInteger tmp = ans;
					ans = ans.add(a);
					a = tmp;
				}
				System.out.println(ans);
			}
		}
	}
}