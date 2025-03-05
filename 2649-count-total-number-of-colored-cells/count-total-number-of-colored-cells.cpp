class Solution {
public:
    long long coloredCells(int n) {
        long long N=n;
        return 1+4*(N-1)+4*((N>=3)?(N-2)*(N-1)/2:0);
    }
};