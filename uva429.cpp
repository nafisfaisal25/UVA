#include<iostream>
using namespace std;
#define endl '\n'
#define mxNd 200

class Queue{
    public:
    int x=0,y=0;
    char arr[mxNd][16];
    void push(char *str){
        int i=0;
        while(str[i]!='\0'){
            arr[x][i]=str[i];
            i++;
        }
        arr[x][i]='\0';
        x++;
    }
    char * pop(){
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
bool stringMatch(char *x,char *y){
    
    int i=0;
    int misMatch=0;
    
    while(x[i] !='\0' || y[i]!='\0'){
        if(x[i]!=y[i])misMatch++;
        if(misMatch>1){
            return false;
        }
        i++;
        
    }
    if(misMatch==1)return true;
    return false;
}

int getIndex(char *x,char str[][16],int l1){
            for(int i=0;i<l1;i++){
                        bool flag=true;

                        int j=0;
                        while(x[j]!='\0'){
                            if(str[i][j]!=x[j]){

                                flag=false;
                                break;
                            }
                            j++;
                        }
                        if(flag){
                            return i;
                        }
            }
    return 0;
}

bool match(char *x,char *y){
    int i=0;
    while(x[i] !='\0' || y[i]!='\0'){
        if(x[i]!=y[i])return false;
        i++;
        
    }
    return true;
}

int main(){
    ios_base::sync_with_stdio(0);
    int t,l=0;
    cin >> t;
    char arr[32];
    cin.getline(arr,2);
    cin.getline(arr,2);

    while(l<t){
        int l1=0;
        char str[mxNd][16];
        cin.getline(str[l1],15);
        bool isVisited[mxNd];
        int distance[mxNd];
        //cout << str[l1][0] << endl;
        while(str[l1][0]!='*'){
            l1++;
            cin.getline(str[l1],15);
            //cout << str[l1][0] << endl;
        }
        
        /*
        cout << l1;
        for(int i=0;i<l1;i++){
            int j=0;
            while(str[i][j++]!='\0')
                cout << str[i][j];
            cout << endl;
        }
        */
        
        cin.getline(arr,31);
        while(arr[0]!='\0'){
            char start[16],end[16];
            int i;
            for(i=0;i<16;i++){
                if(arr[i]==' '){
                    start[i]='\0';
                    break;
                }
                else start[i]=arr[i];
            }
            for(int j=0;j<16;j++){
                if(arr[++i]=='\0'){
                    end[j]='\0';
                    break;
                }
                else end[j]=arr[i];
            }
            
            for(int i=0;i<l1;i++){
                isVisited[i]=false;
                distance[i]=-1;
            }

            Queue q;
            q.push(start);
           
            int startIndex=getIndex(start,str,l1);
            
            isVisited[startIndex]=true;
            distance[startIndex]=0;
            bool flag=false;
            int endIndex=startIndex;
            while(q.x!=q.y){
                if(flag)break;
                char *u =q.pop();
                int startIndex=getIndex(u,str,l1);
                for(int v=0;v<l1;v++){
                    if(stringMatch(u,str[v]) && !isVisited[v]){
                        isVisited[v]=true;
                        distance[v]=distance[startIndex]+1;
                        q.push(str[v]);
                        if(match(str[v],end)){
                            flag=true;
                            endIndex=v;
                            break;
                        }
                    }
                }
                        
            }
                
                
            cin.getline(arr,31);  
            for(int i=0;i<16;i++){
                if(start[i]=='\0')break;
                cout << start[i];
            }
            cout << " ";
            for(int i=0;i<16;i++){
                if(end[i]=='\0')break;
                cout << end[i];
            }
            cout << " " << distance[endIndex] << endl; 
        }
        
        if(l<t-1)cout << endl;
        
        
        
        l++;
    }
}
