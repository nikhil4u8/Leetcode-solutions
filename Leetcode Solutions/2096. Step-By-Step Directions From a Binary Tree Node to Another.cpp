class Solution {
public:
    //Traversing the whole tree and finding path from root to start/end val and then removing the common path from start_path, end_path and output = p1+p2
//     void check_tree(TreeNode* root, int start_val, int end_val, string &p1, string &p2,string t1, string t2){
//         if(!root) return;
        
//         if(root->val == start_val) p1 = t1;
//         if(root->val == end_val) p2 = t2;
        
//         check_tree(root->left, start_val, end_val, p1, p2, t1+'L', t2+'L');
//         check_tree(root->right, start_val, end_val, p1, p2, t1+'R', t2+'R');
//     }
//     string getDirections(TreeNode* root, int startValue, int destValue) {
//         if(!root) return "";
        
//         string p1 = "", p2 = "";
//         check_tree(root, startValue, destValue, p1, p2, "", "");
        
//         int index = 0;
//         while(index<p1.length() && index<p2.length() && p1[index] == p2[index]) index++;
        
//         p1 = p1.substr(index);
//         p2 = p2.substr(index);
        
//         for(int i=0;i<p1.length();i++) p1[i] = 'U';
        
//         return p1+p2;
//     }
    TreeNode* LowestCommonAncestor(TreeNode* root, int start_val, int end_val){
        if(!root) return NULL;
        
        if(root->val == start_val || root->val == end_val) return root;
        
        TreeNode* left = LowestCommonAncestor(root->left, start_val, end_val);
        TreeNode* right = LowestCommonAncestor(root->right, start_val, end_val);
        
        //start or end is in left and right
        if(left && right) return root;
        //start_val and end_val doesn't exist
        if(!left && !right) return NULL; 
            
        return left ? left : right;
    }
    bool DFS(TreeNode* root, int node, string &path){
        if(!root) return false;
        
        if(root->val == node) return true;
        
        path += 'L';
        if(DFS(root->left, node, path))
            return true;
        path.pop_back();
        
        path += 'R';
        if(DFS(root->right, node, path))
            return true;
        path.pop_back();
        
        return false;
    }
    string getDirections(TreeNode* root, int startValue, int destValue) {
        TreeNode* lca = LowestCommonAncestor(root, startValue, destValue);
        
        string path_1 = "", path_2 = "";
        DFS(lca, startValue, path_1);
        for(int i=0;i<path_1.length();i++) path_1[i] = 'U';
        DFS(lca, destValue, path_2);
        
        return path_1 + path_2;
    }
};