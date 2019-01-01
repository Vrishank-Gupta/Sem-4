#include <iostream>
#include <algorithm>
#include <map>
#include <cstdio>
#include <stack>
#include <cstdlib>
#include <vector>
#include <cmath>
#include <unistd.h>
#include <cstring>
#include <utility>
#include <iterator>

#define loop(x,n,k) for(int x = k; x < n; ++x)
#define revLoop(q,w) for (int q = w-1;q>=0 ;q--)
#define ll long long int
#define minMod 10e7+3
#define strInp(a,n) cin.getline(a,n);
#define mp(a,b) make_pair(a,b)
#define init(a,n) memset(a,n,sizeof(a));
#define pb(i) push_back(i);
#define FIO ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL);
#define tc int t; cin >> t; while(t--)

using namespace std;
string charstuff(string s, char start, char end) 
{
	string res;
	res += start;

	for (int i = 0; i < s.length(); i++) 
	{
		if (s[i] == start) 
		{
			res += s[i];
			res += s[i];
		}
		
		else if (s[i] == end) 
		{
			res += s[i];
			res += s[i];
		} 

		else 
		{
			res += s[i];
		}
	}

	res += end;
	return res;
}
string decodecharstuff(string s, char start, char end) 
{
	string data;
	for (int i = 1; i < s.length() - 1; i++) 
	{
		if (s[i] == start && i != s.length() - 2) 
		{
			if (s[i + 1] == start) 
			{
				data += s[i];
				i++;
			}

		}
		else if (s[i] == end && i != s.length() - 2) 
		{
			if (s[i + 1] == end) 
			{
				data += s[i]; i++;
			}
		}
		
		else 
		{
			data += s[i];
		}
	}
	return data;
}

int main()
{
	string str;
	cout << "Enter Data: ";
	cin >> str;
	char start;
	cout << "Enter Starting delimiter: "; cin >> start;
	char end;
	cout << "Enter Ending delimiter: ";
	cin >> end;
	string result = charstuff(str, start, end);
	cout << "Stuffed Data: " << result << endl;
	cout << "De-Stuffed Data: " << decodecharstuff(result, start, end) << endl;
}

