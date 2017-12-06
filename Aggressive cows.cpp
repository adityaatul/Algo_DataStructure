#include<bits/stdc++.h>
typedef long long int lli ;
using namespace std;
int main(){
	ios_base::sync_with_stdio(0);cin.tie(NULL);cout.tie(NULL);
	int t;
	cin>>t;
	while(t--){
		int n,c;
		cin>>n>>c;
		lli arr[n];
		for(int i=0;i<n;i++){
			cin>>arr[i];
		}
		sort(arr,arr+n);
		lli l=0,r= 1000000001;
		lli ans=-1;
		while(l<=r){

			lli mid = (l+r)/2;
			lli first=arr[0];
			int tmp=1;
			for(int i=1;i<n;i++){
				if(arr[i]-first>=mid)
					++tmp,first=arr[i];
			}
			if(tmp<c){
				r=mid-1;
			}
			else{
				l=mid+1;
				ans=mid;
			}	
		}
		cout<<ans<<endl;
	}
}