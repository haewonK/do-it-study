#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main(void) {
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
int n=0,m=0;
cin>>n>>m;
vector<int> input(n,0);

for(int i=0;i<n;i++){
cin>>input[i];
}
sort(input.begin(),input.end());
int start_ind=0;
int end_ind=n-1;
int count=0;

while(start_ind<end_ind) {
    if (input[start_ind]+input[end_ind]==m) {
        count++;
        start_ind++;
        end_ind--;
    } 
    else if (input[start_ind]+input[end_ind]>m){
        end_ind--;
  

    }
    else if (input[start_ind]+input[end_ind]<m){
        start_ind++;
    }

}
cout<<count<<"\n";

}