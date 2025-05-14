class Solution {
public:
    int findKthPositive(vector<int>& arr, int k) {
        int low= 0;
        int high=arr.size()-1;
        while(low<=high){
            int mid = (low+high)/2;
            int miss = arr[mid]-mid-1;
            if(miss>=k) high=mid-1;
            else low=mid+1;
        }
        return k+high+1;
        
    }
};