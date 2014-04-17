bool check(string s,int x,int y)
{
    int r=0,g=0,b=0,len=y-x+1;
    for(int i=x; i<=y; i++)
    {
        if(s[i]=='R') r++;
        if(s[i]=='G') g++;
        if(s[i]=='B') b++;
    }
    if(r==len||g==len||b==len) return true;
    return false;
}
class LittleElephantAndBallsAgain
{
public:
    int getNumber(string S)
    {
        bool flag=false;
        int ll,rr,ans=0;
        ll=0,rr=S.size()-1;
        while(!flag)
        {
            if(check(S,ll,rr))
            {
                ans=rr-ll+1;
                flag=true;
                break;
            }
            int l=ll+1,r=rr-1;
            while(l<=rr&&S[l-1]==S[l]) l++;
            while(r>=ll&&S[r]==S[r+1]) r--;
            if(l-ll+1<rr-r+1)
                ll=l;
            else
                rr=r;
        }
        return S.size()-ans;
    }
};
