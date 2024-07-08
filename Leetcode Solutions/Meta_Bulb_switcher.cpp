class Solution {
public:
// 6 -> 6*1, 2*3 => It has even factors hence it'll be off in end
// 7 -> 7*1 => even factors hence off in end
// 9 -> 9*1, 3*3 => odd factors hence on in end
// Numbers having odd factors will be on => Only perfect square will have odd factors, so find number of perfect square below n
    int bulbSwitch(int n) {
        return sqrt(n);
    }
};

A - array of versions, |A| = n
check(A[0]) = true - first version is fine
check(A[n-1]) = false - last version has the fault

binary search:

int start = 0;
int end = n-1;
while(end-start>1){
int middle = (end+start)/2;
if (check(A[middle])) start = middle;
else end = middle;
}

A[end] is the version with the fault