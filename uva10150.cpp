#include<iostream>
using namespace std;
#define endl '\n'
#define mxNd 25143

char str[mxNd][17];
bool isVisited[mxNd];
int distance[mxNd];
int p[mxNd];
int length[mxNd];

class Queue{
    public:
    int x=0,y=0;
    char arr[mxNd][17];
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


void printPath(int x,int y){
    //cout << x<< " "<< y <<endl;
    if(p[y]==-1){
        cout << "No solution." << endl ;
        return;
    }
    int a[mxNd];
    int counter=0;
    while(1){
        
        a[counter]=y;
        counter++;
        y=p[y];
        if(y==-2){
            break;
        }
    }
    
    for(int i=counter-1;i>=0;i--){
        int j=0;
        while(str[a[i]][j]!='\0'){
            cout << str[a[i]][j];
            j++;
        }
        cout << endl;
    }
    
}
bool stringMatch(char *x,char *y,int m,int n){
    
    if(length[m]!=length[n])
        return false;
    
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

int getIndex(char *x,int l1){
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

bool match(char *x,char *y,int m,int n){
    
    if(length[m]!=length[n])
        return false;
    int i=0;
    while(x[i] !='\0' || y[i]!='\0'){
        if(x[i]!=y[i])return false;
        i++;
        
    }
    return true;
}

int main(){
    ios_base::sync_with_stdio(0);
    
        int l1=0;
        char c;
    
        while(1){
            cin.get(c);
            //cout << c;
            if(c=='\n')break;
            int i;
            for(i=0;i<17;i++){
                
                if(c=='\n'){
                    str[l1][i]='\0';
                    break;
                }
                else str[l1][i]=c;
                cin.get(c);
                //cout << c;
            }
            //cout << endl;
            length[l1]=i;
            l1++;
            
        }
        
    
    
        /*
        //cout << l1;
        for(int i=0;i<l1;i++){
            int j=0;
            while(str[i][j]!='\0')
                cout << str[i][j++];
            cout << endl;
        }
        
    
        for(int i=0;i<l1;i++){
            cout << length[i] << " ";
        }
        */
        
    
        char arr[35];
        int test=0;
        while(cin.getline(arr,33)){
            if(test>0)cout << endl;
            char start[17],end[17];
            int i;
            for(i=0;i<17;i++){
                if(arr[i]==' '){
                    start[i]='\0';
                    break;
                }
                else start[i]=arr[i];
            }
            for(int j=0;j<17;j++){
                if(arr[++i]=='\0'){
                    end[j]='\0';
                    break;
                }
                else end[j]=arr[i];
            }
            
            for(int i=0;i<l1;i++){
                isVisited[i]=false;
                p[i]=-1;
            }

            Queue q;
            q.push(start);
           
            int startIndex=getIndex(start,l1);
            
            isVisited[startIndex]=true;
            p[startIndex]=-2;
            bool flag=false;
            int endIndex=getIndex(end,l1);
            while(q.x!=q.y){
                if(flag)break;
                char *u =q.pop();
                int startIndex=getIndex(u,l1);
                for(int v=0;v<l1;v++){
                    if(stringMatch(u,str[v],startIndex,v) && !isVisited[v]){
                        isVisited[v]=true;
                        p[v]=startIndex;
                        q.push(str[v]);
                        if(match(str[v],end,v,endIndex)){
                            flag=true;
                            break;
                        }
                    }
                }
                        
            }
            printPath(startIndex,endIndex);
            test++;    
                
            
        }
        
        
        
}
