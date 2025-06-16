class Solution {
public:
    unordered_set<char>st;
    int solve(vector<string>& arr, int indx,unordered_map<char,int>& mpp){
        if(indx==arr.size()) return 0;
        int not_taken=0;int taken=0;
        not_taken = solve(arr,indx+1,mpp);
        bool possible=true;
        for(auto it : arr[indx]){
            if(mpp[it]>0 || st.count(it)){
                possible = false;
                break;
            }
            st.insert(it);
        }
        st.clear();
        if(possible){
            for(auto it : arr[indx]) mpp[it]++;
            taken = arr[indx].size() + solve(arr,indx+1,mpp);
            for(auto it : arr[indx]) mpp[it]--;
        }
        return max(taken,not_taken);


    }
    int maxLength(vector<string>& arr) {
        unordered_map<char,int>mpp;
        return solve(arr,0,mpp);
        
    }
};