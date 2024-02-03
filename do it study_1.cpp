#include <iostream>
#include <string>
using namespace std;
//백준 11720 두잇1번
int main(void) {
    string numbers;
    int n;
    cin>>n;
    cin>>numbers;
    int sum=0;

    for(int i=0;i<n;i++){
        sum+=numbers[i]-'0';
    }
    cout<<sum<<endl;
    return 0;
}
