#include<cstdio>
#include<cstring>
#include<string>
#include<algorithm>

using namespace std;

const int MAX = 210;

int main()
{
    char s0[MAX] = {0};
    char s1[MAX] = {0};
    char s2[MAX] = {0};
    scanf("%s%s%s", s0, s1, s2);
    for(int i = strlen(s0), j = 0; j < strlen(s1); i++, j++)
        s0[i] = s1[j];
    sort(s0, s0 + strlen(s0));
    sort(s2, s2 + strlen(s2));
    string arr_a = s0, arr_b = s2;
    if(arr_a == arr_b)
        printf("YES\n");
    else
        printf("NO\n");
    return 0;
}