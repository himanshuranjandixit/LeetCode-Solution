class TaskManager {
public:
    map<int,pair<int,int>>mpp; // taskid -> {userid,priority}
    priority_queue<pair<int,int>>pq;
    TaskManager(vector<vector<int>>& tasks) {
        for(auto &task:tasks){
            mpp[task[1]] ={task[0],task[2]};
            pq.push({task[2],task[1]});
        }

        
    }
    
    void add(int userId, int taskId, int priority) {
        mpp[taskId]={userId,priority};
        pq.push({priority,taskId});
        
    }
    
    void edit(int taskId, int newPriority) {
        int userId = mpp[taskId].first;
        mpp[taskId]={userId,newPriority};
        pq.push({newPriority,taskId});
        
    }
    
    void rmv(int taskId) {
        mpp[taskId] = {-1,-1};
        
    }
    
    int execTop() {
        while(!pq.empty()){
            auto [priority,taskId]= pq.top();
            pq.pop();
            if(mpp[taskId].first==-1 && mpp[taskId].second==-1) continue;
            if(priority != mpp[taskId].second) continue;
            int userId =mpp[taskId].first;
            mpp[taskId].first=-1;
            mpp[taskId].second=-1;
            return userId;

        }
        return -1;
        
    }
};

/**
 * Your TaskManager object will be instantiated and called as such:
 * TaskManager* obj = new TaskManager(tasks);
 * obj->add(userId,taskId,priority);
 * obj->edit(taskId,newPriority);
 * obj->rmv(taskId);
 * int param_4 = obj->execTop();
 */