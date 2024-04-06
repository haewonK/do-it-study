//1920 이진탐색
#include <iostream>
#include <vector>
#include <algorithm>
#include <sstream>
using namespace std;
int main(void){
int N,M;
string str;
string buf;
cin >>N;
cin>>str;
vector<int> num;
vector<int> check;
vector<int> ans;
istringstream ss1(str);

while(getline(ss1,buf,' ')){
    num.push_back(stoi(buf));
}

sort(num.begin(),num.end());
cin>>M;

cin>>str;
while(getline(ss1,buf,' ')){
    check.push_back(stoi(buf));
}
for(int i=0;i<check.size();i++){
    int mid=0;
    mid=num[i/2];
    while(1){
        if(check[i]<mid){
            mid;// a모르겠다 풀이보기 
        }
        else if (check[i]>mid){

        }
        else if (check[i]==mid) {
            ans.push_back(1);
            break;
        }
    }
}

}

