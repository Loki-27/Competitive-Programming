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
    vector<vector<int>> zigzagLevelOrder(TreeNode* root) {
        vector<vector<int>> zigzag;
        if(!root) return zigzag;
        stack<TreeNode*> st1,st2;
        st1.push(root);
        
        while(!st1.empty() || !st2.empty()){
            vector<int> v;

            if(st2.empty()){
                while(!st1.empty()){
                    TreeNode* node = st1.top();st1.pop();
                    v.push_back(node->val);
                    if(node->left!=nullptr) st2.push(node->left);
                    if(node->right!=nullptr) st2.push(node->right);
                }
            }
            else{
                while(!st2.empty()){
                    TreeNode* node = st2.top();st2.pop();
                    v.push_back(node->val);
                    if(node->right!=nullptr) st1.push(node->right);
                    if(node->left!=nullptr) st1.push(node->left);
                }
            }
            zigzag.push_back(v);
        }
        return zigzag;
    }
};