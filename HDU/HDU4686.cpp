// HDU4686.cpp : 定义控制台应用程序的入口点。
//

#include "stdafx.h"
#include <iostream>
#include <algorithm>
#include <cstring>
#include <cstdio>
using namespace std;
#define  MAXN 8
#define MOD 1000000007
typedef long long LL;
struct Matrix
{
	LL mat[MAXN][MAXN];
	int r;
	void clear(int n)
	{
		memset(mat,0,sizeof(mat));
		r=n;
	}
};
Matrix matrix_mul(Matrix a,Matrix b)
{
	Matrix ans;
	ans.clear(a.r);
	for(int i=0;i<a.r;i++)
		for(int j=0;j<a.r;j++)
			for(int k=0;k<a.r;k++)
				if(a.mat[i][k]>0&&b.mat[k][j]>0)
					ans.mat[i][j]=(ans.mat[i][j]+a.mat[i][k]*b.mat[k][j])%MOD;
	return ans;
}
Matrix maxtrix_pow(Matrix a,LL n,int r)
{
	Matrix ans;
	ans.clear(r);
	for(int i=0;i<r;i++) ans.mat[i][i]=1;
	while(n)
	{
		if(n&1) ans=matrix_mul(ans,a);
		n>>=1;
		a=matrix_mul(a,a);
	}
	return ans;
}
int main()
{
	LL a0,b0,ax,bx,ay,by,n;
	while(scanf("%I64d",&n)!=EOF)
	{
		scanf("%I64d%I64d%I64d%I64d%I64d%I64d",&a0,&ax,&ay,&b0,&bx,&by);
		a0%=MOD,ax%=MOD,ay%=MOD,b0%=MOD,bx%=MOD,by%=MOD;
		if(n==0) printf("0\n");
		else
			if(n==1) printf("%I64d\n",a0*b0%MOD);
			else
			{
				Matrix A,B;
				A.clear(8);
				B.clear(8);
				A.mat[0][0]=1,A.mat[0][7]=1;
				A.mat[1][1]=ax,A.mat[1][4]=1;
				A.mat[2][2]=bx,A.mat[2][6]=1;
				A.mat[3][3]=1,A.mat[4][4]=1;
				A.mat[5][5]=1,A.mat[6][6]=1;
				A.mat[7][1]=ax*by%MOD,A.mat[7][2]=bx*ay%MOD;
				A.mat[7][6]=ay,A.mat[7][7]=ax*bx%MOD;
				A=maxtrix_pow(A,n-1,A.r);
				B.mat[0][0]=a0*b0%MOD,B.mat[1][0]=(a0*ax%MOD+ay)%MOD;
				B.mat[2][0]=(b0*bx%MOD+by)%MOD,B.mat[3][0]=ax;
				B.mat[4][0]=ay,B.mat[5][0]=bx;
				B.mat[6][0]=by,B.mat[7][0]=B.mat[1][0]*B.mat[2][0]%MOD;
				B=matrix_mul(A,B);
				printf("%I64d\n",B.mat[0][0]);
			}
	}
	return 0;
}



