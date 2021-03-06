#include <cstdio>
#include <iostream>
#include <algorithm>
#include <cstring>
#include <cmath>
#include <vector>
using namespace std;
const int maxn=6;
typedef long long LL;
typedef long long Matrix[maxn][maxn];
LL M[maxn][maxn]=
{
    {2,1,1,0,1,0},
    {1,2,0,1,1,0},
    {1,1,1,0,1,0},
    {1,1,0,1,1,0},
    {0,0,0,0,1,1},
    {0,0,0,0,0,1},
};
LL n;
void matrix_mul(Matrix A, Matrix B, Matrix res)
{
    Matrix C;
    memset(C, 0, sizeof(C));
    for(int i = 0; i < 6; i++)
        for(int j = 0; j < 6; j++)
            for(int k = 0; k < 6; k++) C[i][j] = (C[i][j] + A[i][k] * B[k][j])%n;
    memcpy(res, C, sizeof(C));
}
void matrix_pow(Matrix A,Matrix res,LL n)
{
    Matrix a, r;
    memcpy(a, A, sizeof(a));
    memset(r, 0, sizeof(r));
    for(int i = 0; i < 6; i++) r[i][i] = 1;
    while(n)
    {
        if(n&1) matrix_mul(r, a, r);
        n >>= 1;
        matrix_mul(a, a, a);
    }
    memcpy(res, r, sizeof(r));
}
int main()
{
    LL sx,sy,dx,dy,t;
    Matrix A,B;
    cin>>n>>sx>>sy>>dx>>dy>>t;
    matrix_pow(M,A,t);
    memset(B,0,sizeof(B));
    B[0][0]=sx,B[1][0]=sy,B[2][0]=dx;
    B[3][0]=dy,B[4][0]=0,B[5][0]=1;
    matrix_mul(A,B,B);
    LL x,y;
    x=B[0][0],y=B[1][0];
    if(x<=0) x+=n;
    if(y<=0) y+=n;
    cout<<x<<" "<<y<<endl;
    return 0;
}
