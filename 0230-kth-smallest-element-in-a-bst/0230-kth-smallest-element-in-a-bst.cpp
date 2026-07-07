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
    int findsmall(TreeNode* root,int k,int& cnt){
        if(!root) return -1;

        int left = findsmall(root->left,k,cnt);

        if(left!=-1) return left;

        cnt++;

        if(cnt==k) return root->val;

        int right = findsmall(root->right,k,cnt);
        return right;
    }
    int kthSmallest(TreeNode* root, int k) {
        int cnt = 0;
        return findsmall(root,k,cnt);
    }
};