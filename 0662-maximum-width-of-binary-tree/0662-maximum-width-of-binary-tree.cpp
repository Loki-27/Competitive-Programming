/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right){}
 * };
 */
class Solution {
public:

    int widthOfBinaryTree(TreeNode* root) {
        if(!root) return 0;

        int ans = 0;
        queue<pair<TreeNode*,long long>> nodes;
        nodes.push({root,0});

        while(!nodes.empty()){
            int size = nodes.size();
            long long mini = nodes.front().second;
            long long first,last;
            for(int i = 0;i<size;i++){
                long long curr_id = nodes.front().second-mini;
                TreeNode* node = nodes.front().first;
                nodes.pop();

                if(i==0) first = curr_id;
                if(i==size-1) last = curr_id;
                if(node->left) nodes.push({node->left,curr_id*2+1});
                if(node->right) nodes.push({node->right,curr_id*2+2});
            }
            ans = max((last-first+1),1LL*ans);
        }
        return ans;
    }
};