class Solution {
public:
    //TIME - O(N) SPACE - O(N)
    //RECRUSIVE
    TreeNode* mergeTrees(TreeNode* root1, TreeNode* root2) {
        if(!root1 && !root2) return NULL;
        
        if(!root1 && root2) return root2;
        if(root1 && !root2) return root1;
        
        TreeNode* left = mergeTrees(root1->left,root2->left);
        TreeNode* right = mergeTrees(root1->right,root2->right);
        
        root1->val += root2->val;
        root1->left = left;
        root1->right = right;
        
        return root1;
    }
    //TIME - O(N) SPACE - O(N)
    //ITERATIVE
    TreeNode* mergeTrees(TreeNode* t1, TreeNode* t2) {
        if(!t1 && !t2) return nullptr;
        if(!t1 || !t2) return t1? t1:t2;
				
        stack<TreeNode*> s1,s2;
        s1.push(t1);
        s2.push(t2);
        
        while(!s1.empty()){
            TreeNode* c1(s1.top());
            TreeNode* c2(s2.top());
            s1.pop();
            s2.pop();
            
            c1->val+=c2->val;
            
            if(!c1->left && c2->left) c1->left = c2->left;
            else if(c1->left && c2->left) { s1.push(c1->left); s2.push(c2->left); }
            
            if(!c1->right && c2->right) c1->right = c2->right;
            else if(c1->right && c2->right) { s1.push(c1->right); s2.push(c2->right); }
        }
        return t1;
    }
};