#include<cstdio>
#include<cstring>
#include<cctype>
#include<string>
#include<sstream>
#include<iostream>

using namespace std;

#define FOR(i, a, b) for(int i = a; i <= b; i++)
#define ROF(i, a, b) for(int i = a; i >= b; i--)
#define PNT putchar('\n')

const int MAX = 1e5 + 10;

int main()
{
    int n;
    while(~scanf("%d", &n))
    {
        while(n--)
        {
            char s[MAX] = {0};
            scanf("%s", s);
            int len = strlen(s);
            bool flag = false;
            int index = 0;
            FOR(i, 0, len - 1)
            {
                if(!isupper(s[i]))
                {
                    for(int j = i; j < len; j++, i++)
                    {
                        if(isupper(s[i]))
                        {
                            index = j;
                            flag = true;
                            break;
                        }
                    }
                }
            }
            if(flag)
            {
                string temp;
                FOR(i, index + 1, len - 1)
                    temp += s[i];
                stringstream ss(temp);
                int num;
                ss >> num;
                char ans[MAX] = {0};
                int cnt = 0;
                while(num)
                {
                    if(num % 26)
                    {
                        ans[cnt++] = num % 26 + 'A' - 1;
                        num /= 26;
                    }
                    else
                    {
                        ans[cnt++] = 'Z';
                        num /= 26;
                        num--;
                    }
                }
                ROF(i, cnt - 1, 0)
                    printf("%c", ans[i]);
                FOR(i, 1, index - 1)
                    printf("%c", s[i]);
                PNT;
            }
            else
            {
                string column, row;
                FOR(i, 0, len - 1)
                {
                    if(isupper(s[i]))
                        column += s[i];
                    else if(isdigit(s[i]))
                        row += s[i];
                }
                cout << "R" << row << "C";
                int num = 0;
                int mypow = 1;
                ROF(i, column.size() - 1, 0)
                {
                    num += (column[i] - 'A' + 1) * mypow;
                    mypow *= 26;
                }
                printf("%d\n", num);
            }
        }
    }
    return 0;
}