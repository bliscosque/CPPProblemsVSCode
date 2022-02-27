#include<bits/stdc++.h>
using namespace std;

int calculate(vector<vector<int>> grid) {
    int sum=0;
    for (vector<int> vi: grid) {
        int parc=0;
        for (int i:vi) {
            if (parc==0) parc = i;
            else {
                parc = (parc<<1)+i;
            }
            //cout << parc << endl;
        }
        //cout << "PARC1: " << parc << endl;
        sum+=parc;
    }
    return sum;
}


int matrixScore(vector<vector<int>> grid) {
    int max = calculate(grid);
    int sizeT=grid.size()*grid[0].size();
    for (int b=0; b<(1<<sizeT);b++) {
        
    }
}

int main() {
    vector<vector<int>> grid = {{0,0,1,1}, {1,0,1,0}, {1,1,0,0}};
    cout << "RES: " << matrixScore(grid) << endl;
    return 0;
}

/* SOLUTION1 - CODINGMINUTES

#include<bits/stdc++.h>
using namespace std;


void update_rows(vector<vector<int>> &grid,int n,int m){
    for(int i=0;i<n;i++){
        if(grid[i][0]==0){
            for(int j=0;j<m;j++){
                if(grid[i][j]){
                    grid[i][j]=0;
                }
                else{
                    grid[i][j]=1;
                }
            }
        }
    }
    return ;
}

void update_cols(vector<vector<int>> &grid,int n,int m){
    for(int i=0;i<m;i++){
        int zc=0;
        int oc=0;
        for(int j=0;j<n;j++){
            if(grid[j][i]){
                oc++;
            }
            else{
                zc++;
            }
        }
        if(zc>oc){
            for(int j=0;j<n;j++){
                if(grid[j][i]){
                    grid[j][i]=0;
                }
                else{
                    grid[j][i]=1;
                }
            }
        }
    }
    return ;
}


void print(vector<vector<int>> grid,int n,int m){
    for(int i=0;i<n;i++){
        for(int j=0;j<m;j++){
            cout<<grid[i][j]<<" ";
        }
        cout<<endl;
    }
    return ;
}

int calc(vector<vector<int>> &grid,int n,int m){

    int ans=0;
    for(int i=0;i<n;i++){
        int temp=0;
        int fac=1;
        for(int j=m-1;j>=0;j--){
            temp+=fac*grid[i][j];
            fac*=2;
        }
        ans+=temp;
    }
    return ans;
}

int matrixscore(vector<vector<int>> grid){

    int n=grid.size();
    int m=grid[0].size();
    update_rows(grid,n,m);
    update_cols(grid,n,m);

    //print(grid,n,m);
    int ans=calc(grid,n,m);
    return ans;
}
int main(){

    int actual = matrixScore({{0,1,0,1,1,1,0,1,1,1,0,1,0,0},{1,0,1,0,1,1,0,1,0,1,0,0,0,0},{1,0,1,0,1,1,0,0,1,1,1,0,0,1},{1,0,1,1,0,0,1,1,0,1,0,1,0,0},{1,0,1,1,0,0,0,0,0,1,1,0,1,0},{0,0,0,0,0,1,0,1,1,1,0,0,0,1},{0,1,0,0,0,1,1,0,0,1,0,1,1,0},{1,0,1,0,1,0,1,1,1,1,1,0,0,1},{1,0,1,1,1,0,1,1,0,0,0,0,0,0},{1,1,0,0,0,1,1,0,0,0,0,0,0,1},{1,1,1,0,1,1,1,1,0,0,1,1,0,1},{0,1,0,1,0,1,1,1,1,1,1,0,1,0},{1,0,0,1,1,1,0,0,0,0,0,1,1,1},{1,1,0,1,0,0,0,1,1,1,0,1,1,0}});
  int expected = 194162;
  cout<<actual;
    return 0;
}

*/
















/* SOLUTION2 - CURSO UDEMY
#include<bits/stdc++.h>
using namespace std;

int matrixScore(vector<vector<int>> grid) {
    int ans=0,n=grid.size(),m=grid[0].size();
    ans=(1<<(m-1))*n;
    for(int j=1;j<m;j++)
    {
        int val=1<<(m-1-j);
        int sets=0;
        for(int i=0;i<n;i++)
        {
            if(grid[i][j]==grid[i][0])
            {
                sets++;
            }
        }
        ans+=max(sets,n-sets)*val;
    }
    return ans;
}
*/