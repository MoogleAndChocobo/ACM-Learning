#include<cstdio>
#include<string>

using namespace std;

int main()
{
    int num;
    scanf("%d", &num);
    getchar();
    char temp[5] = {0}, temp1[5] = {0};
    int cnt = 1;
    scanf("%s", temp);
    string s = temp, s1;
    for(int i = 1; i < num; i++)
    {
        scanf("%s", temp1);
        s1 = temp1;
        if(s != s1)
            cnt++;
        s = s1;
    }
    printf("%d\n", cnt);
    return 0;
}