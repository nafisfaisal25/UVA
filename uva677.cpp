#include<iostream>
using namespace std;
#define endl '\n'
int g[10][10];
bool isVisited[10];
int n,l;
bool flag=false;
void backtrack(int u,int dis,int element,int *result){
    if(dis==l){
        flag=true;
        cout << "(";
        for(int i=0;i<element-1;i++){
            cout << result[i] << ",";
        }
        cout << result[element-1] << ")" << endl;
        return;
    }
    
    for(int i=0;i<n;i++){
        if(g[u][i] && !isVisited[i]){
            result[element++]=i+1;
           // cout << u+1 << " " << i+1 << endl;
            isVisited[i]=true;
            backtrack(i,dis+1,element,result);
            element--;
            isVisited[i]=false;
        }
        //element--;
    }
}

int main(){
    ios_base::sync_with_stdio(0);
    int x;
    int t=0;
    while(cin >> n >> l){
        if(t)cout << endl;
        for(int i=0;i<n;i++){
            for(int j=0;j<n;j++){
                g[i][j]=0;
            }
            isVisited[i]=false;
        }
        
        for(int i=0;i<n;i++){
            for(int j=0;j<n;j++){
                cin >> g[i][j];
            }
        }
        /*
        for(int i=0;i<n;i++){
            for(int j=0;j<n;j++){
                cout << g[i][j] <<" ";
                
            }
            cout << endl;
        }
        */
        
        cin >> x;
        
        int result[10];
        for(int i=0;i<10;i++)
            result[i]=0;
        result[0]=1;
        flag=false;
        isVisited[0]=true;
        backtrack(0,0,1,result);
        if(!flag){
            cout << "no walk of length " << l << endl;
        }
        t++;
        
        
    }
}
