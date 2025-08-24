class TaskManager {
public:
set<pair<int,int>> st;
unordered_map<int,set<pair<int,int>>::iterator> taskAddr;
unordered_map<int,int> taskToUser;
    TaskManager(vector<vector<int>>& tasks) {
        for(auto it:tasks)
        {
            int userId=it[0],taskId=it[1],priority=it[2];
            st.insert({priority,taskId});
            taskToUser[taskId]=userId;
        }

        for(auto it=st.begin();it!=st.end();it++)
        {
            int taskId=it->second;
            taskAddr[taskId]=it;
        }
    }
    
    void add(int userId, int taskId, int priority) {
        st.insert({priority,taskId});
        taskAddr[taskId]=st.find({priority,taskId});
        taskToUser[taskId]=userId;
    }
    
    void edit(int taskId, int newPriority) {
        auto originalAddr=taskAddr[taskId];
        st.erase(originalAddr);
        st.insert({newPriority,taskId});
        taskAddr[taskId]=st.find({newPriority,taskId});
    }
    
    void rmv(int taskId) {
        auto originalAddr=taskAddr[taskId];
        st.erase(originalAddr);
        taskToUser.erase(taskId);
        taskAddr.erase(taskId);
    }
    
    int execTop() {
        if(st.size()==0) return -1;

        int execTask=st.rbegin()->second;
        int userId=taskToUser[execTask];
        auto execTaskAddr=taskAddr[execTask];
        taskAddr.erase(execTask);
        taskToUser.erase(execTask);
        st.erase(execTaskAddr);
        return userId;
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