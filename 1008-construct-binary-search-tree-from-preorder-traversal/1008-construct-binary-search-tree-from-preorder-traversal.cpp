/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
class Solution {
public:
    void tobst(TreeNode* root,int key){
        if(key<root->val){
            if(!root->left){
                TreeNode* node = new TreeNode(key);
                root->left = node;
            }
            else tobst(root->left,key);
        }
        else{
            if(!root->right){
                TreeNode* node = new TreeNode(key);
                root->right = node;}
            else tobst(root->right,key);
        }
    }
    TreeNode* bstFromPreorder(vector<int>& preorder) {
        TreeNode* root = new TreeNode(preorder[0]);

        TreeNode* node = root;

        for(int i=1;i<preorder.size();i++){
            tobst(root,preorder[i]);
        }
        return root;
    }
};