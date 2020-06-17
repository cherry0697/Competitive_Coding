ll fact[N],numinv[N],factinv[N];

const ll m=1e9+7;

ll pow(ll a,ll b) // Big Powers
{
  ll ans=1;
  while(b){
    if(b&1)
      ans=(ans*a)%m;
    a=(a*a)%m;
    b>>=1;
  }
  return ans;
}

void factorial()
{
  fact[0]=1;
  for(ll i=1;i<N;i++)
    fact[i]=(fact[i-1]*i)%m;
}

void number_inverse()
{
  numinv[0]=numinv[1]=1;
  for(ll i=2;i<N;i++)
    numinv[i]=(m-(m/i)*numinv[m%i]%m)%m;
}

void inverse_factorial()
{
  factinv[0]=factinv[1]=1;
  for(ll i=2;i<N;i++)
    factinv[i]=(numinv[i]*factinv[i-1])%m;
}

ll calculate(ll n,ll r)
{
  ll ans=fact[n];
  ans=(ans*factinv[r])%m;
  ans=(ans*factinv[n-r])%m;
  return ans;
}

void precompute()
{
  factorial();
  number_inverse();
  inverse_factorial();
}
