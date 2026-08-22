class Solution {
public:
    bool checkDivisibility(int n) {
        int sum=0;
        int product=1;
        int num=n;
        while(num>0){
        int digit=num%10;
        sum+=digit;
        product*=digit;
        num=num/10;
        }
        int finalnum=sum+product;
        if(n%finalnum==0){
            return true;}
            else{
            return false;
        }

    }
};