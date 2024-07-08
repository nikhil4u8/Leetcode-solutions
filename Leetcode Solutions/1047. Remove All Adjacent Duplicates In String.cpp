/*
Desc : Remove all 2 adjacent duplicates in a string

Ques to ask :
    - Is 'a' & 'A' considered same?
    - Can 's' be a empty string?

Sol :
=> Brute Force : [TIME - O(N^2) SPACE - O(1)]
    - Count repeating adjacent letters & if count >=2 then remove those 
    char from str & then iterate again from starting. Do this until 
    there are no adjacent duplicates remaining.

BEST APPROACH
=> Using Stack : [TIME - O(N) SPACE - O(N)]
    - In the above approach, we re-iterating and recheck already visited 
    char multiple times. So to avoid this we use STACK,to remember what 
    the previous char was.
    - If prev char is same as curr char then remove it & move on to next
    char

Follow up :
    - Remove adjacent >=K elements
        -> When we find a different then check if freq of prev char >= k 
        or not, if it is then remove it completely, else continue 
        traversing. 
    - Remove all adjacent duplicates
        -> Ref : 1047. Remove All Adjacent Duplicates In String
    - Remove all adjacent duplicates >= k
        -> Ref : 1209. Remove All Adjacent Duplicates in String II
*/
class Solution {
public:
    //TIME- O(N) SPACE - O(N)
    string removeDuplicates(string s) {
       stack<char>st;
        for(int i=0;i<s.length();i++){
            if(!st.empty() && s[i]==st.top()) st.pop();
            else st.push(s[i]);
        }
        
        string ans = "";
        while(!st.empty()){
            ans += st.top();
            st.pop();
        }
        reverse(ans.begin(),ans.end());
        return ans;
    }
};