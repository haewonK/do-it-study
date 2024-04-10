// 백준 BFS 2667 단지번호 붙이기 
#include <iostream>
#include <vector>
#include <queue>
#include <string>
#include <map>
#include <algorithm>

using namespace std;
void BFS(int i,int j);
int chk[26][26]={0};
int Map[26][26]={0};
bool visited[26][26]={false};
int Ans[26*26];
int N=0;
int dx[4]={1,0,-1,0};
int dy[4]={0,1,0,-1};
int depth=0;
map<int,int> ans;
queue<pair<int,int>> q;
vector<int> Ans_sort;
int main(void) {
cin>>N;
for(int i=0;i<N;i++){
    string str;
    cin>>str;
    for(int j=0;j<N;j++){
        Map[i][j]=(str[j]-'0');
    }
}

for(int i=0;i<N;i++){
    for(int j=0;j<N;j++){
        if(Map[i][j]==1&&!visited[i][j]) {
            depth++; //첫칸넣어주는거 잊지말기 
            chk[i][j]=depth;
            Ans[depth]+=1;
            BFS(i,j);
        }
    }
}


cout<<depth<<"\n";

for(int i=0;i<(26*26);i++){
    if(Ans[i]!=0) Ans_sort.push_back(Ans[i]); 
}
sort(Ans_sort.begin(),Ans_sort.end());

for(int i=0;i<Ans_sort.size();i++){
    cout<<Ans_sort[i]<<"\n"; 
}

}

void BFS(int i,int j){
    
    q.push(make_pair(i,j));
    visited[i][j]=true;
    // 시작조건에 따라 수정하기 -0부터 시작할수도있고 1부터 시작할수도 
    while(!q.empty()){
        int now[2]={0};

        now[0]=q.front().first;
        now[1]=q.front().second;
        q.pop();
        

        for(int k=0;k<4;k++){
            int x=now[0]+dx[k];
            int y=now[1]+dy[k];
            if(x>=0&&y>=0&&x<N&&y<N){
                if(!visited[x][y]&&Map[x][y]!=0){ //벽이아니어야하고 방문한적 없어야함
                    visited[x][y]=true;
                    chk[x][y]=depth;
                    Ans[depth]+=1;
                    q.push(make_pair(x,y));
                }
            }    
        }    
    }

}

