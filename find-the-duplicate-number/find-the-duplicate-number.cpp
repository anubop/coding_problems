class Solution {
public:
    int findDuplicate(vector<int>& nums) {
        sort(nums.begin(), nums.end());
        for(int i = 1; i < nums.size(); i++) {
            int j = i -1;
            if(nums[i] == nums[j]) {
                return nums[i];
            }
        }
        return 0;
    }
    
};