class Solution {
public:
    //TIME - ~O(N^2) SPACE - O(1)
    bool ispalin(string str,int &index){
        int i=0,j=str.length()-1;
        bool flag = false;
        
        while(j>i){
            if(str[i] == str[j]){
                i++;
                j--;
                continue;
            }
            i=0;
            if(index == -1) j = str.length() - 2;
            else j = index - 2;
            index = j+1;
        }
        
        if(index == -1) flag = true;
        
        return flag;
    }
    string shortestPalindrome(string s) {
        int index = -1;
        if(ispalin(s,index)) return s;
        
        string str = s.substr(index);
        reverse(str.begin(),str.end());

        return str + s;
    }
    //TIME - O(N^2) SPACE - O(1)
    string shortestPalindrome(string s) {
        string s2=s;
        reverse(s2.begin(),s2.end());
        int n=s.size(),l;
        for(l=n;l>=0;l--){
            if(s.substr(0,l)==s2.substr(n-l))
                break;
        }
        return s2.substr(0,n-l)+s;
    }
};