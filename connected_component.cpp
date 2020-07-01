const int MAXN=1e5+1;

int n;
vi graph[MAXN];
bool used[MAXN];
vi comp;

void dfs(int v){
  used[v]=true;
  comp.pb(v);
  for(auto u: graph[v]){
    if(!used[u]){
      dfs(u);
    }
  }
}

void find_comps(){
  for(int i=0;i<n;i++){
    if(!used[i]){
      comp.clear();
      dfs(i);
      cout<<"Component: ";
      for(auto x: comp){
        cout<<x<<" ";
      }
      cout<<endl;
    }
  }
}
