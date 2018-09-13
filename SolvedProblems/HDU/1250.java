import java.util.Scanner;
import java.io.*;
import java.math.*;

public class Main {
	public static void main(String[] args) {
		Scanner sc = new Scanner(new BufferedInputStream(System.in));

		while (sc.hasNextInt()) {
			int n = sc.nextInt();
			if (n == 1 || n == 2 || n == 3 || n == 4) {
				System.out.println("1");
			}
			else {
				BigInteger a = new BigInteger("1");
				BigInteger b = new BigInteger("1");
				BigInteger c = new BigInteger("1");
				BigInteger ans = new BigInteger("1");
				for (int i = 5; i <= n; ++i) {
					BigInteger tmp = ans;
					ans = ans.add(a).add(b).add(c);
					a = b;
					b = c;
					c = tmp;
				}
				System.out.println(ans);
			}
		}
	}
}