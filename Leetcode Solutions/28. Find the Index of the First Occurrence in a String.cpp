/*Traverse all the possible starting points of haystack 
(from 0 to haystack.length() - needle.length()) and see if 
the following characters in haystack match those of needle.
*/
//BRUTE FORCE
class Solution {
public:
    int strStr(string haystack, string needle) {
        int m = haystack.size(), n = needle.size();
        for (int i = 0; i <= m - n; i++) {
            int j = 0;
            for (; j < n; j++) {
                if (haystack[i + j] != needle[j]) {
                    break;
                }
            }
            if (j == n) {
                return i;
            }
        }
        return -1;
    }
};

//KMP ALGO
class Solution {
public:
    int strStr(string haystack, string needle) {
        int m = haystack.size(), n = needle.size();
        if (!n) {
            return 0;
        }
        vector<int> lps = kmpProcess(needle);
        for (int i = 0, j = 0; i < m;) {
            if (haystack[i] == needle[j]) { 
                i++, j++;
            }
            if (j == n) {
                return i - j;
            }
            if (i < m && haystack[i] != needle[j]) {
                j ? j = lps[j - 1] : i++;
            }
        }
        return -1;
    }
private:
    vector<int> kmpProcess(string needle) {
        int n = needle.size();
        vector<int> lps(n, 0);
        for (int i = 1, len = 0; i < n;) {
            if (needle[i] == needle[len]) {
                lps[i++] = ++len;
            } else if (len) {
                len = lps[len - 1];
            } else {
                lps[i++] = 0;
            }
        }
        return lps;
    }
};

/*
KMP EXPLANATION
The key of KMP is to build a look up table that records the 
match result of prefix and postfix. Value in the table means 
the max len of matching substring that exists in both prefix 
and postfix. In the prefix this substring should starts from 
0, while in the postfix this substring should ends at current index.

For example, now we have a string "ababc"
The KMP table will look like this:

a b a b c

0 0 1 2 0

(Note: we will not match substring with itself, so we will skip index 0)

So how does this table help us search string match faster?

Well, the answer is if we are trying to match a char after 
postfix with target string and failed, then we can smartly 
shift the string, so that the matching string in prefix will 
replace postfix and now we can try to match the char after 
prefix with this char in target.
*/