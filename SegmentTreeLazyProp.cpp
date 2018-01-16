#include<bits/stdc++.h>
using namespace std;
int seg[15];
int lazy[15];
int arr[]={1,2,3,4,5,6,7};

void buildSegmentTree(int node,int start,int end){
  if(start>end)
  return ;
  if(start==end){
    seg[node]=arr[start];
    return ;
  }
  buildSegmentTree(2*node,start,(start+end)/2);
  buildSegmentTree(2*node+1,1+(start+end)/2,end);
}
int findSegmentTree(int node,int start,int end,int qs,int ql){
  if(!lazy[node]){
    seg[node]+= lazy[node];
    lazy[node*2]+=lazy[node];
    lazy[node*2+1]+=lazy[node];
    lazy[node]=0;
  }
  if(start > end || start > ql || end < qs) // querry range out of the give start end .
  return 0;

  if(qs<=start || ql>=end)
  return seg[node];

  int q1=findSegmentTree(node*2,start,(start+end)/2,qs,ql);
  int q2=findSegmentTree(node*2 + 1,1+(start+end)/2,end,qs,ql);
  return q1+q2;


}
void updateSegmentTree(int node,int start,int end,int qs,int ql,int val){
  if(!lazy[node]){
    seg[node]+= lazy[node];
    lazy[node*2]+=lazy[node];
    lazy[node*2+1]+=lazy[node];
    lazy[node]=0;
  }
  if (start > end || start > ql || end < qs)
  return ;

  if (qs<=start && ql>=end){
    tree[node]+=val;
    if(start!=end){
      lazy[node*2]+=val;
      lazy[node*2+1]+=val;
    }
    return ;
  }
  updateSegmentTree(node*2,start,(start+end)/2,qs,ql,val);
  updateSegmentTree(node*2+1,1+(start+end)/2,end,qs,ql,val);
  seg[node]=val;
}

int main(){
int node=1,start=0,end=6;
buildSegmentTree(node,start,end);

}
