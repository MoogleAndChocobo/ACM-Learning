/*
	A number whose only prime factors are 2,3,5 or 7 is called a humble number. The sequence 1, 2, 3, 4, 5, 6, 7, 8, 9, 10, 12, 14, 15, 16, 18, 20, 21, 24, 25, 27, ... shows the first 20 humble numbers.

	Write a program to find and print the nth element in this sequence
	Input
	The input consists of one or more test cases. Each test case consists of one integer n with 1 <= n <= 5842. Input is terminated by a value of zero (0) for n.
	Output
	For each test case, print one line saying "The nth humble number is number.". Depending on the value of n, the correct suffix "st", "nd", "rd", or "th" for the ordinal number nth has to be used like it is shown in the sample output.
	Sample Input
	1
	2
	3
	4
	11
	12
	13
	21
	22
	23
	100
	1000
	5842
	0
	Sample Output
	The 1st humble number is 1.
	The 2nd humble number is 2.
	The 3rd humble number is 3.
	The 4th humble number is 4.
	The 11th humble number is 12.
	The 12th humble number is 14.
	The 13th humble number is 15.
	The 21st humble number is 28.
	The 22nd humble number is 30.
	The 23rd humble number is 32.
	The 100th humble number is 450.
	The 1000th humble number is 385875.
	The 5842nd humble number is 2000000000.
*/


#include <cstdio>
#include <algorithm>
#include <cstring>
#include <string>
#include <vector>
#include <set>
#include <queue>
#include <map>
#include <cmath>
#include <cctype>

using namespace std;

typedef long long LL;

#define rep(i, a, b) for(int i = a; i <= b; ++i)
#define dow(i, a, b) for(int i = a; i <= b; --i)
#define sfi(a) scanf("%d", &a)
#define fli freopen("in.txt", "r", stdin);
#define flo freopen("out.txt", "w", stdout);

const int MAX = 1e5 + 5;

LL dp[MAX];

LL minfour(LL dpa, LL dpb, LL dpc, LL dpd)
{
	dpa = min(dpa, dpb);
	dpa = min(dpa, dpc);
	dpa = min(dpa, dpd);
	return dpa;
}

void init()
{
	dp[1] = 1;
	int a, b, c, d;
	a = b = c = d = 1;
	rep(i, 2, 5850)
	{
		LL dpa = dp[a] * 2;
		LL dpb = dp[b] * 3;
		LL dpc = dp[c] * 5;
		LL dpd = dp[d] * 7;
		dp[i] = minfour(dpa, dpb, dpc, dpd);
		if(dp[i] == dpa)
			a++;
		if(dp[i] == dpb)
			b++;
		if(dp[i] == dpc)
			c++;
		if(dp[i] == dpd)
			d++;
	}
}

int main()
{

#ifdef LOCAL
	//~ fli
	//~ flo
#endif	//LOCAL

	init();

	int n;
	while(~sfi(n) && n)
	{
		printf("The %d", n);
		if(n % 10 == 1 && n % 100 != 11)
			printf("st");
		else if(n % 10 == 2 && n % 100 != 12)
			printf("nd");
		else if(n % 10 == 3 && n % 100 != 13)
			printf("rd");
		else
			printf("th");
		printf(" humble number is %lld.\n", dp[n]);
	}
	return 0;
}
