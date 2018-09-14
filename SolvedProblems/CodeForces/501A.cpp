#include<iostream>
#include<algorithm>
#include<cstdio>

using namespace std;

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);

    int a, b, c, d;
    while(cin >> a >> b >> c >> d)
    {
        int misha = max(3 * a / 10, a - a * c / 250);
        int vasya = max(3 * b / 10, b - b * d / 250);
        if(misha > vasya)
            printf("Misha\n");
        else if(misha == vasya)
            printf("Tie\n");
        else
            printf("Vasya\n");

    }
    return 0;
}