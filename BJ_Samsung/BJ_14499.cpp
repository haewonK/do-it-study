#include <iostream>
#include <string>
#include <vector>
#include <sstream>

using namespace std;

int ju[7]={0,0,0,0,0,0,0};
//인덱스 1번 - 윗면 ,인덱스 6번 밑면 
int m[21][21]={0,};
string str;
string buf;
vector<int> s;
//x 세로 y 가로 , N 세로 M 가로 
//동 서 북 남  
int dx[4]={0,0,-1,1};
int dy[4]={1,-1,0,0};
void ju_turn(int case_v);
int main(void) {
    int N,M,X,Y,K;
    cin>>N>>M>>X>>Y>>K;
    int case_v[K]={0};
    cin.ignore();

    for(int i=0;i<N;i++){
        getline(cin,str);
        istringstream ss1(str);
        while(getline(ss1,buf,' ')){
            s.push_back(stoi(buf));
        }
        for(int j=0;j<M;j++){
            m[i][j]=s[j];
        }
        s.clear();

    }
    
    getline(cin,str);
    istringstream ss2(str);
    int aa=0;
    while(getline(ss2,buf,' ')){
        case_v[aa]=(stoi(buf));
        aa++;
    }
    for(int i=0;i<K;i++){
        int num=case_v[i];
        int x=X+dx[num-1];
        int y=Y+dy[num-1];
        if(x>=0&&y>=0&&x<N&&y<M){
            
            ju_turn(num);
            if(m[x][y]==0){
                m[x][y]=ju[6];
            }
            else {
                ju[6]=m[x][y];
                m[x][y]=0;
            }
            X=x;
            Y=y;
            cout<<ju[1]<<"\n";
        }
        

        //for(int j=1;j<=7;j++){
        //    cout<<ju[j];
        //}
        //cout<<"\n";
    }
    

}

void ju_turn(int case_v){
    int pred_ju[7]={0,0,0,0,0,0,0};

    if (case_v==1){
        //동쪽으로 굴리기 
        pred_ju[4]=ju[1];
        pred_ju[2]=ju[2];
        pred_ju[1]=ju[3];        
        pred_ju[6]=ju[4];        
        pred_ju[5]=ju[5];        
        pred_ju[3]=ju[6];  
    }
    else if (case_v==2){
        //서쪽으로
        pred_ju[3]=ju[1];
        pred_ju[2]=ju[2];
        pred_ju[6]=ju[3];        
        pred_ju[1]=ju[4];        
        pred_ju[5]=ju[5];        
        pred_ju[4]=ju[6];        
        
        

    }
    else if (case_v==3){
        //북쪽으로
        pred_ju[2]=ju[1];
        pred_ju[6]=ju[2];
        pred_ju[3]=ju[3];        
        pred_ju[4]=ju[4];        
        pred_ju[1]=ju[5];        
        pred_ju[5]=ju[6];  
    }
    else if (case_v==4){
        //남쪽으로
        pred_ju[5]=ju[1];
        pred_ju[1]=ju[2];
        pred_ju[3]=ju[3];        
        pred_ju[4]=ju[4];        
        pred_ju[6]=ju[5];        
        pred_ju[2]=ju[6]; 
    }
    
    ju[1]=pred_ju[1];
    ju[2]=pred_ju[2];
    ju[3]=pred_ju[3];
    ju[4]=pred_ju[4];
    ju[5]=pred_ju[5];
    ju[6]=pred_ju[6];

}
