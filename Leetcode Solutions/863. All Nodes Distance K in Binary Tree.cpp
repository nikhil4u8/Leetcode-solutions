/*
Ques to ask:
    - What is target doesn't exist in tree?
    - What if k > tree size?
    - In what order do we need to return ans?
    - What if multiple node have same value as target?
    - Can k == 0?

Sol : 
=> BFS : [TIME - O(N) SPACE - O(N)]
    - For nodes which are below target, we can simply do BFS traversal to find 
    nodes which are k distance away.
    - For nodes which are above target, i.e which are going through target 
    parent, so we can do a BFS / DFS traversal to create a mapping of parent 
    node, then traverse through parent and find nodes which are k distance from 
    target & make sure to search the child of parent node in which target
    isn't present.
*/
class Solution {
public:
    void populateParent(TreeNode* root, unordered_map<TreeNode*, TreeNode*>&parentMap){
        if(!root) return;

        if(root->left) parentMap[root->left] = root;
        if(root->right) parentMap[root->right] = root;

        populateParent(root->left, parentMap);
        populateParent(root->right, parentMap);
    }
    vector<int> distanceK(TreeNode* root, TreeNode* target, int k) {
        if(k == 0) return {target->val};

        vector<int>ans;
        //making parent relationships
        unordered_map<TreeNode*, TreeNode*>parentMap;
        populateParent(root, parentMap);

        int parentStep = 0;
        TreeNode* prevTarget = NULL, *tempTarget = target;

        //doing a downward traversal from target node, then upgrading target 
        //node as it's parent node and doing same downward traversal from it, 
        //do this until we reach root node.
        while(tempTarget){
            queue<TreeNode*>q;
            q.push(tempTarget);
            int steps = parentStep;

            while(!q.empty()){
                int size = q.size();
                while(size--){
                    TreeNode* curr = q.front(); q.pop();

                    //when we're at target node, we just have to make sure that 
                    //target node should not a already traversed child of 
                    //tempTarget.
                    if(steps == k && curr != prevTarget) 
                        ans.push_back(curr->val);
                    else{
                        //if current node is not k steps away from target, 
                        //then push it to queue, make sure it's not already 
                        //traversed child node of tempTarget
                        if(curr->left && curr->left != prevTarget) 
                            q.push(curr->left);
                        if(curr->right && curr->right != prevTarget) 
                            q.push(curr->right);
                    }
                }
                //if steps reached then break loop
                if(steps == k) break;
                steps++;
            }    
            //traversing from parent node of tempTarget.
            parentStep++;
            prevTarget = tempTarget;
            tempTarget = parentMap[tempTarget];
        }  

        return ans;
    }
};