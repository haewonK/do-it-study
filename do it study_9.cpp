#include <iostream>
#include <vector>
using namespace std;
// do it 9번 슬라이딩 윈도우 
int main(void) {
    // A ==1 , C==2 ,G==3, T==4
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    int S=0,P=0;
    char EX;
    cin>>S>>P;
    int V_S[S]={0};
    int Temp_S[4]={0};
    int num_a=0,num_c=0,num_g=0,num_t=0;
    int count=0;
    int ind_P=0;
    for(int i=0;i<S;i++){
        cin>>EX;
        if(EX=='A') {
            V_S[i]=1;
            if (i<P) Temp_S[0]+=1;
        }
        else if(EX=='C') {
            V_S[i]=2;
            if (i<P) Temp_S[1]+=1;
        }
        else if(EX=='G') {
            V_S[i]=3;
            if (i<P) Temp_S[2]+=1;
        }
        else if(EX=='T') {
            V_S[i]=4;
            if (i<P) Temp_S[3]+=1;
        }
        
    }
    cin>>num_a>>num_c>>num_g>>num_t;
    
    for(int i=P-1;i<S;i++){
        
        if ((Temp_S[0]>=num_a)&&(Temp_S[1]>=num_c)&&(Temp_S[2]>=num_g)&&(Temp_S[3]>=num_t)) {
            count++;
          
        }


        if(i!=S-1){
            int index=0;
            index=V_S[i+1]-1;
            Temp_S[index]+=1;
          
            index=V_S[ind_P]-1;
            Temp_S[index]-=1;
            
        }
        ind_P++;
      
    }

    cout<<count;
    
}
