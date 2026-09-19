class Solution {
public:
    void moveZeroes(vector<int>& nums) {
        vector<int>temp;
        for(int i=0;i<nums.size();i++){
            if(nums[i]!=0){
                temp.push_back(nums[i]);
            }
        }
        int totalno=temp.size();
        for(int i=0;i<totalno;i++){
            nums[i]=temp[i];
        }
        for(int i=totalno;i<nums.size();i++){
            nums[i]=0;
        } 
    }
};