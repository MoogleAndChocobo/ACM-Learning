import java.util.Scanner;
import java.io.*;
import java.math.*;

public class Main {
	public static void main(String[] args) {
		Scanner sc = new Scanner(new BufferedInputStream(System.in));

		while(sc.hasNextInt()) {
			int n = sc.nextInt();
			BigInteger ans = new BigInteger("1");
			for (int i = 2; i <= n; i++) {
				BigInteger now = new BigInteger(String.valueOf(i));
				ans = ans.multiply(now);
			}
			System.out.println(ans);
		}
	}
}