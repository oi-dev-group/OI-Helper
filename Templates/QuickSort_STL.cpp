#include<bits/stdc++.h>
using namespace std;
int data[114514];//等待排序的数组
bool LESS(int i,int j){
    return i<j;
}
bool GREATER(int i,int j){
    return i>j;
}
int main(){
    /*
    sort()是不稳定的排序，其均衡的时间复杂度为O(n log n)，最坏为O(n^2)，内部实现为快速排序
    */
    int n;
    cin.tie(0);//优化cin和cout的读入速度
    cout.tie(0);
    cin>>n;
    for(int i=1;i<=n;i++)cin>>data[i];//读入
    sort(data+1,data+1+n);//大到小排
    for(int i=1;i<=n;i++)cout<<data[i]<<' ';
    cout<<endl;
    sort(data+1,data+1+n,less<int>());//大到小排
    for(int i=1;i<=n;i++)cout<<data[i]<<' ';
    cout<<endl;
    sort(data+1,data+1+n,LESS);//大到小排
    for(int i=1;i<=n;i++)cout<<data[i]<<' ';
    cout<<endl;
    sort(data+1,data+1+n,greater<int>());//小到大排
    for(int i=1;i<=n;i++)cout<<data[i]<<' ';
    cout<<endl;
    sort(data+1,data+1+n,GREATER);//小到大排
    for(int i=1;i<=n;i++)cout<<data[i]<<' ';
    cout<<endl;
    return 0;
}