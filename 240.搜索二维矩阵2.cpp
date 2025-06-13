#include <iostream>
#include <vector>


class Solution{
    public:
        bool searchMatrix(std::vector<std::vector<int>>& matrix,int target){
            int m = matrix.size();
            int n = matrix[0].size();
            int row = 0, col = n-1;
            while(row < m && col >=0){
                if(matrix[row][col] == target){
                    return true;
                }
                else if(matrix[row][col] > target){
                    --col;

                }
                else{
                    ++row;
                }
            }
            return false;
        }

        bool searchMatrix2(std::vector<std::vector<int>>& matrix,int target){
            int i = matrix.size()-1,j=0;
            while(i>= 0 && j<matrix[0].size()){
                if(matrix[i][j] == target){
                    return true;
                }
                else if(matrix[i][j]>target){
                    i--;
                }
                else{
                    j++;
                }
            }
            return false;
        }
};

int main(){

    return 0;
}