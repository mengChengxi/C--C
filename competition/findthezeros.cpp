#include<bits/stdc++.h>
using namespace std;
int main(){
    //printf("hello world\n");
    int t;
    cin>>t;
    while(t--){
        int n;
        cin>>n;
        int nums[n];
        int cost[n];
        
        for(int i=0;i<n;i++){
            cin>>nums[i];
        }
        for(int i=0;i<n;i++){
            cin>>cost[i];
        }

        long long dp[n+1][2];
        for(int i=0;i<n+1;i++){
            for(int j=0;j<2;j++){
                dp[i][j]=-1;
            }
        }

        dp[0][0]=cost[0];
        dp[1][0]=0;

        for(int i=1;i<n;i++){
            long long minn=0x7FFFFFFFFFFFFFFF;
            int j=0;
            for(j=0;j<n+1 && dp[j][0]!=-1;j++){
                if(j==0){
                    dp[j][1]=dp[j][0]+cost[i];
                    minn=min(minn,dp[j][0]);
                    //printf("found%d ",minn);
                }else if(nums[j-1]<nums[i]){
                    dp[j][1]=dp[j][0]+cost[i];
                    minn=min(minn,dp[j][0]);
                }else if(nums[j-1]==nums[i]){
                    dp[j][1]=dp[j][0];
                    minn=min(minn,dp[j][0]);
                }else{
                    dp[j][1]=dp[j][0]+cost[i];
                }
            }
            dp[j][1]=minn;
            
            for(int k=0;k<n+1;k++){
                //printf("%d ",dp[k][0]);
                dp[k][0]=dp[k][1];
            }
            for(int k=0;k<n+1;k++){
                dp[k][1]=-1;
            }
            //printf("\n");
        }
        // for(int k=0;k<n+1;k++){
        //     printf("%d ",dp[k][0]);      
        // }
        long long minn=0x7FFFFFFFFFFFFFFF;
        for(int i=0; i<n+1; i++){
            minn=min(minn,dp[i][0]);
        }

        cout<<minn<<endl;
    }
    return 0;
}