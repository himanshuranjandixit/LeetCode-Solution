class Solution {
public:
    int maxHeightOfTriangle(int red, int blue) {
        // int maxx = max(red,blue);
        // int mini = min(red,blue);
        // int jadoo =1;
        // int sum = 0;
        // while(maxx>=0 && mini >=0 && jadoo <= max(maxx,mini)){
        //     sum+=jadoo;
        //     if(jadoo%2 !=0 ){
        //         maxx-=jadoo;
        //     }
        //     else  mini -=jadoo;
        //     jadoo++;
        // }
        //  maxx = max(red,blue);
        //  mini = min(red,blue);
        // int summ=0;
        // while(maxx>=0 && mini >=0){
        //     summ+=jadoo;
        //     if(jadoo%2 !=0){
        //         mini-=jadoo;
        //     }
        //     else maxx -=jadoo;
        //     jadoo++;
        // }
        // sum= min(sum,summ) ;
       
        // int ans ;
        // ans = sqrt(1+8*sum);
        // ans = ans -1 ;
        // ans = ans /2;
        // return ans ;
        int a = red ;
        int b = blue ;
        int count =1;
        int step =1 ;
        int jadoo=1;


        while((b>=0 || a>=0) && step == count){
            int ch = 1;
            if(step%2 !=0 && b>=jadoo){
                b-=jadoo;
                step++;
                count++;
                ch =0;
                

            }
            else if (step %2 ==0 && a>=jadoo){
                a-=jadoo;
                step++;
                count++;
                ch = 0;
            }
            if(ch ==1) step++;
            jadoo++;
            

        }
        b= red;
        a =blue;
        int count1=1;
        step =1;
        jadoo=1;

        while((b>=0 || a>=0) && step == count1){
            int ch = 1;
            if(step%2 !=0 && b>=jadoo){
                b-=jadoo;
                step++;
                count1++;
                ch =0;

            }
            else if (step %2 ==0 && a>=jadoo){
                a-=jadoo;
                step++;
                count1++;
                ch =0;
            }
            jadoo++;
            if(ch == 1) step++;

        }
        int ans = max(count , count1);
        return ans -1 ;



        
    }
};