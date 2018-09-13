import java.util.Scanner;
import java.io.BufferedInputStream;
import java.math.*;

public class Main {
	public static void main(String[] args) {
		
		Scanner sc = new Scanner(new BufferedInputStream(System.in));
		
		BigInteger a = new BigInteger(sc.next());
		BigInteger b = new BigInteger(sc.next());
		System.out.println(a.multiply(b));
		
	}
}