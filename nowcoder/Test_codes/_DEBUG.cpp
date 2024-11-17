#include <iostream>
using namespace std;
long sum(int n)
{
	if (n == 1 || n == 2)
	{
		return 1;
	}
	else
	{
		return sum(n - 1) + sum(n - 2);
	}
}

int main()
{
	long a;
	cin >> a;
	long arr[a];
	long zo = 0;
	for (long i = 0; i < a; i++)
	{
		cin >> arr[i];
		long k = arr[i];
		zo += sum(k);
	}

	cout << zo << endl;
	system("pause");
}