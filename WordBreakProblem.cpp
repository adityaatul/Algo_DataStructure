/*

1
11
i like sam sung mobile ice cream icecream man go mango
ilikesamsung


Called ilikesamsung
The value f i 1 i likesamsung
Called likesamsung
The value f i 1 l ikesamsung
The value f i 2 li kesamsung
The value f i 3 lik esamsung
The value f i 4 like samsung
Called samsung
The value f i 1 s amsung
The value f i 2 sa msung
The value f i 3 sam sung
Called sung
The value f i 1 s ung
The value f i 2 su ng
The value f i 3 sun g
The value f i 4 sung 
Called 
1



*/


#include<bits/stdc++.h>
using namespace std;
bool solve(string word,string D[],int l){
    //int l=sizeof(D)/sizeof(D[0]);
    //int l= _countof(D);
    //cout<<s<<endl;
    for(int i=0;i<l;i++){
    //cout<<D[i]<<endl;    
        if(D[i].compare(word) == 0)
        return true;
    }
    return false;
}
bool spillWord(string s,string D[],int len){
    cout<<"Called "<<s<<endl;
    if(s.size()==0)
    return true;
    
    
    int l=s.size();
    for(int i=1;i<=l;i++){
        cout<<"The value f i "<<i<<" "<<s.substr(0,i)<<" "<<s.substr(i,l-i)<<endl;
        if(solve(s.substr(0,i),D,len) && spillWord(s.substr(i,l-i),D,len))
        return true;
    }
    return false;
}


int main()
 {
	int n;
	cin>>n;
	while(n--){
	    int s_len,l;
	    bool flag=false;
	    cin>>s_len;
	    string Dictionary[s_len],x,s_in;
	    for(int i=0;i<s_len;i++){
	    cin>>x;
	    Dictionary[i]=x;
	    }
	    cin>>s_in;
	    flag=spillWord(s_in,Dictionary,s_len);
	    (flag)?cout<<"1":cout<<"0";
	    cout<<endl;
	    
	    
	}
	return 0;
}
