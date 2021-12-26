class Solution {
public:
    int climbStairs(int n) {
        int cache[46] = {0};
        return climbStairsHelper(n, cache);
    }
private: 
    int climbStairsHelper(int n, int cache[]) {
        if(n == 1) {
            cache[1] = 1;
            return 1;
        }
        if(n == 2) {
            cache[2] =2;
        }
        if(cache[n] != 0) {
            return cache[n];
        }
        int solution = climbStairsHelper(n-1, cache) + climbStairsHelper(n-2, cache);
        cache[n] = solution;
        return solution;
        
    }
};