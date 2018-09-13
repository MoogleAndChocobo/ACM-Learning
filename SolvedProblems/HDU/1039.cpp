/*
    Easier Done Than Said?
    Time Limit: 2000/1000 MS (Java/Others)    Memory Limit: 65536/32768 K (Java/Others)
    Total Submission(s): 15193    Accepted Submission(s): 7369


    Problem Description
    Password security is a tricky thing. Users prefer simple passwords that are easy to remember (like buddy), but such passwords are often insecure. Some sites use random computer-generated passwords (like xvtpzyo), but users have a hard time remembering them and sometimes leave them written on notes stuck to their computer. One potential solution is to generate "pronounceable" passwords that are relatively secure but still easy to remember.

    FnordCom is developing such a password generator. You work in the quality control department, and it's your job to test the generator and make sure that the passwords are acceptable. To be acceptable, a password must satisfy these three rules:

    It must contain at least one vowel.

    It cannot contain three consecutive vowels or three consecutive consonants.

    It cannot contain two consecutive occurrences of the same letter, except for 'ee' or 'oo'.

    (For the purposes of this problem, the vowels are 'a', 'e', 'i', 'o', and 'u'; all other letters are consonants.) Note that these rules are not perfect; there are many common/pronounceable words that are not acceptable.


    Input
    The input consists of one or more potential passwords, one per line, followed by a line containing only the word 'end' that signals the end of the file. Each password is at least one and at most twenty letters long and consists only of lowercase letters.


    Output
    For each password, output whether or not it is acceptable, using the precise format shown in the example.


    Sample Input
    a
    tv
    ptoui
    bontres
    zoggax
    wiinq
    eep
    houctuh
    end


    Sample Output
    <a> is acceptable.
    <tv> is not acceptable.
    <ptoui> is not acceptable.
    <bontres> is not acceptable.
    <zoggax> is not acceptable.
    <wiinq> is not acceptable.
    <eep> is acceptable.
    <houctuh> is acceptable.


    Source
    Mid-Central USA 2000


    Recommend
    We have carefully selected several similar problems for you:  1073 1043 1088 1113 1161
*/



#include <cstdio>
#include <algorithm>
#include <iostream>
#include <cstring>
#include <string>
#include <sstream>
#include <queue>
#include <set>
#include <map>
#include <functional>
#include <cmath>
#include <cctype>

using namespace std;

typedef long long LL;

const int MAX = 2e4;
const int N = 2e4;

#define rep(i, a, b) for(int i = a; i <=b; i++)
#define dow(i, a, b) for(int i = a; i >=b; i--)
#define mem(a) memset(a, 0, sizeof(a))
#define mst(a, b) memset(a, b, sizeof(a))
#define sfi(a) scanf("%d", &a)
#define sfl(a) scanf("%lld", &a)
#define sfd(a) scanf("%lf"£¬ &a)
#define sfs(a) scanf("%s", a)
#define sync ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
#define all(a) a.begin(),a.end()
#define fli freopen("in.txt", "r", stdin);
#define flo freopen("out.txt", "w",stdout);
#define pb(a) push_back(a)
#define yes puts("yes")
#define no puts("no");
#define Yes puts("Yes")
#define No puts("No")
#define YES puts("YES")
#define NO puts("NO")

int main()
{
#ifdef LOCAL
    //~ fli
    //~ flo
#endif    //LOCAL


    char s[MAX];
    while(~sfs(s) && strcmp(s, "end"))
    {
        int len = strlen(s);
        bool flag = true;
        string ans = "";
        rep(i, 1, len - 1)
        {
            if(s[i] == s[i - 1] && s[i] != 'e' && s[i] != 'o')
            {
                flag = false;
                goto N;
            }
        }
        rep(i, 0, len - 1)
        {
            if(s[i] == 'a' || s[i] == 'e' || s[i] == 'i' || s[i] == 'o' || s[i] == 'u')
                ans += '0';
            else
                ans += '1';
        }
        flag = ans.find('0') != -1 && ans.find("000") == -1 && ans.find("111") == -1;
        N:;
        printf("<%s> is ", s);
        if(!flag)
            printf("not ");
        puts("acceptable.");
    }
    return 0;
}