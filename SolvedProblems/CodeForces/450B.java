import java.io.*;
import java.math.*;
import java.util.Scanner;

public class Main {
	public static void main(String[] args) {
		final int kMax = 1010;
		final long kMod = 1000000007;
		
		Scanner sc = new Scanner(new BufferedInputStream(System.in));

		Matrix mat = new Matrix();

		long x, y, n;
		while (sc.hasNextInt()) {
			x = sc.nextInt();
			y = sc.nextInt();
			n = sc.nextInt();

			long ans = 0;
			if (n == 1) {
				ans = x;
			} else if (n == 2) {
				ans = y;
			} else {
				long k = n - 2;
				mat.p[0][0] = mat.p[1][0] = 1;
				mat.p[1][1] = 0;
				mat.p[0][1] = -1;
				mat = mat.pow(k);
				ans = (mat.p[0][0] * y + mat.p[0][1] * x) % kMod;
			}
			if (ans < 0) {
				ans += kMod;
			}
			System.out.println(ans);
		}
	}

	public static long f(long b) {
		final long kMod = 1000000007;
		long a = 2;
		long ans = 1;
		while (b != 0) {
			if (b % 2 != 0) {
				ans *= a;
				ans %= kMod;
			}
			a *= a;
			a %= kMod;
			b>>=1;
		}
		return ans;
	}
}

class Matrix {
	static long kMod;

	static {
		kMod = 1000000007;
	}

	long [][] p;

	Matrix() {
		p = new long[1010][1010];
	}

	Matrix multiply(Matrix a) {
		Matrix ret = new Matrix();
		for (int i = 0; i < 2; ++i) {
			for (int j = 0; j < 2; ++j) {
				for (int k = 0; k < 2; ++k) {
					ret.p[i][j] = (ret.p[i][j] + p[i][k] * a.p[k][j]) % kMod;
				}
			}
		}
		return ret;
	}

	Matrix pow(long a) {
		Matrix ret = new Matrix();
		for (int i = 0; i < 2; ++i) {
			ret.p[i][i] = 1;
		}
		long m = a;
		Matrix tmp = new Matrix();
		for (int i = 0; i < 2; ++i) {
			for (int j = 0; j < 2; ++j) {
				tmp.p[i][j] = p[i][j];
			}
		}
		while (m != 0) {
			if (m % 2 != 0) {
				ret = ret.multiply(tmp);
			}
			tmp = tmp.multiply(tmp);
			m>>=1;
		}
		return ret;
	}
}