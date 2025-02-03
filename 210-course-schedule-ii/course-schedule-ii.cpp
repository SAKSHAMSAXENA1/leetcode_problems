class Solution {
public:
    vector<int> findOrder(int numCourses, vector<vector<int>>& prerequisites) {
        vector<int> ordering;
        vector<int> indegree(numCourses,0);
        vector<vector<int>> adj(numCourses, vector<int>());
        queue<int> q;

        for(auto it: prerequisites)
        {
            adj[it[1]].push_back(it[0]);
            indegree[it[0]]++;
        }

        for(int course=0;course<numCourses;course++)
        {
            if(indegree[course]==0) q.push(course);
        }

        while(!q.empty())
        {
            int curCourse=q.front();
            q.pop();
            ordering.push_back(curCourse);

            for(auto nextCourse: adj[curCourse])
            {
                indegree[nextCourse]--;
                if(indegree[nextCourse]==0) q.push(nextCourse);
            }
        }

        if(ordering.size()<numCourses) return vector<int>();
        return ordering;
    }
};