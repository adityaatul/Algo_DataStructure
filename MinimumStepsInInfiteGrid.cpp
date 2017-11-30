// Input : X and Y co-ordinates of the points in order. 
// Each point is represented by (X[i], Y[i])
bool ans(int X,int Y ,int n ,int m){
    return (X>=0 && Y>=0 && X<n && Y<m );
}

/*
Covering the maximum possiable diagonal distance at first , and then covering the left over horizontal or vertical distance !
*/
int Solution::coverPoints(vector<int> &X, vector<int> &Y) {
    int XX[]= {1,-1,0,0,1,-1};
    int YY[]= {1,-1,-1,1,0,0};
    int n = X.size();
    int m = Y.size();
    int ans=0;
    for(int i=1;i<n;i++){
       ans = ans + (abs(X[i]-X[i-1])<abs(Y[i]-Y[i-1])?abs(Y[i]-Y[i-1]):abs(X[i]-X[i-1]));
             
        
    }
    return ans;
}

