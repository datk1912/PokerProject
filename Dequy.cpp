#include<iostream>
#include<math.h>
using namespace std;

int UCLN(int a, int b)
{
	if (b == 0)
		return a;
	if (a % b == 0)
		return b;
	else
		return UCLN(b, a % b);
}

int BCNN(int a, int b)
{
	if (b % a == 0) return b;
	return a * b / UCLN(a, b);
}

int tong(int n)
{
	if (n == 0)
		return 0;
	return n + tong(n - 1);
}

int giaithua(int n)
{
	if (n == 1)
		return 1;
	return n * giaithua(n - 1);
}

int mu(int x, int n)
{
	if (n == 0)
		return 1;
	return x * mu(x, n - 1);
}

int demsotunhien(int n)
{
	if (n / 10 == 0)
		return 1;
	return 1 + demsotunhien(n / 10);
}

int demsotunhienchan(int n)
{
	if (n == 0)
		return 0;
	else
	{
		if ((n % 10) % 2 == 0)
			return 1 + demsotunhienchan(n / 10);
		else
			return 0 + demsotunhienchan(n / 10);
	}
}

int demsotunhienle(int n)
{
	if (n == 0)
		return 0;
	else
	{
		if ((n % 10) % 2 == 1)
			return 1 + demsotunhienle(n / 10);
		else
			return 0 + demsotunhienle(n / 10);
	}
}

int UC(int n, int m)
{
	if (m == 0)
		return n;
	if (n % m == 0)
		return m;
	else
		return UC(m, n % m);
}

int sodoi(int n, int m)
{
	if (n == 0)
		return m;
	else
	{
		m = m * 10 + n % 10;
		return sodoi(n / 10, m);
	}
}

int nhiphan(int n, int m, int k)
{
	if (n == 0)
		return m;
	else
	{
		m = (n % 2) * pow(10, k) + m;
		return nhiphan(n / 2, m, k + 1);
	}
}

int main()
{//=====================//
	/*int a, b;
	cout << "Nhap A: ";
	cin >> a;
	cout << "Nhap B: ";
	cin >> b;
	int ucln, bcnn;
	ucln = UCLN(a, b);
	bcnn = BCNN(a, b);
	cout << "Uoc chung lon nhat: " << ucln << endl;
	cout << "Boi chung nho nhat: " << bcnn << endl;*/

	/*int n, m, s, dem = 1, a = 0;
	cin >> n >> m;
	if (n % m == 0)
	{
		a = 1 - (n / m);
	}
	s = count1(n, m);
	if (s == 1)
		dem++;
	for (int i = m;i < n - m; i++)
		for (int j = m; j <= n - i; j++)
		{
			s = count1(n - i, j);
			if (s == 1)
			{
				dem++;
			}
		}
	cout << "\n" << dem + a;*/
	//cout << count(5, 2);
	/*int n, t = 0, m;
	cin >> n;
	m = n;
	while (m % 10 != 0)
	{
		t++;
		m /= 10;
	}
	int x = demsotunhienle(n);
	if (x == t)
		cout << "True";
	else
		cout << "false";*/
	int n, m;
	cin >> n;
	m = 0;
	int x = nhiphan(n, 0, 0);
	cout << x;
	return 0;
}
