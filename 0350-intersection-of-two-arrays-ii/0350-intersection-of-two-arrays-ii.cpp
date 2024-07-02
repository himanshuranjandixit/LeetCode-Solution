class Solution {
public:
    vector<int> intersect(vector<int>& nums1, vector<int>& nums2) {
        sort(nums1.begin(),nums1.end());
        sort(nums2.begin(),nums2.end());
        int n1 = nums1.size();
        int n2 = nums2.size();
        vector<int>ans;
        int k=0;
        if(n1>n2){
            for(int i = 0 ; i<n2 ; i++){
                for(int j = k; j<n1 ; j++){
                    if(nums2[i]==nums1[j]){
                        ans.emplace_back(nums2[i]) ;
                        k=j+1;
                        break;

                    }
                    if(nums1[j]>nums2[i]) break;
                }
            }
        }
        else{
            for(int i = 0 ; i<n1 ; i++){
                for(int j = k; j<n2 ; j++){
                    if(nums1[i]==nums2[j]){
                        ans.emplace_back(nums1[i]) ;
                        k=j+1;
                        break;

                    }
                    if(nums2[j]>nums1[i]) break;
                }
            }

        }

        return ans;
        
    }
};