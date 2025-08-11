class Solution {
public:
    vector<int> productQueries(int n, vector<vector<int>>& q) {
        int f = 1;
        int mod = 1000000007;
        vector<int>pow;
        vector<int>ans;
        while(n){
            if(n%2){
                pow.push_back((n%2) * f);
            }
            f*=2; n/=2;
        }
        for(int i=0; i<q.size(); i++){
            long pd =1;
            for(int j = q[i][0]; j<=q[i][1]; j++){
                pd = (pd * pow[j]) % mod;
            }
            ans.push_back(pd%mod);
        }
        return ans;
    }
};