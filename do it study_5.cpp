#include <iostream>
#include <vector>

using namespace std;
//두잇 5번 백준 11986 

int main(){
long n,m,count=0;
cin>>n>>m;
vector<long> s(n+1,0);
long orig[m]={0};
long A[n+1]={0};
for(int i=1;i<=n;i++){
    
    cin>>A[i];
    s[i]=s[i-1]+A[i];
 
}

for(int i=0;i<n;i++){
    int re=s[i+1]%m;
    if(re==0) count++;
    orig[re]++;

}

for(int i=0;i<m;i++){

    if(orig[i]>1) count+=(orig[i]*(orig[i]-1)/2);
}
cout<<count<<endl;

}