//2178 미로 탐색
#include <iostream>
#include <vector>
#include <queue>

using namespace std;


//동남서북 
int dx[4]={1,0,-1,0};
int dy[4]={0,1,0,-1};
int A[101][101]={0};
bool visited[101][101]={false};
int N,M=0;
void BFS(int i,int j);
int main(void){

    string num;
    cin>>N>>M;

    for(int i=0;i<N;i++){
        cin>>num;
        for(int j=0;j<M;j++){
        A[i][j]=(num[j]-'0');
        }
        
    } 
    BFS(0,0);
    cout<<A[N-1][M-1]<<"\n";
}

void BFS(int i,int j){
    queue<pair<int,int>> q;
    q.push(make_pair(i,j));
    visited[i][j]=true;
    
    while(!q.empty()){
        int now_node[2];
        now_node[0]=q.front().first;
        now_node[1]=q.front().second;
        q.pop();
        

        for(int k=0;k<4;k++){
            int x= now_node[0]+dx[k];
            int y= now_node[1]+dy[k];

            if (x>=0 && y>=0 && x < N && y < M){
                if(!visited[x][y]&&A[x][y]!=0) {//0(벽)이 아니어야하고 방문한적 없어야함 
                visited[x][y]=true;
                A[x][y]=A[now_node[0]][now_node[1]]+1;
                q.push(make_pair(x,y)); //큐에 기록 
                }

            }
        }
    }
}
