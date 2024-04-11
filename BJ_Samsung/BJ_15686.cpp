//치킨거리 
//조합 만드는 DFS 유튜브 참조 

#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;


struct POSI{
    int x,y;
};
int ret=0;
int n,m,type;
vector<POSI> house, shop, pick;
void dfs(int pos){
    if(pick.size()==m){ //m개만큼의 치킨집에 골라져 pick 배열에 들어간 상황 
        
        int candi =0;
        for(int i=0;i<house.size();i++){
            int min_d=1000000;
            for(int j=0;i<pick.size();j++){ // 각 집마다 가장 가까운 치킨집과의 거리만 모아야함 
                min_d=min(min_d,abs(house[i].x-pick[j].x)+abs(house[i].y-pick[j].y));

            }
            //한 집과 최소가되는 치킨집과의 거리 저장됨 
            candi+=min_d;
        }
        if(ret>candi){
            ret=candi;
        }
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