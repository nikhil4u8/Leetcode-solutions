Implement 
void addStocksVolume(string stockSymbol, int volume)
vector<string> topKstocks(int k)


unordered_map<string, multimap<int,string>::iterator> it_map;
multimap<int, string, greater<int>> vol_map;

// O(logN) updation since insertion in multimap takes logarithmic time
void updateStock (string company, int volume) {
  if (it_map.find(company) == it_map.end()) {
    it_map[company] = vol_map.insert({volume, company}).first; // see return value of map.insert(..) here: http://www.cplusplus.com/reference/map/map/insert/
  } else {
    int currVol = vol_map(it_map[company]);
    vol_map.erase(it_map[company]);
    it_map[company] = vol_map.insert({currVol+volume, company}).first;
  }
}

// O(K) operation
void printTopK (int k) {
  for (auto it = vol_map.begin(); it!=vol_map.begin()+k && it!=vol_map.end(); it++)
    cout<<it->second<<" "<<it->first<<"\n";
}