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
    TreeNode* buildTree(vector<int>& inorder,int inStart,int inEnd,
                        vector<int>& postorder,int posStart,int posEnd,
                        unordered_map<int,int>& inmap){
        
        if(inStart>inEnd||posStart>posEnd) return nullptr;

        TreeNode* root = new TreeNode(postorder[posEnd]);
        
        int inRoot = inmap[root->val];
        int inLeft =  inRoot - inStart;

        root->left = buildTree(inorder,inStart,inRoot-1,
                               postorder,posStart,posStart+inLeft-1,inmap);

        root->right = buildTree(inorder,inRoot+1,inEnd,
                                postorder,posStart+inLeft,posEnd-1,inmap);
        return root;

        }
    TreeNode* buildTree(vector<int>& inorder, vector<int>& postorder) {
        unordered_map<int,int> inmap;
        for(int i = 0;i<inorder.size();i++){
            inmap[inorder[i]]=i;
        }

        TreeNode* root = buildTree(inorder,0,inorder.size()-1,
                                    postorder,0,postorder.size()-1,inmap);

        return root;
    }
};