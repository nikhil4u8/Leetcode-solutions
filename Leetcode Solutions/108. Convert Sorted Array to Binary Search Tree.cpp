class Solution {
public:
    //TIME - O(N) SPACE - O(logN)
    TreeNode* create(vector<int>nums,int l,int r){
        if(l>r) return NULL;
        
        int mid = (l+r)/2;
        TreeNode* node = new TreeNode(nums[mid]);
        
        node->left = create(nums,l,mid-1);
        node->right = create(nums,mid+1,r);
        
        return node;
    }
    TreeNode* sortedArrayToBST(vector<int>& nums) {
         return create(nums,0,nums.size()-1);
    }
};