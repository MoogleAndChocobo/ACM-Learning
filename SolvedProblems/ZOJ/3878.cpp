#include<bits/stdc++.h>
using namespace std;
typedef long long ll;

map<char,char>m;

void c(char a,char c)
{
	m[a]=c;
}

void init()
{
	c('_','{');
	c('-','[');
	c('+','}');
	c('=',']');
	c('Q','\"');
	c('q','\'');
	c('W','<');
	c('w',',');
	c('E','>');
	c('e','.');
	c('R','P');
	c('r','p');
	c('T','Y');
	c('t','y');
	c('Y','F');
	c('y','f');
	c('U','G');
	c('u','g');
	c('I','C');
	c('i','c');
	c('O','R');
	c('o','r');
	c('P','L');
	c('p','l');
	c('{','?');
	c('[','/');
	c('}','+');
	c(']','=');
	c('S','O');
	c('s','o');
	c('D','E');
	c('d','e');
	c('F','U');
	c('f','u');
	c('G','I');
	c('g','i');
	c('H','D');
	c('h','d');
	c('J','H');
	c('j','h');
	c('K','T');
	c('k','t');
	c('L','N');
	c('l','n');
	c(':','S');
	c(';','s');
	c('\"','_');
	c('\'','-');
    c('Z',':');
    c('z',';');
    c('X','Q');
    c('x','q');
    c('C','J');
    c('c','j');
    c('V','K');
    c('v','k');
    c('B','X');
    c('b','x');
    c('N','B');
    c('n','b');
    c('<','W');
    c(',','w');
    c('>','V');
    c('.','v');
    c('?','Z');
    c('/','z');
}
int main()
{
	init();

	string s;
	while(getline(cin,s))
	{
        const int len=s.size();
        for(int i=0;i<len;i++)
		{
			if(m[s[i]])
			{
				s[i]=m[s[i]];
			}
		}
		cout<<s<<endl;
	}
}