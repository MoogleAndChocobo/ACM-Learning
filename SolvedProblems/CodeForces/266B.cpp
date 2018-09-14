#include<cstdio>

const int MAX = 55;

int main()
{
    int n, times;
    scanf("%d%d", &n, &times);
    char s[MAX] = {0};
    scanf("%s", s);
    for(int i = 0; i < times; i++)
    {
        for(int j = 0; j < n - 1; j++)
            if(s[j] == 'B' && s[j + 1] == 'G')
            {
                s[j] = 'G';
                s[++j] = 'B';
            }
    }
    printf("%s\n", s);
    return 0;
}