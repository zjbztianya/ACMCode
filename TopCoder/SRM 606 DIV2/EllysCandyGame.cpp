#define INF 0x3f3f3f3f
int a[15],n;
int dfs(int cnt1,int cnt2,int m,int d)
{
    if(m==d)return cnt1-cnt2;
    int ans=m%2==0?-INF:INF;
    for(int i=1; i<=n; i++)
        if(a[i])
        {
            int tmp1=a[i-1],tmp2=a[i],tmp3=a[i+1];
            a[i-1]*=2,a[i]=0,a[i+1]*=2;
            if(m%2==0) ans=max(ans,dfs(cnt1+tmp2,cnt2,m+1,d));
            else ans=min(ans,dfs(cnt1,cnt2+tmp2,m+1,d));
            a[i-1]=tmp1,a[i]=tmp2,a[i+1]=tmp3;
        }
    return ans;
}
class EllysCandyGame
{
public:
    string getWinner(vector <int> sweets)
    {
        int cnt=0;
        n=sweets.size();
        for(int i=0; i<sweets.size(); i++)
        {
            a[i+1]=sweets[i];
            if(sweets[i]) cnt++;
        }
        int ans=dfs(0,0,0,cnt);
        //cout<<ans<<endl;
        if(ans==0) return "Draw";
        if(ans>0) return "Elly";
        if(ans<0) return "Kris";
    }
};



// Powered by FileEdit
// Powered by TZTester 1.01 [25-Feb-2003]
// Powered by CodeProcessor
