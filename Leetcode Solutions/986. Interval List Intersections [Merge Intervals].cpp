/*
Ques to ask :
    - Can list be empty?
    - Are both list sorted?
    - Can we have interval like [1, 1]?

Sol : 
=> MERGE INTERVAL
    - Traverse both list using pointer i, j. i pointing to A list & j 
    pointing to B list.
    - Then compare the interval at ith / jth idx to find if there exist
    any common interval or not & add it to ans vector. 
    - Find the interval having smallest endpoint, this interval won't 
    intersect with anything else, so move the pointer belonging to this 
    list to next interval & like this traverse both list


=> LOGIC
    - The idea is to traverse both list of intervals one by one with two 
    pointers approach. We can have options:
        Here curr = {max(starting_point(a,b)), min(ending_point(a,b))}
        - If we have curr[0] <= curr[1], it means that we have new 
        intersection piece, add it to answer.
        - if A[i][1] <= B[j][1], it means, that we need to move pointer 
        for A, in the opposite case we move pointer for B.
*/
class Solution {
public:
//TIME - O(N+M) SPACE - O(N+M)
    vector<vector<int>> intervalIntersection(vector<vector<int>>& firstList, vector<vector<int>>& secondList) {
        int i=0, j=0, aLen = firstList.size(), bLen = secondList.size();
        vector<vector<int>>ans;

        while(i < aLen && j < bLen){
            vector<int>curr = {max(firstList[i][0], secondList[j][0]), 
                               min(firstList[i][1], secondList[j][1])};

            if(curr[0] <= curr[1]) ans.push_back(curr);
            if(firstList[i][1] <= secondList[j][1]) i++;
            else j++;
        }

        return ans;
    }
};


//TIME - O(N+M) SPACE - O(N+M)
class Solution {
public:
    vector<vector<int>> intervalIntersection(vector<vector<int>>& firstList, vector<vector<int>>& secondList) {
        int i = 0, j = 0;
        vector<vector<int>>ans;
        
        while(i<firstList.size() && j<secondList.size()){
            if(secondList[j][0] <= firstList[i][1] && secondList[j][1] >= firstList[i][0]){
                int start = max(firstList[i][0], secondList[j][0]);
                int end = min(firstList[i][1], secondList[j][1]);
                
                int last_idx = ans.size()-1;
                
                if(last_idx >= 0 && ans[last_idx][1] == start) ans[last_idx][1] = end;
                else ans.push_back({start, end});
            }    
            
            if(firstList[i][1] <= secondList[j][1]) i++;
            else j++;
        }
        
        return ans;
    }
};