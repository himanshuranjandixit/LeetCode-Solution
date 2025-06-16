class Solution {
public:
    int solve(vector<string>& arr, int indx,unordered_set<char>& st){
        if(indx==arr.size()) return 0;
        int not_taken=0;int taken=0;
        not_taken = solve(arr,indx+1,st);
        bool possible=true;
        unordered_set<char>temp(st);
        for(auto it : arr[indx]){
            if(temp.count(it)){
                possible = false;
                break;
            }
            temp.insert(it);
        }
        if(possible){
            taken = arr[indx].size() + solve(arr,indx+1,temp);
        }
        return max(taken,not_taken);


    }
    int maxLength(vector<string>& arr) {
        unordered_set<char>st;
        return solve(arr,0,st);
        
    }
};