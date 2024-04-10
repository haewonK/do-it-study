//1012 BFS 유기농배추 
#include <iostream>
#include <queue>
#include <vector>
#include <string.h>
using namespace std;

int Map[51][51]={0,};
queue<pair<int,int>> q;
int visited[51][51]={0,};
int chk[51][51]={0,};
int dx[4]={1,0,-1,0};
int dy[4]={0,1,0,-1};
int N,M,K;
int count=0;
vector<int> ans;
void BFS(int i,int j){
    

    q.push(make_pair(i,j));
                    
    visited[i][j]=true;                    

    while(!q.empty()){  
        int now[2]={0};          
        now[0]=q.front().first; //y
        now[1]=q.front().second;//x     
        q.pop();
        for(int k=0;k<4;k++){
            int x= now[1]+dx[k];
            int y= now[0]+dy[k];
            if(x>=0&&y>=0&&x<M&&y<N){
                if(!visited[y][x]&&Map[y][x]!=0){
                    visited[y][x]=true;
                    q.push(make_pair(y,x));                
                }
            }
    
        }
    }
}
int main(void){
    int T_num;
    int map_x,map_y;
    cin>>T_num;    
    for(int i=0;i<T_num;i++){ //한 테케
        cin>>M>>N>>K; //가로 세로 개수 
        for(int a=0;a<K;a++){ //지도그리기 
            cin>>map_x>>map_y;
            Map[map_y][map_x]=1;
        }

        /*
        for(int i=0;i<N;i++){
            for(int j=0;j<M;j++){
                cout<<Map[i][j];
            }
            cout<<"\n";
        }
        */
        for(int nn=0;nn<N;nn++){
            for(int mm=0;mm<M;mm++){
                if(!visited[nn][mm]&&Map[nn][mm]==1){
                    BFS(nn,mm);
                    count++;
                }
            }
        }
        ans.push_back(count);
        count=0;
        memset(Map,0,sizeof(Map));
        memset(visited,0,sizeof(visited));
    }

    for(int i=0;i<ans.size();i++){
        cout<<ans[i]<<"\n";
    }
}