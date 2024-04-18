#include <iostream>
#include <vector>
#include <stack>
#include <queue>
using namespace std;

int main(void) {
    int n;
    int num;
    int cons_num=1;//비교를 위한 숫자 
    int ind=0;
    int flag=0;
    vector<int> A; // 입력값 저장
    stack<int> S;//올바른 스택수열값 저장 
    vector<char>Order; //명령결과 저장 
    cin>>n;
    for (int i=0;i<n;i++){ //입력된수열 저장 
        cin>>num;
        A.push_back(num);

    }

    for(int j=0;j<n;j++){
        if(A[j]>=cons_num){ //같아질때까지 증가하면서 push
            while(A[j]>=cons_num){
                //cout<<(cons_num);
                S.push(cons_num);
                Order.push_back('+');
                cons_num++;
            }
            S.pop(); //같아지면 pop
            Order.push_back('-');

        }
        else if (A[j]<cons_num){ // 감소해야하는경우
            int su= S.top();
            S.pop();
            Order.push_back('-');
            if(su!=A[j]) { //!= 로 해도 됨, 최고점 찍고난후 팝할때는 수열에있는거랑 똑같이 나오지 않으면 NO기 때문에
                flag=1;
                break;
            }

        }
    }

    if(flag==0) {
        for(int i=0;i<Order .size();i++){
            cout<<Order[i]<<"\n";
        }
    }
    else if (flag==1){
        cout<<"NO";
        
    }   



}