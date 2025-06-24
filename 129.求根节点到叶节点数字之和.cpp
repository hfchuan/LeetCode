#include <iostream>
#include <vector>
#include <queue>

struct TreeNode{
    int val;
    TreeNode* left;
    TreeNode* right;
    TreeNode(int x):val(x),left(NULL),right(NULL){}
};


class Solution{
    public:
        int sumNumbers(TreeNode* root){
            return dfs(root,0);
        }

        int sumNumbers2(TreeNode* root){
             if(root == nullptr){
                return 0;
             }
             int sum = 0;
             std::queue<TreeNode*> q1;
             std::queue<int> q2;
             q1.push(root);
             q2.push(root->val);
             while(!q1.empty()){
                TreeNode* node=q1.front();
                int num = q2.front();
                q1.pop();
                q2.pop();
                if(node->left == nullptr && node->right ==nullptr){
                    sum+=num;
                }
                else{
                    if(node->left!=NULL){
                        q1.push(node->left);
                        q2.push(num*10 +node->left->val);
                    }
                    if(node->right!=NULL){
                        q1.push(node->right);
                        q2.push(num*10 +node->right->val);
                    }
                }
             }
             return sum;
        }
    
    private:
        int dfs(TreeNode* node,int currentSum){
            if(node == nullptr){
                return 0;
            }
            currentSum = currentSum*10 + node->val;
            if(node->left == NULL && node->right==NULL){
                return currentSum;
            }
            return dfs(node->left,currentSum) + dfs(node->right,currentSum);
        }
};

int main(){


    return 0;
}