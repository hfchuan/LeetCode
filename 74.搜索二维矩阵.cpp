#include <iostream>
#include <vector>

class Solution {
    public:
        bool searchMatrix(std::vector<std::vector<int>>& matrix,int target){
            int m = matrix.size();
            int n = matrix[0].size();
            int i =0,j=n-1;
            while(i<m && j>=0){
                if(matrix[i][j] == target){
                    return true;
                }
                else if(matrix[i][j] > target){
                    j--;
                }
                else{
                    i++;
                }
            }
            return false;

        }
};


int main(){
    Solution sol;
    std::vector<std::vector<int>> matrix = {{1,3,5,7},{10,11,16,20},{23,30,34,60}};
    int target = 3;
    bool res = sol.searchMatrix(matrix,target);
    std::cout<<res<<std::endl;


    return 0;
}