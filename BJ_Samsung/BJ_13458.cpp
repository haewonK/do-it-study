#include <iostream>
#include <vector>
#include <string>
#include <sstream>
using namespace std;

long long int N;//시험장개수 
vector<long long int> people; //응시자수 
long long int main_V,sub_V; //총감독관 , 서브감독관
long long int count=0;
string str;
string buf;
string ss;
int main(void) {
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    cin>>N;
    cin.ignore();
    getline(cin,str);
    //cout<<str<<"str1";
    istringstream ss(str);
    //cout<<str<<"str";
    while(getline(ss,buf,' ')){
        people.push_back(stoi(buf));
    
    }

    cin>>main_V>>sub_V;
    //cout<<"gg"<<main_V<<sub_V<<endl;
    
    for(int i=0;i<N;i++){
        long long int num=0;
        num=people[i];
        num=num-main_V;
        count++; //main 필수 
        if (num<=0) continue;
        if (num>=sub_V){
            if(num%sub_V==0) count+=num/sub_V;
            else count+=(num/sub_V)+1;           
        }
        else count++;

        //초기화
    }
    cout<<count<<"\n";
}