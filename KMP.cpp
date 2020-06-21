// Trivial Algorithm 
// Complexity: O(n^3)

vi prefix_function(string const &s){
  int n=s.size();
  vi pi(n);
  
  for(int i=0;i<n;i++){
    for(int k=0;k<=i;k++){
      if(s.substr(0,k)==s.substr(i-k+1,k)){
        pi[i]=k;
      }
    }
  }
  
  return pi;
}

// Optimized 
// Complexity: O(n)

vi prefix_function(string const &s){
  int n=s.size();
  vi pi(n);
  pi[0]=0;
  for(int i=1;i<n;i++){
    int j=pi[i-1];
    while(j>0 && s[i]!=s[j])
      j=pi[j-1];

    if(s[i]==s[j]) j++;
    pi[i]=j;
  }
  return pi;
}
