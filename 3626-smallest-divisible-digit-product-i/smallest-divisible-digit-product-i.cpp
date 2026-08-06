class Solution {
public:
    int smallestNumber(int n, int t) {
        
        for(int i=n;i<INT_MAX;i++){
            int temp=i;
            int pro=1;
            while(temp>0){
            int digit=temp%10;
            pro=pro*digit;
            temp=temp/10;
            }
            if(pro%t==0)
                return i;
            
        }
        return -1;
    }
};
