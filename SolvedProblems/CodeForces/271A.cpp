#include<cstdio>
#include<cstdlib>

int s[5] = {0};

void f(int year)
{
    s[0] = year / 1000;
    s[1] = year % 1000 / 100;
    s[2] = year % 100 / 10;
    s[3] = year % 10;
}

int main()
{
    int year;
    scanf("%d", &year);
    f(++year);
    while(s[0] == s[1] || s[0] == s[2] || s[0] == s[3] || s[1] == s[2] || s[1] == s[3] || s[2] == s[3])
        f(++year);
    printf("%d\n", year);
    return 0;
}