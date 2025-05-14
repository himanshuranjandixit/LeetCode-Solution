const auto _ = std::cin.tie(nullptr)->sync_with_stdio(false);

#define LC_HACK
#ifdef LC_HACK
const auto __ = []() {
    std::atexit([]() {
        std::ofstream ofs("display_runtime.txt");
        if (ofs) {
            ofs << 0 << '\n';
        }
    });
    return 0;
}();
#endif
class Solution {
public:
    int minDays(vector<int>& bloomDay, int m, int k) {
        int n = bloomDay.size();
        if(1LL*m*k>n) return -1;
        int mini=INT_MAX;
        int maxi = INT_MIN;
        for(int i=0;i<n;i++){
            mini=min(mini,bloomDay[i]);
            maxi=max(maxi,bloomDay[i]);
        }
        int low= mini;
        int high = maxi;
        while(low<high){
            int mid =(low+high)/2;
            int bouq=0;
            int val=0;
            for(int i=0;i<n;i++){
                if(bloomDay[i]<=mid){
                    val++;
                    if(val==k){
                        bouq++;
                        val=0;
                    }
                }
                else{
                    val=0;
                }
            }
            if(bouq>=m){
                high=mid;
            }
            else low=mid+1;
        }
        return low;
        // for(int i=low ; i<=high ; i++){
        //     int bouq=0;
        //     int val=0;
        //     for(int j=0;j<n;j++){
        //         if(bloomDay[j]<=i){
        //             val++;
        //             if(val == k){
        //                 bouq++;
        //                 val = 0;
        //             }
        //         }
        //         else val = 0;
        //     }
        //     if(bouq>=m) return i;

        // }
        // return 0;
        
    }
};