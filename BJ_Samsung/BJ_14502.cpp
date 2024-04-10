#include <iostream>
#include <queue>
#include <vector>
#include <algorithm>
using namespace std;


struct wall{
    int virus_w;

};


int n,m;
bool is_end=true;
int map[8][8];

int dx[4]={0,0,1,-1};
int dy[4]={1,-1,0,0};


queue<pair<int,int> > org_w;
queue<pair<int,int> > new_w;


void pick_dfs(int countt, int sx, int sy){
    if (count ==3){

        return;
    }
    for(int x=sx;x<n;x++){
        for(int y=sy;y<m;y++){


        }
        
    }
}


int main() {
    cin>>n>>m;
    for(int i=0;i<n;i++){
        for(int j=0;j<m;j++){
            cin>>map[i][j];
            if(map[i][j]==1){
                org_w.push(make_pair(i,j));
            }
            else if (map[i][j]==0){
                new_w.push(make_pair(i,j));
            }
        }
    }
    

    while(is_end){
        is_end=false;

        bool visited[8][8]=false;
        
    }






    return 0;
}