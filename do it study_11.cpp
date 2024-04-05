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

    for(int j=0;j<n;j++){
        if(A[j]>=cons_num){
            while(A[j]>=cons_num){
                //cout<<(cons_num);
                S.push(cons_num);
                Order.push_back('+');
                cons_num++;
            }
            S.pop();
            Order.push_back('-');

        }
        else if (A[j]<cons_num){
            int su= S.top();
            S.pop();
            Order.push_back('-');
            if(su!=A[j]) { //!= 로 해도 됨, 최고점 찍고난후 팝할때는 수열에있는거랑 똑같이 나오지 않으면 NO기 때문에
                flag=1;
                break;
            }

        }
    }
/*
    while(Order.size()!=n){
        if(A[ind]>=cons_num){
            S.push(cons_num);
            Order.push_back('+');
            cons_num++;
            cout<<(cons_num);

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
    */
    if(flag==0) {
        for(int i=0;i<Order .size();i++){
            cout<<Order[i]<<"\n";
        }
    }
    else if (flag==1){
        cout<<"NO";
        
    }   



}