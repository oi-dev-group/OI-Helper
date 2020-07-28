#include<bits/stdc++.h>
using namespace std;
const int INF=1919810;//INF大小自己调qaq
int data[205][205],n,m,x,y,dis;//data数组用来存邻接矩阵
int QUICK_MIN(int x,int y){
    //STL里的min()比手写慢
    return x<y?x:y;
}
void init(){
    //用于初始化邻接矩阵
    for(int i=1;i<=n;i++){
        for(int j=1;j<=n;j++){
            if(i==j)data[i][j]=0;
            else data[i][j]=INF;
        }
    }
}
void floyd(){//Floyd主体
    for(int k=1;k<=n;k++){//循环节点
        for(int i=1;i<=n;i++){
            //有时候这里要添加判断语句……自己看着办qwq
            for(int j=1;j<=n;j++){
                data[i][j]=QUICK_MIN(data[i][j],data[i][k]+data[k][j]);
            }
        }
    }
}
int main(){
    /*
    Floyd核心只有5行，但是复杂度为O(n^3)，只能解决n<200的问题
    */
    //IO Stream优化
    cin.tie(0);
    cout.tie(0);
    cin>>n>>m;
    init();
    for(int i=1;i<=m;i++){
        scanf("%d%d%d",&x,&y,&dis);//x为出发点，y为结束点，dis为距离
        data[x][y]=dis;
    }
    floyd();
    for(int i=1;i<=n;i++){
        for(int j=1;j<=n;j++){
            if(data[i][j]>=INF)cout<<setw(15)<<"INF"<<' ';//这里设置了场宽，自行修改。模板不是直接套的qwq
            else cout<<setw(15)<<data[i][j]<<' ';
        }
        cout<<endl;
    }
    return 0;
}