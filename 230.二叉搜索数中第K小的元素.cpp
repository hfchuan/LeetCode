#include <iostream>
#include <vector>
#include <queue>

struct TreeNode{
    int val;
    TreeNode* left;
    TreeNode* right;
    TreeNode() : val(0), left(nullptr), right(nullptr) {}
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
    TreeNode(int x, TreeNode* left, TreeNode* right) : val(x), left(left), right(right) {}
};

class Solution{
    public:
        int kthSmallest(TreeNode* root, int k){
            int res = -1;
            inorderTraversal(root,k,res);
            return res;
        }

        void inorderTraversal(TreeNode* root,int &k,int &res){
            if(root == nullptr || k<=0){
                return;
            }
            inorderTraversal(root->left,k,res);
            k--;
            if(k==0){
                res = root->val;
                return;
            }
            inorderTraversal(root->right,k,res);
        }
};


int main(){

    return 0;
}