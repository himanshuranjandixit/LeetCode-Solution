class Solution {
public:
    int candy(vector<int>& ratings) {
        if(ratings.size()==1) return 1;
        if(ratings.size()==2){
            if(ratings[0]==ratings[1]) return 2;
            return 3;
        }
        vector<int>v(ratings.size(),1);
        if(ratings[0]>ratings[1])v[0]++;
        for(int i=1;i<ratings.size()-1;i++){
            if(ratings[i-1]<ratings[i]){
                v[i] = max(v[i],v[i-1]+1);
            }
            if(ratings[i]>ratings[i+1]){
                v[i]= max(v[i],v[i+1]+1);
            }
        }
        if(ratings[v.size()-1]>ratings[v.size()-2]){
            v[v.size()-1] = max(v[v.size()-1],v[v.size()-2]+1);
        }

        for(int i=ratings.size()-2;i>=1;i--){
            if(ratings[i+1]<ratings[i]){
                v[i] = max(v[i],v[i+1]+1);
            }
            if(ratings[i]>ratings[i-1]){
                v[i] = max(v[i],v[i-1]+1);
            }
        }
        if(ratings[0]>ratings[1]){
            v[0] =max(v[0],v[1]+1);
        }
        int ans=accumulate(v.begin(),v.end(),0);
        return ans;
    }
};