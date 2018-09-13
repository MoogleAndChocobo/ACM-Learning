import java.math.*;
import java.util.Scanner;
import java.io.BufferedInputStream;

public class Main {
	public static void main(String[] args) {
		
		Scanner sc = new Scanner(new BufferedInputStream(System.in));
		
		BigInteger a = new BigInteger(sc.next());
		BigInteger b = new BigInteger(sc.next());
		BigInteger ans[] = a.divideAndRemainder(b);
		System.out.println(ans[0] + "\n" + ans[1]);
	}
}