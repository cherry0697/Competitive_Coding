vector<vi> compute_automata(string s){
  s+='#;
  int n=s.size();
  vi v1=prefix_function(s);
  
  vector<vi> aut(n,vi(26);
  
  for(int i=0;i<n;i++){
    for(int c=0;c<26;c++){
      if(i>0 && c+'a'!=s[i])
        aut[i][c]=aut[pi[i-1]][c];
       else
        aut[i][c]=i+(c+'a'==s[i);
    }
  }
  
  return aut;
}
