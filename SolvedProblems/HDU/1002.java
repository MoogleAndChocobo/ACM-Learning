import java.util.Scanner;
import java.io.*;
import java.math.*;

public class Main {
	public static void main(String[] args) {
		Scanner sc = new Scanner(new BufferedInputStream(System.in));

		int t = sc.nextInt();
		for (int i = 1; i <= t; ++i) {
			BigInteger a = sc.nextBigInteger();
			BigInteger b = sc.nextBigInteger();
			System.out.println("Case " + i + ":");
			System.out.println(a + " + " + b + " = " + a.add(b));
			if (i != t) {
				System.out.println();
			}
		}
	}
}