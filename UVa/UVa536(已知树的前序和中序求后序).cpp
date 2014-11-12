
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
#define  maxn 1111
typedef long long LL;
char sa[30],sb[maxn];
void dfs(int l, int r,int ll,int rr)
{
	if (l > r) return;
	for (int i = l; i <= r; i++)
	{
		if (sa[ll] == sb[i])
		{
			int len = i - l;
			dfs(l, i - 1,ll+1,ll+len);
			dfs(i + 1, r,ll+len+1,rr);
			printf("%c", sa[ll]);
			break;
		}
	}
}
int main()
{
	while (scanf("%s%s",sa,sb)!=EOF)
	{
		int n = strlen(sa);
		dfs(0, n - 1,0,n-1);
		puts("");
	}
	return 0;
}

