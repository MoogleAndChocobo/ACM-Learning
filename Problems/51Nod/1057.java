import java.math.*;
import java.util.Scanner;
import java.io.BufferedInputStream;

public class Main {
	public static void main(String[] args) {
		
		Scanner sc = new Scanner(new BufferedInputStream(System.in));
		
		int n = sc.nextInt();
		BigInteger ans = new BigInteger("1");
		for(int i = 2; i <= n; ++i) {
			BigInteger val = new BigInteger(String.valueOf(i));
			ans = ans.multiply(val);
		}
		System.out.println(ans);
	}
}