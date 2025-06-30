#include <bits/stdc++.h>
using namespace std;
void findMinRoute(vector<vector<int>> tsp) {
    int sum=0;
    int counter=0;
    int j=0, i=0;
    int min=INT_MAX;
    map<int, int> visitedRouteList;
    visitedRouteList[0]=1;
    int route[tsp.size()];
    while(i<tsp.size() && j<tsp[i].size()) {
        if(counter>=tsp[i].size()-1) {
            break;
        }
        if(j==i && (visitedRouteList[j]==0)) {
            if(tsp[i][j]<min) {
                min=tsp[i][j];
                route[counter]=j+1;
            }
        }
        j++;
        if(j==tsp[i].size()) {
            sum+=min;
            min=INT_MAX;
            visitedRouteList[route[counter]-1]=1;
            j=0;
            i=route[counter]-1;
            counter++;
        }
    }
    route[counter-1]=1;
    for(j=0;j<tsp.size();j++) {
        if((i!=j) && tsp[i][j]<min) {
            min=tsp[i][j];
            route[counter]=j+1;
        }
    }
    sum+=min;
    cout<<sum;
}
int main() {
    vector<vector<int>> tsp={{0,4,8,7},{4,0,2,3},{8,2,0,6},{7,3,6,0}};
    findMinRoute(tsp);
}