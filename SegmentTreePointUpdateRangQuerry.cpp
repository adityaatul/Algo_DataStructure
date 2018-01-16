#include<bits/stdc++.h>
using namespace std;
int seg[10000007];
void buildSegmentTree(int idx , int start , int end){
  if (start > end)return ;
  if (start == end){
     seg[idx]=1;
     return ;
  }
  buildSegmentTree(2*idx , start , (start+end)/2);
  buildSegmentTree(2*idx+1 , 1+(start+end)/2 , end);
  seg[idx]=seg[2*idx+1]+seg[2*idx];
}
void updateSegmentTree(int idx , int start , int end , int qs , int qe , int val){
  if (start > end || qe < start || qs > end ) // Out of bound condtion ;
  return ;
  if (start == end ){
     seg[idx]=val;
     return ;
  }
  updateSegmentTree(2*idx , start , (start + end )/2 , qs , qe , val);
  updateSegmentTree(2*idx+1 ,1+(start + end )/2 , end , qs , qe , val);
  seg[idx]=seg[2*idx+1]+seg[2*idx];
}
int findSegmentTree(int idx , int start , int end , int qs , int qe){
  if (start > end || qe < start || qs > end ) // Out of bound condtion ;
     return 0 ;
  if (start >=qs && end <= qe  ){
    return seg[idx];
  }
  int q1=findSegmentTree(2*idx , start , (start + end )/2 ,  qs ,  qe);
  int q2=findSegmentTree(2*idx+1 ,1 + (start + end )/2 , end ,  qs ,  qe);
  return q1+q2;
}

int main(){

  int n ;//n is the length of array all filled with 1;
  cin>>n;
    buildSegmentTree(1,0,n-1);
  int q ;//q is the number of querry
  cin>>q;
  int x,k;
    while(q--){
      cin>>x>>k;//x is the querry type.
      if(x==0){
        //querry type 0 is update the value of the given idex  (k) with 0;
        --k;
        updateSegmentTree(1,0,n-1,k,k,0);
      }else{
        int l=0,r=n-1;
        int ans = -1;
        while(l<r){
          int mid = ( l + r )/2;
          int val = findSegmentTree(1,0,n-1,0,mid);
          if (val >= k){
            ans = mid + 1;
            r = mid - 1;
          }else{
            l = mid + 1;
          }
        }
        cout<<ans<<endl;

      }
    }
    return 0;
}
