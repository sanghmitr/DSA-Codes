#include<bits/stdc++.h>
using namespace std;

bool cmp(int a,int b){
   return a>b;
}

int main(){
 
int t;
cin>>t;
while(t--){
   string s;
   cin>>s;
   int k=0;
   int n=s.length();
   if((s[n-1]-48)%2!=0){
     for(int i=0;i<n-1;i++){
        if( (s[i]-48)%2!=0){k=1;break;}
     }
   }
   else {
       for(int i=0;i<n-1;i++){
        if( (s[i]-48)%2==0){k=1;break;}
     }

   }
   if(k)cout<<"YES"<<endl;
   else cout<<"NO"<<endl;
}

   return 0;
}

// #include<bits/stdc++.h>
// using namespace std;
  
// int main()
// {
//     ios_base :: sync_with_stdio(0);
//     cin.tie(0);
//     cout.tie(0);
    
//     int t;
//     cin>>t;
//     while(t--)
//     {
//         int n;
//         cin>>n;

//         int x = n;
//         int odds = 0, evens = 0, zeros = 0;
//         while(x>0)
//         {
//             int a = x%10;
//             x /= 10;
//             if(a%2 == 0 and a != 0)
//             {
//                 evens++;
//             }
//             else if(a%2 == 1)
//                 odds++;
//             else
//                 zeros++;
//         }
//         if(evens >= 2 or odds >= 2)
//             cout<<"YES"<<endl;
//         else if(evens == 1 and zeros >= 1)
//             cout<<"YES"<<endl;
//         else if(zeros >= 2)
//             cout<<"YES"<<endl;
//         else
//             cout<<"NO"<<endl;
//     }
//     return 0;
// }