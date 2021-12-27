class Solution {
public:
    int shipWithinDays(vector<int>& weights, int days) {
        int left = *max_element(weights.begin(), weights.end());
        int right = accumulate(weights.begin(), weights.end(), 0);
        
        while(left < right) {
            int mid = left + (right - left)/2;
            if(isFeasible(weights, days, mid)) {
                right = mid;
            } else {
                left = mid + 1;
            }
        }
        return left;
    }
    
private:
    //private helper function to tell us if it is possible to ship packages in allotted days with specified capacity 
    bool isFeasible(vector<int> weights, int maxDays, int maxCap) {
        
        int numDays = 1;
        int shipped = 0; //keeps index of next container to ship
        
        while(numDays <= maxDays) {
            int cap = 0;
            while(cap <= maxCap) {
                if(cap + weights[shipped] <= maxCap) {
                    cap += weights[shipped];
                    shipped++;
                    if(shipped >= weights.size()) {
                        return true;
                     }
                } 
                else {
                    break;
                }
                
            }
            numDays++;
            if(shipped >= weights.size()) {
                return true;
            }
        }
        return false;
    }
};