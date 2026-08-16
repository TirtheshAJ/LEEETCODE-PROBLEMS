class Solution {
public:
    static bool stoneGameIX(vector<int>& stones) {
        int freq[3]={0};
        for(int x: stones){
            freq[x%3]++;

        }
        const bool f0 = (freq[0]&1)==1;
        if(f0==0) return freq[1]>0 &&  freq[2]>0;
        const int diff = abs(freq[1]-freq[2]);
        return diff>=3;

    }
};
auto init= [](){
    ios:: sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    return 'c';
}();