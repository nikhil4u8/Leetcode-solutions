vector<int> preorder(TreeNode* root){
    vector<int>ans;
    stack<TreeNode*>sta;
    TreeNode* p = NULL;

    while(!sta.empty() && p){
        if(p){
            sta.push(p);
            ans.push_back(p->val);
            p = p->left;
        }else{
            p = sta.top()->right;
            sta.pop();
        }
    }
}

vector<int> inorder(TreeNode* root){
    vector<int>ans;
    stack<TreeNode*>sta;
    TreeNode* p = NULL;

    while(!sta.empty() && p){
        if(p){
            sta.push(p);
            p = p->left;
        }else{
            ans.push_back(p->val);
            p = sta.top()->right;
            sta.pop();
        }
    }
}

vector<int> postorder(TreeNode* root){
    vector<int>ans;
    stack<TreeNode*>sta;
    TreeNode* p = NULL;

    while(!sta.empty() && p){
        if(p){
            sta.push(p);
            ans.addbegin(p->val);
            p = p->right;
        }else{
            p = sta.top()->left;
            sta.pop();
        }
    }
}