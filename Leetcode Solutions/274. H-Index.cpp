/*
Template - Clarifying Ques -> Approach desc -> Code for approach -> Follow-ups
*/
/*
Clarifying Ques - 1. What exactly is H index?
                  2. Is it possible to have multiple H index?
                  3. If there are many H index value then what should I take?
*/
/*
Approach - H index is that there are H papers whose citations are greater than equal to H. 
Ex - [12, 10, 8, 4, 3] 
    -> H = 1 - there are atleast 1 paper whose citation is >=1 [12,10,8,4,3]    --> true
    -> H = 2 - there are atleast 2 paper whose citation is >=2 [12,10,8,4,3]    --> true
    -> H = 3 - there are atleast 3 paper whose citation is >=3 [12,10,8,4,3]    --> true
    -> H = 4 - there are atleast 4 paper whose citation is >=4 [12,10,8,4]      --> true
    -> H = 5 - there are atleast 3 paper whose citation is >=5 [12,10,8]        --> false
    
    --> Hence highest H index possible is 4
*/
class Solution {
public:
    //TIME - O(NlogN) SPACE - O(1)
//     int hIndex(vector<int>& citations) {
//         sort(citations.rbegin(), citations.rend());
//         int n = citations.size();

//         for(int i=0;i<n;i++){
//             if(citations[i] >= i+1) continue; // i paper having citations >=i
//             return i;    
//         }
        
//         return n;
//     }
    //TIME - O(N) SPACE - O(N)
    int hIndex(vector<int>& citations) {
        unordered_map<int,int>hash;
        int n = citations.size();
        
        for(int i=0;i<citations.size();i++){
            if(citations[i] >= n) hash[n]++;
            else hash[citations[i]]++;
        }
        
        int paper = 0;
        for(int i=n;i>=0;i--){
            paper += hash[i];
            if(paper >= i) return i;
        }
        return 0;
    }
};