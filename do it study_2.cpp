#include <iostream>
#include <vector>

using namespace std;

int main(void){

    int n;
    int grade;
    int max=0;
    int sum=0;
    cin>>n;
    for(int i=0;i<n;i++){

        cin>>grade;
        sum+=grade;
        if(grade>=max) max=grade;
        
    }
    cout<<(((float)sum*100/n)/(float)max);

    return 0;
}