#include <iostream>
#include <vector>



class Solution{
    public:
        std::vector<int> spiralOrder(std::vector<std::vector<int>>& matrix){
            int m = matrix.size();
            int n = matrix[0].size();
            std::vector<int> res;
            int top = 0, bottom = m-1, left=0,right = n-1;
            while(top<=bottom && left<=right){
                for(int i=left;i<=right;i++){
                    res.push_back(matrix[top][i]);
                }
                top++;
                for(int i=top;i<=bottom;i++){
                    res.push_back(matrix[i][right]);
                }
                right--;
                if(top<=bottom){
                    for(int i=right;i>=left;i--){
                        res.push_back(matrix[bottom][i]);
                    }
                    bottom--;
                }
                if(left<=right){
                    for(int i=bottom;i>=top;i--){
                        res.push_back(matrix[i][left]);
                    }
                    left++;
                }
            }
    

            return res;
        }
};

int main(){


    return 0;
}