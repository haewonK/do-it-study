#include <iostream>

using namespace std;
static int N;
void DFS(int num,int ja);
int isPrime(int num);
int main (void){
    
    int j=1;
    cin>>N; 
    DFS(2,j);
    DFS(3,j);
    DFS(5,j);
    DFS(7,j);

}


void DFS(int num,int ja){

    if(ja==N) { 
        if (isPrime(num)==0) {cout<<num<<"\n";
        return;
        }
    }
    for (int i=1;i<=9;i++){
        if (i%2==0) continue;
        if (isPrime(num*10+i)==0) {
            DFS(num*10+i,ja+1);
        }
    }
}

int isPrime(int num){
    for (int i=2;i<=num/2;i++){
        if (num%i==0) 
        return 1;
    }
    return 0;
}