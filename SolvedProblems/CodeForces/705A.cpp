#include<cstdio>

int main()
{
    int num;
    scanf("%d", &num);
    printf("I hate ");
    for(int i = 1; i < num; i++)
    {
        if(i % 2)
            printf("that I love ");
        else
            printf("that I hate ");
    }
    printf("it");
    return 0;
}