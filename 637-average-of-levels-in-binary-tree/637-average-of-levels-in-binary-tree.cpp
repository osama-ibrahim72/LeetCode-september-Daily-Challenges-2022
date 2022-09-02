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
    static const int N = 1e4 + 10;
    vector<int>nodes[N];
    void dfs(TreeNode* root,int depth){
        if (!root)
            return;
        int val = root->val;
        nodes[depth].push_back(val);
        dfs(root->left,depth+1);
        dfs(root->right,depth+1);
    }
    vector<double> averageOfLevels(TreeNode* root) {
        vector<double>ans;
        dfs(root,0);
        for(int i=0;i<N;i++){
            if(nodes[i].size()>0){
                double tmp =0; 
                for (auto j: nodes[i]){
                    tmp +=j;
                }
                tmp/=nodes[i].size();
                ans.push_back(tmp);
            }
            else 
                break;
        }
        return ans;
    }
};