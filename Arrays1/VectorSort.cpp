#include<iostream>
#include<vector>
using namespace std;
int main(){
    int n;
    cin>>n;
    vector<int> v;
    for(int i=0;i<n;i++){
        int q=n;
        cin>>q;
        v.push_back(q);
    }
    // for(int i=0,j=n-1;i<=j;i++,j--){
    //     if(v[i]<v[j])i++;
    //     else if(v[i]>v[j]){
    //         v[i]=v[i]+v[j];
    //         v[j]=v[i]-v[j];
    //         v[i]=v[i]-v[j];
    //     }
    //     i++;
    //     j--;
        
    // }
    // //print
    // for(int k=0;k<n;k++){
    //     cout<<v[k]<<" ";
    // }
    sort(v.begin(),v.end());
 for(int i=0;i<n;i++){
    cout<<v[i]<<" ";
 }
    return 0;
}
