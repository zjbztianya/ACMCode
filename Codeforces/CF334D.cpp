// CF334D.cpp : �������̨Ӧ�ó������ڵ㡣
//

#include "stdafx.h"
#include <iostream>
#include <cstdio>
#include <stack>
#include <string>
using namespace std;
stack<char>q;
int main()
{
	string s;
	cin>>s;
	for(int i=0;i<s.length();i++)
	{
		  if(!q.empty()&&q.top()==s[i])
			  q.pop();
		  else
			  q.push(s[i]);
	}
	if(!q.empty()) printf("No\n");
	else
		printf("Yes\n");
	return 0;
}

