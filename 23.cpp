#include <iostream>
#include <vector>

using namespace std;

static vector<vector<int>> A;
static vector<bool> visited;
void DFS(int v);
int main(void){
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int N,M;
    cin>>N>>M;
    A.resize(N+1);
    visited=vector<bool>(N+1,false);

    for(int i=0;i<M;i++){
        int a,b;
        cin>>a>>b;
        A[a].push_back(b);
        A[b].push_back(a);
    }
    int count=0;
    for (int i=1;i<=N;i++){
        if(!visited[i]){ //재귀 들어갈때 
            count++;
            DFS(i);
        }

    }
    cout<<count<<"\n";
}


void DFS(int v){
    if (visited[v]){ //방문한적 있는 노드라면
        return;
    }
    visited[v]=true;
    
    for (int i: A[v]){
        if(visited[i]==false){
            DFS(i);
        }
    }
}
