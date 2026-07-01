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
    bool isSameTree(TreeNode* p, TreeNode* q) {

        if(!p || !q){
            return p==q;
        }

        if(p->val == q->val){
            bool left = isSameTree(p->left,q->right);
            bool right = isSameTree(p->right,q->left);
            return left && right;
        }
        return false;
    }
    bool isSymmetric(TreeNode* root) {
        return isSameTree(root->left,root->right);
    }
};