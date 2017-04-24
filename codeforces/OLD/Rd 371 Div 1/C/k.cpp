// <1588.cpp> - 05/12/16 19:45:13
// This file is created by XuYike's black technology automatically.
// Copyright (C) 2015 ChangJun High School, Inc.
// I don't know what this program is.

#include <iostream>
#include <vector>
#include <algorithm>
#include <cstring>
#include <cstdio>
#include <cmath>
#include <ext/pb_ds/tree_policy.hpp>
#include <ext/pb_ds/assoc_container.hpp>
using namespace std;
using namespace __gnu_pbds;
typedef long long lol;
int gi(){
    int res=0,fh=1;char ch=getchar();
    while((ch>'9'||ch<'0')&&ch!='-')ch=getchar();
    if(ch=='-')fh=-1,ch=getchar();
    while(ch>='0'&&ch<='9')res=res*10+ch-'0',ch=getchar();
    return fh*res;
}
const int MAXN=100001;
const int INF=1e9;
tree <int,null_type> t;
tree <int,null_type>::iterator it;
int main(){
    int n=gi(),ANS=0;
    for(int i=1;i<=n;i++){
        int k=0;
        scanf("%d",&k);
        if(t.find(k)!=t.end())continue;
        t.insert(k);
        it=t.find(k);
        int ans=INF;
        if(i==1)ans=k;
        if(it!=t.begin()){
            ans=k-*--it;
            it++;
        }
        if(++it!=t.end())ans=min(ans,*it-k);
        ANS+=ans;
    }
    printf("%d\n",ANS);
    return 0;
}
