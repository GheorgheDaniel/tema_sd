class Solution {
public:
    bool searchMatrix(vector<vector<int>>& matrix, int target) {
        int idx = matrix.size() - 1;
        for(int i = 0; i < matrix[0].size(); i++) {
            while(idx - 1 >= 0 && matrix[idx - 1][i] >= target) {
                idx--;
            }
            if(matrix[idx][i] == target) return true;
            if(matrix[idx][i] > target && idx == 0) return false;
        }
        return false;
    }

};