//
// Created by zhanghao on 22-10-12.
//
#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

const int N = 1010;

int n,m;
int v[N],w[N];
//vector<vector<int>>f(N,vector<int>(N,0));
//int f[N][N];

int main(){

    cin >> n >> m;//4 5  4个物品 背包容量为5
    vector<vector<int>>f(n+1,vector<int>(m+1,0));
    for(int i = 1 ; i <= n; i++) cin >> v[i] >> w[i];

    for(int i = 1 ; i <= n; i++)
        for(int j = 1 ; j <= m; j++){
            //  当前背包容量装不进第i个物品，则价值等于前i-1个物品
            if(j < v[i])
                f[i][j] = f[i-1][j];
            //  能装，需进行决策是否选择第i个物品
            else
                f[i][j] = max(f[i-1][j],f[i-1][j-v[i]] + w[i]);
        }
    cout<< f[n][m] << endl;
    return 0;
}




