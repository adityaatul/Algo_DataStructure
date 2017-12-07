#include<bits/stdc++.h>
using namespace std;
string s;
int n;
int dp[10][1000005][2];
int len(int num){
	int ct=0;
	while(num){
		num/=10;
		ct++;
	}
	return ct;
}
int solve(int idx,int number,int tight){
if(idx==n){
	if(len(number) == n){
		return 1;
	}else
	return 0;
}
int ans=0,&res=dp[idx][number][tight];
if(res!=-1)
	return res;

if(tight == 1){

for(int i=0;i<=s[idx]-'0';i++){
	if(i==s[idx]-'0'){
		ans+=solve(idx+1,number*10+i,1);
	}else{
		ans+=solve(idx+1,number*10+i,0);
	}
}
}else{
	for(int i=0;i<=9;i++){
		ans+=solve(idx+1,number*10+i,0);
	}
}
return res=ans;
}
int main(){
	memset(dp,-1,sizeof dp);
	cin>>s;
	n=s.size();
cout<<solve(0,0,1)<<endl;
	return 0;
}
