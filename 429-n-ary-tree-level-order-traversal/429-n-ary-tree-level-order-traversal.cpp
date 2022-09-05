/*
// Definition for a Node.
class Node {
public:
    int val;
    vector<Node*> children;

    Node() {}

    Node(int _val) {
        val = _val;
    }

    Node(int _val, vector<Node*> _children) {
        val = _val;
        children = _children;
    }
};
*/

class Solution {
public:
    int mx_depth=0;
    vector<pair<int,int>>vec;
    void dfs (Node* root , int depth ){
        if(!root)
            return;
        vec.push_back({depth,root->val});
        mx_depth= max(depth,mx_depth);
        for(auto i:root->children){
            dfs(i,depth+1);
        }
    }
    vector<vector<int>> levelOrder(Node* root) {
        dfs(root,1);
        vector<vector<int>>ans(mx_depth);
        for(auto [k,v]:vec){
            ans[k-1].push_back(v);
        }
        return ans;
    }
};