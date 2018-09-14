#include<cstdio>
#include<vector>

using namespace std;

vector<int> monster;
vector<int> help;

int main()
{
    int stre, test;
    scanf("%d%d", &stre, &test);
    for(int i = 0; i < test; i++)
    {
        int temp, temp1;
        scanf("%d%d", &temp, &temp1);
        monster.push_back(temp);
        help.push_back(temp1);
    }
    for(int j = 0; j < test; j++)
    {
        int mymax, record;
        for(int i = 0; i < test; i++)
        {
            if(stre > monster[i] && monster[i] != -1)
            {
                mymax = help[i];
                record = i;
                break;
            }
            if(i == test - 1)
            {
                printf("NO");
                return 0;
            }
        }
        for(int i = record + 1; i < test; i++)
        {
            if(mymax < help[i] && help[i] != -1 && stre > monster[i])
            {
                mymax = help[i];
                record = i;
            }
        }
        stre += help[record];
        monster[record] = -1;
        help[record] = -1;
    }
    printf("YES");
    return 0;
}