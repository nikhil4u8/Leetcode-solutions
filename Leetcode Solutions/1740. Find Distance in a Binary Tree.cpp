//TIME - O(N) SPACE - O(H)
//N is total nodes in tree, H is height of tree
class Solution {
public:
    vector<int> path(TreeNode* root, int p){
        if(!root) return {};
        vector<int>ans;
        
        if(root->val == p) return {p};
        
        vector<int>left = path(root->left, p);
        vector<int>right = path(root->right, p);

        ans.push_back(root->val);
        
        if(left.size() != 0) ans.insert(ans.end(), left.begin(),left.end());
        else if(right.size() != 0) ans.insert(ans.end(), right.begin(), right.end());
        if(left.size() != 0 || right.size() != 0) return ans;
        
        return {};
    }
    int findDistance(TreeNode* root, int p, int q) {
        if(!root) return -1;
        
        vector<int>path_p = path(root, p);
        vector<int>path_q = path(root, q);
        
        int i = 0, j = 0;
        
        while(i<path_p.size() && j<path_q.size() && path_p[i] == path_q[j]){
            i++;
            j++;
        }
        
        return (path_p.size()-i) + (path_q.size()-j);
    }
};