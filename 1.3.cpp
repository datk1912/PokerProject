#include <iostream>
#include <string>
#include <fstream>
#include <sstream>

using namespace std;

int count1(int n, int m)
{
	static int s = 1, dem = 0;
	if (m == n) return 1 + dem;

	for (int i = m; i <= n; i++)
		if (s*i < n)
		{
			s *= i;
			count1(n, i);
			if (s > 1 )s /= i;
		}
		else if (s*i == n)
		{
			s = 1;
			dem++;
			break;
		}
		else if (s*i > n) break;
	
}

int main()
{
	int n, m;
	cout << "n: "; cin >> n;
	cout << "m: "; cin >> m;
	cout << count1(n, m);
}
