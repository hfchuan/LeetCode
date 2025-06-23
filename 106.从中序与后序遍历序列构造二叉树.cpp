#include <iostream>
#include <vector>

struct TreeNode{
    int val;
    TreeNode* left;
    TreeNode* right;
    TreeNode(int x):val(x),left(NULL),right(NULL){}
};


class Solution{
    public:
        TreeNode* buildTree(std::vector<int>& inorder,std::vector<int>& postorder){
            if(inorder.empty() || postorder.empty()){
                return nullptr;
            }
            int rootVal = postorder.back();
            int rootIndex = 0;
            for(int i=0;i<inorder.size();i++){
                if(inorder[i]==rootVal){
                    rootIndex =i;
                    break;
                }

            }
            TreeNode* root = new TreeNode(rootVal);
            std::vector<int> leftInorder(inorder.begin(),inorder.begin()+rootIndex);
            std::vector<int> rightInorder(inorder.begin()+rootIndex+1,inorder.end());
            std::vector<int> leftPostorder(postorder.begin(),postorder.begin()+leftInorder.size());
            std::vector<int> rightPostorder(postorder.begin()+leftInorder.size(),postorder.end()-1);
            root->left = buildTree(leftInorder,leftPostorder);
            root->right = buildTree(rightInorder,rightPostorder);
            return root;

        }
};


int main(){


    return 0;
}