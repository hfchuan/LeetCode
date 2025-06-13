#include <iostream>
#include <vector>


class Solution{
    public:
        void setZeroes(std::vector<std::vector<int>>& matrix){
            int m = matrix.size();
            int n = matrix[0].size();
            bool row_flag = false;
            bool col_flag = false;
            for(int j =0;j<n;j++){
                if(matrix[0][j]==0){
                    row_flag = true;
                    break;
                }
            }

            for(int i=0;i<m;i++){
                if(matrix[i][0]==0){
                    col_flag = true;
                    break;
                }
            }

            for(int i=1;i<m;i++){
                for(int j=1;j<n;j++){
                    if(matrix[i][j] == 0){
                        matrix[i][0] = 0;
                        matrix[0][j]=0;
                    }
                }
            }

            for(int i=1;i<m;i++){
                for(int j=1;j<n;j++){
                    if(matrix[i][0] == 0 || matrix[0][j] ==0){
                        matrix[i][j]=0;
                    }
                }
            }

            if(row_flag){
                for(int j=0;j<n;j++){
                    matrix[0][j] = 0;
                }
            }

            if(col_flag){
                for(int i=0;i<m;i++){
                    matrix[i][0] = 0;
                }
            }
            

        }

        void setZeroes2(std::vector<std::vector<int>>& matrix){
            int m = matrix.size();
            int n = matrix[0].size();
            std::vector<int> row(m),col(n);
            for(int i=0;i<m;i++){
                for(int j=0;j<n;j++){
                    if(matrix[i][j] == 0){
                        row[i] = 1;
                        col[j] = 1;
                    }
                }
            }

            for(int i=0;i<m;i++){
                for(int j=0;j<n;j++){
                    if(row[i] || col[j]){
                        matrix[i][j] = 0;
                    }
                }
            }

        }

};

int main(){


    return 0;
}