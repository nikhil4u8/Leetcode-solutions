/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class Codec {
public:
    int i=0;
    // Encodes a tree to a single string.
    string serialize(TreeNode* root) {
        if(!root) return "#";
        return to_string(root->val)+","+serialize(root->left)+","+serialize(root->right);
    }
    int create_node(string data){
        int val = 0,sign=1;
        if(data[i] == '-'){
            sign = -1;
            i++;
        }
        
        while(i<data.length() && data[i]!=',') val = val*10 + (data[i++]-'0');
        
        return val*sign;
    }
    // Decodes your encoded data to tree.
    TreeNode* deserialize(string data){
        if(data[i] == '#'){
            i++;
            return NULL;
        }
        
        TreeNode* node = new TreeNode();
        node->val = create_node(data);
        
        i++;
        if(i<data.length()) node->left = deserialize(data);
        i++;
        if(i<data.length()) node->right = deserialize(data);
        
        return node;
    }
};

// Your Codec object will be instantiated and called as such:
// Codec ser, deser;
// TreeNode* ans = deser.deserialize(ser.serialize(root));