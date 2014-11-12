#include <iostream>
#include <algorithm>
#include <cstdio>
#include <cstring>
#include <utility>
#include <vector>
#include <queue>
using namespace std;
#define maxn 1111
typedef long long LL;
int a[maxn][10],b[10][maxn],c[10][10],ans[10][10];
int nn[maxn][10],mm[maxn][maxn];
void matrix_mul_a_b(int n,int m)
{
    memset(c,0,sizeof(c));
    for(int i=0; i<m; i++)
        for(int j=0; j<m; j++)
            for(int k=0; k<n; k++)
                c[i][j]=(c[i][j]+b[i][k]*a[k][j])%6;
}
void matrix_mul(int n,int m)
{
    int mat[10][10];
    memset(mat,0,sizeof(mat));
    for(int i=0; i<n; i++)
        for(int j=0; j<n; j++)
            for(int k=0; k<m; k++)
                mat[i][j]=(mat[i][j]+ans[i][k]*c[k][j])%6;
    memcpy(ans,mat,sizeof(mat));
}
void matrix_fuck(int n,int m)
{
    int mat[10][10];
    memset(mat,0,sizeof(mat));
    for(int i=0; i<n; i++)
        for(int j=0; j<n; j++)
            for(int k=0; k<m; k++)
                mat[i][j]=(mat[i][j]+c[i][k]*c[k][j])%6;
    memcpy(c,mat,sizeof(mat));
}
void matrix_b(int n,int m)
{
    memset(mm,0,sizeof(mm));
    for(int i=0; i<n; i++)
        for(int j=0; j<n; j++)
            for(int k=0; k<m; k++)
                mm[i][j]=(mm[i][j]+nn[i][k]*b[k][j])%6;
}
void matrix_a(int n,int m)
{
    memset(nn,0,sizeof(nn));
    for(int i=0; i<n; i++)
        for(int j=0; j<m; j++)
            for(int k=0; k<m; k++)
                nn[i][j]=(nn[i][j]+a[i][k]*ans[k][j])%6;
}
void matrix_pow(int n)
{
    memset(ans,0,sizeof(ans));
    for(int i=0; i<10; i++) ans[i][i]=1;
    while(n)
    {
        if(n&1) matrix_mul(6,6);
        matrix_fuck(6,6);
        n>>=1;
    }
}
int main()
{
    int n,m;
    while(scanf("%d%d",&n,&m)!=EOF)
    {
        if(n+m==0) break;
        for(int i=0; i<n; i++)
            for(int j=0; j<m; j++) scanf("%d",&a[i][j]);
        for(int i=0; i<m; i++)
            for(int j=0; j<n; j++) scanf("%d",&b[i][j]);
        matrix_mul_a_b(n,m);
        matrix_pow(n*n-1);
        matrix_a(n,m);
        matrix_b(n,m);
        LL sum=0;
        for(int i=0; i<n; i++)
            for(int j=0; j<n; j++) sum+=mm[i][j];
        printf("%lld\n",sum);
    }
    return 0;
}


