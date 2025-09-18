class TaskManager {
    unordered_map<int, pair<int, int>> mp;
    priority_queue<pair<int, int>> pq;
public:
    TaskManager(vector<vector<int>>& tasks) {
        mp.reserve(tasks.size());
        for (auto& t : tasks){
            int userId = t[0], taskId = t[1], priority = t[2];
            mp[taskId] = {priority, userId};
            pq.emplace(priority, taskId);
        }
    }
    
    void add(int userId, int taskId, int priority) {
        mp[taskId] = {priority, userId};
        pq.emplace(priority, taskId);
    }
    
    void edit(int taskId, int newPriority) {
        auto it = mp.find(taskId);
        if (it == mp.end())
            return;
        it -> second.first = newPriority;
        pq.emplace(newPriority, taskId);
    }
    
    void rmv(int taskId) {
        mp.erase(taskId);
    }
    
    int execTop() {
        while (!pq.empty()){
            auto [p, id] = pq.top(); pq.pop();
            auto it = mp.find(id);
            if (it != mp.end() && it -> second.first == p){
                int userId = it -> second.second;
                mp.erase(it);
                return userId;
            }
        }
        return -1;
    }
};

