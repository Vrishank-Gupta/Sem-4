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

int main()
{
	FIO
	bool a[100] = {0};
	cout << "Enter Frame Size:- ";
	ll n;
	cin >> n;
	int size = n;

	cout << "\nEnter Bits(0s and 1s):-\n";

	int count = 0;
	loop(i,size,0)
	{
		cin >> a[i];
		if(a[i] == 1)
		{
			count++;

			if(count == 5)
			{
				if(i>=5 && a[i-5] == 0)
				{
					a[i+1] = 0;
					i++;
					size++;
				}
				count =0;
			}

			
		}
		else
			count =0;
	}

			cout << endl;

			cout << "After Bit Stuffing:- ";
		loop(i,size,0)
			cout << a[i] << " ";
}