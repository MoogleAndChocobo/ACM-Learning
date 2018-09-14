#include<cstdio>

int main()
{
    int sum, s_sum, cost, s_cost;
    scanf("%d%d%d%d", &sum, &s_sum, &cost, &s_cost);
    int mymin = sum * cost;
    if(s_cost / s_sum < cost)
    {
        int temp = sum / s_sum * s_cost;
        if(sum % s_sum)
        {
            if(s_cost < (sum % s_sum) * cost)
                temp += s_cost;
            else
                temp += (sum % s_sum) * cost;
        }
        if(temp < mymin)
            mymin = temp;
    }
    printf("%d", mymin);
    return 0;
}