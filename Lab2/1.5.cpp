class Solution {
public:
    string removeDuplicates(string s, int k) {
        vector<pair<char, int>>stk;
        stk.push_back({s[0], 1});
        for(int i = 1; i < s.size(); i++) {
            if(!stk.empty() && stk.back().first == s[i]) stk.back().second++;
            else stk.push_back({s[i], 1});
            if(stk.back().second >= k) stk.back().second -= k;
            if(stk.back().second == 0) stk.pop_back();
        }

        string ans;
        for(auto [chr, occ] : stk) {
            while(occ--) ans += chr;
        }
        return ans;
    }
};