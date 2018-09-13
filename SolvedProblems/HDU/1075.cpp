#include<cstdio>
#include<map>
#include<string>
#include<cstring>
#include<cctype>
#include<iostream>

using namespace std;

map<string,string> dict;

const int MAX = 3 * 1e3 + 10;

int main()
{
	char temp[MAX];
	scanf("%s", temp);
	while(~scanf("%s", temp))
	{
		if(!strcmp(temp, "END"))
			break;
		char cvt[MAX];
		scanf("%s", cvt);
		string sa = temp, sb = cvt;
		dict[sb] = sa;
	}
	scanf("%s", temp);
	getchar();
	char line[MAX];
	while(gets(line) != NULL)
	{
		if(!strcmp(line, "END"))
			break;
		bool flag = false;
		int len = strlen(line);
		string word;
		for(int i = 0; i < len; i++)
		{
			char c = line[i];
			if(!isalpha(c) && !flag)
			{
				printf("%c", c);
				flag = false;
			}
			else if(!isalpha(c) && flag)
			{
				if(dict[word] == "\0")
					printf("%s%c", word.c_str(), c);
				else
					printf("%s%c", dict[word].c_str(), c);
				flag = false;
				word.clear();
			}
			else if(isalpha(c))
			{
				flag = true;
				word += c;
			}
		}
		printf("\n");
	}
	return 0;
}