//치킨거리 
//조합 만드는 DFS 유튜브 참조 

#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;


struct POSI{
    int x,y;
};
int ret=1000000;
int n,m,type;
vector<POSI> house, shop, pick;
void dfs(int pos){
    if(pick.size()==m){ //m개만큼의 치킨집에 골라져 pick 배열에 들어간 상황 
        
        /*
        int min=0;
        for(int a=0;a<pick.size();a++){
            for(int b=0;b<house.size();b++){
                min+=abs(pick[a].x-house[b].x)+abs(pick[a].y-house[b].y);
            }
        }
        */
        




        if(ret>min) ret=min;
        
        
        return;
    }

    for(int i=pos;i<shop.size();i++){
        pick.push_back(shop[i]);
        dfs(i+1);
        pick.pop_back();//재귀빠져나올때 (1,2,3 넣고 3빼고 4넣는거 )
    }

}   

int main(){
    POSI target;
    cin>>n>>m;
    for(int x=0;x<n;x++){
        for(int y=0;y<n;y++){
            cin>>type;
            if(type==1){ //house
                target.x=x;
                target.y=y;
                house.push_back(target);
            }
            if(type==2){
                target.x=x;
                target.y=y;
                shop.push_back(target);
            }

        }
    }

    ret=0x7fffffff;
    dfs(0);
    cout<<ret;
}