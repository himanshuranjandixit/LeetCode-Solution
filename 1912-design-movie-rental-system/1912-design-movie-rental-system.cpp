class MovieRentingSystem {
public:
    unordered_map<int,set<pair<int,int>>>mps; //movie-> price,shop
    unordered_map<int,set<pair<int,int>>>msp;
    set<tuple<int,int,int>>rented; //{price,shop,movie}
    MovieRentingSystem(int n, vector<vector<int>>& entries) {
        for(auto &entry : entries){
            int s = entry[0];
            int m = entry[1];
            int p = entry[2];
            mps[m].insert({p,s});
            msp[m].insert({s,p});
        }        
    }    
    vector<int> search(int movie) {
        vector<int>ans;
        int cnt =0;
        if(!mps.count(movie)) return ans;
        for(auto &[p,s]:mps[movie]){
            ans.push_back(s);
            cnt++;
            if(cnt==5) break;
        }
        return ans;        
    }
    
    void rent(int shop, int movie) {
        auto it = msp[movie].lower_bound({shop,0});
        int price = it->second;
        mps[movie].erase({price,shop});
        rented.insert({price,shop,movie});

        
    }
    
    void drop(int shop, int movie) {
        auto it = msp[movie].lower_bound({shop,0});
        int price = it->second;
        mps[movie].insert({price,shop});
        rented.erase({price,shop,movie});

    }
    
    vector<vector<int>> report() {
        vector<vector<int>>ans;
        int cnt =0;
        for(auto &[p,s,m] : rented){
            ans.push_back({s,m});
            cnt++;
            if(cnt == 5) break;
        }
        return ans;
    }
};

/**
 * Your MovieRentingSystem object will be instantiated and called as such:
 * MovieRentingSystem* obj = new MovieRentingSystem(n, entries);
 * vector<int> param_1 = obj->search(movie);
 * obj->rent(shop,movie);
 * obj->drop(shop,movie);
 * vector<vector<int>> param_4 = obj->report();
 */