/*
Ques to ask : Empty tree? High and low inclusive or not?

Sol : 
    - Traverse tree via DFS / BFS & if root->val falls b/w low / high
    then add it in sum & find sum of left / right subtree recursively
    and add it to sum & return sum

Follow up:
    - Get the average not sum
    - Quering RangeSumBST fun multiple time with different low/high val. Optimize it?
    - New elements (distinct unique numbers) are inserted into the 
    tree, how to get rangeSumBST(low, high) quickly?
*/
class Solution {
public:
//TIME - O(N) SPACE - O(N) -> recursive stack
//Recursive
    int rangeSumBST(TreeNode* root, int low, int high) {
        if(!root) return 0;

        int sum = 0;
        if(root->val >= low && root->val <= high) sum += root->val;
        return sum + 
                rangeSumBST(root->right, low, high) + 
                rangeSumBST(root->left, low, high);
    }
//Iterative
    int rangeSumBST(TreeNode* root, int low, int high) {
        int ans = 0;
        stack<TreeNode*> stack;
        stack.push(root);

        while (!stack.isEmpty()) {
            TreeNode* node = stack.pop();
            if (node != null) {
                if (low <= node.val && node.val <= high)
                    ans += node.val;
                if (low < node.val)
                    stack.push(node.left);
                if (node.val < high)
                    stack.push(node.right);
            }
        }
        return ans;
    }
};

//Follow up
//Get average
void sum_count(tree *root, int &sum, int &count){
    if(root != NULL){
        sum += root->value;
        count++;
        sum_count(root->left, sum, count);
        sum_count(root->right, sum, count);
    }
}
double avg(tree *root){
    int sum=0, count=0;
    sum_count(root, sum, count);
    return (double)sum / count;
}