/** 
 * Forward declaration of guess API.
 * @param  num   your guess
 * @return 	     -1 if num is lower than the guess number
 *			      1 if num is higher than the guess number
 *               otherwise return 0
 * int guess(int num);
 */

class Solution {
public:
    int guessNumber(int n) {
       int beg=1;
        int end=n;
        while(beg<=end){
            long mid= beg + (end-beg)/2;
            if(guess(mid)==0)
                return mid;
            if(guess(mid)==-1)
                end=mid-1;
             if(guess(mid)==1)
                beg=mid+1;
        }
        return -1;
    }
};