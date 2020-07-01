vector<vi> graph;
int n; // Number of Vertices

vector <bool> visited;

void dfs(int v){
  visited[v]=true;
  for(auto u: graph[v]){
    if(!visited[u])
      dfs(u);
  }
}
