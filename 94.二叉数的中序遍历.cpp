#include <iostream>
#include <vector>

struct TreeNode{
    int val;
    TreeNode* left;
    TreeNode* right;
    TreeNode() : val(0),left(nullptr),right(nullptr){}
    TreeNode(int x) : val(x),left(nullptr),right(nullptr){}
    TreeNode(int x, TreeNode* left,TreeNode* right) : val(x),left(left),right(right){} 
};

class Solution{
    public:
        std::vector<int> inorderTraversal(TreeNode* root){
            std::vector<int> res;
            if(root == nullptr){
                return res;
            }
            std::vector<TreeNode*> stack;
            TreeNode* curr = root;
            while(curr!= nullptr || !stack.empty()){
                while(curr!=nullptr){
                    stack.push_back(curr);
                    curr = curr->left;

                }
                curr = stack.back();
                stack.pop_back();
                res.push_back(curr->val);
                curr = curr->right;

            }
            return res;
        }
};


int main(){


    return 0;
}