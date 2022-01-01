class Solution {
public:
    void setZeroes(vector<vector<int>>& matrix) {
        unordered_set<int> rows;
        unordered_set<int> cols;
        
//         int m = matrix.size();
//         int n = matrix[0].size();
        
        //loop through matrix and put rows and cols of the zero elements
        
        for(int row_idx = 0; row_idx < matrix.size(); ++row_idx) {
            for(int col_idx = 0; col_idx < matrix[0].size(); ++col_idx) {
                
                if(matrix[row_idx][col_idx] == 0) {
                    rows.insert(row_idx);
                    cols.insert(col_idx);
                }
            }
        }
        
        
        for(int row_idx = 0; row_idx < matrix.size(); ++row_idx) {
            //if there was a zero in that row set entire row to zero
            if(rows.count(row_idx)) {
                fill(matrix[row_idx].begin(), matrix[row_idx].end(), 0);
            }
            else {
                for(int col_idx = 0; col_idx < matrix[0].size(); ++col_idx) {
                    if(cols.count(col_idx)) {
                        matrix[row_idx][col_idx] = 0;
                    }
                }
            }
        
        }
        
    }
};