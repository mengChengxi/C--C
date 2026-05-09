#include <bits/stdc++.h>
#include <string>
#include <vector>
using namespace std;
const int INF = 0x3f3f3f3f;
const int mod = 1e9 + 7;
#define mkp make_pair

vector<int> gss;
string out="";
int gtotalsum;
int sumofdigits(int t){
    int sum=0;
    if(t<=9){
        if(gss[t-t/10*10]-1<0){
            
            return 0;
        }else{
            gss[t-t/10*10]--;
            gtotalsum-=(t-t/10*10);
            return 1;
        }
    }
    while(t>9){
        if(gss[t-t/10*10]-1<0){
            return 0;
        }else{
            gss[t-t/10*10]--;
            sum+=(t-t/10*10);
            gtotalsum-=(t-t/10*10);
            t=t/10;
            
        }
    }
    if(gss[t]-1<0){
        return 0;
    }
    sum+=t;
    gtotalsum-=t;
    gss[t]--;
    
    
    return sumofdigits(sum);
}
void makestring(int t){
   
    int sum=0;
    out+=to_string(t);
    if(t<=9){
        return;
    }
    while(t>9){
        sum+=(t-t/10*10);
        
        t=t/10;
            
        
    }
    sum+=t;
    makestring(sum);
    
    
}


void solve() {
    string s;
    cin>>s;
    if(s.size()==1){
        cout<<s<<endl;
        return;
    }
    vector<int> ss(10,0);
    for(int i=0; i<s.size(); i++){
        ss[s[i]-'0']++;
    }
    int totalsum=0;
    for(int i=0; i<10; i++){
        totalsum+=ss[i]*i;
    }
    int ans;
    for(int i=1; i<totalsum; i++){
        gss=ss;
        gtotalsum=totalsum;
        if(sumofdigits(i)==1&&gtotalsum==i){
            ans=i;
            break;
        }
    }
    out="";
    for(int i=1; i<10; i++){
        while(gss[i]>0){
            out+=(char)('0'+i);
            gss[i]--;

        }
    }
    while(gss[0]>0){
        out+=(char)('0'+0);
        gss[0]--;

    }
    makestring(ans);
    cout<<out<<endl;


    
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int dashabi;
    cin >> dashabi;
    while (dashabi--) {
        solve();
    }
    return 0;
}