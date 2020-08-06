const int mxN=1e5;
vi adj[mxN];
int timer,n;
bool vis[mxN];
vi tin,low;

void is_cutpoint(int v){
  cout<<v+1<<endl;
}

void dfs(int v,int p){
  vis[v]=true;
  timer++;
  tin[v]=low[v]=timer;
  int children=0;

  for(auto to: adj[v]){
    if(to==p) continue;
    if(vis[to]){
      low[v]=min(low[v],tin[to]);
    }
    else{
      dfs(to,v);
      low[v]=min(low[v],low[to]);
      if(low[to]>=tin[v] && p!=-1)
        is_cutpoint(v);
      ++children;
    }
  }

  if(p==-1 && children>1)
    is_cutpoint(v);
}

void find_cutpoints(){
  timer=0;
  tin.assign(n,-1);
  low.assign(n,-1);

  for(int i=0;i<n;i++){
    if(!vis[i]){
      dfs(i,-1);
    }
  }
}
