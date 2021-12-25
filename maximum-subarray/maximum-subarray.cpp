class Solution {
public:
    //this implemetns kadane's algorithm
    int maxSubArray(vector<int>& nums) {
        
        if(nums.size() == 1) {
            return nums[0];
        }
        int maxSum = INT_MIN, sum = 0;
        
        for(int i =0; i < nums.size(); i++) {
            sum = max(nums[i], sum + nums[i]);
            maxSum = max(sum, maxSum);
        }
        return maxSum;
    }
};