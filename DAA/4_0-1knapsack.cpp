
#include<iostream>
#include<algorithm>
using namespace std;

// Function to solve 0/1 Knapsack using Dynamic Programming
int knapsack(int weight[],int value[],int n,int capacity){

    // Create DP table to store maximum profit
    int dp[n+1][capacity+1];

    for(int i=0;i<=n;i++){
        for(int w=0;w<=capacity;w++){

            // Base condition: No items or zero capacity
            if(i==0 || w==0){
                dp[i][w]=0;
            }

            // Check whether the current item can fit
            else if(weight[i-1]<=w){

                // Choose maximum profit: Include or Exclude the item
                dp[i][w]=max(
                    value[i-1]+dp[i-1][w-weight[i-1]],
                    dp[i-1][w]
                );
            }
            else{

                // If item does not fit, exclude it
                dp[i][w]=dp[i-1][w];
            }
        }
    }

    // Return maximum profit from the DP table
    return dp[n][capacity];
}

int main(){
    int n;

    cout<<"Enter the number of items: ";
    cin>>n;

    int weight[n],value[n];

    cout<<"Enter the weights of the items: ";
    for(int i=0;i<n;i++){
        cin>>weight[i];
    }

    cout<<"Enter the values of the items: ";
    for(int i=0;i<n;i++){
        cin>>value[i];
    }

    int capacity;

    cout<<"Enter the capacity of the knapsack: ";
    cin>>capacity;

    // Call knapsack function and display maximum profit
    cout<<"The maximum value that can be obtained is: "
        <<knapsack(weight,value,n,capacity)<<endl;

    return 0;
}

/*Enter the number of items: 3
Enter the weights of the items: 10 8 3
Enter the values of the items: 8 6 4
Enter the capacity of the knapsack: 15*/