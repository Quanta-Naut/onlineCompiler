#include<stdio.h>

int max(int a, int b){
    return (a > b) ? a : b;
}

int knapsack(int w, int wt[], int profit[], int n){

    if(n==0 || w == 0){
        return 0;
    }

    if(wt[n-1] > w){
        return knapsack(w,wt,profit,n-1);
    }

    else{
        return max(profit[n-1] +knapsack(w - wt[n-1],wt, profit, n-1), knapsack(w,wt,profit,n-1));
    }
}

int main(){
    int w, wt[10], profit[10], n;

    printf("Enter the number of Items: ");
    scanf("%d",&n);
    printf("Enter the total weight: ");
    scanf("%d", &w);
    printf("Enter the cost and weight: ");
    for(int i = 0; i<n; i++){
        scanf("%d%d",&profit[i],&wt[i]);
    }
    printf("The effective cost is: %d\n",knapsack(w,wt,profit,n));
    return 0;
}