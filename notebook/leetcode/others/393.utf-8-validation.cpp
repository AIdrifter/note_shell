/*
 * @lc app=leetcode id=393 lang=cpp
 *
 * [393] UTF-8 Validation
 *
 * https://leetcode.com/problems/utf-8-validation/description/
 *
 * algorithms
 * Medium (35.33%)
 * Total Accepted:    31.5K
 * Total Submissions: 89.1K
 * Testcase Example:  '[197,130,1]'
 *
 * A character in UTF8 can be from 1 to 4 bytes long, subjected to the
 * following rules:
 *
 * For 1-byte character, the first bit is a 0, followed by its unicode code.
 * For n-bytes character, the first n-bits are all one's, the n+1 bit is 0,
 * followed by n-1 bytes with most significant 2 bits being 10.
 *
 * This is how the UTF-8 encoding would work:
 *
 * ⁠  Char. number range  |        UTF-8 octet sequence
 * ⁠     (hexadecimal)    |              (binary)
 * ⁠  --------------------+---------------------------------------------
 * ⁠  0000 0000-0000 007F | 0xxxxxxx
 * ⁠  0000 0080-0000 07FF | 110xxxxx 10xxxxxx
 * ⁠  0000 0800-0000 FFFF | 1110xxxx 10xxxxxx 10xxxxxx
 * ⁠  0001 0000-0010 FFFF | 11110xxx 10xxxxxx 10xxxxxx 10xxxxxx
 *
 *
 * Given an array of integers representing the data, return whether it is a
 * valid utf-8 encoding.
 *
 *
 * Note:
 * The input is an array of integers. Only the least significant 8 bits of each
 * integer is used to store the data. This means each integer represents only 1
 * byte of data.
 *
 *
 *
 * Example 1:
 *
 * data = [197, 130, 1], which represents the octet sequence: 11000101 10000010
 * 00000001.
 *
 * Return true.
 * It is a valid utf-8 encoding for a 2-bytes character followed by a 1-byte
 * character.
 *
 *
 *
 *
 * Example 2:
 *
 * data = [235, 140, 4], which represented the octet sequence: 11101011
 * 10001100 00000100.
 *
 * Return false.
 * The first 3 bits are all one's and the 4th bit is 0 means it is a 3-bytes
 * character.
 * The next byte is a continuation byte which starts with 10 and that's
 * correct.
 * But the second continuation byte does not start with 10, so it is invalid.
 *
 *
 */
class Solution {
    public:
        //assumes little endian
        void printBits(size_t const size, void const * const ptr)
        {
            unsigned char *b = (unsigned char*) ptr;
            unsigned char byte;
            int i, j;

            for (i=size-1;i>=0;i--)
            {
                for (j=7;j>=0;j--)
                {
                    byte = (b[i] >> j) & 1;
                    printf("%u", byte);
                }
            }
            puts("");
        }

        //  [Operation priorities in C and C++] 
        //  https://www.viva64.com/en/t/0064/
        //  (A&B) == C  is not equavalent to A&B == C
        bool validUtf8(vector<int>& data) {
            int i = 0;
            int len = data.size();
            while (i < len){
                //printBits(sizeof(data[i]),&data[i]);
                //puts("");

                if(data[i] <= 0b01111111  ) {i++;  printf("[DEBUG][%s]@%u       \n",__func__,__LINE__); }
                else if((data[i]   & 0b11100000) == 0b11000000 ){
                    if(i+1>=len) break;
                    else if((data[i+1] & 0b11000000) == 0b10000000){ i+=2;}
                    else break;
                }
                else if((data[i]   & 0b11110000) == 0b11100000 ){
                    if(i+2>=len) break;
                    else if((data[i+1] & 0b11000000) == 0b10000000 && (data[i+2] & 0b11000000) == 0b10000000) i+=3;
                    else break;
                }
                else if((data[i]   & 0b11111000) == 0b11110000 ){
                    if(i+3>=len) break;
                    else if((data[i+1] & 0b11000000) == 0b10000000 && (data[i+2] & 0b11000000) == 0b10000000 && (data[i+3] & 0b11000000) == 0b10000000 ) i+=4;
                    else break;
                }
                else{
                    break;
                }
            }

            //printf("[DEBUG][%s]@%u   i %u data.size(%u)   \n",__func__,__LINE__,i,data.size());
            if(i == data.size())
                return true;
            else
                return false;
        }
};
