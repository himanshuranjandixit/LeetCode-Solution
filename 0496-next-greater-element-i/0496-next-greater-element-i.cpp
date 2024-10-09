class Solution {
public:
    vector<int> nextGreaterElement(vector<int>& nums1, vector<int>& nums2) {
        vector<int>v;
        for(int i=0;i<nums1.size();i++){
            int val=-1;
            for(int j=0;j<nums2.size();j++){
                if(nums1[i]==nums2[j]){
                    while(j!=nums2.size()){
                        if(nums1[i]<nums2[j]){
                            val=nums2[j];
                            break;
                        }
                        j++;
                    }
                    break;
                }

            }
            v.push_back(val);
        }
        return v;
        
    }
};