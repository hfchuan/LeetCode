#include <iostream>
#include <vector>

struct TreeNode{
    int val;
    TreeNode* left;
    TreeNode* right;
    TreeNode() : val(0),left(nullptr),right(nullptr){}
    TreeNode(int x) : val(x),left(nullptr),right(nullptr){}
    TreeNode(int x,TreeNode*left,TreeNode* right) : val(x),left(left),right(right){}

};


class Solution{
    public:
        int diameterOfBinaryTree(TreeNode* root){
            int diameter = 0;
            depth(root,diameter);
            return diameter;

        }
    private:
        int depth(TreeNode* node,int& diameter){
            if(!node) {
                return 0;
            }
            int left_depth = depth(node->left,diameter);
            int right_depth = depth(node->right,diameter);
            diameter = std::max(diameter,left_depth+right_depth);
            return 1+std::max(left_depth,right_depth);
        }
};

int main(){


    return 0;
}