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
    int cnt =1;
    void dfs (TreeNode* root ,int max){
        if(root ==nullptr)
            return ;
        if(root->left != nullptr){
        if((root->left->val)>=max){
            cnt++;
            dfs(root->left,(root->left->val));
        }
        else {
            dfs(root->left,max);
        }
        }
        if(root->right !=nullptr){
        if((root->right->val)>=max){
            cnt++;
            dfs(root->right,root->right->val );
        }
        else {
            dfs(root->right,max);
        }
        }
        
    }
    int goodNodes(TreeNode* root) {
        dfs(root,root->val);
        return cnt;
    }
};