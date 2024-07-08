/*
Sol :
    - Traversing nestedList and checking if each element in list is 
    integer or not, meanwhile keeping track of depth too.
        - If ith idx is integer then add it to sum (depth*nestedList[i]
        .getInteger())       
        - Else get the nested list at ith idx and recrusively call the 
        fun again to find sum of nested list at ith idx along with keeping 
        track of depth
*/
class Solution {
public:
//TIME - O(N) SPACE - O(depth) -> recursive stack
//-> N is total number of nested elements in list
    int depthSum(vector<NestedInteger>& nestedList, int depth = 0) {
        int sum = 0;
        depth++;

        for(int i=0;i<nestedList.size();i++){
            if(nestedList[i].isInteger()) sum += depth*nestedList[i].getInteger();
            else sum += depthSum(nestedList[i].getList(), depth);
        }

        return sum;
    }
};