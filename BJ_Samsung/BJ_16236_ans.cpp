#include <iostream>

#include <queue>
using namespace std;
struct shk{
    int y,x,time;

};

int n;
int map[20][20];
int dy[4]={0,0,-1,1};
int dx[4]={1,-1,0,0};
int shark_size , shark_eat;

shk s;

int main (){
    cin>>n;

    for(int y=0;y<n;++y){
        for(int x=0;x<n;++x){
            cin>>map[y][x];
            if(map[y][x]==9){
                s.y=y;
                s.x=x;
                s.time=0;
                shark_size=2;
                shark_eat=0;
                map[y][x]=0;
            }
        }
    }


    bool is_eat= true;
    while(is_eat){
        is_eat=false;
        bool visited[20][20]={false,};
        queue<shk>q;
        visited[s.y][s.x]=true;

        q.push(s);//초기 상어위치 넣기 
        
        shk min; //거리가 최소가 되는 먹을수있는 상어 
        min.y=20;
        min.time=-1;
        while(!q.empty()){
            shk cur=q.front(); //현재 상어값 (먹고나서 갱신된)
            q.pop();
            if(min.time!=-1 && min.time<cur.time ) break; //가장 가까운 물고기는 이미 잡았다 (time 이 갱신이 되었고 , 지금노드가 가리키는 거리보다 가까운거리가 입력된적이 있음을 의미)
            

            if (map[cur.y][cur.x] < shark_size && map[cur.y][cur.x]!=0) { //먹을 수 있음 ,최소가 되는 노드를 넣기 
                is_eat=true;
                if(min.y>cur.y||(min.y==cur.y && min.x>cur.x)){ //거리가 최소인 노드 

                    min=cur;
                }
            }
            for(int k=0;k<4;k++){ //연관노드들을 넣는 과정 ,지나갈수있으면 time 증가시키면서 큐에 넣기 
                shk next;
                next.y=cur.y+dy[k];
                next.x=cur.x+dx[k];
                next.time= cur.time+1;
                if(next.y<0 || next.x<0|| next.x>=n||next.y>=n) continue;

                if(!visited[next.y][next.x]&&shark_size>=map[next.y][next.x]){ //지나갈수있는지 
                    visited[next.y][next.x]=true;
                    q.push(next);
                }
            }
        }
        if(is_eat) {
            s=min;
            shark_eat++;
            if(shark_eat==shark_size){ 
               shark_size++;
                shark_eat=0;
            }
            map[s.y][s.x]=0;   
        }
    }
    cout<<s.time;
}