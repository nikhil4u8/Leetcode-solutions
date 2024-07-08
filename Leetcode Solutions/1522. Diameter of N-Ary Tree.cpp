class Solution {
public:
    int ans = 0;
    int longestPath(Node* root){
        if(!root) return 0;

        int maxLen1 = 0, maxLen2 = 0;
        for(int i=0;i<root->children.size();i++){
            int len = longestPath(root->children[i]);
            
            if(maxLen1 == 0) maxLen1 = len;
            else if(maxLen2 == 0){
                if(len > maxLen1){
                    maxLen2 = maxLen1;
                    maxLen1 = len;
                }else maxLen2 = len;
            }else{
                if(len > maxLen1){
                    maxLen2 = maxLen1;
                    maxLen1 = len;
                }else if(len > maxLen2) maxLen2 = len;
            }
        }

        ans = max(ans, maxLen1 + maxLen2);
        return 1 + maxLen1;
    }
    int diameter(Node* root) {
        cout<<longestPath(root);
        return ans;
    }
};