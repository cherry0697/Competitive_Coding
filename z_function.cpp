// Trivial Algorithm
// Complexity: O(n^2)

vi z_function(string const &s){
  int n=s.size();
  vi z(n,0);
  
  for(int i=1;i<n;i++){
    while(i+z[i]<n && s[z[i]]==s[i+z[i]])
      ++z[i];
  }
  return z;
}



// Optimized ALgo
// Complexity: O(n)

vi z_function(string const &s){
  int n=s.size();
  int l=0,r=0;
  vi z(n,0);
  
  for(int i=1;i<n;i++){
    if(i<=r)
      z[i]=min(z[i-l],r-i+1);
    while(i+z[i]<n && s[z[i]]==s[i+z[i]])
      ++z[i];
     if(i+z[i]-1>r){
       l=i;
       r=i+z[i]-1;
     }
  }
  return z;
}
