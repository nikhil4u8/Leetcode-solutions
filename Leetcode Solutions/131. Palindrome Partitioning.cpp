class Solution {
public:
// TIME - O(N*2^N) SPACE - O(N)
// In worst case every substring can be a palindrome ("aaa"), so 
// there are 2^N possible substr and each str takes O(N) time to generate
// hence 2^N*N is time complexity
    vector<vector<string>>ans;
    bool isPal(string str){
        int i = 0, j = str.length()-1;
        while(i < j){
            if(str[i] != str[j]) return false;
            i++;
            j--;
        }
        return true;
    }
    void generatePartition(string s, int idx, 
                           string temp, vector<string>temp_str){
        if(idx == s.length()){
            if(temp != "" && isPal(temp)){
                temp_str.push_back(temp);
                ans.push_back(temp_str);
            }
            return;
        }

        if(temp != "" && isPal(temp)){
            generatePartition(s, idx+1, temp+s[idx], temp_str);
            temp_str.push_back(temp);
            temp = "";
        }

        temp += s[idx];
        generatePartition(s, idx+1, temp, temp_str);
    }
    vector<vector<string>> partition(string s) {
        generatePartition(s, 0, "", {});
        return ans;
    }
};