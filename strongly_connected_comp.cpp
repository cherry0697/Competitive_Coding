// Cherry
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

const int mxN=1e5;
vi adj[mxN];
vi adjtr[mxN];
bool visited[mxN];
int n,m;
vi comp;
vi order;

void pre(){

}

void dfs1(int v){
  visited[v]=true;
  for(auto x: adj[v]){
    if(!visited[x]){
      dfs1(x);
    }
  }

  order.pb(v);
}

void dfs2(int v){
  visited[v]=true;
  comp.pb(v);
  for(auto x: adjtr[v]){
    if(!visited[x]){
      dfs2(x);
    }
  }
}

void solve(){
  cin>>n>>m;
  for(int i=0;i<m;i++){
    int x,y; cin>>x>>y;
    x--; y--;
    adj[x].pb(y);
    adjtr[y].pb(x);
  }

  memset(visited,false,sizeof(visited));

  for(int i=0;i<n;i++){
    if(!visited[i]){
      dfs1(i);
    }
  }

  memset(visited,false,sizeof(visited));

  for(int i=0;i<n;i++){
    int v=order[n-i-1];
    if(!visited[v]){
      comp.clear();
      dfs2(v);
      cout<<"Comp: ";
      for(auto x: comp){
        cout<<x+1<<" ";
      }
      cout<<"\n";
    }
  }
}

int main(){
  ios_base::sync_with_stdio(0); cin.tie(0);
  pre();
  int t; cin>>t;
  rep(i,t) solve();
  return 0;
}
