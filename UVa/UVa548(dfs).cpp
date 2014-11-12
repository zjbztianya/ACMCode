
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
#include <sstream>
using namespace std;
#define  INF 0x3f3f3f3f
#define  maxn 11111
typedef long long LL;
int sa[maxn],sb[maxn],ch[maxn][2];
int ans, val;
int dfs1(int l, int r,int ll,int rr)
{
	if (l > r) return 0;
	int rt = sb[rr];
	for (int i = l; i <= r; i++)
	{
		if (sb[rr] == sa[i])
		{
			int len = i - l;	
				ch[rt][0]=dfs1(l, i - 1, ll, ll + len - 1);
				ch[rt][1]=dfs1(i + 1, r, ll + len, rr - 1);
			break;
		}
	}
	return rt;
}
void dfs2(int rt,int sum)
{
	sum += rt;
	if (ch[rt][0] == 0 && ch[rt][1] == 0)
	{
		if (sum < ans || (sum == ans&&rt < val))
		{
			ans = sum; val =rt;
		}
		return;
	}
	if (ch[rt][0])  dfs2(ch[rt][0], sum);
	if (ch[rt][1])  dfs2(ch[rt][1], sum);
}
int in(string line,int *a)
{
	int cnt = 0;
	stringstream ss(line);
	int x;
	while (ss >> x) a[cnt++] = x;
	return cnt;
}
int main()
{
	//freopen("in.txt", "r", stdin);
	string line;
	while (getline(cin,line))
	{
		int n = in(line,sa);
		getline(cin, line);
		in(line, sb);
		dfs1(0, n - 1,0,n-1);
		ans = val=INF;
		dfs2(sb[n-1], 0);
		cout << val << endl;
	}
	return 0;
}

