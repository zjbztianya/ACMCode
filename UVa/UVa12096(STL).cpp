
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
#define  maxn 222222
typedef long long LL;
map< set<int>, int >id;
vector< set<int> >vec;
stack<int>st;
int idx(set<int> x)
{
	if (id.count(x)) return id[x];
	vec.push_back(x);
	id[x] = vec.size() - 1;
	return id[x];
}
int main()
{
	freopen("in.txt", "r", stdin);
	int T;
	scanf("%d", &T);
	while (T--)
	{
		int n;
		scanf("%d", &n);
		vec.clear();
		id.clear();
		while (!st.empty()) st.pop();
		for (int i = 0; i < n; i++)
		{
			char op[15];
			scanf("%s", op);
			if (op[0] == 'P')
			{
				st.push(idx(set<int>()));
			}
			else if (op[0] == 'D')
			{
				st.push(st.top());
			}
			else
			{
				set<int>x1 = vec[st.top()]; st.pop();
				set<int>x2 = vec[st.top()]; st.pop();
				set<int> x;
				if (op[0] == 'U')  set_union(x1.begin(), x1.end(), x2.begin(), x2.end(), inserter(x, x.begin()));
				if (op[0] == 'I')  set_intersection(x1.begin(), x1.end(), x2.begin(), x2.end(), inserter(x, x.begin()));
				if (op[0] == 'A') { x = x2; x.insert(idx(x1)); }
				st.push(idx(x));
			}
			printf("%d\n", vec[st.top()].size());
		}
		puts("***");
	}
	return 0;
}
