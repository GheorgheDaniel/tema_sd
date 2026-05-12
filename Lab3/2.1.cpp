class Solution {
public:
    vector<vector<int>> threeSum(vector<int>& nums) {
        vector<vector<int>>ans;
        unordered_map<int, int>first;
        sort(nums.begin(), nums.end());
        unordered_map<int, int>second;
        for(int i = 0; i < nums.size(); i++) {
            unordered_map<int, int>m;
            if(first.count(nums[i])) continue;
            first[nums[i]] = 1;
            for(int j = i + 1; j < nums.size(); j++) {
                m[nums[j]]++;
            }

            for(int j = i + 1; j < nums.size(); j++) {
                if(second.count(nums[j])) {
                    m[nums[j]]--;
                    if(m[nums[j]] == 0) m.erase(nums[j]);
                    continue ;
                }
                second[nums[j]] = 1;
                m[nums[j]]--;
                if(m[nums[j]] == 0) m.erase(nums[j]);
                if(m.count(0 - nums[i] - nums[j])) {
                    vector<int>v1;
                    v1.push_back(nums[i]); v1.push_back(nums[j]); v1.push_back(0 - nums[i] - nums[j]);
                    ans.push_back(v1);
                }
            }
            second.clear();
        }
        return ans;
    }
};