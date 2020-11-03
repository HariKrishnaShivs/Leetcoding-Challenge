class Solution {
public:
    TreeNode*prev = nullptr ;
    TreeNode*first = nullptr ;
    TreeNode*last = nullptr ;
    void recoverTree( TreeNode* root ) {
        solve(root);
        swap(first->val , last->val );
    }
    void solve(TreeNode*root){
        if(root == nullptr) return ; 
        solve(root->left) ;
        if(prev != nullptr ){
            if(prev->val > root->val ){
                if(first == nullptr ){
                    first = prev ;
                }
                last = root ;
            }
        }
        prev = root ;
        solve(root->right);
    }
};