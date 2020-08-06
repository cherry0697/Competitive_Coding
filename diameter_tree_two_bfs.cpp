#include<bits/stdc++.h>
using namespace std;

#define rep(i,n) for(int i=0;i<n;i++)
#define repa(i,a,n) for(int i=a;i<=n;i++)
#define repb(i,a,n) for(int i=a;i>=n;i--)
#define trav(a,x) for(auto a=x.begin();a!=x.end();a++)
#define all(x) x.begin(),x.end()
#define fst first
#define snd second
#define pb push_back
#define mp make_pair
typedef long double ld;
typedef pair <int,int> pii;
typedef vector <int> vi;
typedef long long ll;

const int mxN=1e5+5;
vi adj[mxN];
bool visited[mxN];
int n,m;
vi d;

void pre(){

}

void bfs(int s){
  queue<int> q;
  q.push(s);
  d[s]=0;
  visited[s]=true;

  while(!q.empty()){
    int v=q.front();
    q.pop();
    for(auto x: adj[v]){
      if(!visited[x]){
        visited[x]=true;
        d[x]=d[v]+1;
        q.push(x);
      }
    }
  }
}

void solve(){
  cin>>n>>m;
  for(int i=0;i<m;i++){
    int x,y; cin>>x>>y;
    x--; y--;
    adj[x].pb(y);
    adj[y].pb(x);
  }

  memset(visited,false,sizeof(visited));
  d.resize(n,0);
  bfs(0);

  int dis=-1;
  int node=-1;

  for(int i=0;i<n;i++){
    if(d[i]>dis){
      dis=d[i];
      node=i;
    }
  }

  memset(visited,false,sizeof(visited));
  d.resize(n,0);
  bfs(node);

  int ans=-1;

  for(int i=0;i<n;i++) ans=max(ans,d[i]);

  cout<<ans<<"\n";
}

int main(){
  ios_base::sync_with_stdio(0); cin.tie(0);
  pre();
  int t; t=1;
  rep(i,t) solve();
  return 0;
}
