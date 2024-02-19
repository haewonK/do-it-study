#include <iostream>
using namespace std;
 //두잇 6번 투포인터 기초 
 
int main(void) {
    int n;
    int start_ind=1;
    int end_ind=1;
    int count=1;
    int sum=1;

    cin>>n;
    while(end_ind !=n){

        if (sum==n) { //end++은 범위확장
            count++;
            end_ind++;
            sum=sum+end_ind;
        }
        else if (sum>n) { // 값이 크면 안에 가능성을 염두에 두고 start 늘리면서 연속이 될 수 있는 범위 줄여가기 
            sum=sum-start_ind; 
            start_ind++;
        }

        else if (sum<n){ //작다면 범위확장 
            end_ind++;
            sum=sum+end_ind;
        }
    }
    cout<<count<<"\n";

}