
#include <iostream>
#include <queue>


using namespace std;


struct shark{
    
    int y;
    int x;
    int time;

};
//int dx[4]={1,-1,0,0};
//int dy[4]={0,0,1,-1};

int dy[4]={0,0,-1,1};
int dx[4]={1,-1,0,0};

int n;
int shark_size;
int shark_eat;
int map[20][20];

shark s;

int main(){

    cin >>n;
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

    bool is_eat=true;
    while(is_eat){
        is_eat=false;
        
        bool visited[20][20]={false,};

        queue<shark> q;
        visited[s.y][s.x]=true;
        q.push(s);

        shark min;
        min.y=20;
        min.time=-1;

        while(!q.empty()){
            shark cur=q.front();
            q.pop();
            //들어온 한 노드에 대한 탐색

            if (min.time !=-1 && min.time<cur.time ) break; // 아예 0이면 q를 다 돌아서 나갈것,얘는 가까운거 찾았으니 나가란 뜻 

            if (map[cur.y][cur.x] < shark_size && map[cur.y][cur.x]!=0) {
                is_eat=true;
                if(min.y>cur.y||(min.y==cur.y && min.x>cur.x)){//먹을 수 있다면 가장왼쪽 위의 물고기 먹기 
                //cout<<"cur_x"<<cur.x<<" cur_y : "<<cur.y;
                    min=cur;
                
                }
            }
        
            for(int k=0;k<4;++k){ //들어온 노드로부터 뻗어나갈 수 있는 노드들 추가하기
                shark next;
                next.y=cur.y+dy[k];
                next.x=cur.x+dx[k];
                next.time = cur.time + 1;

               if (next.x < 0 || next.y < 0 || next.x >=n || next.y>=n) continue;

                if(visited[next.y][next.x]==false && map[next.y][next.x]<=shark_size){
                    visited[next.y][next.x]=true;
                    q.push(next);
                }

            }
        }
        if(is_eat){
            s=min; //다음 이어서 할수 있도록 
            
            ++shark_eat;

            if(shark_eat==shark_size){
                ++shark_size;
                shark_eat=0;
            }
            map[s.y][s.x]=0;
        }
    }
    cout<<s.time;


}
