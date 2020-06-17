ll gcd(ll a, ll b, ll &x, ll &y){

  if(b==0){
    x=1;
    y=0;
    return a;
  }

  int x1,y1;
  int d=gcd(b,a%b,x1,y1);
  x=y1;
  y=x1-(a/b)*y1;

  return d;
}

ll modular_inverse(ll a,ll m){

  ll x,y;
  ll g=gcd(a,m,x,y);

  if(g!=1)
    return -1;
  else{
    x=(x%m+m)%m;
    return x;
  }

}

bool any_solution(ll a,ll b,ll c,ll &x0, ll &y0, ll g){

  g=gcd(abs(a),abs(b),x0,y0);
  if(c%g!=0)
    return false;

  x0*=c/g;
  y0*=c/g;

  if(a<0)
    x0*=-1;
  if(b<0)
    y0*=-1;
    
  return true;
}
