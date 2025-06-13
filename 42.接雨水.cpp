#include <iostream>
#include <vector>


class Solution{
    public:
        int trap(std::vector<int>& height){
            int res = 0;
            int n = height.size();
            std::vector<int> left_max(n,0);
            std::vector<int> right_max(n,0);

            left_max[0] = height[0];
            for(int i=1;i<n;i++){
                left_max[i] = std::max(left_max[i-1],height[i]);
            }

            right_max[n-1] = height[n-1];
            for(int i=n-2;i>=0;i--){
                right_max[i] = std::max(right_max[i+1],height[i]);
            }
            for(int i=1;i<n-1;i++){
                res += std::min(left_max[i],right_max[i]) - height[i];
            }


            return res;
        }




        int trap2(std::vector<int>& height){
            int res = 0;
            int n = height.size();
            std::vector<int> left_max(n,0);
            std::vector<int> right_max(n,0);
            for(int i=1;i<n;i++){
                for(int j=i;j<n;j++){
                    if(height[j]>right_max[i]){
                        right_max[i] = height[j];
                    }
                }

                for(int j=i;j>=0;j--){
                    if(height[j]>left_max[i]){
                        left_max[i] = height[j];
                    }
                }
                
            }

            for(int i=1;i<n-1;i++){
                res += std::min(left_max[i],right_max[i]) - height[i];
            }

            return res;

            

            
        }
};



int main(){

    Solution s;
    std::vector<int > height = {4,2,0,3,2,5};
    std::cout<<s.trap2(height)<<std::endl;



    return 0;
}