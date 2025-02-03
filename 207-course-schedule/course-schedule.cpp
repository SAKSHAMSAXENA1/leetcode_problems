class Solution {
public:
    bool canFinish(int numCourses, vector<vector<int>>& prerequisites) {
        vector<vector<int>> adj(numCourses, vector<int>());
        vector<int> indegree(numCourses,0);
        queue<int> q;
        int coursesDone=0;

        for(auto it: prerequisites)
        {
            adj[it[1]].push_back(it[0]);
            indegree[it[0]]++;
        }

        for(int i=0;i<numCourses;i++)
        {
            if(indegree[i]==0) q.push(i);
        }

        while(!q.empty())
        {
            int curCourse=q.front();
            q.pop();

            coursesDone++;

            for(auto nextCourse: adj[curCourse])
            {
                indegree[nextCourse]--;

                if(indegree[nextCourse]==0) q.push(nextCourse);
            }
        }

        return coursesDone==numCourses;
    }
};