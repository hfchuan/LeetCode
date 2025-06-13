#include <iostream>
#include <vector>
#include <algorithm>

class Solution{
    public:
        void heapify(std::vector<int>& nums,int n,int i){
            int largest=i;
            int l=2*i+1;
            int r=2*i+2;
            if(l<n && nums[l]>nums[largest]){
                largest=l;
            }
            if(r<n && nums[r]>nums[largest]){
                largest=r;
            }
            if(largest!=i){
                int temp=nums[i];
                nums[i]=nums[largest];
                nums[largest]=temp;
                heapify(nums,n,largest);
            }

        }

        void heapSort(std::vector<int>& nums,int n){
            for(int i=n/2-1;i>=0;i--){
                heapify(nums,n,i);

            }
            for(int i=n-1;i>=0;i--){
                int temp=nums[0];
                nums[0]=nums[i];
                nums[i]=temp;
                heapify(nums,i,0);
            }
        }
};

int main(){

    std::vector<int > nums={2,3,1,5,6,4};
    int n=nums.size();
    Solution sol;
    sol.heapSort(nums,n);
    for(int i=0;i<n;i++){
        std::cout<<nums[i]<<" ";
    }       
    std::cout<<std::endl;

    return 0;
}