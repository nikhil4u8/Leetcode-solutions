class Solution {
public:
//TIME - O((N+M)*no of unique elements) SPACE - O(no of unique elements)
//using Union find to make a tree of char in a grp, and make the parent to be the 
//smallest of all nodes in tree, and then if there is no parent of BaseStr[i], then add it as it as
//otherwise add the parent of grp tree. 
    char find(char s1, vector<int>&parent){
        if(parent[s1 - 'a'] == -1) return s1;
        return find('a' + parent[s1 - 'a'], parent);
    }
    void _union(char s1, char s2, vector<int>&parent){
        char s1_parent = find(s1, parent);
        char s2_parent = find(s2, parent);

        if(s1_parent == s2_parent) return;
        
        int s2_idx = s2_parent - 'a', s1_idx = s1_parent - 'a';

        if(s1_parent > s2_parent) parent[s1_idx] = s2_idx;
        else parent[s2_idx] = s1_idx;
    }
    string smallestEquivalentString(string s1, string s2, string baseStr) {
        vector<int>parent(26, -1);
        int index = 0;

        for(int i=0;i<s1.length();i++){
            _union(s1[i], s2[i], parent);
        }

        string ans = "";
        for(int i=0;i<baseStr.length();i++){
            int idx = baseStr[i] - 'a';
            if(parent[idx] == -1) ans += 'a' + idx;
            else ans += find(baseStr[i], parent);
        }

        return ans;
    }
};