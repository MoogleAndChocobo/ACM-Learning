#include<bits/stdc++.h>
using namespace std;

vector<int> line;

int main()
{
    int num, temp;
    while(~scanf("%d", &num))
    {
        line.clear();
        for(int i = 0; i < num; i++)
        {
            scanf("%d", &temp);
            line.push_back(temp);
        }
        sort(line.begin(), line.end());
        printf("%d\n", line[(num+1)/2]);
    }
    return 0;
}