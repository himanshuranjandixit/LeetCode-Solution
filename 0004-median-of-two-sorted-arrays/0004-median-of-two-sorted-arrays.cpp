class Solution {
public:
    double findMedianSortedArrays(vector<int>& nums1, vector<int>& nums2) {
        double ans;
        vector<int>v;
        for(int i=0;i<nums2.size();i++){
            nums1.push_back(nums2[i]);
        }
        sort(nums1.begin(),nums1.end());
        int n = nums1.size();
        cout<<n;
        if(n==1) return (double)nums1[0];
        if(n%2!=0) return (double)(nums1[n/2]);
        return (double)((double)nums1[n/2]+ (double) nums1[n/2-1])/2;
        
    }
};