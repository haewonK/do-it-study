#include <iostream>
#include <queue>
#include <string>
using namespace std;

int t_1[8]={0,};
int t_2[8]={0,};
int t_3[8]={0,};
int t_4[8]={0,};
void turn(int t_n[],int dir);
void check(int num,int dir);
bool t_1_f=false;
bool t_2_f=false;
bool t_3_f=false;
bool t_4_f=false;
int dir_1=0;
int dir_2=0;
int dir_3=0;
int dir_4=0;
bool f1_2=false;
bool f2_3=false;
bool f3_4=false;
queue< pair <int,int> > q;
int K=0; //회전 수 
int main(void){
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    for(int i=0;i<4;i++){
        string str;
        cin>>str;
        for(int k=0;k<8;k++){
            if (i==0) t_1[k]=int(str[k]-'0');
            else if (i==1) t_2[k]=int(str[k]-'0');
            else if (i==2) t_3[k]=int(str[k]-'0');
            else if (i==3) t_4[k]=int(str[k]-'0');
        }
    }

    cin>>K;
    for(int i=0;i<K;i++){
        int a,b;
        cin>>a>>b;
        q.push(make_pair(a,b));
        
    }
    while(!q.empty()){

            t_1_f=false;
            t_2_f=false;
            t_3_f=false;
            t_4_f=false;
            dir_1=1;
            dir_2=1;
            dir_3=1;
            dir_4=1;
            f1_2=false;
            f2_3=false;
            f3_4=false;
        int num=q.front().first;
        int dir=q.front().second;
        q.pop();


        if(t_1[2]!=t_2[6]) f1_2 =true;
        if(t_2[2]!=t_3[6]) f2_3 =true;
        if(t_3[2]!=t_4[6]) f3_4 =true;


        if(num==1){
            check(1,dir);
        }
        else if (num==2){
            check(2,dir);
        }
        else if (num==3){
            check(3,dir);
        }
        else if (num==4){
            check(4,dir);
        }

    }
    int count=(t_1[0]*1)+(t_2[0]*2)+(t_3[0]*4)+(t_4[0]*8);
    cout<<count<<"\n";
    return 0;
}
void turn(int t_n[],int dir){
    int p[8]={0,};
    if (dir==1){ //cw 
        for(int i=0;i<8;i++){
        p[i]=t_n[i];
    }

    for (int j=0;j<8;j++){
        if(j==0) t_n[j]=p[7];
        else {
            t_n[j]=p[j-1];
        }
        
    }
    }

    else if (dir==-1) {//ccw
        for(int i=0;i<8;i++){
        p[i]=t_n[i];
    }
    for (int j=0;j<8;j++){
        if(j==0) t_n[7]=p[j];
        else {
            t_n[j-1]=p[j];
        }
        
    }   
    }
}


void check(int num,int dir){ //초기 회전 번호와 회전방향 

    
    if (num==1){
        turn(t_1,dir);
        if(f1_2==true){ //1-2회전
            dir_2=(-1)*dir;
            turn(t_2,dir_2);
            t_2_f=true;
        }
        if(f2_3=true&&t_2_f==true){ // 2-3회전
            dir_3=(-1)*dir_2;
            turn(t_3,dir_3);
            t_3_f=true;

        }
        if(f3_4==true&&t_3_f==true){ //3-4회전 
            dir_4=(-1)*dir_3;
            turn(t_4,dir_4);
        }


    }   
    else if (num==2){
        turn(t_2,dir);
        if(f1_2==true){ //1-2회전
            dir_1=(-1)*dir;
            turn(t_1,dir_1);
        }
        if(f2_3==true){ // 2-3회전
            dir_3=(-1)*dir;
            turn(t_3,dir_3);
            t_3_f=true;
        }
        if(f3_4==true&&t_3_f==true){ //3-4회전 
            dir_4=(-1)*dir_3;
            turn(t_4,dir_4);
        }

    }
    else if (num==3){
        turn(t_3,dir);
        
        if(f2_3==true){ // 2-3회전
            dir_2=(-1)*dir;
            turn(t_2,dir_2);
            t_2_f=true;
        }
        if(f3_4==true){ //3-4회전 
            dir_4=(-1)*dir;
            turn(t_4,dir_4);
        }
        if(f1_2==true&&t_2_f==true){ //1-2회전
            dir_1=(-1)*dir_2;
            turn(t_1,dir_1);
        }

    }
    else if (num==4){
        turn(t_4,dir);
        if(f3_4==true){ //3-4회전 
            dir_3=(-1)*dir;
            turn(t_3,dir_3);
            //cout<<"HH"<<endl;
            t_3_f=true;
        }
        if(f2_3==true&&t_3_f==true){ // 2-3회전
            dir_2=(-1)*dir_3;
            turn(t_2,dir_2);
            t_2_f=true;
        }
        if(f1_2==true&&t_2_f==true){ //1-2회전
            dir_1=(-1)*dir_2;
            turn(t_1,dir_1);
        }

    }

    
}