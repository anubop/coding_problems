class Solution {
public:
    int mySqrt(int x) {
        //basic idea : perform binary search from 1 to x.
        if(x == 0) {
            return 0;
        }
        if(x==1) {
            return 1;
        }
        
        int left = 1, right = x;
        while(left < right) {
            int mid = left + (right - left) / 2;
             
            if((long)(mid) * mid > x) {
                right = mid;
            } else {
                left = mid + 1;
            }
        }
        return left - 1;
    }
};