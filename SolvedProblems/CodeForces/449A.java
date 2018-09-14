import java.util.Scanner;
import java.io.*;
import java.math.*;

public class Main {
	public static void main(String[] args) {
		Scanner sc = new Scanner(new BufferedInputStream(System.in));

		while (sc.hasNextInt()) {
			long ans = -1;
			long m = sc.nextInt();
			long n = sc.nextInt();
			long k = sc.nextInt();

			if (k > n + m - 2) {
				;
			} else if (k >= Math.max(m, n)) {
				ans = Math.min(m, n) / (k + 1 - (Math.max(m, n) - 1));
			} else {
				ans = Math.max(Math.max(n / (k + 1) * m, m / (k + 1) * n), ans);
			}

			System.out.println(ans);
		}
	}
}