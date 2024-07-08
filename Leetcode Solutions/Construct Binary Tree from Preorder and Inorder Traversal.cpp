class Solution {
public:
    //TIME - O(N)->map O(N),bulid tree O(N) SPACE - O(N)->hash map & new node
    int index = 0;
    TreeNode* build(vector<int>&pre,vector<int>&in,int start,int end,unordered_map<int,int>&mp){
        if(start>end) return NULL;

        int index_ele = mp[pre[index]];
        
        TreeNode* node = new TreeNode(in[index_ele]);
        index++;
        
        node->left = build(pre,in,start,index_ele-1,mp);
        node->right = build(pre,in,index_ele+1,end,mp);
        
        return node;
    }
    TreeNode* buildTree(vector<int>& preorder, vector<int>& inorder) {
        int n = inorder.size();
        unordered_map<int,int>mp;
        for(int i=0;i<n;i++) mp[inorder[i]] = i;
        return build(preorder,inorder,0,n-1,mp);
    }
};