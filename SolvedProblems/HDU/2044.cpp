#include <stdio.h>

int main()
{
    int num;
    scanf("%d", &num);
    for(int i = 0; i < num; i++)
    {
        int min, max;
        scanf("%d%d", &min, &max);
        long long s[55] = {0};
        s[0] = 1;
        s[1] = 1;
        for(int j = 2; j <= max - min; j++)
            s[j] = s[j - 1] + s[j - 2];
        printf("%lld\n", s[max - min]);
    }
}