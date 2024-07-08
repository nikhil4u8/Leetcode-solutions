/*
Ques to ask:
    - Are negative numbers allowed?
    - What's the range of num? 1B? 1M?

Sol :
BEST APPROACH
=> Divide num into chunks of 3 digit each
-> [TIME - O(1) SPACE - O(1)]
    - Keep a map of num to word for - 0-9, 11-19, 10,20,30,40,50,60,70,
    80,90 and thousand, million, billion.
    - In this case, we only need to consider 3 cases:
    1. num < 20, which is hardcoded and no pattern to do the conversion.
    2. 20 <= num < 100, the pattern is to express num as a+b, where a is 
    twenty ~ ninety, b is one to nine.
    3. 100 <= num, divide num from the one of the dividers {1000000000, 
    1000000, 1000, 100} and see if the quotient > 0. If the quotient > 0, 
    we can express the num = num/divider + divider word + num/divider. 
    num/divider and num/divider can be processed recursively with the same 
    function.
    

Explanation of Time complexity : since we need to traverse only 10-12 
time, since that's how long the number can be.

Edge case : "0", "-ve num", "200", "123k", "123M"
*/
class Solution {
public:
    //These are the special numbers we need mapped to strings:
    //1 - 9 (single digits)
    //11 - 19 (special double digit words)
    //10, 20, 30, 40, 50, 60, 70, 80, 90 - tens
    //1000, 1_000_000, 1_000_000_000 - Thousand, Million, Billion (for 
    //steps)
    unordered_map<int, string> mapping = {
        {1000000000, "Billion"},
        {1000000, "Million"},
        {1000, "Thousand"},
        {100, "Hundred"},

        {90, "Ninety"},
        {80, "Eighty"},
        {70, "Seventy"},
        {60, "Sixty"},
        {50, "Fifty"},
        {40, "Forty"},
        {30, "Thirty"},
        {20, "Twenty"},

        {19, "Nineteen"},
        {18, "Eighteen"},
        {17, "Seventeen"},
        {16, "Sixteen"},
        {15, "Fifteen"},
        {14, "Fourteen"},
        {13, "Thirteen"},
        {12, "Twelve"},
        {11, "Eleven"},

        {10, "Ten"},
        {9, "Nine"},
        {8, "Eight"},
        {7, "Seven"},
        {6, "Six"},
        {5, "Five"},
        {4, "Four"},
        {3, "Three"},
        {2, "Two"},
        {1, "One"},
        {0, "Zero"},
    };
    vector<int> divider = {
        100,
        1000,
        1000000,
        1000000000,
    };
    
    string numberToWords(int num) {
        if(num<20)
            return mapping[num];
        
        if(num<100) {
            int m = num%10;
            int q = num-m;
            return mapping[q] + (m==0?"": " "+mapping[m]);
        }
        
        for(int i=divider.size()-1; i>=0; i--) {
            int q = num/divider[i];
            if(q==0) continue;
            int m = num%divider[i];

            //Ex : 123*1000 + 345
            //Here q = 123 which will be processed recrusively
            //m stores rest of the num, which will be processed recusively
            return numberToWords(q) + " " + mapping[divider[i]] + (m==0?"": " "+numberToWords(m));
        }
       
        return "";
    }
};