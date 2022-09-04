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
    vector<tuple<int,int,int>>vec;
    //col -- row -- val
    void dfs (TreeNode* root , int row,int col){
        if(!root)
             return;
        vec.push_back({col, row, root->val});
        dfs(root->left,row+1,col-1);
        dfs(root->right,row+1,col+1);
    }
    vector<vector<int>> verticalTraversal(TreeNode* root) {
        dfs(root,0,0);
        sort(vec.begin(),vec.end());
        vector<vector<int>>ans;
        int tmp = -900000;
        vector<int>tmp_vec;
        for(int i=0;i<vec.size();i++){
            if ( get<0>(vec[i]) != tmp ){
                tmp = get<0>(vec[i]);
                if(!tmp_vec.empty()){
                    ans.push_back(tmp_vec);
                    tmp_vec.clear();
                }
                tmp_vec.push_back(get<2>(vec[i]));
            }
            else {
                tmp_vec.push_back(get<2>(vec[i]));
            }
        }
        if(!tmp_vec.empty()){
                ans.push_back(tmp_vec);
                tmp_vec.clear();
            }
        return ans;
    }
};