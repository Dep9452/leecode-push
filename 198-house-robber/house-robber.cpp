class Solution {
public:
    int rob(vector<int>& nums) {
        int prev2 = 0;
        int prev1 = 0;

        for (int money : nums) {
            int take = prev2 + money;
            int skip = prev1;

            int current = max(take, skip);

            prev2 = prev1;
            prev1 = current;
        }

        return prev1;
    }
};