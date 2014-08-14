#include <iostream>
#include <algorithm>
#include <cstdio>
#include <cstring>
#include <utility>
#include <vector>
#include <queue>
#include <map>
using namespace std;
int main()
{
	int T,kase=0;
	scanf("%d", &T);
	while (T--)
	{
		int n,m,ans=0;
		scanf("%d%d", &n,&m);
		for (int i = 0; i < n; i++)
		{
			for (int j = 0; j < m; j++)
			{
				int x;
				scanf("%d", &x);
				int step = n - i - 1 + m - j - 1;
				if (step & 1) ans ^= x;
			}
		}
		printf("Case %d: ", ++kase);
	
			if (ans) printf("win\n");
			else printf("lose\n");
	}
	return 0;
}

