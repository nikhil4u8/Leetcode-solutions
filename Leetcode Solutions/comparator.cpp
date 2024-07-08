 auto cmp = [](string& t1,string& t2){
            return t1.length()<=t2.length();
        };
        sort(words.begin(),words.end(),cmp);
        
bool operator() defines the operator () for the class 
instances and makes it accept two arguments to make a 
comparison and return a bool.

While operator bool() defines the bool operator i.e makes 
the class instances be convertible to bools

As a summary, the first function overloads the operator () 
while the second overloads the operator bool

/*
Logic - 
By default, the order will be L -> R, if you want to maintain the order
then return true when L>R, else reverse it L<R.
*/
struct compare {
        bool operator()(pair<int, string>& l, pair<int, string>& r) {
            if(l.first == r.first) return l.second < r.second;
            return l.first > r.first; 
        }
};

priority_queue<int, vector<int>, compare>pq;

// using compare for sorting
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

// To use compare fun inside the class make it as static
class Solution {
public:
    static bool compare(int l, int r) {
        if(left == right) return l < r;
        return left < right;
    }
    vector<int> sortByBits(vector<int>& arr) {
        sort(arr.begin(), arr.end(), compare);
        return arr;
    }
};

/*
Why using static works in above case?
-->When a regular (non-static) member function is called, 
it brings along an "instance-specific" note (this pointer) 
that causes problems with how the function is expected to look (static / global). 
When marked as static means that function has no dependency on any particular 
instance of the class and can be treated similarly to a regular non-member function.
thus there's no confusion with function pointer signatures.
*/