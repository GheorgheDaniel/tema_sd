
class Solution {
public:
    vector<int> twoSum(vector<int>& numbers, int target) {
        int j = 0;
        vector<int>ans; 
        for(int i = 0; i < numbers.size(); i++) {
            j = i + 1;
            while(numbers[i] + numbers[j] < target) j++;   
            if(numbers[i] + numbers[j] == target) {
                ans.push_back(i + 1); ans.push_back(j + 1);
                break;
            }
        }
        return ans;
    }
};