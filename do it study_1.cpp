#include <iostream>
#include <string>
using namespace std;
//백준 11720 두잇1번
int main(void) {
   int n=0;
   string numbers;
   int sum=0;
   cin>>n;
   cin>>numbers;
   for(int i=0;i<n;i++){
      sum+=numbers[i]-'0';
   }
   cout<<sum<<endl;
   return 0;
}

