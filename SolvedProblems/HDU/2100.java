import java.io.*;
import java.math.*;
import java.util.Scanner;

public class Main {
	public static void main(String[] args) {
		Scanner sc = new Scanner(new BufferedInputStream(System.in));

		while(sc.hasNextLine())
		{
			String tmp = sc.nextLine();
			int mid = tmp.indexOf(' ');
			int tmplen = tmp.length();
			String a = tmp.substring(0, mid);
			String b = tmp.substring(mid + 1, tmplen);

			int la = a.length(), lb = b.length();

			BigInteger m = new BigInteger("0");
			BigInteger n = new BigInteger("0");
			BigInteger thispow = new BigInteger("26");
			

			BigInteger mypow = new BigInteger("1");
			for (int i = la - 1; i >= 0; --i) {
				BigInteger now = new BigInteger(String.valueOf(ch(a.charAt(i))));
				m = m.add(mypow.multiply(now));
				mypow = mypow.multiply(thispow);
			}

			mypow = new BigInteger("1");
			for (int i = lb - 1; i >= 0; --i) {
				BigInteger now = new BigInteger(String.valueOf(ch(b.charAt(i))));
				m = m.add(mypow.multiply(now));
				mypow = mypow.multiply(thispow);
			}

			BigInteger res = m.add(n);
			String ans = "";
			BigInteger cmp = new BigInteger("0");
			while(!res.equals(cmp)) {
				String now = String.valueOf(res.remainder(thispow));
				res = res.divide(thispow);
				int in = Integer.valueOf(now);
				ans += re(in);
			}

			boolean flag = false;
			int len = ans.length();
			for (int i = len - 1; i >= 0; --i) {
				System.out.print(ans.charAt(i));
				flag = true;
			}
			if (!flag) {
				System.out.print("A");
			}
			System.out.println();
		}
	}

	public static int ch(char c) {
		return (c - 'A');
	}

	public static char re(int x) {
		return (char)(x + 'A');
	}
}