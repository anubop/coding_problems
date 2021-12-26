class Solution {
public:
    int coinChange(vector<int>& coins, int amount) {
        unordered_map<int, int> cache;
        return coinChangeHelper(coins, amount, cache);
    }
private:
    int coinChangeHelper(vector<int>& coins, int amount, unordered_map<int, int> & cache) {
        int best = INT_MAX;
        if(amount < 0) {
            return -1;
        }
        if(amount == 0) {
            return 0;
        }
        if(cache.count(amount) != 0 ) {
            return cache[amount];
        }
        for(int coin : coins) {
            int prev = -1;
            prev = coinChangeHelper(coins, amount - coin, cache);
            if(prev != -1) {
                best = min(best, prev + 1);
            }
            
            cache[amount] = best == INT_MAX ? -1 :best;
        }
        return best == INT_MAX ? -1 :best;
    }
};