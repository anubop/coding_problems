class KthLargest {
public:
    vector<int> nums;
    int k;
    
    KthLargest(int k, vector<int>& nums) {
        
        sort(nums.begin(), nums.end());
        this->nums = nums;
        this->k = k;
                
    }
    
    int add(int val) {
        //use binary search to insert 
        int left = 0;
        int right = this->nums.size();
        
        while(left < right) {
            int mid = (left + right) / 2;
            if(val < this->nums[mid]) {
                right = mid;
            } else {
                left = mid + 1;
            }
        }
        this->nums.insert(this->nums.begin()+left, val);
        return nums[nums.size() - this->k];
    }
    
};

/**
 * Your KthLargest object will be instantiated and called as such:
 * KthLargest* obj = new KthLargest(k, nums);
 * int param_1 = obj->add(val);
 */