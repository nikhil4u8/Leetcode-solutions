class Solution {
public:
    //RECRUSIVE
    //TIME - O(N) SPACE - O(N)->recursive stack 
    vector<int>ans;
    void inorder(TreeNode* root){
        if(!root) return;
        
        inorder(root->left);
        ans.push_back(root->val);
        inorder(root->right);
    }
    vector<int> inorderTraversal(TreeNode* root) {
        inorder(root);
        return ans;
    }
    //ITERATIVE USING STACK
    //TIME - O(N) SPACE - O(N)
    vector<int>inorderTraversal(TreeNode* root){
        stack<TreeNode*>sta;
        TreeNode* curr = root;
        vector<int>ans;
        
        while(!sta.empty() || curr){
            if(curr){
                sta.push(curr);
                curr = curr->left;
            }else{
                ans.push_back(sta.top()->val);
                curr = sta.top()->right;
                sta.pop();
            }
        }
        return ans;
    }
    //MORRIS TRAVERSAL
    //TIME - O(N) SPACE - O(1)
    vector<int>inorderTraversal(TreeNode* root){
        vector<int>ans;
        TreeNode* curr = root;
        
        while(curr){
            if(curr->left){
                TreeNode* temp = curr->left,*temp2=curr->left;
                while(temp->right) temp = temp->right;
                
                temp->right = curr;
                curr->left = NULL;
                curr = temp2;
            }else{
                ans.push_back(curr->val);
                curr = curr->right;
            }
        }
        
        return ans;
    }
};
