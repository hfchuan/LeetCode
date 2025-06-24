#include <iostream>
#include <stack>
#include <vector>
#include <queue>


struct TreeNode{
    int val;
    TreeNode* left;
    TreeNode* right;
    TreeNode(int x):val(x),left(NULL),right(NULL){}
};

class BSTIterator{
    public:
        BSTIterator(TreeNode* root):idx(0),arr(inorderTraversal(root)){}

        

        int next(){
            return arr[idx++];

        }

        bool hasNext(){
            return (idx<arr.size());

        }

    private:
        void inorder(TreeNode* root,std::vector<int>& res){
            if(root==NULL){
                return;
            }
            inorder(root->left,res);
            res.push_back(root->val);
            inorder(root->right,res);
        }

        std::vector<int > inorderTraversal(TreeNode* root){
            std::vector<int> res;
            inorder(root,res);
            return res;
        }

        std::vector<int> arr;
        int idx;
};


int main(){


    return 0;
}