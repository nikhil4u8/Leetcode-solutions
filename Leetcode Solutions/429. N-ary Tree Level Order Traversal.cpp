class Solution {
public:
    vector<vector<int>> levelOrder(Node* root) {
        if(!root) return {};
        
        vector<vector<int>>ans;
        queue<Node*>q;
        q.push(root);
        
        while(!q.empty()){
            int size = q.size();
            vector<int>tt;
            while(size--){
                Node* temp = q.front();
                q.pop();
                
                tt.push_back(temp->val);
                
                for(int i=0;i<temp->children.size();i++){
                    Node* child = temp->children[i];
                    q.push(child);
                }
            }
            ans.push_back(tt);
        }
        
        return ans;
    }
};