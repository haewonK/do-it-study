//24479

#include <iostream>
#include <vector>
#include <algorithm>
#include <map>

using namespace std;
vector<vector<int>> A;
vector<bool> visited;
map<int,int> report;
int num=0;
int depth=1;
int cou=0;
void DFS(int v,int depth);

int main(void){
    
    int N,M,R;
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    cin>>N>>M>>R;
    A.resize(N+1);
    visited=vector<bool>(N+1,false);
    for(int i=0;i<M;i++){
        int s,e;
        cin>>s>>e;
        A[s].push_back(e);
        A[e].push_back(s);
    }
    for(int i=0;i<N;i++){
        sort(A[i].begin(),A[i].end());
        
    }

   DFS(R,depth);
   for(int i=1;i<=N;i++){
    if(report.find(i)==report.end()){
        report.insert({i,0});    
    }
   }
    for (auto iter : report) {
		cout << iter.second << "\n";
	}

}


void DFS(int v,int depth){
    
    if (visited[v]){
        
        return;
    }
    if(!visited[v]){
        visited[v]=true;
        cou++;
        report.insert({v,cou});
    }
    
    for(int i:A[v]){
        
        DFS(i,depth+1);
        
    }

}