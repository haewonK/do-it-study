#include <iostream> 
#include <vector>
using namespace std;
vector<vector<int>> A;
vector<bool> visited;
void DFS(int v,int depth);
int count=0;
int main(void){
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int N,M;
    
    int d=1;
    cin>>N>>M;
    A.resize(N+1);
    visited=vector<bool> (N+1,false);

    for (int i=0;i<M;i++){
        int s,e;
        cin>>s>>e;
        A[s].push_back(e);
        A[e].push_back(s);
    }


    for(int i=0;i<N;i++){
        DFS(i,d);
        if(count==1) break;
        
    }

    if (count==1) {
            cout<<1;
        }
    else cout<<0;
}

void DFS(int v,int depth){  //모든 경로를 다 고려해봐야하기때문에 갔던 경로도 다시 들어가야할 필요 있어서 다시 방문 false해주는거
    if (depth==5) {
        count=1;
        return;
    }
    visited[v]=true;
    
    for(int i:A[v]){
        if (!visited[i]) DFS(i,depth+1);
    }
    visited[v]=false;

}