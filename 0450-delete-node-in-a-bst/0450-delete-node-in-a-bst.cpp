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

    TreeNode* findSuccesor(TreeNode* root){
            TreeNode* curr = root->right;
            while(curr && curr->left){
                curr = curr->left;
            }
            return curr;
    }
    
    TreeNode* deleteNode(TreeNode* root, int key) {
        if(!root) return root;

        if(root->val>key){
            root->left = deleteNode(root->left,key);
        }
        else if(root->val<key){
            root->right = deleteNode(root->right,key);
        }
        else{
            if(root->left==nullptr){
                TreeNode* tmp = root->right;
                delete root;
                return tmp;
            }
            if(root->right==nullptr){
                TreeNode* tmp = root->left;
                delete root;
                return tmp;
            }

            TreeNode* succ = findSuccesor(root);
            root->val = succ->val;
            root->right = deleteNode(root->right,succ->val);
        }

        return root;
    }
};