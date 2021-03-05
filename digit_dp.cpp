vector <int> num;
int cache[12][2][12];

int dp(int idx,int less,int cond)
{
  if(idx==num.size())
  {
    if(cond)
      return 1;
    else
      return 0;
  }

  int &ans=cache[idx][less][cond];
  if(ans!=-1)
    return ans;

  ans=0;

  int lo=0,hi=num[idx];

  if(less)
    hi=9;

  for(int i=lo;i<=hi;i++)
  {
    if(i<num[idx] || less)
      ans+=dp(idx+1,1,cond);
    else
      ans+=dp(idx+1,0,cond);
  }

  return ans;
}

int solve(int n)
{
  num.clear();
  while(n)
  {
    num.push_back(n%10);
    n/=10;
  }

  reverse(num.begin(),num.end());
  memset(cache,-1,sizeof(cache));
  int ans=dp(0,0,0);
  return ans;
}
