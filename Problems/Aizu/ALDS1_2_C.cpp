#include<cstdio>
#include<algorithm>

using namespace std;

#define FOR(i, a, b) for(int i = a; i <= b; i++)

struct Card
{
	char color;
	int value;
	friend bool operator!= (Card a, Card b)
	{
		if(a.color != b.color || a.value != b.value)
			return true;
		else
			return false;
	}
};

const int MAX = 40;
int n;
Card s[MAX], org[MAX];

void BubbleSort(void)
{
	FOR(i, 0, n - 1)
	{
		for(int j = n - 1; j >= i + 1; j--)
		{
			if(s[j].value < s[j - 1].value)
				swap(s[j], s[j - 1]);
		}
	}
	FOR(i, 0, n - 1)
	{
		printf("%c%d", s[i].color, s[i].value);
		if(i != n - 1)
			printf(" ");
		else
			printf("\n");
	}
	printf("Stable\n");
	return;
}

void SelectionSort(void)
{
	FOR(i, 0, n - 1)
	{
		int minj = i;
		for(int j = i; j < n; j++)
			if(org[j].value < org[minj].value)
				minj = j;
		swap(org[i], org[minj]);
	}
	FOR(i, 0, n - 1)
	{
		printf("%c%d", org[i].color, org[i].value);
		if(i != n - 1)
			printf(" ");
		else
			printf("\n");
	}
	bool flag = true;
	FOR(i, 0, n - 1)
	{
		if(s[i] != org[i])
		{
			flag = false;
			break;
		}
	}
	if(flag)
		printf("Stable\n");
	else
		printf("Not stable\n");
	return;
}

int main()
{
	while(~scanf("%d", &n))
	{
		FOR(i, 0, n - 1)
		{
			getchar();
			scanf("%c%d", &s[i].color, &s[i].value);
			org[i].color = s[i].color, org[i].value = s[i].value;
		}

		BubbleSort();
		SelectionSort();
	}
	return 0;
}