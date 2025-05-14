class Solution {
public:
    int shipWithinDays(vector<int>& weights, int days) {
        long long sum=0;
        int high=0;
        for(int i=0 ; i<weights.size();i++){
            sum+=weights[i];
            high=max(high,weights[i]);
        }
        int low = high;
        high=sum;
        while(low<=high){
            int mid = (low+high)/2;
            int day=1;
            int val=0;
            for(int i=0;i<weights.size();i++){
                if(val+weights[i]>mid){
                    day++;
                    val=0;
                }
                val+=weights[i];
            }
            if(day>days) low=mid+1;
            else high=mid-1;
        }
        return low;
        
    }
};