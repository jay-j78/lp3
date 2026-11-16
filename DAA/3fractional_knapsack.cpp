#include<iostream>
#include<algorithm>
using namespace std;

struct Item{
    int weight;
    int value;
    double ratio;
};

// Sort items in descending order of value/weight ratio
bool compare(Item a,Item b){
    return a.ratio>b.ratio;
}

double fractionalknapsack(Item arr[],int n,int capacity){

    // Calculate value/weight ratio for each item
    for(int i=0;i<n;i++){
        arr[i].ratio=(double)arr[i].value/arr[i].weight;
    }

    // Sort items according to highest ratio
    sort(arr,arr+n,compare);

    double totalvalue=0;

    // Select items until the knapsack becomes full
    for(int i=0;i<n;i++){

        if(arr[i].weight<=capacity){

            // Take the complete item
            capacity-=arr[i].weight;
            totalvalue+=arr[i].value;
        }
        else{

            // Take only the required fraction of the item
            totalvalue+=arr[i].ratio*capacity;

            capacity=0;
            break;
        }
    }

    return totalvalue;
}

int main(){
    int n,capacity;

    cout<<"Enter the number of items: ";
    cin>>n;

    Item arr[n];

    cout<<"Enter the weight and value of each item: "<<endl;

    for(int i=0;i<n;i++){
        cin>>arr[i].weight>>arr[i].value;
    }

    cout<<"Enter the capacity of the knapsack: ";
    cin>>capacity;

    // Call the function to calculate maximum profit
    double maxvalue=fractionalknapsack(arr,n,capacity);

    cout<<"The maximum value in the knapsack is: "<<maxvalue<<endl;

    return 0;
}

/*Enter the number of items: 4
Enter the weight and value of each item:
10 8
8 6
3 4
4 2
Enter the capacity of the knapsack: 15*/