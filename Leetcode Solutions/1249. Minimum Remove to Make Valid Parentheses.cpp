/*
Ques to ask : 
    - Does string have only one kind of paranthesis?
    - What if we've multiple valid string then which one to return?

Sol :
=> Using Stack - [TIME - O(N) | SPACE - O(N)]
    - Use a stack to store {paranthesis, index}
    - Remove top element from stack if a pair '()' is found
    - Traverse the str in backward, and skip all idx present in stack &
    store rest of the str in ans & reverse it & return it.
    
=> Without Stack [Two Pointer, applicable for multiple brackets too]
[TIME - O(N) SPACE - O(1) | str space = O(N))]

    - Maintaining 2 counter i.e opening / closing bracket which will keep
    track of count of opening / closing bracket until idx i
    - First traverse the str in forward dir & maintaining the rule that 
    open_bracket >= close_bracket, if this rules voilate at ith idx, then 
    skip that char & store rest of str (removing unnecessary close bracket)
    - Repeat the above step & traverse in bakward dir & remove all 
    unecessary open brakcets not & return string.
    - In case of multiple bracket, we need to call removeInvalidClosingBrackets
    fun for every bracket type.

Follow up : 
    - Do it without using stack?
    - What if there are 2 or more brackets? 
        -> use Two pointer method for every bracket or use stack method
*/
class Solution {
public:
//BEST APPROACH
//FOLLOW UP -> WITHOUT STACK
//Using Two Pointer
//TIME - O(N) SPACE - O(N) [space used in creating string]
    string removeInvalidClosingBrackets(string s, char open, char close){
        string ans = "";
        int n = s.length(), count = 0;
        for(int i=0;i<s.length();i++){
            if(s[i] == open) count++;
            else if(s[i] == close){
                if(count == 0) continue;
                count--;
            }
            ans += s[i];
        }
        return ans;
    }
    string minRemoveToMakeValid(string s) {
        s = removeInvalidClosingBrackets(s, '(', ')');        
        reverse(s.begin(), s.end());
        s = removeInvalidClosingBrackets(s, ')', '(');
        reverse(s.begin(), s.end());

        return s;
    }

//Using Stack
    //TIME - O(N) SPACE - O(N)
    string minRemoveToMakeValid(string s) {
        int n = s.length();
        stack<pair<char, int>>sta;
        string ans = "";

        for(int i=0;i<n;i++){
            if(s[i] == '(') sta.push({s[i], i});
            else if(s[i] == ')'){
                if(!sta.empty() && sta.top().first == '(') sta.pop();
                else sta.push({s[i], i});
            }
        }

        for(int i=n-1;i>=0;i--){
            if(!sta.empty() && sta.top().second == i) sta.pop();
            else ans += s[i];
        }

        reverse(ans.begin(), ans.end());
        return ans;
    }
};