import java.math.BigInteger;
import java.util.Scanner;
import java.io.*;

public class Main {
	public static void main(String[] args) {
		
		Scanner sc = new Scanner(new BufferedInputStream(System.in));

		int n = sc.nextInt();
		BigInteger ans = new BigInteger("1");
		for(int i = 2; i <= n; ++i) {
			ans = ans.multiply(new BigInteger(String.valueOf(i)));
		}
		String res = ans.toString();
		int len = res.length();
		int lmt = len / 1000;
		if(len % 1000 != 0) {
			++lmt;
		}
		for(int i = 0; i < lmt; ++i) {
			int now = i * 1000;
			if(i != lmt - 1)
				System.out.println(res.substring(now,  now + 1000));
			else
				System.out.println(res.substring(now, len));
		}
	}
}
