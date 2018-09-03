/*
*	User: Isanchez_Aguilar
*	Problem: ICPC Live Archive 6789 - Superstitious Socks
*/
#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

int numberSocks;
ll socks[100000];

inline ll getPairsNumberLowerThan(ll difference)
{
	int i = 0;
	ll totalPairs = 0;
	int currentSock = 1;
	ll currentPairs = 0;

	while (i < numberSocks)
	{
		if (currentSock < numberSocks and socks[currentSock] - socks[i] <= difference)
		{
			++currentPairs;
			++currentSock;
		}
		else
		{
			++i;
			totalPairs += currentPairs--;
		}
	}

	return totalPairs;
}

int main(void)
{
	ios_base::sync_with_stdio(0);
	cin.tie(0);

	int pairNumber;

	while (cin >> numberSocks >> pairNumber and (numberSocks or pairNumber))
	{
		for (int i = 0; i < numberSocks; ++i)
			cin >> socks[i];

		sort(socks, socks + numberSocks);

		ll l = 0;
		ll r = 1e9;

		while (l < r)
		{
			ll m = (l + r) >> 1LL;
			ll pairsNumber = getPairsNumberLowerThan(m);
			
			if (pairsNumber < pairNumber)
				l = m + 1;
			else
				r = m;
		}

		int i = 0;
		int j = 1;
		ll positionDiff = pairNumber - getPairsNumberLowerThan(l - 1);
		
		while (i < numberSocks and positionDiff != 0)
		{
			if (j < numberSocks and socks[j] - socks[i] <= l)
			{
				if (socks[j] - socks[i] == l)
					--positionDiff;
				
				if (positionDiff == 0)
					break;
			
				++j;
			}
			else
				++i;
		}

		cout << socks[i] << " " << socks[j] << "\n";
	}

	return 0;
}