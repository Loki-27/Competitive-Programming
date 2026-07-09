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
class BSTIterator {
    stack<TreeNode*> st;
    TreeNode* Node;
public:

    BSTIterator(TreeNode* root) {
        Node = root;
    }
    
    int next() {
        int nex;
        while(true){
            if(Node){
                st.push(Node);
                Node = Node->left;
            }
            else{
                if(st.empty()) break;
                Node = st.top();st.pop();
                nex = Node->val;
                Node = Node->right;
                break;
            }
        }
        return nex;
    }
    
    bool hasNext() {
        if(st.empty() && !Node) return false;
        return true;
    }
};

/**
 * Your BSTIterator object will be instantiated and called as such:
 * BSTIterator* obj = new BSTIterator(root);
 * int param_1 = obj->next();
 * bool param_2 = obj->hasNext();
 */