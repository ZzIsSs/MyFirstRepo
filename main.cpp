#include <vector>
#include <iostream>
#include <fstream>
#include <string>
#include<stack>
#include<queue>
#include <climits>
#include <algorithm>

using namespace std;

vector<vector<int>> convertMatrixToList(const string &filename){
    ifstream doc(filename);
    if (!doc.is_open())
    {
        cout << "Can not open file " << filename << endl;
        return {{}};
    }
    int size;
    doc >> size;
    vector<vector<int>> ans(size);
    int add = 0;
    int cnt = 0;
    for (int i = 0; i < size; i++)
    {
        ans[i].push_back(0);
        for (int j = 0; j < size; j++)
        {
            cnt = 0;
            doc >> add;
            if (add)
            {
                ans[i].push_back(j);
                cnt++;
            }
        }
        ans[i][0] = cnt;
    }
    doc.close();
    return ans;
}

vector<vector<int>> convertListToMatrix(const string &filename)
{
    ifstream doc(filename);
    if (!doc.is_open())
    {
        cout << "Can not open file " << filename << endl;
        return {{}};
    }
    int size;
    doc >> size;
    vector<vector<int>> ans(size, vector<int>(size, 0));
    int n;
    int add;
    for(int i = 0;i<size;i++){
        doc>>n;
        for(int j=0;j<n;j++){
            doc>>add;
            ans[i][add]=1;
        }
    }
    doc.close();
    return ans;
}

void printMatrix(const vector<vector<int>> &grid){
    int n=grid.size();
    for(int i=0;i<n;i++){
        for(int j : grid[i]){
            cout<<j<<' ';
        }
        cout<<endl;
    }
    cout<<endl;
}

vector<vector<int>> convertMatrixToList2(const vector<vector<int>> &grid){
    int n = grid.size();
    vector<vector<int>> ans(n);
    for(int i=0;i<n;i++){
        ans[i].push_back(0);
        for(int j=0;j<n;j++){
            if(grid[i][j]){
                ans[i].push_back(j);
                ans[i][0]++;
            } 
        }
    }
    return ans;
}

bool isDirected(const vector<vector<int>> &adjMatrix)
{
    int n = adjMatrix.size();
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < i; j++)
        {
            if (adjMatrix[i][j] != adjMatrix[j][i])
            {
                return 1;
            }
        }
    }
    return 0;
}

int countVertices(const vector<vector<int>> &adjMatrix)
{
    return adjMatrix.size();
}

int countEdges(const vector<vector<int>>& adjMatrix){
    int cnt = 0;
    int n =adjMatrix.size();
    for(int i=0;i<n;i++){
        for(int j=i+1;j<n;j++){
            cnt+=adjMatrix[i][j];
        }
    }
    return cnt;
}

vector<int> getIsolatedVertices(const vector<vector<int>> &adjMatrix)
{
    vector<int> ans;
    int n = adjMatrix.size();
    bool flag;
    for (int i = 0; i < n; i++)
    {
        flag = 0;
        for (int j = 0; j < n; j++)
        {
            if (adjMatrix[j][i])
            {
                flag = 1;
                break;
            }
        }
        if (!flag)
        {
            ans.push_back(i);
        }
    }
    return ans;
}

bool isCompleteGraph(const vector<vector<int>> &adjMatrix)
{
    int n = adjMatrix.size();
    for (int i = 0; i < n; i++)
    {
        for (int j = i + 1; j < n; j++)
        {
            if (!adjMatrix[i][j])
            {
                return 0;
            }
        }
    }
    return 1;
}

bool isBipartite(const std::vector<std::vector<int>>& adjMatrix){
    int n = adjMatrix.size();
    vector<int> v(n,-1);
    queue<int> q;
    int node;
    for(int  i=0;i<n;i++){
        if(v[i] != -1) continue;
        q.push(i);
        v[i] = 0;
        while(!q.empty()){
            node = q.front();
            q.pop();
            for(int j=0;j<n;j++){
                if(adjMatrix[node][j]){
                    if(v[j]== -1){
                        v[j] = 1-v[node];
                        q.push(j);
                    }else{
                        if(v[j] == v[node]) return 0;
                    }
                }
            }
        }
    }
    return 1;
}

bool isCompleteBipartite(const vector<vector<int>>& adjMatrix){
    int n = adjMatrix.size();
    vector<int> v(n,-1);
    vector<int> a;
    vector<int> b;
    queue<int> q;
    int node;
    for(int  i=0;i<n;i++){
        if(v[i] != -1) continue;
        q.push(i);
        v[i] = 0;
        a.push_back(i);
        while(!q.empty()){
            node = q.front();
            q.pop();
            for(int j=0;j<n;j++){
                if(adjMatrix[node][j]){
                    if(v[j]== -1){
                        v[j] = 1-v[node];
                        if(v[j]){
                            b.push_back(j);
                        }else{
                            a.push_back(j);
                        }
                        q.push(j);
                    }else{
                        if(v[j] == v[node]) return 0;
                    }
                }
            }
        }
    }
    int Asize = a.size();
    int Bsize = b.size();
    for(int i = 0;i<Asize;i++){
        for(int j=0;j<Bsize;j++){
            if(!adjMatrix[a[i]][b[j]]) return 0;
        }
    }
    return 1;
}

vector<vector<int>> convertToUndirectedGraph(const vector<vector<int>>& adjMatrix){
    int  n = adjMatrix.size();
    vector<vector<int>> ans(n,vector<int>(n,0));
    for(int i=0;i<n;i++){
        for(int j=0;j<n;j++){
            if(adjMatrix[i][j]){
                ans[i][j]=1;
                ans[j][i]=1;
            }
        }
    }
    return ans;
}

vector<vector<int>> getComplementGraph(const vector<vector<int>>& adjMatrix){
    int n = adjMatrix.size();
    vector<vector<int>> ans(n,vector<int> (n));
    for(int i=0;i<n;i++){
        for(int j=0;j<n;j++){
            ans[i][j]=1-adjMatrix[i][j];
        }
    }
    return ans;
}



vector<int> findEulerCycle(const vector<vector<int>>& adjMatrix){
    vector<vector<int>> list = convertMatrixToList2(adjMatrix);
    vector<vector<int>> grid = adjMatrix;
    int n = adjMatrix.size();
    for(int i=0;i<n;i++){
        if(list[i][0]%2) return {};
    }
    stack<int> s;
    s.push(0);
    vector<int> ans;
    int cur;
    while(!s.empty()){
        cur = s.top();
        if(list[cur][0]){
            int last = list[cur].size()-1;
            //list[cur][last] == dinh ke cua cur
            while(!grid[cur][list[cur][last]] || !grid[list[cur][last]][cur]){
                grid[cur][list[cur][last]]=0;
                grid[list[cur][last]][cur]=0;
                last--;
            }
            s.push(list[cur][last]);
            list[cur][0]--;
            list[list[cur][last]][0]--;
            grid[cur][list[cur][last]]=0;
            grid[list[cur][last]][cur]=0;
        }else{
            ans.push_back(cur);
            s.pop();
        }
    }
    return ans;
}


vector<vector<int>> dfsSpanningTree(const vector<vector<int>>& adjMatrix, int start){
    int n = adjMatrix.size();
    vector<bool> v(n,0);
    vector<vector<int>> ans(n,vector<int> (n,0));
    stack<int> s;
    s.push(start);
    v[start]=1;
    int cur;
    while(!s.empty()){
        cur = s.top();
        s.pop();
        for(int i=0;i<n;i++){
            if(adjMatrix[cur][i] && !v[i]){
                s.push(i);
                v[i]=1;
                ans[cur][i]=1;
                ans[i][cur]=1;
            }
        }
    }
    return ans;
}


vector<vector<int>> bfsSpanningTree(const vector<vector<int>>& adjMatrix, int start){
    int n = adjMatrix.size();
    vector<bool> v(n,0);
    vector<vector<int>> ans(n,vector<int> (n,0));
    queue<int> q;
    q.push(start);
    v[start]=1;
    int cur;
    while(!q.empty()){
        cur=q.front();
        q.pop();
        for(int i=0;i<n;i++){
             if(adjMatrix[cur][i] && !v[i]){
                q.push(i);
                v[i]=1;
                ans[cur][i]=1;
                ans[i][cur]=1;
            }
        }
    }
    return ans;
}

bool isConnected(int u, int v, const vector<vector<int>>& adjMatrix){
    stack<int> s;
    int cur;
    s.push(u);
    int n = adjMatrix.size();
    vector<bool> visit(n,0);
    visit[u]=1;   
    while(!s.empty()){
        cur = s.top();
        s.pop();
        if(cur == v){
            return 1;
        }
        for(int i=0;i<n;i++){
            if(adjMatrix[cur][i]){ 
                if(!visit[i]) s.push(i);
                visit[i]=1;
            }
        }
    }    
    return 0;
}

vector<int> dijkstra(int start, int end, const vector<vector<int>>& adjMatrix) {
    int n = adjMatrix.size();
    vector<bool> visit(n,0);
    vector<int> dist(n,INT_MAX);
    vector<int> pre(n,-1);
    dist[start]=0;

    for(int times=0;times<n;times++){
        int u = -1;
        int dmin = INT_MAX;
        for(int i=0;i<n;i++){
            if(!visit[i] && dmin > dist[i]){
                dmin = dist[i];
                u=i;
            }
        }
        if(u == -1 || u == end){
            break;
        }
        visit[u]=1;
        for(int i=0;i<n;i++){
            if(adjMatrix[u][i] && !visit[i]){
                if(dist[i]>dist[u]+adjMatrix[u][i]){
                    pre[i]=u;
                    dist[i]=dist[u]+adjMatrix[u][i];
                }
            }
        }
    }
    vector<int> ans;
    if (dist[end] == INT_MAX) return ans;

    for (int at=end; at!=-1; at=pre[at]){
        ans.push_back(at);  
    }    
    reverse(ans.begin(), ans.end());
    return ans;
}

vector<int> bellmanFord(int start, int end, const vector<vector<int>>& adjMatrix){
    int n = adjMatrix.size();
    vector<int> pre(n,-1);
    vector<int> dist(n,INT_MAX);

    dist[start] = 0;
    for(int i=0;i<n;i++){
        for(int u=0;u<n;u++){
            for(int v=0;v<n;v++){
                if(adjMatrix[u][v] && dist[u]!=INT_MAX){
                    if(dist[v]>dist[u]+adjMatrix[u][v]){
                        dist[v] = dist[u]+adjMatrix[u][v];
                        pre[v]=u;
                    }
                }
            }
        }
    }
    vector<int> ans;
    int sum = 0;
    int cur = end;
    ans.push_back(cur);
    cur = pre[cur];
    for(;cur!=-1;cur=pre[cur]){
        sum+=adjMatrix[cur][ans[ans.size()-1]];
        ans.push_back(cur);
    }
    if(sum<0) return {};
    reverse(ans.begin(),ans.end());
    return ans;
}
