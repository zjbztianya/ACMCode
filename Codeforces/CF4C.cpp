// Codeforces4C.cpp : 定义控制台应用程序的入口点。
//

#include "stdafx.h"
#include <iostream>
#include <algorithm>
#include <map>
#include <string>
using namespace std;
map<string,int>word_count;
int main()
{
	
	int n;
	cin>>n;
	for(int i=0;i<n;i++)
	{
		string name;
		cin>>name;
		word_count[name]++;
		if(word_count[name]==1) cout<<"OK"<<"\n";
		else
			cout<<name<<word_count[name]-1<<"\n";
	}

	return 0;
}

