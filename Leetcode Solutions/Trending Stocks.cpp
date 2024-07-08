We can use an approach similar to LFU cache and attain O(1) complexity for both the functions.

1.) Have a HashMap to store the Stock name as key and its frequency as the value.
2.) Have a HashMap with key as the frequency as the key and a doubly-linked list as its value.
3.) Have a LinkedList to store the max frequencies.

The doubly linked list will be a custom class that will also have a HashMap to store which node each 
stock belongs to. This will be required to remove a node from the doubly linked list in O(1) time.

class TrendingStock {
public:
    unordered_map<string, int> key_freq; // stock_name to freq map -> keep track of freq of a stock
    unordered_map<string, list<string>::iterator> key_it; // stock_name to iterator map
    // freq to list of stocks map -> help in extracting the stock which will be removed using max_freq
    unordered_map<int, list<string>> freq_map; 
    list<int> freqlist; // freq list -> keep track of max_freq
    unordered_map<int, list<int>::iterator> maxfreq_map; // freq to list iterator map of freqList
    int max_freq {0};
   
    TrendingStock() {}
    string getTrendingStock() {
        max_freq = freqlist.back();
        string res = freq_map[max_freq].back();
        freq_map[max_freq].pop_back();
        key_freq.erase(res);
        key_it.erase(res);
        if(freq_map[max_freq].size() == 0) {
            //max_freq--;
            auto it = maxfreq_map[max_freq];
            freqlist.erase(it);
        }
        return res;
    }
    void processStock(const string &stock) {
        if(key_freq.count(stock) == 0) {
            key_freq[stock] = 1;
            freq_map[1].push_back(stock);
            key_it[stock] = --freq_map[1].end();
            if(freqlist.empty()) {
                freqlist.push_back(1);
                maxfreq_map[1] = prev(freqlist.end());
            }
            //max_freq = max_freq ==0 ? 1 : max_freq;
        }
        else {
            int freq = key_freq[stock];
            auto it = key_it[stock];
            freq_map[freq].erase(it);
            
            if(freq_map[freq].size() == 0) {
                auto it = maxfreq_map[freq];
                freqlist.erase(it);
            }
            
            freq_map[freq+1].push_back(stock);
            key_it[stock] = --freq_map[freq+1].end();
            key_freq[stock] = freq+1;
            max_freq = freqlist.back(); //max(max_freq , freq +1);
            if(freq+1 > max_freq) {
                freqlist.push_back(freq+1);
                maxfreq_map[freq+1] = prev(freqlist.end());
            }
        }
    }
};