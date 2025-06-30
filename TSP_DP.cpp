#include<iostream>
using namespace std;
const int n=4;
const int MAX=1000000;
int dist[4][4]={{0,4,8,7},{4,0,2,3},{8,2,0,6},{7,3,6,0}};
int memo[n+1][1<<(n+1)];
int fun(int i, int mask){
    if(mask==(1<<i)){
        return dist[i][0];
    }
    if(memo[i][mask]!=-1){
        return memo[i][mask];
    }
    int res=MAX;
    for(int j=1;j<=n;j++){
        if((mask & (1<<j)) && j!=i && j!=1){
            res=std::min(res,fun(j,mask & ~(1<<i))+dist[j][i]);
        }
    }
    return memo[i][mask]=res;
}
int main(){
    int ans=MAX;
    for(int i=1;i<=n;i++){
        ans=std::min(ans,fun(i,(1<<(n+1))-1)+dist[i][1]);
    }
    printf("Cost of most efficient tour=%d",ans);
    return 0;
}