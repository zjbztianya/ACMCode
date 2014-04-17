#include <iostream>
#include <algorithm>
#include <cstdio>
#include <cstring>
#include <cmath>
#include <map>
using namespace std;
#define maxn 305
typedef int Matrix[maxn][maxn];
map<string,int>ms;
int gcd(int a,int b)
{
    return b==0?a:gcd(b,a%b);
}
int lcm(int a,int b)
{
    return  a/gcd(a,b)*b;
}
int gauss(Matrix A,int n,int m)
{
    int row,col;
    for(row=0,col=0; row<n&&col<m; row++,col++)
    {
        int r=row;
        for(int i=row+1; i<n; i++)
            if(abs(A[i][col])>abs(A[r][col])) r=i;
        if(r!=row) for(int j=0; j<=m; j++) swap(A[r][j],A[row][j]);
        if(A[row][col]==0)
        {
            row--;
            continue;
        }
        for(int k=row+1; k<n; k++)
            if(A[k][col])
            {
                int LCM=lcm(abs(A[k][col]),abs(A[row][col]));
                int ra=LCM/abs(A[k][col]);
                int rb=LCM/abs(A[row][col]);
                if (A[k][col]*A[row][col]<0) rb=-rb;
                for(int j=col; j<=m; j++)
                {
                    A[k][j]=A[k][j]*ra-A[row][j]*rb;
                    A[k][j]=(A[k][j]%7+7)%7;
                }
            }
    }
    for(int i=row; i<n; i++)
        if(A[i][m]) return -1;
    if(row<m) return 0;
    for(int i=m-1; i>=0; i--)
    {
        for(int j=i+1; j<m; j++)
        {
            A[i][m]-=A[j][m]*A[i][j];
            A[i][m]=(A[i][m]%7+7)%7;
        }
        for(int j=3; j<=9; j++)
            if((j*A[i][i])%7==A[i][m])
            {
                A[i][m]=j;
                break;
            }
    }
    return 1;
}
Matrix A;
int main()
{
    int n,m;
    ms["MON"]=1,ms["TUE"]=2,ms["WED"]=3,ms["THU"]=4;
    ms["FRI"]=5,ms["SAT"]=6,ms["SUN"]=7;
    while(scanf("%d%d",&n,&m)!=EOF&&(n+m))
    {
        int cnt;
        char s1[10],s2[10];
        memset(A,0,sizeof(A));
        for(int i=0; i<m; i++)
        {
            scanf("%d%s%s",&cnt,&s1,&s2);
            int a=ms[s1],b=ms[s2];
            A[i][n]=((b-a+1+7)%7+7)%7;
            for(int j=0; j<cnt; j++)
            {
                int num;
                scanf("%d",&num);
                A[i][num-1]++;
                A[i][num-1]%=7;
            }
        }
        int ans=gauss(A,m,n);
        if(ans==-1) printf("Inconsistent data.\n");
        else if(ans==0) printf("Multiple solutions.\n");
        else
        {
            for(int i=0; i<n; i++) if(A[i][n]<3) A[i][n]+=7;
            printf("%d",A[0][n]);
            for(int i=1; i<n; i++) printf(" %d",A[i][n]);
            printf("\n");
        }
    }
    return 0;
}
