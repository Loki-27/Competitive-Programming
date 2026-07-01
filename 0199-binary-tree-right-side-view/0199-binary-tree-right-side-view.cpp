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
    vector<int> rightSideView(TreeNode* root) {
        vector<int> res;
        if(!root) return res;

        map<int,int> right;

        queue<pair<TreeNode* , int>> nodes;   //node, lev;
        nodes.push({root,0});

        while(!nodes.empty()){
            auto p = nodes.front(); nodes.pop();

            int lev = p.second;
            TreeNode* curr = p.first;

            right[lev] = curr->val;

            if(curr->left) nodes.push({curr->left,lev+1});
            if(curr->right) nodes.push({curr->right,lev+1});
        }

        for(auto x:right){
            res.push_back(x.second);
        }
        return res;
    }
};