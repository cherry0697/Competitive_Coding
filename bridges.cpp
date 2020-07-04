const int mxN=1e5;
vi adj[mxN];
bool vis[mxN];
int n;
vi tin,low;
int timer;

void is_bridge(int v,int to){
  cout<<v+1<<"-"<<to+1<<endl;
}

void dfs(int v,int p){
  vis[v]=true;
  tin[v]=low[v]=timer++;
  for(int to: adj[v]){
    if(to==p) continue;
    if(vis[to]){
      low[v]=min(low[v],low[to]);
    }
    else{
      dfs(to,v);
      low[v]=min(low[v],low[to]);
      if(low[to]>tin[v]){
        is_bridge(v,to);
      }
    }
  }
}

void find_bridges(){
  timer=0;
  memset(vis,false,sizeof(vis));
  tin.assign(n,-1);
  low.assign(n,-1);
  for(int i=0;i<n;i++){
    if(!vis[i]){
      dfs(i,-1);
    }
  }
}
