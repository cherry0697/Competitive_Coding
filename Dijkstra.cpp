const int mxN=1e5+5;
vector<pii> adj[mxN];
const int INF=1000000000;
int n;

void dijkstra(int s,vector<int> &d, vector <int> &p){
  d.assign(n,INF);
  p.assign(n,-1);
  vector <bool> visited(n,false);

  d[s]=0;

  for(int i=0;i<n;i++){
    int v=-1;

    for(int j=0;j<n;j++){
      if(!visited[j] && (v==-1 || d[j]<d[v])){
        v=j;
      }
    }

    if(d[v]==INF)
      break;

    visited[v]=true;

    for(auto x: adj[v]){
      int to=x.fst;
      int len=x.snd;

      if(d[v]+len<d[to]){
        d[to]=d[v]+len;
        p[to]=v;
      }
    }
  }
}

vector<int> restore_path(int s,int t, const vector<int> &p){
  vector <int> path;

  for(int v=t;v!=s;v=p[v]){
    path.push_back(v);
  }

  path.push_back(s);
  reverse(path.begin(),path.end());

  return path;
}
