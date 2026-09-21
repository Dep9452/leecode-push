class Solution {
public:
    vector<long long> resultArray(vector<int>& nums, int k) {
        vector<long long> ans(k,0), dp(k,0);
        for(int x:nums){
            vector<long long> temp(k,0);
            temp[x%k]++;
            for(int r=0;r<k;r++){
                temp[(r*(x%k))%k]+=dp[r];
            }
            dp=temp;
            for(int r=0;r<k;r++) ans[r]+=dp[r];
        }
        return ans;
    }
};