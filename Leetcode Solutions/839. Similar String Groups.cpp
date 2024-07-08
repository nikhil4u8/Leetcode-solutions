class UnionFind{
    public:
        int size = 0;
        unordered_map<string, string>parent;
        UnionFind(int n){
            size = n;
        }
        string find(string str){
            if(parent[str] == "") return str;
            return find(parent[str]);
        }
        void _union(string s1, string s2){
            string s1_parent = find(s1);
            string s2_parent = find(s2);
            
            if(s1_parent == s2_parent && s1_parent != "") 
                return;
            parent[s1_parent] = s2_parent;
            size--;
        }
};
class Solution {
public:
    int isSimilar(string str1, string str2){
        if(str1.length() != str2.length())
            return false;
        int count = 0;
        for(int i=0;i<str1.length();i++){
            if(str1[i] != str2[i])
                count++;
        }
        return count;
    }
    int numSimilarGroups(vector<string>& strs) {
        int n = strs.size();
        
        UnionFind uf(n);
            
        for(int i=0;i<n;i++){
            string str1 = strs[i];
            bool is_same = false;
            for(int j=i-1;j>=0;j--){
                string str2 = strs[j];
                
                int count = isSimilar(str1, str2);
                if(count == 2) uf._union(str1, str2);
                else if(count == 0) is_same = true;
            }
            if(is_same) uf.size--;
        }
        
        return uf.size;
    }
};