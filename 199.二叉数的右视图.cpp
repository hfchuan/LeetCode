#include <iostream>
#include <vector>

struct TreeNode{
    int val;
    TreeNode* left;
    TreeNode* right;
    TreeNode(): val(0), left(NULL), right(NULL) {}
    TreeNode(int x): val(x), left(NULL), right(NULL) {}
    TreeNode(int x, TreeNode* left, TreeNode* right): val(x), left(left), right(right) {}
};


class Solution{
    public:
        std::vector<int> rightSideView(TreeNode* root){
            std::vector<int> res;
            if(root == nullptr){
                return res;
            }
            std::vector<TreeNode*> q;
            q.push_back(root);
            while(!q.empty()){
                int size = q.size();
                for(int i=0;i<size;i++){
                    TreeNode* node = q.front();
                    q.erase(q.begin());
                    if(i == size-1){
                        res.push_back(node->val);
                    }
                    if(node->left!=nullptr){
                        q.push_back(node->left);
                    }
                    if(node->right!=nullptr){
                        q.push_back(node->right);
                    }
                }

            }
            return res;

        }
};

int main(){


    return 0;
}