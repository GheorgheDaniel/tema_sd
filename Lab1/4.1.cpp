class Solution {
public:
    int maximumCandies(vector<int>& candies, long long k) {
        auto check = [&](int X) {
            long long count = 0;
            for(auto i : candies) {
                count += i / X;
                if(count >= k) return true;
            }
            return false;
        };

        long long ans = 0;
        for(int bit = 29; bit >= 0; bit--) {
            if(check(ans + (1LL << bit))) ans += (1LL << bit);
        }
        return ans;
    }
};