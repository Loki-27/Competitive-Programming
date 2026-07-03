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
    void parentfind(unordered_map<TreeNode* ,TreeNode*>&parent,TreeNode* root){
        if(!root) return;
        if(root->left){
            parent[root->left] = root;
            parentfind(parent,root->left);
        }
        if(root->right) {
            parent[root->right] = root;
            parentfind(parent,root->right);
        }
    }
    vector<int> distanceK(TreeNode* root, TreeNode* target, int k) {
        unordered_map<TreeNode* ,TreeNode*> parentof;
        
        parentfind(parentof,root);


        unordered_map<TreeNode*,bool> visited;
    
        queue<TreeNode*> q;
        q.push(target);
        visited[target]=true;
        int dis = 0;
        while(dis<k && !q.empty()){
            int size = q.size();
            for(int i =0;i<size;i++){
                TreeNode* curr = q.front();q.pop();
                
                if(curr->left && visited.find(curr->left)==visited.end()){
                    q.push(curr->left);
                    visited[curr->left]=true;
                }
                if(curr->right && visited.find(curr->right)==visited.end()){
                    q.push(curr->right);
                    visited[curr->right]=true;
                }
                if(parentof.find(curr)!=parentof.end() && visited.find(parentof[curr])==visited.end()){
                    q.push(parentof[curr]);
                    visited[parentof[curr]]=true;
                }
            }
            dis++;
        }

        vector<int> res;
        while(!q.empty()){
            TreeNode* node = q.front();q.pop();
            res.push_back(node->val);
        }

        return res;
    }
};