class Solution {
public:
    int missingMultiple(vector<int>& nums, int k) {
        
        for (int i = k; ; i += k) {
            bool found = false;
            
            for (int x : nums) {
                if (x == i) {
                    found = true;
                    break;
                }
            }
            
            if (!found) {
                return i;
            }
        }
    }
};