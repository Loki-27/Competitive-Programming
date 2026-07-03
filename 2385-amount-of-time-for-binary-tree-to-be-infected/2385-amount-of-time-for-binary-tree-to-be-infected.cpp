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
    void findparent(unordered_map<TreeNode*,TreeNode*> &parent,TreeNode*root,TreeNode* &pin,int start){
        if(!root) return;

        if(root->val == start) pin = root; //to find the root of causing element;

        if(root->left){
            parent[root->left] = root;
            findparent(parent,root->left,pin,start);
        }
        if(root->right){
            parent[root->right] = root;
            findparent(parent,root->right,pin,start);
        }
    }
public:
    int amountOfTime(TreeNode* root, int start) {
        unordered_map<TreeNode*,TreeNode*> parentof;
        TreeNode* pin = NULL;
        findparent(parentof,root,pin,start);

        unordered_set<TreeNode*> visited;
        queue<TreeNode*> q;
        q.push(pin);
        visited.insert(pin);

        int time = -1;
        while(!q.empty()){
            int size = q.size();
            time++;
            for(int i =0;i<size;i++){
                TreeNode* curr = q.front();q.pop();

                if(curr->left &&  !visited.contains(curr->left)){
                    q.push(curr->left);
                    visited.insert(curr->left);
                }
                if(curr->right &&  !visited.contains(curr->right)){
                    q.push(curr->right);
                    visited.insert(curr->right);
                }
                if(parentof[curr] &&  !visited.contains(parentof[curr])){
                    q.push(parentof[curr]);
                    visited.insert(parentof[curr]);
                }
            }
        }
        return time;
    }
};