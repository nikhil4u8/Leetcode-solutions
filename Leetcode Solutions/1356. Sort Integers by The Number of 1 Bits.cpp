bool compare(int l, int r) {
    int left = __builtin_popcount(l);
    int right = __builtin_popcount(r);

    if(left == right) return l < r;
    return left < right;
}
class Solution {
public:
    vector<int> sortByBits(vector<int>& arr) {
        sort(arr.begin(), arr.end(), compare);
        return arr;
    }
};