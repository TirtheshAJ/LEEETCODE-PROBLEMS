using ll= long long;
class Solution {
public:
    vector< ll > dp;
        ll f(long  long  x, unsigned bitmask){
        ll cnt=0;
        for(unsigned i=1; i<=bitmask; i++)
            cnt +=(popcount(i)&1)?(x/dp[i]):(-x/dp[i]);
        return cnt;
        
    }
    long long findKthSmallest(vector<int>& coins, int k) {
        sort(coins.rbegin(),coins.rend());
        if(coins.back()==1)
            return k;
        bitset<26> valid_coins=0;
        for(int c:coins){
            valid_coins[c]=1;
            for(int r=2*c;r<26;r+=c)
                valid_coins[r]=0;
        }
        coins.clear();
        for(int i=1;i<=25; i++)
            if(valid_coins[i])
                coins.push_back(i);

        int sz=coins.size();
        if(sz==1)
            return (ll)coins[0]*k;

        unsigned bitMask=(1<<sz)-1;
        dp.assign(1<<sz, -1);

        for(int bMask=1; bMask<=bitMask; bMask++){
            ll lcm=1;
            for(int i=0;i<sz; i++){
                if(bMask & (1LL<<i)){
                    lcm=lcm/gcd(lcm, coins[i])*coins[i];
                }
            }
            dp[bMask]=lcm;
        }
        ll l=k+1, r=(long long)coins[0]*k, mid, ans=r;
        
        while(l<=r){
            mid=l+(r-l)/2;
            if(f(mid, bitMask)>=k){
                ans=mid;
                r=mid-1;
            }else
                l=mid+1;
        }
        return ans;
    }
};