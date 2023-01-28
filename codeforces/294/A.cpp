# include <iostream>
using namespace std;

int main()
{
	int n;
	cin >> n;
	int* arr = new int[n +2 ];
	for (int i = 1; i <= n; i++)
	{
		int xz;
		cin >> xz;
		arr[i] = xz;
	}
	int m;
	cin >> m;
	for (int i = 0; i < m; i++)
	{
		int x, y;
		cin >> x >> y;
		if (x > 1 && x < n)
		{
			if (y > 1 && y < arr[x])
			{
				arr[x + 1] = arr[x + 1] + (arr[x] - y);
				arr[x - 1] = arr[x - 1] + (y - 1);
				arr[x] = 0;
			}
			else if (y == 1)
			{
				arr[x + 1] = arr[x + 1] + (arr[x] - y);
				arr[x] = 0;
			}
			else if (y == arr[x])
			{
				arr[x - 1] = arr[x - 1] + (arr[x] - 1);
				arr[x] = 0;
			}
		}
		else if (x == 1)
		{
			if (y > 1 && y < arr[x])
			{
				arr[x + 1] = arr[x + 1] + (arr[x] - y);
				arr[x] = 0;
			}
			else if (y == 1)
			{
				arr[x + 1] = arr[x + 1] + (arr[x] - y);
				arr[x] = 0;
			}
			else if (y == arr[x])
			{
				arr[x] = 0;
			}
		}
		else
		{
			if (y > 1 && y < arr[x])
			{
				arr[x - 1] = arr[x - 1] + (y - 1);
				arr[x] = 0;
			}
			else if (y == 1)
			{
				arr[x] = 0;
			}
			else if (y == arr[x])
			{
				arr[x - 1] = arr[x - 1] + (arr[x] - 1);
				arr[x] = 0;
			}
		}
	}
	for (int i = 1; i <= n; i++)
	{
		cout << arr[i] << endl;
	}
}