// HDU4546.cpp : 定义控制台应用程序的入口点。
//

#include "stdafx.h"

#include <iostream>
#include <cstdio>
#include <cstring>
#include <algorithm>
using namespace std;
#define  MAXN 2
typedef long long Matrix[MAXN][MAXN];
typedef long long LL;
LL m;
void matrix_mul(Matrix &A,Matrix &B,Matrix res)
{
	Matrix C;
	memset(C,0,sizeof(C));
	for(int i=0;i<2;i++)
		for(int j=0;j<2;j++)
			for(int k=0;k<2;k++) 
				C[i][j]=(C[i][j]+A[i][k]*B[k][j])%m;
	memcpy(res,C,sizeof(C));
}
void matrix_pow(Matrix &A,LL n,Matrix res)
{
	Matrix a,r;
	memset(r,0,sizeof(r));
	memcpy(a,A,sizeof(A));
	for(int i=0;i<2;i++) r[i][i]=1;
	while(n)
	{
		if(n&1) matrix_mul(r,a,r);
		n>>=1;
		matrix_mul(a,a,a);
	}
	memcpy(res,r,sizeof(r));
}
int main()
{
	LL a,b,n;
	while(scanf("%I64d%I64d%I64d%I64d",&a,&b,&n,&m)!=EOF)
	{
		if(n==1) printf("%I64d\n",(2*a)%m);
		else 
			if(n==2) printf("%I64d\n",(2*a*a+2*b)%m);
			else
			{

				Matrix A,B;
				A[0][0]=(2*a)%m,A[0][1]=((b-a*a)%m+m)%m;
				A[1][0]=1,A[1][1]=0;
				matrix_pow(A,n-2,A);
				B[0][0]=(2*a*a+2*b)%m,B[0][1]=0;
				B[1][0]=(2*a)%m,B[1][1]=0;
				matrix_mul(A,B,B);
				printf("%I64d\n",B[0][0]);
			}
	}
	return 0;
}


