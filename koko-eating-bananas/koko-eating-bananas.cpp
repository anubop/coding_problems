class Solution {
public:
    int minEatingSpeed(vector<int>& piles, int h) {
        //Employ Binary Search
        
        //step 1 define search space
        
        //minumum bound is total bananas divided by total hours
        int left = 1; 
        //max bound is max number of elements in a pile (any speed faster than this is pointless)
        int right = *max_element(piles.begin(), piles.end());
        
        //step 2 set binary search template
        while(left < right) {
            int mid = left + (right - left) /2;
            //step 3 define condition (private method below)
            if(canEatAllBananas(piles, h, mid)) {
                right = mid;
            } else {
                left = mid + 1;
            }
        }
        return left;
    }
    
private:
    bool canEatAllBananas(vector<int> piles, int h, int speed) {
        //since we can only finish a maximum of 1 pile per hour if we have less hours than pile return false
        if(h < piles.size()) {
            return false;
        }
        
        int totalHours = 0;
        for(int pile: piles) {
            totalHours += pile / speed + (pile % speed > 0);
        }
        return totalHours <= h;
    }
};