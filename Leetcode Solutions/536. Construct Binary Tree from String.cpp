/*
Ques to ask :
    - What if we've 4(3)? does this means 4 has left child or right child?
    - Can this be valid input "4()"?
    - Do we've space in string?
    - Does str contains negative num?
    - We've only 1 type of bracket?
    - Is input valid? Like we don't have extra open/close brackets?
    - We just have 2 childrens?

Sol :
BEST APPROACH
=> Recursion - [TIME - O(N) SPACE - O(H) -> H is tree height]
    - Traverse the string, if a digit is found then traverse and find the 
    number & this will root value.
    - If '(' is found on traversing further, that means there exist a 
    subtree, then we'll traverse str & store the substr until we find 
    corresponding ')'.
    - Build subtree by calling str2tree fun recursively and passing 
    subtree substr.
    - If a left child of root is not present then that subtree will be 
    left child else right child
*/
class Solution {
public:
//TIME - O(N) SPACE - O(H) -> H is tree height
    TreeNode* str2tree(string s) {
        if(s.length() == 0) return NULL;

        int root_val = 0, i = 0;
        //creating a new root node
        TreeNode* root = new TreeNode(0);

        while(i < s.length()){
            //a digit is found
            if(s[i] != '('){
                int sign = 1;
                if(s[i] == '-'){ //finding sign of num
                    sign = -1;
                    i++;
                }

                //finding value of digit
                while(i<s.length() && s[i] != '(') 
                    root_val = root_val*10 + (s[i++] - '0');
                root->val = sign * root_val;
            }else{ //a subtree is found
                string child_str = "";
                stack<char>sta;
                sta.push(s[i++]);
                //finding subtree string
                while(!sta.empty() && i<s.length()){
                    if(s[i] == '(') sta.push(s[i]);
                    else if(s[i] == ')') sta.pop();
                    if(sta.empty()){
                        i++;
                        break;
                    }
                    child_str += s[i++];
                }

                //generating subtree recursively 
                TreeNode* subtree = str2tree(child_str);
                //if left child is not present, then subtree will be left child else right child
                if(!root->left) root->left = subtree;
                else root->right = subtree;
            }
        }

        return root;
    }
};