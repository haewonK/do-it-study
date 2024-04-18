#include <iostream>
#include <queue>
#include <vector>
#include <algorithm>
using namespace std;

//연구소 

struct POSI{
    int x,y,depth;
};
int ret;
int x,y,type;
int n,m;
bool is_end=true;
int map[8][8];
int chk[8][8];
int dx[4]={0,0,1,-1};
int dy[4]={1,-1,0,0};
queue<POSI> q;
vector<POSI> pick,space,virus,wall;



 //벽 3개뽑는 조합(재귀로) 

void pick_dfs(int pos){
    if (pick.size()==3){
        // BFS 시작 
        int candi=0;
        //초기화 
        bool visited[8][8]={false,};
        for(int aa=0;aa<n;aa++){
            for(int bb=0;bb<m;bb++){
                chk[aa][bb]=map[aa][bb];
            }
        }
        
        for(int i=0;i<3;i++){//벽그리기 
            chk[pick[i].x][pick[i].y]=1;
        }
        for(int a=0;a<virus.size();a++){
            visited[virus[a].x][virus[a].y]=true;
            q.push(virus[a]);
            while(!q.empty()){
                POSI now=q.front();
                q.pop();
                
                
                for(int k=0;k<4;k++){
                    POSI cur;
                    cur.x=now.x+dx[k];
                    cur.y=now.y+dy[k];
                    if(cur.x<0||cur.y<0||cur.x>=n||cur.y>=m) continue;

                    if(visited[cur.x][cur.y]==false&&chk[cur.x][cur.y]!=1){//퍼질수 있는거
                        visited[cur.x][cur.y]=true;
                        chk[cur.x][cur.y]=2;
                        q.push(cur);
                    }
                }
            } 
        }
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                if(chk[i][j]==0) {
                    candi+=1;
                }
            }
        }
        if(ret<candi) {
            ret=candi;
        }

        return;
    }

    for(int i=pos;i<space.size();i++){ //조합으로 벽세울공간 3개의 인덱스를 만들어야함 , space공간
        pick.push_back(space[i]);
        pick_dfs(i+1);
        pick.pop_back();
    }


}


int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    POSI target;
    cin>>n>>m;
    for(int i=0;i<n;i++){
        for(int j=0;j<m;j++){
            cin>>type;

            map[i][j]=type;
            chk[i][j]=type;
            if(type==1){ //벽
                target.x=i;
                target.y=j;
                wall.push_back(target);
            }
            else if (type==0){//빈칸
                target.x=i;
                target.y=j;
                space.push_back(target);

            }
            else if(type==2){ //바이러스위치 
                target.x=i;
                target.y=j;
                virus.push_back(target);

            }
        }
    }
    pick_dfs(0);

    cout<<ret;

    return 0;
}