map<int,int>a,b;
int prime[MAXN],cnt=0;
bool check[MAXN];
void go(int x)
{
    if(x==1)
    {
        a[1]++;
        return;
    }
    for(int i=0; i<cnt&&x>1; i++)
        if(x%prime[i]==0)
        {
            while(x%prime[i]==0)
            {
                a[prime[i]]++;
                x/=prime[i];
            }
        }
    if(x>1) a[x]++;
}
bool checks(int B,int x,int D)
{
    if(x==1) return true;
    for(int i=0; i<cnt&&x>1; i++)
        if(x%prime[i]==0)
        {
            while(x%prime[i]==0)
            {
                b[prime[i]]++;
                if((LL)b[prime[i]]*(LL)D>(LL)a[prime[i]]*(LL)B) return false;
                x/=prime[i];
            }
        }
    if(x>1) b[x]++;
    if((LL)b[x]*(LL)D>(LL)a[x]*(LL)B) return false;
    return true;
}
void get_prime()
{
    int high=MAXN;
    memset(check,false,true);
    cnt=0;
    for(int i=2; i<=high; i++)
    {
        if(!check[i])
            prime[cnt++]=i;
        for(int j=0; j<cnt&&i*prime[j]<=high; j++)
        {
            check[i*prime[j]]=true;
            if(i%prime[j]==0) break;
        }
    }
}
class BigFatInteger2
{
public:
    string isDivisible(int A, int B, int C, int D)
    {
        a.clear();
        b.clear();
        get_prime();
        go(A);
        if(!checks(B,C,D))
            return "not divisible";
        return "divisible";
    }
};
