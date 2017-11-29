#include<bits/stdc++.h>
using namespace std;
bool dp[1000];

bool solve(std::map<string, int> mymap,string s){
int l=s.size();

if(l == 0) return true ;
memset (dp , 0 , sizeof dp);

for(int i=1; i<=l;i++){
  if(!dp[i] && mymap[s.substr(0,i)])
  dp[i] = true ;

  if(dp[i]){
      if (i==l)return true ;

      for(int k= i+1 ; k<=l ;k++){
         if(!dp[k] && mymap[s.substr(i,k-i)])
            dp[k]=true;

            if(k == l && dp[k] == true)
            return true ;

      }

  }

}

return false;

}


int main(){

    int n;
    cin>>n;
    std::map<string, int> mymap;
    string s[n];
    for (int i=0; i < n; i++) {
      cin>>s[i];
      mymap[s[i]]++;
    }

    for(int i=0;i<n;i++){
    	--mymap[s[i]];
      if(solve(mymap,s[i]))
        cout<<s[i]<<endl;
        ++mymap[s[i]];
    }
  return 0;
}
