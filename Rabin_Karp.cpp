vi rabin_karp(string const &s, string const &t){
  const int p=31;
  const int m=1e9+9;

  int s1=s.size(),t1=t.size();

  vector<ll> p_pow(max(s1,t1));
  p_pow[0]=1;
  for(int i=1;i<p_pow.size();i++){
    p_pow[i]=(p_pow[i-1]*p)%m;
  }

  vector<ll> h(t1+1,0);
  for(int i=0;i<t1;i++){
    h[i+1]=(h[i]+(t[i]-'a'+1)*p_pow[i])%m;
  }

  ll h_s=0;
  for(int i=0;i<s1;i++){
    h_s=(h_s+(s[i]-'a'+1)*p_pow[i])%m;
  }

  vi occur;
  for(int i=0;i+s1-1<t1;i++){
    ll curr_h=(h[i+s1]+m-h[i])%m;
    if(curr_h==((h_s*p_pow[i])%m))
      occur.pb(i);
  }
  
  return occur;
}

//https://codeforces.com/problemset/problem/271/D
