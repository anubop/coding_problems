class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        
        vector<int> output = vector<int>();
        
        //create hashmap to store all numbers and thier indices
        unordered_map<int, int> map;
        
        //insert all nums and indices in hashmap (1st pass)
        for(int i = 0; i < nums.size(); i++) {
            map.insert({nums[i], i});
        }
        //look through all indicies in num and search for complement in hashmap (2nd pass)
        for(int i = 0; i < nums.size(); i++) {
            
            int diff = target - nums[i];
            //complement exists in map
            if(map.count(diff) != 0 && map[diff] != i) {
                output.push_back(i);
                output.push_back(map[diff]);
                return output;
            }
        }
        return output;
    }
};