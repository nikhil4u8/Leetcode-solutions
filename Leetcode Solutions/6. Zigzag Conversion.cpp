class Solution {
public:
    //Time - O(s.length()) SPACE - O(numRow*s.length())
    //Create a array of char filled with '#' and fill according to the pattern
    //then traverse zugzag vector row wise and add all non '#' char in string res
    string convert(string s, int numRows) {
        if(numRows == 1) return s;
        
        vector<vector<char>>zigzag(numRows,vector<char>(s.length(),'#'));
        
        int i=0;
        int row = 0,col = 0;
        
        while(i<s.length()){
            while(i<s.length() && row<numRows) zigzag[row++][col] = s[i++];
           
            row-=2;
            col++;
            
            while(i<s.length() && row>=0 && col<s.length()) zigzag[row--][col++] = s[i++];
            row = 1;
            col--;
        }
        
        string res = "";
        
        for(int i=0;i<zigzag.size();i++){
            for(int j=0;j<zigzag[i].size();j++){
                if(zigzag[i][j] != '#')  res += zigzag[i][j];
            }
        }
        
        return res;
    }
    //TIME - O(s.length()) Space - O(s.length())
    //Instead of a array filled with '#', take a array of string and just add new char to vector[i]
    //then traverse that vector and add all string to ans string
    string convert(string s, int numRows) {
        if(numRows == 1) return s;
        vector<string>storing_string(numRows,"");
        
        int i=0,j=0;
        
        while(j<s.length()){
            while(i<numRows && j<s.length()) storing_string[i++] += s[j++];
            i-=2;
            while(i>=0 && j<s.length()) storing_string[i--] += s[j++];
            i=1;   
        }
        
        string res = "";
        for(int i=0;i<numRows;i++) res += storing_string[i];
        
        return res;
    }
    //TIME - O(N) SPACE - O(1)
    //Period of each cycle i.e num of element in each cycle= 2*numRow - 2
    //In every period, every row has 2 elements, except the first row and the last row
    //Suppose the current row is i, the index of the first element is j:
    //j = i + cycle*k, k = 0, 1, 2, ...
    //(j-i) is the start of current period, (j-i) + cycle is the start 
    //of next period.
    string convert(string s, int nRows) {
        if(nRows <= 1) return s;
        string result = "";
        //the size of a cycle(period)
        int cycle = 2 * nRows - 2;
        for(int i = 0; i < nRows; ++i)
        {
            for(int j=i;j<s.length();j+=cycle){
               result += s[j];
               int secondJ = (j - i) + cycle - i;
               if(i!=0 && i!=nRows-1 && secondJ<s.length())
                   result += s[secondJ];
            }
        }
        return result;
    }

// TIME - O(N) SPACE - O(1)
    string convert(string s, int numRows) {
        if(numRows == 1) return s;

        string res = "";

        for(int i=0;i<numRows;i++){
            int temp = i;
            bool flag = true;
            while(temp < s.length()){
                cout<<temp<<" ";
                res += s[temp];
                if(i == 0 || i == numRows-1) temp += 2*(numRows - 1);
                else{
                    if(flag) temp += 2*(numRows - i - 1);
                    else temp += 2*i;
                    flag = !flag;
                }
            }cout<<"\n";
        }
        
        return res;
    }
};  

***FOLLOW-UP
    1.Convert this encrypted string back to clear text form? (numRow given)

 public:
  String decrypt(String s, int numRows) {
        if(numRows==1) return s;
        int cycle = (numRows-1)*2,len = s.length(),i=0,j=0;
        vector<char>arr(len);

        while(i<len){
            arr[i]=s[j++];
            i+=cycle;
        }
        for(int d=1; d<numRows-1; d++){
            for(i=0; i<len; i+=cycle){
                if(i+d<len) arr[i+d]=s[j++];
                if(i+cycle-d<len) arr[i+cycle-d]=s[j++];
            }
        }
        i=numRows-1;
        while(i<len){
            arr[i]=s[j++];
            i+=cycle;
        }
        string res = "";
        for(int i=0;i<len;i++) res += arr[i];

        return res;
    }