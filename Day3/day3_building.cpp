#include <iostream>
using namespace std;
int n,m,sum;

bool doesExist_valid(int x,int y,int **arr,bool **vis){
    if(x<0||x>=n||y<0||y>=m||arr[x][y]==0) //doesn't exist and not zero
        return false;
    if(vis[x][y]==true) //already visited
        return false;
    return true;
}

//To move up, right, down, left while performing DFS
int temp_x[]={-1,0,1,0};
int temp_y[]={0,1,0,-1};

//Searcher
void dfs(int x,int y,int **arr,bool **vis){
   if(!doesExist_valid(x,y,arr,vis)){
       return;
    }
    sum+=arr[x][y];
    vis[x][y]=true;
    for(int i=0;i<4;i++){
        // if(doesExist_valid(x+temp_x[i],y+temp_y[i],arr,vis)){ 
          
          dfs(x+temp_x[i],y+temp_y[i],arr,vis);
    }
    
}


//Main function
int main(){
    cout<<"Enter the x coordinate length: ";
    cin>>m;
    cout<<"Enter the y coordinate length: ";
    cin>>n;

    //Allocating 2d array of size m*n
    int** arr = new int*[m];
    bool **visited =new bool*[m];
    int** grouper = new int*[m];
    for(int i=0;i<m;i++){
        arr[i] = new int[n];
        visited[i] = new bool[n];
        grouper[i] = new int[n];
    }

    //getting input from user
    for(int i=0;i<m;i++){
        for(int j=0;j<n;j++){
            cin>>arr[i][j]; 
            visited[i][j]=false;
            grouper[i][j]=0;
        }
    }
    //calling dfs
    cout<<"\nThe fromed groups sum are: ";
    for(int i=0;i<m;i++){
        for(int j=0;j<n;j++){
            sum=0;
            dfs(i,j,arr,visited);
            if(sum>0){
                grouper[i][j]=sum;
                cout<<grouper[i][j]<<" ";
            }
        }
    }
    


    //Deallocate
    for(int i=0;i<m;i++){
        delete [] arr[i];
    } delete [] arr;
    return 0;
}