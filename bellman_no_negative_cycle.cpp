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

struct edge{
  int a,b,cost;
};

int n,m,v;
vector <edge> e;
const int INF=1000000000;

void pre(){

}

void bellman(vector <int> &d,vector <int> &p){
  d.assign(n,INF);
  p.assign(n,-1);
  d[v]=0;

  for(int i=0;i<n-1;i++){
    bool any=false;
    for(int j=0;j<m;j++){
      if(d[e[j].a]<INF){
        if(d[e[j].b]>d[e[j].a]+e[j].cost){
            d[e[j].b]=min(d[e[j].b],d[e[j].a]+e[j].cost);
            p[e[j].b]=e[j].a;
            any=true;
        }
      }
    }
    if(!any) break;
  }
}

void solve(){
  cin>>n>>m;
  e.resize(m);

  for(int i=0;i<m;i++){
    cin>>e[i].a>>e[i].b>>e[i].cost;
    e[i].a--;
    e[i].b--;
  }

  cin>>v; v--;
  vi d,p;
  bellman(d,p);

  for(int i=0;i<n;i++){
    cout<<d[i]<<endl;
  }
}

int main(){
  ios_base::sync_with_stdio(0); cin.tie(0);
  pre();
  int t; t=1;
  rep(i,t) solve();
  return 0;
}
