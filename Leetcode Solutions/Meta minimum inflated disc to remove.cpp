/*
Find minimum inflatable disc which needs to be removed

Sol :
=> LIS : [TIME - O(N^2) SPACE - O(1)]
    - Find the size longest increasing seq & subtract it from array size
    and that many disc we need to remove

=> Backward Traversal : [TIME - O(N) SPACE - O(1)]
    - Traverse from backward & compare 2 adjacent elements, if 
    R[i] >= R[i+1] means we need to remove R[i] & replace value of R[i+1]
    in R[i] and move backwards
*/
function getMinimumDeflatedDiscCount(N, R) {
    let deflations = 0;

    for (let i = N - 2; i >= 0; i--) { // Starting from second last disc, moving upwards
        if (R[i] >= R[i + 1]) { // If current disc radius is greater than or equal to the disc below it
            if (R[i + 1] - 1 <= 0) { // If the disc below is already at minimum radius
                return -1; // Impossible to stabilize
            }
            deflations++; // Increment the counter for deflations
            R[i] = R[i + 1] - 1; // deflate the disc to make it 1 less than the disc below
        }
    }
    return deflations;
}