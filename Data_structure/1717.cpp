#include <iostream>
#include <vector>


using namespace std;
int n,m;
vector<int> p;

int find_f(int a){
    if(a==p[a]) return a; //재귀일때는 1-1처럼 대표값찾았을때

    else {
        return p[a]= find_f(p[a]);// 재귀 빠져나가면서 거쳐간 노드 모두 대표값으로 변경
    }

}

void union_f(int a,int b){
    a=find_f(a);
    b=find_f(b);
    if(a!=b){
        p[b]=a;
    }

}
bool check(int a, int b){
    a=find_f(a);
    b=find_f(b);
    if(a==b) return true;
    else return false;
}



int main(){
    ios:: sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    cin>>n>>m;

    p.resize(n+1);
    
    for (int i=0;i<=n;i++){ //n+1 범위조심
        p[i]=i;
    }
    
    for(int i=0;i<m;i++){
        int o,v1,v2;
        cin>>o>>v1>>v2;
        if(o==0) {
            union_f(v1,v2);
        }
        else if(o==1) {
            if (check(v1,v2)==true) cout<<"YES"<<"\n";
            else cout<<"NO"<<"\n";
        }

    }



}