#include <iostream>
#include <vector>
#include <algorithm>


class Solution{
    public:
        int findKthLargest(std::vector<int>& nums,int k){
            int heapSize = nums.size();
            buildMaxHeap(nums,heapSize);
            for(int i =nums.size()-1;i>=nums.size()-k+1;i--){
                std::swap(nums[0],nums[i]);
                heapSize--;
                maxHeapify(nums,0,heapSize);

            }
            return nums[0];
            
        }



    private:
        int quickSelect(std::vector<int>& nums,int k){
            int pivot = nums[0];
            std::vector<int> left,right,equal;
            for(const auto& num : nums){
                if(num > pivot){
                    right.push_back(num);
                }
                else if(num < pivot){
                    left.push_back(num);
                }
                else{
                    equal.push_back(num);
                }
            }

            if(k <= right.size()){
                return quickSelect(right,k);
            }

            if(nums.size()-left.size() < k){
                return quickSelect(left,k-nums.size()+right.size());
            }

            return pivot;

        }

        void maxHeapify(std::vector<int>& a,int i,int heapSize){
            int left = 2*i+1,right = 2*i+2,largest = i;
            if(left < heapSize && a[left]>a[largest]){
                largest = left;

            }

            if(right < heapSize && a[right] > a[largest]){
                largest = right;
            }

            if(largest!=i){
                std::swap(a[i],a[largest]);
                maxHeapify(a,largest,heapSize);
            }
        }

        void buildMaxHeap(std::vector<int>& a,int heapSize){
            for(int i = heapSize / 2-1;i>=0;i--){
                maxHeapify(a,i,heapSize);
            }
        }
};

int main(){
    Solution sol;
    std::vector<int> nums = {3,2,1,5,6,4};
    int k = 2;
    int res = sol.findKthLargest(nums,k);
    std::cout<<res<<std::endl;


    return 0;
}