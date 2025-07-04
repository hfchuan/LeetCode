#include <iostream>
#include <vector>
#include <climits>

struct TreeNode{
    int val;
    TreeNode* left;
    TreeNode* right;
    TreeNode():val(0),left(nullptr),right(nullptr){}
    TreeNode(int x):val(x),left(nullptr),right(nullptr){}
    TreeNode(int x,TreeNode* left,TreeNode* right):val(x),left(left),right(right){}
};

class Solution{
    public:
        int maxPathSum(TreeNode* root){
            int maxSum = INT_MIN;
            maxGain(root,maxSum);
            return maxSum;

        }

    private:
        int maxGain(TreeNode* node,int& maxSum){
            if(node == nullptr){
                return 0;
            }

            int leftGain = std::max(maxGain(node->left,maxSum),0);
            int rightGain = std::max(maxGain(node->right,maxSum),0);

            int priceNewpath = node->val + leftGain + rightGain;
            maxSum = std::max(maxSum,priceNewpath);

            return node->val + std::max(leftGain,rightGain);
        }
};

int main(){


    return 0;
}