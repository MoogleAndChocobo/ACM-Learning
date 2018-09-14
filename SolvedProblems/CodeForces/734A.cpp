#include<cstdio>

int main()
{
    int num;
    scanf("%d", &num);
    getchar();
    char c;
    int acnt = 0, dcnt = 0;
    for(int i = 0; i < num; i++)
    {
        scanf("%c", &c);
        if(c == 'A')
            acnt++;
        if(c == 'D')
            dcnt++;
    }
    if(acnt == dcnt)
        printf("Friendship");
    else if(acnt > dcnt)
        printf("Anton");
    else
        printf("Danik");
    return 0;
}