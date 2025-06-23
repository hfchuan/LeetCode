#include <iostream>
#include <vector>
#include <unordered_map>
#include <queue>

struct TreeNode{
    int val;
    TreeNode* left;
    TreeNode* right;
    TreeNode() : val(0),left(nullptr),right(nullptr){}
    TreeNode(int x):val(x),left(nullptr),right(nullptr){}
    TreeNode(int x,TreeNode* left,TreeNode* right):val(x),left(left),right(right){}

};


class Solution{
    public:
        bool hasPathSum(TreeNode* root,int targetSum){
            if(root==nullptr){
                return false;
            }
            if(root->left==nullptr && root->right==nullptr){
                return root->val==targetSum;

            }
            return hasPathSum(root->left,targetSum-root->val) || hasPathSum(root->right,targetSum-root->val);
        }

        bool hasPathSum2(TreeNode* root, int targetSum) {
            if(root==nullptr){
                return false;

            }
            std::queue<TreeNode*> que_node;
            std::queue<int> que_val;
            que_node.push(root);
            que_val.push(root->val);
            while(!que_node.empty()){
                TreeNode* node=que_node.front();
                int val=que_val.front();
                que_node.pop();
                que_val.pop();
                if(node->left==nullptr && node->right==nullptr){
                    if(val==targetSum){
                        return true;
                    }
                    continue;
                }
                if(node->left!=nullptr){
                    que_node.push(node->left);
                    que_val.push(val+node->left->val);
                }
                if(node->right!=nullptr){
                    que_node.push(node->right);
                    que_val.push(val+node->right->val);
                }
            }
            return false;


        }
};


int main(){


    return 0;
}