/*
TIME - O(NlogN) SPACE - O(max node in a level)

Ques to ask :-
    - Val of K start from 0/1?
    - what if k>n

Sol :- Level order traversal
*/
class Solution {
    public:
        long long kthLargestLevelSum(TreeNode* root, int k) {
            priority_queue<long long, vector<long long>, greater<long long>>pq;
            queue<TreeNode*>q;
            q.push(root);
    
            while(!q.empty()){
                int size = q.size();
                long long int levSum = 0;
                while(size--){
                    TreeNode* curr = q.front();
                    q.pop();
    
                    if(curr->left) q.push(curr->left);
                    if(curr->right) q.push(curr->right);
    
                    levSum += curr->val;
                }
    
                pq.push(levSum);
                if(pq.size() > k) pq.pop();
            }
    
            if(k > pq.size()) return -1;
            return pq.top();
        }
    };