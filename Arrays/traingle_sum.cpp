#include<stdio.h>
void printTriangle(int arr[] , int n) {
   if (n < 1) {
      return;
   }
   int temp[n - 1];
   for (int i = 0; i < n - 1; i++) {
      int x = (arr[i] + arr[i + 1])%10;
      temp[i] = x;
   }
   printTriangle(temp, n - 1);
   for (int i = 0; i < n ; i++) {
      if(i == n - 1)
         printf("%d ",arr[i]);
      else
         printf("%d, ",arr[i]);
   }
   printf("\n");
}
int main() {
   int arr[] = {1,2,3,4,5};
   int n = sizeof(arr) / sizeof(arr[0]);
   printTriangle(arr, n);
}