#include <iostream>
#include <vector>
#include <algorithm>


class Solution{
    public:
        void rotate(std::vector<std::vector<int>>& matrix){
            int n = matrix.size();
            
            for(int i=0;i<n;i++){
                for(int j=i;j<n;j++){
                    std::swap(matrix[i][j],matrix[j][i]);
                }
            }

            for(int i=0;i<n;i++){
                std::reverse(matrix[i].begin(),matrix[i].end());
            }
        }
};

int min(){

    return 0;
}