#include<iostream>
using namespace std;
#define endl '\n'
#define N 20
int m,n;
int result,element,finalElement,arr[N],finalArray[N],tempArray[N];
void backtrack(int sum,int pos){
    if(sum>n) return;
    tempArray[element++]=arr[pos-1];
    //cout << element << endl;
    
    
    for(int i=pos;i<m;i++){
        backtrack(sum+arr[i],i+1);
    }
    if(result<sum){
        //cout << result << " " << sum << endl;
        result=sum;
        finalElement=0;
        for(int i=0;i<element;i++){
            finalArray[i]=tempArray[i];
            finalElement++;
        }
        
    }
    element--;
}

int main(){
     ios_base::sync_with_stdio(0);
     while(cin >> n >> m){
         for(int i=0;i<m;i++){
             cin >> arr[i];
         }
         result=0;
         for(int i=0;i<m;i++){
             element=0;
             backtrack(arr[i],i+1);
         }
         for(int i=0;i<finalElement;i++){
             cout << finalArray[i] << " ";
         }
         
         cout << "sum:" << result << endl;
             
     }
 }
