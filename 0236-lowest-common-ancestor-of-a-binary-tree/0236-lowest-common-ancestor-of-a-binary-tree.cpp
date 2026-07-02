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
        if(root==NULL || root==p|| root==q){
            return root;
        }

        TreeNode* left = lowestCommonAncestor(root->left,p,q);
        TreeNode* right = lowestCommonAncestor(root->right,p,q);

        if(left==NULL) return right;
        else if(right==NULL) return left;
        else return root;
    }
};



// class Solution {
// public:
//         bool isnode(TreeNode* root,vector<TreeNode*>& path,int x){
//             if(root==NULL) return false;

//             path.push_back(root);

//             if(root->val==x) return true;

//             if(isnode(root->left,path,x) || 
//                 isnode(root->right,path,x)) return true;

//             path.pop_back();
//             return false;
//         }

//         bool isnode2(TreeNode* root,int x){
//             if(root==NULL) return false;

//             if(root->val==x) return true;

//             if(isnode2(root->left,x) || 
//                 isnode2(root->right,x)) return true;

//             return false;
//         }


//     TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
//         vector<TreeNode*> pathp;
//         isnode(root,pathp,p->val);

//         for(int i = pathp.size()-1;i>=0;i--){
//             if(isnode2(pathp[i],q->val)) return pathp[i];
//         }

//         return root;


//     }
// };