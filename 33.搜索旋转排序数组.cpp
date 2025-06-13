#include <iostream>
#include <vector>

class Solution {
    public:
        int search(std::vector<int>& nums,int target){
            int res =-1;
            int left=0,right =nums.size()-1;
            
            while(left <= right){
                int mid =(left+right)/2;
                if(nums[0]<=nums[mid]){
                    left = mid+1;
                }
                else{
                    right = mid-1;
                }
            }

            int k =left;

            if(k==0 || target < nums[0]){
                left =k;
                right = nums.size()-1;

            }
            else{
                left = 0;
                right = k-1;
            }

            

            
            
            while(left <=right){
                int mid = (left+ right)/2;
                if(nums[mid]==target){
                    return mid;
                }
                else if(nums[mid]>target ){
                    right = mid-1;
                }
                else{
                    left = mid +1;
                }

            }
            return res;
            

            

        }
};


int main(){
    Solution sol;
    std::vector<int> nums ={1,3};
    int target = 3;
    std::cout<<sol.search(nums,target)<<std::endl;


    return 0;
}