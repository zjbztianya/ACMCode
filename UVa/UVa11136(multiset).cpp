
#include "stdafx.h"
// GO.cpp : 定义控制台应用程序的入口点。

#include "stdafx.h"
// GO.cpp : 定义控制台应用程序的入口点。
#include <iostream>
#include <algorithm>
#include <cstdio>
#include <cstring>
#include <utility>
#include <vector>
#include <queue>
#include <map>
#include <deque>
#include <cmath>
#include <stack>
#include <string>
#include <set>
using namespace std;
#define  INF 0x3f3f3f3f
#define  maxn 111111
typedef long long LL;
multiset<int>num;
int main()
{
	int n;
	while (scanf("%d", &n) != EOF)
	{
		if (n==0) break;
		LL ans = 0;
		num.clear();
		for (int i = 0; i < n; i++)
		{
			int k;
			scanf("%d", &k);
			for (int j = 0; j < k; j++)
			{
				int x;
				scanf("%d", &x);
				num.insert(x);
			}
			ans += *num.rbegin() - *num.begin();
			num.erase(num.find(*num.begin()));
			num.erase(num.find(*num.rbegin()));
		}
		printf("%I64d\n", ans);
	}
	return 0;
}

