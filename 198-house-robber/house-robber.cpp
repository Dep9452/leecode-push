class Solution {
public:
    int rob(vector<int>& nums) {
        int prev = 0, curr = 0;

        for (int x : nums) {
            int temp = curr;
            curr = max(curr, prev + x);
            prev = temp;
        }

        return curr;
    }
};