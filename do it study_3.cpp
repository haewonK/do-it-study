#include <iostream>

using namespace std;

int main(void){

    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    int n,m,a;
    int I,J;
    cin>>n>>m;
    int s[n];
    for(int i=0;i<n;i++){
        cin>>a;
        if(i==0) s[i]=a;
        else s[i]=s[i-1]+a;

    }  
    for (int k=0;k<m;k++){
        cin>>I>>J;
        cout<<s[J-1]-s[I-2]<<"\n";
    }

    return 0;
}