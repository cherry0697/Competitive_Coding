void kadanes(int a[],int n){
  int ans=a[0];
  int ans_l=0;
  int ans_r=0;

  int sum=0;
  int minus_pos=-1;

  for(int r=0;r<n;r++){
    sum+=a[r];
    if(sum>ans){
      ans=sum;
      ans_l=minus_pos+1;
      ans_r=r;
    }

    if(sum<0){
      sum=0;
      minus_pos=r;
    }
  }
}
