#include <iostream>
#include <vector>

class Solution{
    public:
        double findMedianSortedArrays(std::vector<int>& nums1,std::vector<int>& nums2){
            int m = nums1.size(), n = nums2.size();
            std::vector<int> nums(m+n);
            int i=0,j=0,k=0;
            while(i<m && j<n){
                if(nums1[i]>nums2[j]){
                    nums[k] = nums2[j];
                    j++;
                }
                else{
                    nums[k] = nums1[i];
                    i++;
                }
                k++;
            }
            while(i<m){
                nums[k] = nums1[i];
                i++;
                k++;
            }
            while(j<n){
                nums[k] = nums2[j];
                j++;
                k++;
            }

            double res;

            if((m+n)%2==0){
                return res=(nums[(m+n)/2-1]+nums[(m+n)/2])/2.0;

            }
            else{
                return res=nums[(m+n)/2];
            }

        }
};

int main(){
    Solution sol;
    std::vector<int> nums1 = {1,3};
    std::vector<int> nums2 = {2};
    std::cout<<sol.findMedianSortedArrays(nums1,nums2)<<std::endl;


    return 0;
}