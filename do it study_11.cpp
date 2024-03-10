#include <iostream>
#include <vector>
#include <stack>
#include <queue>
using namespace std;

int main(void) {
    int n;
    int num;
    int cons_num=1;
    int ind=0;
    int flag=0;
    vector<int> A;
    stack<int> S;
    vector<char>Order;
    cin>>n;
    for (int i=0;i<n;i++){
        cin>>num;
        A.push_back(num);
    }
    while(Order.size()!=n){
        if(A[ind]>cons_num){
            S.push(cons_num);
            Order.push_back('+');
            cons_num++;
        }
        else if (A[ind]==cons_num){
            S.pop();
            Order.push_back('-');
            ind++;
        }
        else if (A[ind]<cons_num){
            S.pop();
            Order.push_back('-');
            if(cons_num==n) {
                flag=1;
                break;
            }
            ind++;
            
        }
        

    }
    if(flag==0) {
        for(int i=0;i<n;i++){
            cout<<Order[i]<<"\n";
        }
    }
    else if (flag==1){
        cout<<"NO";
        cout<<ind;
    }   



}