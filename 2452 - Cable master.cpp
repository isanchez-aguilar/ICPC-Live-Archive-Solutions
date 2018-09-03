/*
*	User: Isanchez_Aguilar
*	Problem: ICPC Live Archive 2452 - Cable master
*/
#include <bits/stdc++.h>

using namespace std;

int main(void)
{
	ios_base::sync_with_stdio(0);
	cin.tie(0);

	int testCases;
	double length[10000];

	cin >> testCases;

	while (testCases--)
	{
		int n;
		int requiredCable;
		
		cin >> n >> requiredCable;
		
		for (int i = 0; i < n; ++i)
		{
			cin >> length[i];	
			length[i] = floor(length[i] * 100.0);
		}

		double l = 1.0;
		double r = 1e7 + 1;
		double maxLength = -1.0;

		while (l < r)
		{
			int total = 0;
			int m = (l + r) / 2.0;
			
			for (int i = 0; i < n; ++i)
				total += (int)floor(length[i] / m);

			if (total < requiredCable)
				r = m;
			else
			{
				l = m + 1;
				maxLength = m;
			}

		}
		

		if (maxLength == -1.0)
			cout << "0.00\n";
		else
			cout << fixed << setprecision(2) << maxLength / 100.0 << "\n";

		if (testCases)
			cout << "\n";
	}

	return 0;
}