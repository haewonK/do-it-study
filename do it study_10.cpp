#include <iostream>
#include <deque>
#include <queue>
using namespace std; 
typedef pair<int,int> Node; //index ,num 
int main(void){
    int N,M;
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    queue<int> A;
    deque<Node> D;
    int num=0;
    int index=0;
    int flag =1;
    cin>>N>>M;
    for(int i=0;i<N;i++){
        cin>>num;
        //
        if(D.size()==0) D.push_back(Node(i,num));
        
        else {
            while(D.size()>=1){
                if(D.back().second>num) D.pop_back();
                else break;
            }
            
            D.push_back(Node(i,num));
            if(D.front().first<=i-M) D.pop_front();

        }
        cout<<D.front().second<<" ";
    }
}