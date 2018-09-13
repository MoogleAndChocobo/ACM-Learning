#include <bits/stdc++.h>

using namespace std;

/*
 *
 * FUNCTION: ��һ��������һ����������ƥ��λ��
 *
 * TIME COMPLEXITY: O(N + M)
 *
 * setvalue() -- ������ģʽ��+�ı��� ����ֵ: void
 * find_substring() -- ����: void ����ֵ: ����ƥ�������ַ��±�
 *
 * P.S. ֱ��ʹ��cin coutʱ, �����ٷ�ֹtle
 */

class Kmp
{
private:
	string pattern, text;

public:
	void setvalue(string a, string b)
	{
		pattern = a, text = b;
	}

	vector<int> find_substring()
	{
		int n = pattern.size();
		vector<int> nxt(n + 1,0);
		for(int i = 1; i < n; i++)
		{
			int j = i;
			while(j > 0)
			{
				j = nxt[j];
				if(pattern[j] == pattern[i])
				{
					nxt[i + 1] = j + 1;
					break;
				}
			}
		}
		vector<int> pos;
		int m = text.size();
		for(int i = 0, j = 0; i < m; ++i)
		{
			if(j < n && text[i] == pattern[j])
				j++;
			else
			{
				while(j > 0)
				{
					j = nxt[j];
					if(text[i] == pattern[j])
					{
						j++;
						break;
					}
				}
			}
			if(j == n)
				pos.push_back(i - n + 1);
		}
		return pos;
	}
};

int main()
{
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);

	int T;
	cin >> T;
	while(T--)
	{
		string a, b;
		cin >> a >> b;
		Kmp kmp;
		kmp.setvalue(a, b);
		cout << kmp.find_substring().size() << endl;
	}
	return 0;
}