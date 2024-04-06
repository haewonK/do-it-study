//백준 1240 DFS와 BFS 기본구현 

#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>

using namespace std;
vector<vector<int>> A;
vector<bool> visited;
queue<int> Q;
void DFS(int value);
void BFS(int value);
int main(void){
    int N,M,R=0;
    cin>>N>>M>>R;
    A.resize(N+1);
    visited=vector<bool>(N+1,false);
    for (int i=0;i<M;i++){
        int s,e;
        cin>>s>>e;
        A[s].push_back(e);
        A[e].push_back(s);
    }
    for (int i=0;i<A.size();i++){
        sort(A[i].begin(),A[i].end());
    }

    DFS(R);//시작점부터 출발 
    visited=vector<bool>(N+1,false);
    cout<<"\n";
    BFS(R);
    

}

void DFS(int value){

    if (visited[value]) return;

    visited[value]=true;
    cout<<value<<" ";
    for(int i:A[value]){
        if(!visited[i])
        DFS(i);
    }
}

void BFS(int value){
    if(visited[value]) return;

    Q.push(value);
    visited[value]=true;
    while(!Q.empty()){
        int now_node =Q.front();
        Q.pop();
        cout<<now_node<<" ";
        for(int i:A[now_node]){
            if(!visited[i]){
                visited[i]=true;
                Q.push(i);
            }
        }

    }

}
