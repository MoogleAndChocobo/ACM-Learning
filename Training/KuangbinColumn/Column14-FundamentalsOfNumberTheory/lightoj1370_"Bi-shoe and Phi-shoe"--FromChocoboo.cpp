/*
Bamboo Pole-vault is a massively popular sport in Xzhiland. And Master Phi-shoe is a very popular coach for his success. He needs some bamboos for his students, so he asked his assistant Bi-Shoe to go to the market and buy them. Plenty of Bamboos of all possible integer lengths (yes!) are available in the market. According to Xzhila tradition,

Score of a bamboo = Φ (bamboo's length)

(Xzhilans are really fond of number theory). For your information, Φ (n) = numbers less than n which are relatively prime (having no common divisor other than 1) to n. So, score of a bamboo of length 9 is 6 as 1, 2, 4, 5, 7, 8 are relatively prime to 9.

The assistant Bi-shoe has to buy one bamboo for each student. As a twist, each pole-vault student of Phi-shoe has a lucky number. Bi-shoe wants to buy bamboos such that each of them gets a bamboo with a score greater than or equal to his/her lucky number. Bi-shoe wants to minimize the total amount of money spent for buying the bamboos. One unit of bamboo costs 1 Xukha. Help him.

Input
Input starts with an integer T (≤ 100), denoting the number of test cases.

Each case starts with a line containing an integer n (1 ≤ n ≤ 10000) denoting the number of students of Phi-shoe. The next line contains n space separated integers denoting the lucky numbers for the students. Each lucky number will lie in the range [1, 106].

Output
For each case, print the case number and the minimum possible money spent for buying the bamboos. See the samples for details.

Sample Input
3

5

1 2 3 4 5

6

10 11 12 13 14 15

2

1 1

Sample Output
Case 1: 22 Xukha

Case 2: 88 Xukha

Case 3: 4 Xukha
*/

#include <cstdio>
#include <cstring>
#include <algorithm>
#include <string>
#include <iostream>
#include <queue>
#include <set>
#include <map>
#include <vector>

using namespace std;

typedef long long LL;

#define sfi(a) scanf("%d", &a)
#define rep(i, a, b) for(int i = a; i <= b; i++)
#define mem(a) memset(a, 0, sizeof(a))
#define mst(a, b) memset(a, b, sizeof(a))

const int MAX = 2e6 + 5;
const int N = 2e6;
const int INF = 1e9 + 7;

bool isprime[MAX];
int prime[MAX];
int tot;
int ans[MAX];

void getprime(void)
{
	mst(isprime, true);
	isprime[0] = isprime[1] = false;
	rep(i, 2, N)
	{
		if(isprime[i])
			prime[++tot] = i;
		for(int j = 1; j <= tot && i * prime[j] <= N; j++)
		{
			isprime[i * prime[j]] = false;
			if(i % prime[j] == 0)
				break;
		}
	}
}

void geteuler(void)
{
	getprime();

	int cnt = 1;
	rep(i, 1, 1000000)
	{
		if(prime[cnt] > i)
			ans[i] = prime[cnt];
		else
		{
			while(prime[cnt] <= i)
				cnt++;
			ans[i] = prime[cnt];
		}
	}
}



int main()
{
	geteuler();

	int T;
	sfi(T);
	rep(kase, 1, T)
	{
		int n;
		sfi(n);
		LL sum = 0;
		rep(i, 1, n)
		{
			int tmp;
			sfi(tmp);
			sum += (LL)ans[tmp];
		}
		printf("Case %d: %lld Xukha\n", kase, sum);
	}

	return 0;
}
