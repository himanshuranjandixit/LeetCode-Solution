class Solution {
public:
    int maximumLength(vector<int>& nums) {
        int odd=0; int even=0;
        for(auto it :nums){
            if(it%2==0) even++;
            else odd++;
        }
        int maxlength = max(odd,even);
        int oddfirst =0; int evenfirst =0;
        bool oddcheck=true; bool evencheck = true;
        //even 
        for(auto it:nums){
            if(it%2==0 && evencheck){
                evenfirst++;
                evencheck=false;
            }
            else if(it%2!=0 && !evencheck){
                evenfirst++;
                evencheck=true;
            }
            
        }
        for(auto it:nums){
            if(it%2!=0 && oddcheck){
                oddfirst++;
                oddcheck=false;
            }
            else if(it%2==0 && !oddcheck){
                oddfirst++;
                oddcheck=true;
            }
            
        }
        return max(maxlength,max(oddfirst,evenfirst));
        
    }
};