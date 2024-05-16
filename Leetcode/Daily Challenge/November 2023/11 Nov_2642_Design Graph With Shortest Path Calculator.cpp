//Floyd Warshall
class Graph {
public:
vector<vector<int>> mat;
int m, u, v, cost;
    Graph(int n, vector<vector<int>>& edges) {
        mat=vector<vector<int>>(n,vector<int>(n,1e9));
        m=n;
        for(int i=0;i<edges.size();i++)
        {
            mat[edges[i][0]][edges[i][1]]=edges[i][2];
        }
        for(int i=0;i<n;i++)
        mat[i][i]=0;
        for(int k=0;k<n;k++)
        {
            for(int i=0;i<n;i++)
            {
                for(int j=0;j<n;j++)
                {
                    mat[i][j]=min(mat[i][j],mat[i][k]+mat[k][j]);
                }
            }
        }
    }
    
    void addEdge(vector<int> edge) {
        u=edge[0]; v=edge[1]; cost=edge[2];
        for(int i=0;i<m;i++)
        {
            for(int j=0;j<m;j++)
            {
                mat[i][j]=min(mat[i][j],mat[i][u]+cost+mat[v][j]);
            }
        } 
    }
    int shortestPath(int node1, int node2) {
        cost=mat[node1][node2];
        return cost==1e9? -1:cost;
    }
};

//Dijkstra
class Graph {
public:
    vector<vector<pair<int, int>>> adjList;
    Graph(int n, vector<vector<int>>& edges) {
        adjList.resize(n);
        for (auto& e: edges)
            adjList[e[0]].push_back(make_pair(e[1], e[2]));
    }

    void addEdge(vector<int> edge) {
        adjList[edge[0]].push_back(make_pair(edge[1], edge[2]));
    }

    int shortestPath(int node1, int node2) {
        int n = adjList.size();
        priority_queue<vector<int>, vector<vector<int>>, greater<vector<int>>> pq;
        vector<int> costForNode(n, INT_MAX);
        costForNode[node1] = 0;
        pq.push({0, node1});

        while (!pq.empty()) {
            int currCost = pq.top()[0];
            int currNode = pq.top()[1];
            pq.pop();

            if (currCost > costForNode[currNode]) {
                continue;
            }
            if (currNode == node2) {
                return currCost;
            }
            for (auto& neighbor : adjList[currNode]) {
                int neighborNode = neighbor.first;
                int cost = neighbor.second;
                int newCost = currCost + cost;

                if (newCost < costForNode[neighborNode]) {
                    costForNode[neighborNode] = newCost;
                    pq.push({newCost, neighborNode});
                }
            }
        }
        return -1;
    }
};
