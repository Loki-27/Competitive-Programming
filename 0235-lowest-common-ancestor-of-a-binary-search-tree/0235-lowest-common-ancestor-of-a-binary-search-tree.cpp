/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */

class Solution {
public:
    
    TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
        while(root){
            if(p->val<root->val && q->val<root->val) root = root->left;
            else if(p->val>root->val && q->val>root->val) root = root->right;
            else return root;
        }
        return NULL;
        // if(!root||root==p||root==q) return root;

        // TreeNode* left = lowestCommonAncestor(root->left,p,q);
        // TreeNode* right = lowestCommonAncestor(root->right,p,q);

        // if(!left) return right;
        // else if(!right) return left;
        // else return root;
    }
};