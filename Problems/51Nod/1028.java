import java.util.Scanner;
import java.math.*;
import java.io.*;

public class Main {
	public static void main(String[] args) {
		Scanner sc = new Scanner(new BufferedInputStream(System.in));
		
		BigInteger a = sc.nextBigInteger();
		
		System.out.println(a.multiply(sc.nextBigInteger()));
	}
}