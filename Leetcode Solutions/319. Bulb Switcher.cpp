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