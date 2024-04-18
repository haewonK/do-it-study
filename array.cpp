#include <iostream>

using namespace std;

int main(){
    int n=5;
    int a=1;
    int array[5][5];
    int array_tmp[5][5];
    for(int i=0;i<n;i++){
        for(int j=0;j<5;j++){
            array[i][j]=a;
            array_tmp[i][j]=a;
            a++;

        }
    }

    for(int i=0;i<n;i++){
        for(int j=0;j<n;j++){
            cout<<array[i][j]<<" ";
        }
        cout<<endl;
    }

    

    for(int i=0;i<n;i++){
        for(int j=0;j<n;j++){
            array[n-1-j][i]=array_tmp[i][j];
        }
    }

    
    for(int i=0;i<n;i++){
        for(int j=0;j<n;j++){
            cout<<array[i][j]<<" ";
        }
        cout<<endl;
    }

    
    for(int i=0;i<n;i++){
        for(int j=0;j<n;j++){
            array[j][n-1-i]=array_tmp[i][j];
        }
    }
    

    
    for(int i=0;i<n;i++){
        for(int j=0;j<n;j++){
            cout<<array[i][j]<<" ";
        }
        cout<<endl;
    }



}
