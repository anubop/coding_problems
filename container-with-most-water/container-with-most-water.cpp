class Solution {
public:
    int maxArea(vector<int>& height) {
        int left = 0;
        int right = height.size() - 1;
        int maxWater = INT_MIN;
        
        while(left < right) {
            int area = getArea(left, height[left], right, height[right]);
            maxWater = max(area, maxWater);
            if(height[left] < height[right]) {
                left++;
            } else {
                right--;
            }
        }
        return maxWater;
        
    }
    
private:
    int getArea(int x1, int h1, int x2, int h2) {
        return min(h2,h1) * (x2 - x1);
    }
};