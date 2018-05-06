# UVA
#include<iostream>
using namespace std;
#define endl '\n'
#define mxNd 1000

class Queue{
    public:
    int x=0,y=0;
    int arr[301];
    void push(int i){
        arr[x++]=i;
    }
    int pop(){
        return arr[y++];
    }
};

class Stack{
    public:
    int x=0;
    int arr[mxNd];
    void push(int i){
        arr[x++]=i;
    }
    int pop(){
        return arr[--x];
    }
};


void printPath(char map[][2],int *pre,int x,int y){
    //cout << x<< " "<< y <<endl;
    if(pre[y]==-1){
        cout << "No route" << endl;
        return;
    }
    int a[mxNd];
    int counter=0;
    while(1){
        
        a[counter]=y;
        counter++;
        y=pre[y];
        if(y==-2){
            break;
        }
    }
    
    for(int i=counter-1;i>0;i--){
        cout << map[a[i]][0] << map[a[i]][1] << " " << map[a[i-1]][0] << map[a[i-1]][1] << endl;
    }
    
}
int main(){
    ios_base::sync_with_stdio(0);
    int l;
    int counter=1;
    while(cin >> l){
        bool g[mxNd][mxNd];
        bool vis[mxNd];
        int pre[mxNd];
        for(int i=0;i<mxNd;i++)
            for(int j=0;j<mxNd;j++)
                g[i][j]=false;
        for(int i=0;i<mxNd;i++){
            pre[i]=-1;
            vis[i]=false;
        }
        
        char arr[6];
        cin.getline(arr,2);
        char map[mxNd][2];
        int currentIndex=0;
        //cout << counter << endl;
        for(int i=0;i<l;i++){
            
            cin.getline(arr,6);
            //cout <<  arr[0] << arr[1] << " " << arr[3] << arr[4] << endl;
            
            int x,y;
            bool n1=false,n2=false;
            for(int i=0;i<currentIndex;i++){
                if(arr[0]==map[i][0] && arr[1]==map[i][1]){
                    x=i;
                    n1=true;
                    break;
                }
            }
            if(!n1){
                x=currentIndex;
                map[currentIndex][0]=arr[0];
                map[currentIndex][1]=arr[1];
                currentIndex++;
            }
            
            for(int i=0;i<currentIndex;i++){
                if(arr[3]==map[i][0] && arr[4]==map[i][1]){
                    y=i;
                    n2=true;
                    break;
                }
            }
            if(!n2){
                y=currentIndex;
                map[currentIndex][0]=arr[3];
                map[currentIndex][1]=arr[4];
                currentIndex++;
            }
            g[x][y]=true;
            g[y][x]=true;
            
            
        }
        /*
        for(int i=0;i<currentIndex;i++){
            for(int j=0;j<currentIndex;j++){
                cout << g[i][j] << " ";
            }
            cout << endl;
        }
        */
        
        cin.getline(arr,6);
        int x=0,y=0;
        bool n1=false,n2=false;
            for(int i=0;i<currentIndex;i++){
                if(arr[0]==map[i][0] && arr[1]==map[i][1]){
                    x=i;
                    n1=true;
                    break;
                }
            }
            if(!n1){
                x=currentIndex;
            }
            
            for(int i=0;i<currentIndex;i++){
                if(arr[3]==map[i][0] && arr[4]==map[i][1]){
                    y=i;
                    n2=true;
                    break;
                }
            }
            if(!n2){
                y=currentIndex+1;
                
            }
        
        
        //cout << x << y;
        Queue q;
        q.push(x);
        vis[x]=true;
        pre[x]=-2;
        bool flag=false;
        while(q.x!=q.y){
            if(flag)break;
            int u=q.pop();
            for(int v=0;v<currentIndex;v++){
                if(g[u][v] && !vis[v]){
                    vis[v]=true;
                    pre[v]=u;
                    q.push(v);
                    if(v==y){
                        flag=true;
                        break;
                    }
                }
            }
        }
        printPath(map,pre,x,y);
        
        counter++;
    }
}
