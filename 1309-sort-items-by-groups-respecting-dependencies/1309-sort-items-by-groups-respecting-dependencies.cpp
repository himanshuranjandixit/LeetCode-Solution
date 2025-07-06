

class Solution {
public:
    vector<int> topological_sort(vector<vector<int>>& graph){
        int n = graph.size();
        vector<int> in_degree(n);
        vector<int> result, sources;
        for(int u=0;u<n;u++){
            for(int v : graph[u])
                in_degree[v]++;
        }
        for(int u=0;u<n;u++) 
            if (in_degree[u] == 0) sources.push_back(u);
        
        while(!sources.empty()){
            int source = sources.back();
            sources.pop_back();
            result.push_back(source);
            for(int v : graph[source]){
                if (--in_degree[v] == 0)
                    sources.push_back(v);
            } 
        }
        return result.size() < n ? vector<int>{} : result;
    }

    vector<int> sortItems(int n, int m, vector<int>& group, vector<vector<int>>& beforeItems) {
        for(int i=0;i<n;i++){
            if (group[i] == -1)
                group[i] = m++;
        }
        vector<vector<int>> groups_graph(m);
        vector<vector<int>> items_graph(n);

        for(int curr=0;curr<n;curr++){
            int g2 = group[curr];
            for(int before : beforeItems[curr]){
                int g1 = group[before];
                if (g1 != g2)  groups_graph[g1].push_back(g2);
                items_graph[before].push_back(curr);
            }
        }

        auto groups_order = topological_sort(groups_graph);
        auto items_order = topological_sort(items_graph);
        if (items_order.empty() || groups_order.empty()) return {};

        vector<vector<int>> in_group_sorted(m);
        for(int item : items_order) in_group_sorted[group[item]].push_back(item);

        vector<int> result;
        for(int g : groups_order) copy(in_group_sorted[g].begin(), in_group_sorted[g].end(), back_inserter(result));
        
        return result;



    }
};