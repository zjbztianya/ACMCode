// POJ2541.cpp : 定义控制台应用程序的入口点。
//

#include "stdafx.h"
/*
ID:spcjv51
PROG:clocks
LANG:C
*/
#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#define MAXSTEPS 30
const int a[9][9]=
{
	{1,1,0,1,1,0,0,0,0},
	{1,1,1,0,0,0,0,0,0},
	{0,1,1,0,1,1,0,0,0},
	{1,0,0,1,0,0,1,0,0},
	{0,1,0,1,1,1,0,1,0},
	{0,0,1,0,0,1,0,0,1},
	{0,0,0,1,1,0,1,1,0},
	{0,0,0,0,0,0,1,1,1},
	{0,0,0,0,1,1,0,1,1},
};
int now[9],minstep;
int path[MAXSTEPS],time[9];
void init()
{
	int i,k;
	for(i=0; i<9; i++)
	{
		scanf("%d",&k);;
		now[i]=k;
	}
	memset(path,0,sizeof(path));
	memset(time,0,sizeof(time));
}
int ok()
{
	int i;
	for(i=0; i<9; i++)
		if(now[i]%4!=0)return 0;
	return 1;
}
void output()
{
	int i;
	for(i=0;i<minstep-1;i++)
		printf("%d ",path[i]+1);
	printf("%d\n",path[minstep-1]+1);

}


void change(int i)
{
	int j;
	for(j=0; j<9; j++)
		now[j]+=a[i][j];
}
void regain(int i)
{
	int j;
	for(j=0; j<9; j++)
		now[j]-=a[i][j];

}
void search(int step)
{
	int i,j;
	if(step>=MAXSTEPS) return;
	if(ok())
	{
		minstep=step;
		output();
		return;
	}
	if (step==0) j=0;
	else if(time[path[step-1]]<3) j=path[step-1];
	else
		j=path[step-1]+1;
	for(i=j; i<9; i++)
	{
		change(i);
		time[i]++;
		path[step]=i;
		search(step+1);
		regain(i);
		time[i]--;

	}
}

int main(void)
{
	init();
	search(0);
	return 0;
}
