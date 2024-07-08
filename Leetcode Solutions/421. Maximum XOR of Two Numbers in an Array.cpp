// struct Trie{
//     unordered_map<int, Trie*>child;
//     bool isend = false;
// };
// class Solution {
// public:
//     Trie* root;
//     void insert(int num){
//         Trie* temp = root;
        
//         for(int i=31;i>=0;i--){
//             int n = (num>>i)&1;
            
//             if(temp->child.find(n) == temp->child.end())
//                 temp->child[n] = new Trie();
//             temp = temp->child[n];
//         }
//         temp->isend = true;
//     }
//     int findMaxXorWith(int num){
//         Trie* temp = root;
//         int ans_xor = 0;
        
//         for(int i=31;i>=0;i--){
//             int n = ((num>>i)&1) == 1 ? 0 : 1;
            
//             if(temp->child.find(n) == temp->child.end()) n = !n;
//             else ans_xor += 1<<i;
//             temp = temp->child[n];
//         }
        
//         return ans_xor;
//     }
//     int findMaximumXOR(vector<int>& nums) {
//         root = new Trie();
        
//         for(int i=0;i<nums.size();i++)
//             insert(nums[i]);
        
//         int max_xor = 0;
//         for(int i=0;i<nums.size();i++)
//             max_xor = max(max_xor, findMaxXorWith(nums[i]));
        
//         return max_xor;
//     }
// };

class Solution {
public:
    class TreeNode {
    public:
        TreeNode* next[2];
        TreeNode () {next[0] = NULL; next[1] = NULL;};
    };
    TreeNode* buildTree(vector<int>& nums) {
        TreeNode* root = new TreeNode(), *cur;
        int n = nums.size();
        for (int i = 0; i < n; i++) {
            int num = nums[i];
            cur = root;
            for (int j = 31; j >= 0; j--) {
                int index = ((num >> j) & 1);
                if (cur->next[index] ==  NULL)
                    cur->next[index] = new TreeNode();
                cur = cur->next[index];
            }
        }
        return root;
    }
    
    int helper(TreeNode* cur, int num) {
        int res = 0;
        for (int i = 31; i >= 0; i--) {
            int index = ((num >> i) & 1) ? 0 : 1;
            if (cur->next[index]) {
                res <<= 1;
                res |= 1;
                cur = cur->next[index];
            } else {
                res <<= 1;
                res |= 0;
                cur = cur->next[index ? 0 : 1];
            }
        }
        return res;
    }
    
    int findMaximumXOR(vector<int>& nums) {
        int res = 0;
        TreeNode* root = buildTree(nums);
        
        for (auto i : nums) {
            res = max(res, helper(root, i));
        }
        
        return res;
    }
};
