
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
int a[maxn], b[maxn];
vector<int>vec[maxn];
void BFS(int n)
{
	queue< pair<int, int> >que;
	que.push(make_pair(0, n - 1));
	int cnt = 1;
	int rt;
	while (!que.empty())
	{
		pair<int,int> h = que.front();
		que.pop();
		rt = h.first;
		if (h.second-h.first<=0) continue;
		int pre = rt + 1;
		for (int i = pre; i <= h.second; i++)
		{
			if (b[i] == a[cnt])
			{
				que.push(make_pair(pre, i - 1));
				pre = i;
				vec[b[rt]].push_back(a[cnt]);
				cnt++;
			}
		}
		if (pre < h.second) que.push(make_pair(pre, h.second));
	}
}
int main()
{
	int n;
	while (scanf("%d",&n)!=EOF)
	{
		for (int i = 0; i < n; i++) scanf("%d", &a[i]);
		for (int i = 0; i < n; i++) scanf("%d", &b[i]);
		for (int i = 0; i < maxn; i++) vec[i].clear();
		BFS(n);
		for (int i = 1; i <= n; i++)
		{
			printf("%d:",i);
			for (int j = 0; j < vec[i].size(); j++)
				printf(" %d", vec[i][j]);
			printf("\n");
		}
	}
	return 0;
}

