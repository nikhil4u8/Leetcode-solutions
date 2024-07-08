/*
Ques to ask :
    - Can N = 0?
    - Does read4 store the read4 output in buf4 (which is given to read4 as para)?
    - What if we've more char than req in buf?
    - What if we've less char than req in buf?

Sol :
=> Read char from buffer maintaing next buffer - [TIME - O(N) SPACE - O(4)]
-> For next Query - Next Buffer
    - Maintain a global cache buffer, which will store elements which 
    aren't read in previous query.
    - When next query comes, then first read left over char from global
    cache buffer then read new char from file using read4 API.

Edge Cases : 
    - If n == buff size | N == 0 | N < buff size | N > buff size

Follow up :
    - Speed up process ? -> copying directly from file
*/
class Solution {
public:
//BEST APPROACH
//TIME - O(N) SPACE - O(1) -> N = no of char read in query
    //global cache which will store all unread char
    char next_buf[4];
    //cache_read_ptr = points to idx until which the cache is read
    //cache_write_ptr = point to idx at which last char is present in cache
    int cache_read_ptr = 0, cache_write_ptr = 0;
    int read(char *buf, int n) {
        int count = 0;

        //reading char from file and adding them to buffer until we've read
        //n char
        while(count < n){
            //if cache is not read fully then process cache first before
            //reading new char from file
            if(cache_read_ptr < cache_write_ptr){
                buf[count++] = next_buf[cache_read_ptr++];
                continue;
            }

            //once cache if fully read, then reset cache_read_ptr & read
            //new char from file and reset cache_write_ptr to last idx
            //of new cache
            cache_read_ptr = 0;
            cache_write_ptr = read4(next_buf);

            //if file doesn't have anymore char, and we've not read N char
            //yet then we return what all char we've read
            if(cache_write_ptr == 0) break;
        }
    
        return count;
    }


//FOLLOW UP
//SPEED UP PROCESS
/*
Using inner buf4 can introduce more memory copy operation, which is time consuming
When > 4 char left to copy, then we'll directly add those char in buf
When < 4 char left to copy, then we've to take those in buf4 and then copy them to buf
*/


char next_buf[4];
int cache_read_ptr = 0, cache_write_ptr = 0;
int read(char *buf, int n) {
    int count = 0;
    while(count < n){
        if(cache_read_ptr < cache_write_ptr)
            buf[count++] = next_buf[cache_read_ptr++];
        else{
            if(n - count >= 4){
                int char_read = read4(buf + count);
                count += char_read;
                if(char_read == 0) return count;
            }else{
                cache_write_ptr = read4(next_buf);
                cache_read_ptr = 0;
                if(cache_write_ptr == 0) return count;
            }
        }
    }

    return count;
}






//Long answer
/*
- First reading left over char from cache -> resetting cache
-> reading new char -> adding unread char to cache
*/
    vector<char>next_buf = vector<char>(4, '#');
    int read(char *buf, int n) {
        //creating a buffer which will store output of read4 API
        char buf4[4];
        int count = 0, i = 0, j = 0, l = 0, k = 0, char_read = 0;

        //reading leftover char from next buffer
        while(j < next_buf.size() && count < n && next_buf[j] != '#'){
            buf[count] = next_buf[j];
            count++;
            j++;
        }

        //removing all processed char from next buffer
        while(l < 4){
            if(j >= 4) next_buf[l] = '#';
            else next_buf[l] = next_buf[j];
            l++;
            j++;
        }

        //reading char from file and adding them to buffer until we've read
        //n char
        while(count < n){
            char_read = read4(buf4);
            i = 0;

            //if file doesn't have anymore char, and we've not read N char
            //yet then we return what all char we've read
            if(char_read == 0) return count;
            
            //adding all the read char from file in buffer
            while(i < char_read && count < n){
                buf[count] = buf4[i];
                count++;
                i++;
            }
        }

        //Going to the idx in from where we can start entering new char in
        //next buffer
        while(k < 4 && next_buf[k] != '#') k++;
        //Adding all unread char in buffer to next buffer
        while(i < char_read){
            next_buf[k] = buf4[i];
            i++;
            k++;
        }

        return count;
    }
};