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
    TreeNode* intobst(TreeNode* root, int val){
        if(!root){
            return root;
        }
        if(val>root->val) {
            if(!root->right) return root;
            return intobst(root->right,val);}
        else{
            if(!root->left) return root;
            return intobst(root->left,val);}
    }
    TreeNode* insertIntoBST(TreeNode* root, int val) {
        TreeNode* node = new TreeNode(val);
        if(!root) return node;
        
        TreeNode* pos;
        pos = intobst(root,val);
        if(val>pos->val) pos->right = node;
        else pos->left = node;
        return root;
    }
};