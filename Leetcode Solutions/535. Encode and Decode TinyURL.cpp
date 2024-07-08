class Solution {
public:
    unordered_map<string,string>short_long;
    unordered_map<string,string>long_short;
    int count = 0;
    // Encodes a URL to a shortened URL.
    string generate_url(){
        return "http://tinyurl.com/" + to_string(count++);
    }
    string encode(string longUrl){
        if(long_short.find(longUrl) != long_short.end()) return long_short[longUrl];
        
        string short_url = generate_url();
        long_short[longUrl] = short_url;
        short_long[short_url] = longUrl;
        
        return short_url;
    }
    // Decodes a shortened URL to its original URL.
    string decode(string shortUrl) {
        return short_long[shortUrl];
    }
};

// Your Solution object will be instantiated and called as such:
// Solution solution;
// solution.decode(solution.encode(url));