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
        std::vector<std::vector<int>> zigzagLevelOrder(TreeNode* root){
            std::vector<std::vector<int>> res;
            if(root==NULL){
                return res;
            }

            std::queue<TreeNode*> q;
            q.push(root);
            bool flag = true;
            while(!q.empty()){
                int size = q.size();
                std::vector<int> level(size);
                for(int i=0;i<size;i++){
                    TreeNode* node = q.front();
                    q.pop();
                   
                    int index = flag? i : size-1-i;
                    level[index] = node->val;
                    if(node->left){
                        q.push(node->left);
                    }
                    if(node->right){
                        q.push(node->right);
                    }
                }
                flag = !flag;
                res.push_back(level);
                
            }
            return res;
        }
};



int main(){


    return 0;
}