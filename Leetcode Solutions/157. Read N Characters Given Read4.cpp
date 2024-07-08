/**
 * The read4 API is defined in the parent class Reader4.
 *     int read4(char *buf4);
 */

/*
Ques :
    - Can N = 0?
    - Does read4 store the read4 output in buf4 (which is given to read4 as para)?
    - What if we've more char than req in buf?
    - What if we've less char than req in buf?

Sol :
=> Read char from Buffer - [TIME - O(N | SPACE - O(1)]
    - Create a buf4 of size 4 byte, used to pass as a parameter in read4
    - Start reading 4 char at a time from file until we've read N char
    - Meanwhile store all the char which we've read until buffer size is 
    full

Edge Cases : 
    - If n == buff size
    - N == 0
    - N < buff size
    - N > buff size

Follow up :
    - If read fun is called multiple times : 
    Refer - 158. Read N Characters Given read4 II - Call Multiple Times
*/
class Solution {
public:
    /**
     * @param buf Destination buffer
     * @param n   Number of characters to read
     * @return    The number of actual characters read
     */
    int read(char *buf, int n) {
        int count = 0, buf_read_ptr = 0, buf_end_ptr = 0;
        char buf4[4];

        //reading char from file and adding them to buffer until we've read
        //n char
        while(count < n){
            //adding the read char from file in buffer one by one
            if(buf_read_ptr < buf_end_ptr){
                buf[count++] = buf4[buf_read_ptr++]; 
                continue;
            }

            //read 4 more char from file, and reset buf_read_ptr
            buf_read_ptr = 0;
            buf_end_ptr = read4(buf4);
            //if file doesn't have anymore char, and we've not read N char
            //yet then we return what all char we've read
            if(buf_end_ptr == 0) return count;
        }

        return count;
    }
};