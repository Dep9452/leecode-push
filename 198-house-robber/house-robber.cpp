class Solution {
public:
    int rob(vector<int>& nums) {
        int prev = 0;
        int curr = 0;

        for (int money : nums) {
            int temp = curr;
            curr = max(curr, prev + money);
            prev = temp;
        }

        return curr;
    }
};