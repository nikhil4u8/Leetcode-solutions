class Solution {
public:
    //Traverse all the possible starting points of haystack (from 0 to haystack.length() - needle.length()) and see if the following characters in haystack match those of needle.


    int strStr(string haystack, string needle) {
        if(needle.length() == 0) return 0;
    
        int n = haystack.length() - needle.length()+1;
        for(int i=0;i<n;i++){
            string str = haystack.substr(i,needle.length());
            if(str == needle) return i;
        }
        
        return -1;
    }
    //Approach 2
    //use one pointer p for haystack, two pointers i and j for needle. First compare haystack.charAt(p) with needle.charAt(i) and keep increase index if matches, and search for match start in the middle by using j. When needle.charAt(i) fails, directly turn to j, keep comparing haystack.charAt(p) and needle.charAt(j).
    /// The match function that helps match the needle with the haystack starting with 'offset'
    private boolean match(String haystack, int offset, String needle) {
        for(int i = 0; i < needle.length(); i++) {
            if(haystack.charAt(offset++) != needle.charAt(i)) {
                return false;   
            }
        }
        return true;
    }
    
    public int strStr(String haystack, String needle) {
        
        if(needle.isEmpty()) return 0;
        if(needle.length() > haystack.length()) return -1;
        
        /// Get the last pos where we still need to match the needle
        int lastPos = haystack.length() - needle.length();
        
        /// Try each pos of haystack
        for(int i = 0; i <= lastPos; i++) {
            if(haystack.charAt(i) == needle.charAt(0)) {
                /// Try to match the needle with this part of the haystack
                if(match(haystack, i , needle)) return i;
            }
        }
        
        return -1;
    }
};
//KMP
public int strStr(String haystack, String needle) {
        if(haystack == null || needle == null || needle.length() > haystack.length()) return -1;
        
        int[] parr = kmpPreprocess(needle);
        int i = 0, j = 0;
        while(i < haystack.length() && j < needle.length()) {
            if(haystack.charAt(i) == needle.charAt(j)) {
                i++; j++;
            } else if(j > 0) {
                j = parr[j - 1];
            } else {
                i++;
            }
        }
        return j == needle.length() ? i - j : -1;
    }

    private int[] kmpPreprocess(String pattern) {
        int i = 1, j = 0;
        int[] res = new int[pattern.length()];
        while(i < pattern.length()) {
            if(pattern.charAt(i) == pattern.charAt(j)) {
                res[i] = j+1;
                i++; j++;
            } else if (j > 0) {
                j = res[j-1];
            } else {
                res[i] = 0;
                i++;
            }
        }
        return res;
    }