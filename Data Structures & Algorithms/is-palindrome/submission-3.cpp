class Solution {
public:
    bool isPalindrome(string s) {
        string snew = "";
        for(char c:s){
            if((97 <= c && 122 >= c) || (48 <= c && 57 >= c)){
                snew += c;
            }

            if(65 <= c && 90 >= c){
                snew += (c+32);
            }
        }
        bool flag = true;
        for(int i = 0; i < snew.length(); i++){
            if(snew[i] != snew[snew.length()-i-1]){
                flag = false;
                break;
            }
        }
        return flag;
    }
};
