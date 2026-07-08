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
    bool helper(TreeNode* root,long long maxi,long long mini){
        if(!root) return true;

        if(root->val<=mini||root->val>=maxi){
            return false;
        }

        return helper(root->left,root->val,mini) &&
                helper(root->right,maxi,root->val);
    }

    bool inorder(TreeNode* root,long long& prev){
        if(!root) return true;

        if(!inorder(root->left,prev)) return false;

        if(prev>=root->val) return false;

        prev = root->val;

        return inorder(root->right,prev);
    }
    bool isValidBST(TreeNode* root) {
        // return helper(root,LLONG_MAX,LLONG_MIN);
        long long prev = LLONG_MIN;
        return inorder(root,prev);
    }
};