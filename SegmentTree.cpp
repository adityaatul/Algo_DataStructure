#include<tuple>
#include<stdio.h>
#include<iostream>
#include<vector>
#include<algorithm>
#include<string>
#include<string.h>
using namespace std;


int Arr[]={1,2,3,4,5,6,7};
int Seg[15];
//Segement tree size is 2*n + 1 , n leaf node , total node in a binaray tree
/*
3
1
0 6
0
0 6 1
1
2 6
*/

void buildSegmentTree(int idx,int start,int end)
{
  if(start>end)
    return ;
  if(start == end ) {
    Seg[idx]=Arr[start];
    return;
  }
  buildSegmentTree(2*idx,start,(start+end)/2);
  buildSegmentTree(2*idx+1,1+(start+end)/2,end);
  Seg[idx]=Seg[2*idx]+Seg[2*idx+1];

}

void updateSegmentTree(int idx,int start,int end,int qs,int qe,int val)
{

  if(start > end || qs > end || qe < start)
  return ;
  if(start == end){
  Seg[idx]+=val;
  return ;
  }
  updateSegmentTree(2*idx , start , (start+end)/2 , qs , qe , val);
  updateSegmentTree(2*idx+1 , 1+(start+end)/2 , end , qs , qe , val);
  Seg[idx]+=Seg[2*idx]+Seg[2*idx+1];
}

int findSegmentTree(int idx,int start,int end,int qs,int qe){
  if(start>end)
    return 0;
  if(start > end || qs > end || qe < start)
    return 0;
  if(start>qs && end < qe)
    return Seg[idx];
  int q1 = findSegmentTree(2*idx , start , (start+end)/2, qs , qe);
  int q2 = findSegmentTree(2*idx+1 , 1+(start+end)/2 , end , qs , qe);
    return q1+q2;
}


int main(){
  int q; //scanning the querry
  cin>>q;
  //q=0 for update , range update , with a value
  //q=1 for displaying a given range sum
  int start=0,end=6,idx=1;
  //Intinializing the indexes with the convention values of indexes
  buildSegmentTree(idx,start,end);
  while (q--) {

    int x;
    cin>>x;
    if(x==0){
      //update querry
      int qs,qe,val;
      //querry start , querry end , value to be updated with
      cin>>qs>>qe>>val;
      updateSegmentTree(idx,start,end,qs,qe,val);
    }
    else{
      int qs,qe;
      cin>>qs>>qe;
      cout<<findSegmentTree(idx,start,end,qs,qe)<<endl;
    }
  }


return 0;
}
