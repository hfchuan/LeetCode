#include <iostream>
#include <vector>
#include <algorithm>

class Solution{
    public:
        int maxArea(std::vector<int>& height){
            int n =height.size(),left = 0,right = n-1;
            int res = 0;
            while(right >left){
                res = std::max(res,std::min(height[right],height[left])*(right-left));
                if(height[right]>height[left]){
                    left++;

                }
                else{
                    right--;
                }

            }
            return res;



        }


};

int main(){
    std::vector<int> height = {1,8,6,2,5,4,8,3,7};
    Solution s;
    int res = s.maxArea(height);
    std::cout<<res<<std::endl;


    return 0;
}