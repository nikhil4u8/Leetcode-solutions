/*
// Definition for a Node.
class Node {
public:
    int val;
    vector<Node*> children;

    Node() {}

    Node(int _val) {
        val = _val;
    }

    Node(int _val, vector<Node*> _children) {
        val = _val;
        children = _children;
    }
};
*/

class Codec {
public:
    // Encodes a tree to a single string.
    string serialize(Node* root) {
        if(!root) return "#";
        
        string res = to_string(root->val) + ",#";
        queue<Node*>q;
        q.push(root);
        
        while(!q.empty()){
            int size = q.size();
            while(size--){
                Node* temp = q.front(); q.pop();
                
                for(int i=0;i<temp->children.size();i++){
                    res += "," + to_string(temp->children[i]->val);
                    q.push(temp->children[i]);
                }
                res += ",#";
            }
        }
        return res;
    }
	
    // Decodes your encoded data to tree.
    int idx = 0;
    int filter(string data){
        int val = 0;
        while(idx<data.length() && data[idx] != ',') val = val*10 + (data[idx++]-'0');
        idx++;
        return val;
    }
    Node* deserialize(string data){
        if(data[idx] == '#') return NULL;
        
        Node* root = new Node(filter(data));
        idx+=2;
        
        queue<Node*>q;
        q.push(root);
        
        while(!q.empty()){
            int size = q.size();
            while(size--){
                Node* child = q.front(); q.pop();
                
                while(data[idx] != '#'){
                    Node* temp_child = new Node(filter(data));
                    child->children.push_back(temp_child);
                    if(!temp_child) break;
                    q.push(temp_child);
                }
                
                idx+=2;
            }
        }
        
        return root;
    }
};