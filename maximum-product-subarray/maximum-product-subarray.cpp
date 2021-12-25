class Solution {
public:
    int maxProduct(vector<int>& nums) {
        
        //the max product at any index is either the max product up to the index before it times the number at the index. or the number at the index OR the min product up to ehe index before it times the number at the index. So we have to keep track of the min and the max
        int result = INT_MIN, maxProd = 1, minProd = 1;
        
        for(int i =0; i<nums.size(); i++) {
            
            int tempMax = max(nums[i], max(minProd*nums[i], maxProd * nums[i]));
            minProd = min(nums[i], min(minProd*nums[i], maxProd* nums[i]));
            
            maxProd = tempMax;
            result = max(result, maxProd);
        }
        return result;
    }
};