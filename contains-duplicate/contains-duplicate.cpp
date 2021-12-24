class Solution {
public:
    bool containsDuplicate(vector<int>& nums) {
        unordered_set<int> mySet;
        
        for(int num : nums) {
            //element already exists
            if(mySet.count(num) != 0) {
                return true;
            }
            mySet.insert(num);
        }
        return false;
    }
};