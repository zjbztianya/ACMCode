typedef long long LL;
map<LL,int>ms;
LL getAns(LL r,LL p)
{
    ms.clear();
    LL ans=0;
    for(LL i=0; i*i<=r; i++)
    {
        if(ms[i*i%p]) continue;
        ans+=(r-i*i)/p;
        ms[i*i%p]++;
    }
    return ans;
}
class SparseFactorialDiv2
{
public:
    LL getCount(LL lo, LL hi, LL divisor)
    {
        return getAns(hi,divisor)-getAns(lo-1,divisor);
    }
};
