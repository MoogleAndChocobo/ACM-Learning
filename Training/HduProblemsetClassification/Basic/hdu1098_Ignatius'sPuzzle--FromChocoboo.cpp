/*
	Ignatius's puzzle
	Time Limit: 2000/1000 MS (Java/Others)    Memory Limit: 65536/32768 K (Java/Others)
	Total Submission(s): 11057    Accepted Submission(s): 7820


	Problem Description
	Ignatius is poor at math,he falls across a puzzle problem,so he has no choice but to appeal to Eddy. this problem describes that:f(x)=5*x^13+13*x^5+k*a*x,input a nonegative integer k(k<10000),to find the minimal nonegative integer a,make the arbitrary integer x ,65|f(x)if
	no exists that a,then print "no".



	Input
	The input contains several test cases. Each test case consists of a nonegative integer k, More details in the Sample Input.


	Output
	The output contains a string "no",if you can't find a,or you should output a line contains the a.More details in the Sample Output.


	Sample Input
	11
	100
	9999


	Sample Output
	22
	no
	43


	Author
	eddy


	Recommend
	We have carefully selected several similar problems for you:  1071 1052 1082 1124 1035
*/


#include <bits/stdc++.h>

using namespace std;

#define sfi(a) scanf("%d", &a)
#define rep(i, a, b) for(int i = a; i <= b; i++)

int main()
{
	int n;
	while(~sfi(n) && n)
	{
		int a = 0;
		rep(i, 1, 65)
		{
			if((18 + i * n) % 65 == 0)
			{
				a = i;
				break;
			}
		}
		if(a)
			printf("%d\n", a);
		else
			puts("no");
	}
	return 0;
}
