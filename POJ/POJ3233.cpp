// POJ3233.cpp : 定义控制台应用程序的入口点。
//

#include "stdafx.h"
#include <cstdio>
#include <iostream>
#include <cstring>
#include <cmath>
#include <algorithm>
using namespace std;
#define  MAXN 70
typedef long long Matrix[MAXN][MAXN];
typedef long long LL;
int n,m;
void matrix_mul(Matrix &A,Matrix &B,Matrix res)
{
	Matrix C;
	memset(C,0,sizeof(C));
	for(int i=0;i<2*n;i++)
		for(int j=0;j<2*n;j++)
			for(int k=0;k<2*n;k++) 
				C[i][j]=(C[i][j]+A[i][k]*B[k][j])%m;
	memcpy(res,C,sizeof(C));
}
void matrix_pow(Matrix &A,int k,Matrix res)
{
	Matrix a,r;
	memset(r,0,sizeof(r));
	memcpy(a,A,sizeof(A));
	for(int i=0;i<2*n;i++) r[i][i]=1;
	while(k)
	{
		if(k&1) matrix_mul(r,a,r);
		k>>=1;
		matrix_mul(a,a,a);
	}
	memcpy(res,r,sizeof(r));
}
int main()
{
	int k;
	while(scanf("%d%d%d",&n,&k,&m)!=EOF)
	{
		Matrix A,B;
		memset(A,0,sizeof(A));
		memset(B,0,sizeof(B));
		for(int i=0;i<n;i++)
			for(int j=0;j<n;j++) scanf("%d",&A[i][j]);
		for(int i=0;i<n;i++)
			for(int j=0;j<n;j++) A[i+n][j]=A[i][j];
		for(int i=n;i<2*n;i++) A[i][i]=1;
		for(int i=0;i<n;i++) B[i][i]=1;
		matrix_pow(A,k,A);
		matrix_mul(A,B,B);
		for(int i=0;i<n;i++)
		{
			for(int j=0;j<n;j++) printf("%d ",B[i+n][j]);
			printf("\n");
		}
	}
	return 0;
}

