#include<cstdio>
#include<cctype>

int judgewhite(char c)
{
    if(c == 'Q')
        return 9;
    if(c == 'R')
        return 5;
    if(c == 'B')
        return 3;
    if(c == 'N')
        return 3;
    if(c == 'P')
        return 1;
    else
        return 0;
}

int judgeblack(char c)
{
    if(c == 'q')
        return 9;
    if(c == 'r')
        return 5;
    if(c == 'b')
        return 3;
    if(c == 'n')
        return 3;
    if(c == 'p')
        return 1;
    else
        return 0;
}

int main()
{
    int white, black;
    white = black = 0;
    for(int i = 0; i < 72; i++)
    {
        char c;
        scanf("%c", &c);
        if(isupper(c))
            white += judgewhite(c);
        else if(islower(c))
            black += judgeblack(c);
    }
    if(white > black)
        printf("White");
    else if(white < black)
        printf("Black");
    else
        printf("Draw");
    return 0;
}