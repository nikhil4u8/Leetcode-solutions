class Solution {
public:
    //TIME - O(N)
    //PRE-ORDER
    TreeNode* build(string tra,int pre,int &i){
        if(i>=tra.length()) return NULL;
        
        int n=0,count=0,index=i;
        while(tra[index]=='-' && i<tra.length()){
            count++;
            index++;
        }
        
        if(count<=pre && pre!=0) return NULL;
        
        i = index;
        while(tra[i]!='-' && i<tra.length()){
           n = n*10 + (tra[i]-'0');
           i++;
        }
        
        TreeNode* node = new TreeNode(n);
        
        node->left = build(tra,count,i);
        node->right = build(tra,count,i);
        
        return node;
    }
    TreeNode* recoverFromPreorder(string tra) {
        if(tra.length()==0) return NULL;
        int i=0;
        return build(tra,0,i);
    }
};