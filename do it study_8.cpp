#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
// 0과 중복된 수가 있으니 정렬기준 왼쪽것들로만 합을 만들어야한다는 보장은 없음 전체범위를 다 탐색해야함 
int main(void) {
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    int n;
    cin>>n;
    vector<long long> A(n,0);
    int start_ind=0;
    int end_ind=0;
    int count=0;
    for(int i=0;i<n;i++){
        cin>>A[i];
    }
    sort(A.begin(),A.end());
    
    for(int k=0;k<n;k++){ //좋다찾기 
        start_ind=0;
        end_ind=n-1;
        while(start_ind<end_ind){ // start와 end의 인덱스 같아지는 경우는 두수의 합이아니니까 안됨, <=이면XX 
            if(A[start_ind]+A[end_ind]==A[k]){
                if (start_ind !=k && end_ind != k) {
                    count++;
                    break;
                }
                else if (end_ind == k) end_ind--; // 022 있을때 가운데 2가 왼쪽0과 오른쪽 2의합으로 생기는경우 고려 
                else if (start_ind == k) start_ind++; // 00012일때 처음 0이 2번째0과 세번쨰 0의 합으로 생기는 경우 고려
            }
            else if (A[start_ind]+A[end_ind]>A[k]) {
                end_ind--;    
            }
            else if (A[start_ind]+A[end_ind]<A[k]) {
                start_ind++;
            }
        }
    }
    cout<<count<<"\n";


}