#include <iostream>
#include <vector>

class Solution{
    public:
        int minimumTotal(std::vector<std::vector<int>>& triangle){
            if(triangle.empty()){
                return 0;
            }
            int n = triangle.size();
            std::vector<std::vector<int>> dp(n,std::vector<int>(n,0));
            dp[0][0] = triangle[0][0];
            for(int i=1;i<n;i++){
                for(int j=0;j<=i;j++){
                    if(j==0){
                        dp[i][j]=dp[i-1][j]+triangle[i][j];
                    }
                    else if(j==i){
                        dp[i][j]=dp[i-1][j-1]+triangle[i][j];
                    }
                    else{
                        dp[i][j]=std::min(dp[i-1][j-1],dp[i-1][j])+triangle[i][j];
                    }

                }

            }
            int res = dp[n-1][0];
            for(int i=1;i<n;i++){
                if(dp[n-1][i]<res){
                    res = dp[n-1][i];
                }
            }
            return res;
            

        }
};


int main(){


    return 0;
}