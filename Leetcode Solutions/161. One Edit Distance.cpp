/*
Sol :
=> Follow rules : [TIME - O(N) SPACE - O(1)]
    - There are 3 cases
        1. If len(s) > len(t) : Deletion
        2. If len(s) < len(t) : Insertion
        3. If len(s) == len(t) : Replace
*/
class Solution {
public:
    bool isOneEditDistance(string s, string t) {
        int n = s.length(), m = t.length();
        //If difference in len is more than 1 or str are equal then 
        //return false
        if(abs(m - n) > 1 || s == t) return false;

        int i = 0, j = 0;
        bool foundInequality = false;

        while(i < n && j < m){
            if(s[i] != t[j]){
                if(foundInequality) return false;
                foundInequality = true;

                //Case 2 : Insertion so decreasing i
                if(n < m) i--;
                //Case 1 : Deletion so decreasing j
                else if (n > m) j--;
            }
            i++;
            j++;
        }

        return true;
    }
};