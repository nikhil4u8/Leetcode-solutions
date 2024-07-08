/*
Ques to ask :
    - Tree is Null?
    - Multiple different closest value? Ex: target = 4, node = 3 / 5?
    - Multiple same closest value? like target = 4 & tree has 2 entry of 5?

Sol : 
=> Traversing all nodes : [TIME - O(N) SPACE - O(N)]
    - Just traversing the whole tree and comparing each num to find the 
    closest one. 

BEST APPROACH
=> Eliminating nodes as it's a BST : [TIME - O(N) SPACE - O(logN)]
    - Since it's a BST, so we don't need to traverse whole tree, 
    we just need to find the precedsor / successor of the target node &
    return one of them. 
*/
class Solution {
public:
//Approach 2 : BEST APPROACH
//TIME - O(N) SPACE - O(logN)
    double ret;
    void inorder(TreeNode* root, double target){
        if(!root) return;

        if(abs(target - root->val) <= abs(target - ret)){
            if(abs(target - root->val) == abs(target - ret))
                ret = min(ret, (double)root->val);
            else ret = (double)root->val;
        }

        if((double)root->val > target) inorder(root->left, target);
        else inorder(root->right, target);
    }
    int closestValue(TreeNode* root, double target) {
        ret = root->val;
        inorder(root, target);
        return ret;
    }
//Approach 1
//TIME - O(N) SPACE - O(N)
    void findClosestVal(TreeNode* root, double tar, int &closest_so_far){
        if(!root) return;

        if(abs(root->val - tar) <= abs(closest_so_far - tar)){
            if(abs(root->val - tar) == abs(closest_so_far - tar))
                closest_so_far = min(closest_so_far, root->val);
            else closest_so_far = root->val;
        }

        findClosestVal(root->left, tar, closest_so_far);
        findClosestVal(root->right, tar, closest_so_far);
    }
    int closestValue(TreeNode* root, double target) {
        int closest = INT_MAX;
        findClosestVal(root, target, closest);
        return closest;
    }
};