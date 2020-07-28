//并查集（DSU）
#include<bits/stdc++.h>
using namespace std;
int FATHER[114514],n,m,sum,x,y;
void init(){
    for(int i=1;i<=n;i++)FATHER[i]=i;//初始情况下，每个人的爸爸都是自己（套娃？）
    return;
}
int FindFather(int x){//找爸爸
    if(FATHER[x]==x){//我的爸爸是我（大雾）
        return x;
    }
    FATHER[x]=FindFather(FATHER[x]);//找不到就继续找
    return FATHER[x];//返回
}
void MERGE(int x,int y){
    int FATHER_X,FATHER_Y;//把两个人的爸爸连在一起（大雾）
    FATHER_X=FindFather(x);
    FATHER_Y=FindFather(y);
    if(FATHER_Y!=FATHER_X){
        FATHER[FATHER_Y]=FATHER_X;
    }
    return;
}
int main(){
    //IO流优化
    cin.tie(0);
    cout.tie(0);
    cin>>n>>m;//n个人，m个关系
    init();
    for(int i=1;i<=m;i++){//m个关系输入
        cin>>x>>y;
        MERGE(x,y);
    }
    for(int i=1;i<=n;i++){
        //扫一遍，看看有几个人的爸爸是自己（大雾），构成一个家庭
        if(FATHER[i]==i){
            cout<<i<<' ';
            sum++;
        }
    }
    cout<<endl<<sum;
    return 0;
}