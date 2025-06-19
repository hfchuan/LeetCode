#include <iostream>
#include <vector>
#include <algorithm>

class Solution{
    public:
        int maximalSquare(std::vector<std::vector<char>>& matrix){
            if(matrix.empty() || matrix[0].empty()){
                return 0;
            }
            int m=matrix.size();
            int n=matrix[0].size();
            std::vector<std::vector<int>> dp(m,std::vector<int>(n,0));
            int res=0;
            for(int i=0;i<m;i++){
                if(matrix[i][0]=='1'){
                    dp[i][0]=1;
                    res =1;

                }
            }
            for(int j=0;j<n;j++){
                if(matrix[0][j]=='1'){
                    dp[0][j]=1;
                    res=1;
                }
            }
            for(int i=1;i<m;i++){
                for(int j=1;j<n;j++){
                    if(matrix[i][j]=='1'){
                        dp[i][j]=std::min({dp[i-1][j],dp[i][j-1],dp[i-1][j-1]})+1;
                        res=std::max(res,dp[i][j]);
                    }
                }
            }
            return res*res;

            

        }
};


int main(){

    return 0;
}