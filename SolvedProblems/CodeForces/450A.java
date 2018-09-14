import java.io.*;
import java.math.*;
import java.util.Scanner;
import java.util.Queue;
import java.util.LinkedList;

public class Main {
	public static void main(String[] args) {
		final int kMax = 1010;
		
		Scanner sc = new Scanner(new BufferedInputStream(System.in));

		int n = sc.nextInt();
		int m = sc.nextInt();

		Queue<Person> q = new LinkedList<Person>();
		Integer [] s = new Integer[kMax];

		for (int i = 1; i <= n; ++i) {
			s[i] = sc.nextInt();
			q.offer(new Person(0, i));
		}
		int ans = 1;
		while (!q.isEmpty()) {
			Person now = q.element();
			q.remove();
			ans = now.order;
			now.num += m;
			if (now.num < s[now.order]) {
				q.offer(now);
			}
		}
		System.out.println(ans);
	}
}

class Person {
	int num;
	int order;
	Person(int num, int order) {
		this.num = num;
		this.order = order;
	}
}