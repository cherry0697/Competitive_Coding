vector<vi> graph;
int n; // Number of Edges 
int s; // Source Vertex

queue<int> q;
vector<bool> used;
vi d(n),p(n);

q.push(s);
used[s]=true;
d[s]=0;
p[s[=-1;

while(!q.empty()){
  int v=q.front();
  q.pop();
  for(int u: graph[v]){
    if(!used[u]){
      q.push(u);
      d[u]=d[v]+1;
      p[u]=v;
      used[u]=true;
    }
  }
}


// Path restore

if(!used[u]){
  cout<<"NO Path"<<endl;
}
else{
  vi path;
  for(int v=u;v!=-1;v=p[v]){
    path.pb(v);
  }
  reverse(all(path));
  for(auto x: path)
    cout<<x<<" ";
  cout<<endl;
}
