import java.util.Scanner;
import java.io.*;
import java.math.*;

public class Main {
	public static void main(String[] args) {
		Scanner sc = new Scanner(new BufferedInputStream(System.in));

		while (sc.hasNextBigDecimal()) {
			BigDecimal a = sc.nextBigDecimal();
			BigDecimal b = sc.nextBigDecimal();
			String ans = String.valueOf(a.add(b));
			int len = ans.length();
			int idx = len - 1;
			if (ans.indexOf('.') != -1) {
				for (int i = len - 1; i >= 0; --i) {
					if (ans.charAt(i) != '0') {
						break;
					}
					--idx;
				}
				if(idx >= 0 && ans.charAt(idx) == '.') {
					--idx;
				}
			}
			if(idx < 0) {
				System.out.println("0");
			} else {
					System.out.println(ans.substring(0, idx + 1));
			}
		}
	}
}