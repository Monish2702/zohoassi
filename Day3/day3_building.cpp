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

//To move left, up, right, down while performing DFS
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
    cout<<"Enter the x (m) coordinate length: ";
    cin>>m;
    cout<<"Enter the y (n) coordinate length: ";
    cin>>n;
    int max=0;
    //Allocating 2d array of size m*n
    int** arr = new int*[m];
    bool **visited =new bool*[m];
    int** grouper = new int*[m];  //max possible group size is size of arr i.e m*n
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
    cout<<"\nThe formed groups sum are: ";
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
    for(int i=0;i<m;i++){
        for(int j=0;j<n;j++){
            max=max>grouper[i][j]?max:grouper[i][j];
        }
    }
    cout<<"\nThe leader group is: "<<max;
    
    //Deallocate
    for(int i=0;i<m;i++){
        delete [] arr[i];
        delete [] visited[i];
        delete [] grouper[i];
    } delete [] arr; delete [] visited; delete [] grouper;
    return 0;
}