#include <iostream>
#include <vector>
#include <queue>
#include <stack>
#include <climits>

struct TreeNode{
    int val;
    TreeNode* left;
    TreeNode* right;
    TreeNode(int x):val(x),left(NULL),right(NULL){}
};


class Solution{
    public:
        int getMinimumDifference(TreeNode* root){
            if(root==NULL){
                return 0;
            }
            std::stack<TreeNode*> s;
            TreeNode* node = root;
            int pre = INT_MIN;
            int res = INT_MAX;
            while(node!=NULL || !s.empty()){
                while(node!=NULL){
                    s.push(node);
                    node = node->left;
                }
                node = s.top();
                s.pop();
                if(pre > INT_MIN){
                    res = std::min(res,node->val-pre);
                }
                pre = node->val;
                node = node->right;
            }
            return res;

            
        }
};


int main(){


    return 0;
}