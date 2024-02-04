#include <iostream>
#include <vector>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int n,m;
    int X1,X2,Y1,Y2;
    cin>>n>>m;
    int a=0;
    //vector<vector<int>> A(n+1,vector<int>(n+1,0));
    vector<vector<int>> D(n+1,vector<int>(n+1,0));
    for(int i=1;i<=n;i++){
        for(int j=1;j<=n;j++){
            cin>>a;
            D[i][j]=D[i][j-1]+D[i-1][j]-D[i-1][j-1]+a;

        }
    }
    for(int i=0;i<m;i++){
        
        cin>>X1>>Y1>>X2>>Y2;
        int sum=D[X2][Y2]-D[X2][Y1-1]-D[X1-1][Y2]+D[X1-1][Y1-1];
        cout<<sum<<"\n";
    }  
}

