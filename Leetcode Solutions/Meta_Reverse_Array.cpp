/*
You receive a vector/ array and 2 numbers, eg 2 and 5. Between those 
2 positions in the vector (2 and 5) you have to reverse the order of 
the elements.
*/

//TIME - O(N) SPACE - O(1)
void reverseArray(vector<int>array, int l, int r){
    while(l < r){
        swap(array[l], array[r]);
        l++;
        r--;
    }
}

void reverseArray(vector<int>array, int l, int r){
    //Find position of 2
    itr it1 = std::find(v.begin(), v.end(), 2); //O(n)

    //Find position of 5
    itr it2 = std::find(v.begin(), v.end(), 5); //O(n)

    std::reverse(it1+1, it2); //O(n)
}