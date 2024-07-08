**FOLLOW-UP
    1.Do it in costant space
//APPROACH-1
// for example, s = 'cdadabcc', s contains a, b, c, d
// index['a'] = [2, 4]
// index['b'] = [5]
// index['c'] = [0, 6, 7]
// index['d'] = [1, 3]

// which will be the first letter in ans?
// it will be letter 'a', cause 2 < min(5, 7, 3), (5,7,3) is the last index of other letters

// after append 'a', now the index becomes
// index['b'] = [5]
// index['c'] = [6, 7]
// index['d'] = [3]
// we delete all index less than 2
// obviously, the next letter will be 'd'.
// analyse one by one.

//APPROACH-2
class Solution {
public:
    //TIME - O(N) SPACE-O(N)
    //Using stack + frequency vector + visited vector.
    //If coming char is visited before then decrease its frequency and continue to next char.
    //We'll only fill stack in lexicographically order and when we encounter lexicographically low 
    //char then start poping out the characters from stack to maintain lexicographical order but also 
    //check if frequency of that char > 0 so that we can;t miss that char in ans.
    //After traversing pop out char from stack into string  -> reverse string -> return it
    string smallestSubsequence(string s) {
        vector<int>freq(26,0);
        vector<bool>visited(26,false);
        stack<char>sta;
        
        for(int i=0;i<s.length();i++) freq[s[i]-'a']++;
        
        for(int i=0;i<s.length();i++){
            freq[s[i]-'a']--;
            if(visited[s[i]-'a']) continue;
            
            //if asked to do in O(1) space then replace below part with
            /*
            while(res.length()>0 && res.back() > s[i] && freq[res.back()-'a']>0){
                visited[res.back()-'a'] = false;
                res.pop_back();
            }
            visited[s[i]-'a'] = true;
            res += s[i];
            */
            while(!sta.empty() && sta.top()>s[i] && freq[sta.top()-'a']>0){
                visited[sta.top()-'a'] = false;
                sta.pop();
            }
          
            visited[s[i]-'a'] = true; 
            sta.push(s[i]);
        }
        
        string res = "";
        while(!sta.empty()){
            res += sta.top();
            sta.pop();
        }
        
        reverse(res.begin(),res.end());
        return res;
    }
};