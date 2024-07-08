class Solution {
public:
    //INORDER  => LDR
    //PREORDER => DLR
    //first element of preorder is mid of inorder
    TreeNode* generate_tree(vector<int>&preorder, unordered_map<int,int>&mp, int start, int end, int &index){
        if(start > end) return NULL;
        
        TreeNode* root = new TreeNode();
    
        root->val = preorder[index++];
        int mid = mp[root->val];
        
        root->left = generate_tree(preorder,mp,start, mid-1, index);
        root->right = generate_tree(preorder,mp,mid+1, end, index);
        
        return root;
    }
    TreeNode* buildTree(vector<int>& preorder, vector<int>& inorder) {
        if(preorder.size() == 0) return NULL;
        
        unordered_map<int,int>mp;
        for(int i=0;i<inorder.size();i++) mp[inorder[i]] = i;
        
        int len = preorder.size(), index=0;
        
        return generate_tree(preorder,mp,0,len-1,index);
    }
};