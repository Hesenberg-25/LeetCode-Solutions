#include <vector>

class Solution {
public:
    void setZeroes(std::vector<std::vector<int>>& matrix) {
        int rows = matrix.size();
        int cols = matrix[0].size();
        
    
        std::vector<std::vector<int>> copy = matrix;

        for (int i = 0; i < rows; i++) {
            for (int j = 0; j < cols; j++) {
                
                if (matrix[i][j] == 0) {
                    
                    
                    for (int k = 0; k < cols; k++) {
                        copy[i][k] = 0;
                    }
                    
                    
                    for (int k = 0; k < rows; k++) {
                        copy[k][j] = 0;
                    }
                }
            }
        }

        
        matrix = copy;
    }
};
