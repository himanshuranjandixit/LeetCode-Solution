class Solution {
public:
    int totalMoney(int n) {
        int i=1;
        int sum =0;
        while(n>0){
            int el =i;
            for(int j=0;j<7;j++){
                sum +=el;
                el++; 
                n--;
                if(n==0) break;
            }
            i++;


        }
        return sum;

        
    }
};