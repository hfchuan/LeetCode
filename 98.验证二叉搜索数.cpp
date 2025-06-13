#include <iostream>
#include <vector>
#include <limits.h>



struct TreeNode{
    int val;
    TreeNode* left;
    TreeNode* right;
    TreeNode() : val(0),left(nullptr),right(nullptr){}
    TreeNode(int x) : val(x),left(nullptr),right(nullptr){}
    TreeNode(int x,TreeNode* left,TreeNode* right):val(x),left(left),right(right){}
};

class Solution{
    public:
        bool isValidBST(TreeNode* root){
            return isValidBSTHelper(root,LLONG_MIN,LLONG_MAX);
        }

        bool isValidBSTHelper(TreeNode* root,long long min,long long max){
            if(root==nullptr){
                return true;
            }
            if(root->val<=min || root->val>=max){
                return false;
            }
            return isValidBSTHelper(root->left,min,root->val) && isValidBSTHelper(root->right,root->val,max);

        }
};

int main(){



    return 0;
}