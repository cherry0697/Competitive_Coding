//set

void dijkstra(int s,vector<int> &d, vector <int> &p){
  d.assign(n,INF);
  p.assign(n,-1);

  d[s]=0;
  set <pii> q;

  q.insert({0,s});

  while(!q.empty()){
    int v=q.begin()->second;
    q.erase(q.begin());

    for(auto x: adj[v]){
      int to=x.fst;
      int len=x.snd;

      if(d[v]+len<d[to]){
        q.erase({d[to],to});
        d[to]=d[v]+len;
        p[to]=v;
        q.insert({d[to],to});
      }
    }
  }
}


// priority_queue

void dijkstra(int s,vector<int> &d, vector <int> &p){
  d.assign(n,INF);
  p.assign(n,-1);

  d[s]=0;
  priority_queue<pii,vector<pii>,greater<pii>> q;
  q.push({0,s});

  while(!q.empty()){
    int v=q.top().snd;
    int d_v=q.top().fst;
    q.pop();

    if(d_v!=d[v]) continue;

    for(auto x: adj[v]){
      int to=x.fst;
      int len=x.snd;

      if(d[v]+len<d[to]){
        d[to]=d[v]+len;
        p[to]=v;
        q.push({d[to],to});
      }
    }
  }
}
