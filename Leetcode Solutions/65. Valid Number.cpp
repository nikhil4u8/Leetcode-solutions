/*
Ques to ask:
    - Are number with leading zero valid? Ex: "008"
    - Does str contains spaces too?
    - Is empty str valid?
    - Is "4.", ".4", "-.4" valid?
    - Is "-e", "-.e", "-e.", "e3", "3e4e", "-.e5" valid?
    - Is "." valid?

Edge case :
    - "+.", ".+", "..", ".", "3e4e", "e3", "3ee", "-.e", "+e.", "e", 
    "5-e95". "99e2.5", "+-6".

Sol :
=> Following the rules : [TIME - O(N) SPACE - O(1)]
    - Traverse the str & remove all leading / trailing spaces
    - Count how many e is there in the string.
        - If count of E >= 2, then string is invalid i.e return false
        - If count of E == 1, then check if left str of E must be a 
        "decimal or integer" string & right str must be "interger" string
        - If count of E == 0, then check if whole string is a valid 
        "integer or decimal" string
*/
class Solution {
public:
    bool isValidIntNum(string s){
        if(s == "") return false;
        int i = 0;
        //skip the first sign
        if(s[i] == '+' || s[i] == '-') i++;
        
        while(i < s.length()){
            //if found any other char then return false
            //sign char is already skipped
            if(!(s[i] >= '0' && s[i] <= '9')) return false;
            i++;
        }
        //string must not be "+" || "-"
        return s != "+" && s != "-";
    }

    bool isValidDecimalNum(string s){
        if(s == "") return false;

        int i = 0, countNumAfterDecimal = 0, countNumBeforeDecimal = 0;
        bool decimalFound = false;
        //skip the first sign
        if(s[i] == '+' || s[i] == '-') i++;

        while(i < s.length()){
            //if found any other char except [0..9], "." then return false
            if(!((s[i] >= '0' && s[i] <= '9') || s[i] == '.')) return false;
            //found multiple "." in str
            if(s[i] == '.' && decimalFound) return false;
            //if "." is found then marking decimalFound as true & counting 
            //number before & after decimal, we should have either of 
            //them > 0
            if(s[i] == '.') decimalFound = true;
            else if(!decimalFound) countNumBeforeDecimal++;
            else if(decimalFound) countNumAfterDecimal++;
            i++;
        }
        
        //here decimal should be found & it should have atleast one number 
        //either before or after decimal
        return decimalFound && 
               (countNumBeforeDecimal>0 || countNumAfterDecimal>0);
    }

    bool isValidENum(string s){
        int i = 0;

        //checking if (before e) str can be a "digit or "integer" & 
        //(after e) str must be a "integer" 
        while(i < s.length()){
            if(s[i] == 'e' || s[i] == 'E') break;
            i++;
        }

        return (isValidIntNum(s.substr(0, i)) || 
                isValidDecimalNum(s.substr(0, i))) && 
                isValidIntNum(s.substr(i+1));
    }

    bool isNumber(string s) {
        int countE = 0;

        //counting number of "e"
        for(int i = 0;i<s.length();i++){
            if(s[i] == 'E' || s[i] == 'e') countE++;
        }

        if(countE >= 2) return false;
        if(countE == 1) return isValidENum(s);

        return isValidIntNum(s) || isValidDecimalNum(s); 
    }
};