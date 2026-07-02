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
     bool isleaf(TreeNode* root){
         if(!root->right && !root->left) return true;
         return false;
     }
     void leafpath(TreeNode* root,vector<vector<int>>&res,vector<int> &state){
         if(!root) return;
         
         state.push_back(root->val);
         
         if(isleaf(root)) {
            res.push_back(state); 
            state.pop_back();
            return;
         }
         
         leafpath(root->left,res,state);
         leafpath(root->right,res,state);
         
         state.pop_back();
         return;
     }
    vector<string> binaryTreePaths(TreeNode* root) {
        vector<int> state;
        vector<vector<int>> paths;
        vector<string> res;
        leafpath(root,paths,state);
        
        for(auto& p:paths){
            string s = "";
            for(int i = 0;i<p.size()-1;i++){
                
                s = s + to_string(p[i]) +'-'+'>';
            }
            s = s + to_string(p.back());
            res.push_back(s);
        }
        return res;
        
    }
};