class Solution {
public:
    bool isPalindrome(int x) {
        int initial=0;
        if(x<0){
            return false;
        }
            long long rev=0;
            int inti=x;
            while(x!=0){
                initial=x%10;
                rev=rev*10+initial;
                x=x/10;
            }
                if(inti==rev){
                    return true;
                }
                    else{
                        return false;
                    }
                
        
    }
};