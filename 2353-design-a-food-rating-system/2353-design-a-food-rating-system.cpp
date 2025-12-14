class FoodRatings {
public:
    map<string,set<pair<int,string>>>crf;
    map<string,pair<string,int>>fcr;
    FoodRatings(vector<string>& foods, vector<string>& cuisines, vector<int>& ratings) {
        for(int i=0;i<foods.size();i++){
            crf[cuisines[i]].insert({-ratings[i],foods[i]});
            fcr[foods[i]] = {cuisines[i],ratings[i]};
        }
        
    }
    
    void changeRating(string food, int newRating) {
        auto [cuisine,prevRating] = fcr[food];
        crf[cuisine].erase({-prevRating,food});
        crf[cuisine].insert({-newRating,food});
        fcr[food]={cuisine,newRating};

        
    }
    
    string highestRated(string cuisine) {
        return crf[cuisine].begin()->second;
        
    }
};

/**
 * Your FoodRatings object will be instantiated and called as such:
 * FoodRatings* obj = new FoodRatings(foods, cuisines, ratings);
 * obj->changeRating(food,newRating);
 * string param_2 = obj->highestRated(cuisine);
 */