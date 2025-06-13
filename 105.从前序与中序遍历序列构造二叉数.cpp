#include <iostream>
#include <vector>
#include <unordered_map>

struct TreeNode{
    int val;
    TreeNode* left;
    TreeNode* right;
    TreeNode() : val(0),left(nullptr),right(nullptr){}
    TreeNode(int x) : val(x),left(nullptr),right(nullptr){}
    TreeNode(int x,TreeNode* left,TreeNode* right) : val(x),left(left),right(right){}

};

class Solution{
    public:
        TreeNode* buildTree(std::vector<int>& preorder,std::vector<int>& inorder){
            std::unordered_map<int,int> inMap;
            for(int i=0;i<inorder.size();i++){
                inMap[inorder[i]] = i;
            }
            return buildTreeHelper(preorder,inorder,0,preorder.size()-1,0,inorder.size()-1,inMap);

        }

        TreeNode* buildTreeHelper(std::vector<int>& preorder,std::vector<int>& inorder,int preStart,int preEnd,int inStart,int inEnd,std::unordered_map<int,int>& inMap){
            if(preStart > preEnd || inStart > inEnd){
                return nullptr;
            }
            int rootVal = preorder[preStart];
            TreeNode* root = new TreeNode(rootVal);

            int inRoot = inMap[rootVal];
            int numsLeft = inRoot - inStart;

            root->left = buildTreeHelper(preorder,inorder,preStart+1,preStart+numsLeft,inStart,inRoot-1,inMap);
            root->right = buildTreeHelper(preorder,inorder,preStart+numsLeft+1,preEnd,inRoot+1,inEnd,inMap);

            return root;
        }

        TreeNode* buildTree2(std::vector<int>& preorder,std::vector<int>& inorder){
            this->preorder = preorder;
            for(int i=0;i<inorder.size();i++){
                dic[inorder[i]] = i;
                
            }
            return recur(0,0,inorder.size()-1);

        }

    private:
        std::vector<int> preorder;
        std::unordered_map<int,int> dic;
        TreeNode* recur(int root,int left,int right){
            if(left > right){
                return nullptr;
            }
            TreeNode* node = new TreeNode(preorder[root]);
            int i = dic[preorder[root]];
            node->left = recur(root+1,left,i-1);
            node->right = recur(root+i-left+1,i+1,right);
            return node;
        }

};


int main(){

    return 0;
}