//{ Driver Code Starts
//Initial Template for C++

#include<bits/stdc++.h>
using namespace std;

// } Driver Code Ends
//User function Template for C++

class Solution{
public:
      string maxSum(string w,char x[], int b[],int n){
          map<char,int> ascii;
          int maxi=-1e9;
          string nans="";
          for(int i=0;i<n;i++)
          {
              ascii[x[i]]=b[i];
              if(b[i]>maxi){
                  if(nans.size()){
                      nans.pop_back();
                  }
                      nans.push_back(x[i]);
              }
          }          
          string ans="";
          string str="";
          int mx=0;
          int score=0;
          
          bool found=false;
          for(int i=0;i<w.length();i++){
              if(!ascii.count(w[i]) or ascii[w[i]]>0)found=true;
              if(ascii.count(w[i]))score+=ascii[w[i]];
              else score += int(w[i]);
              str.push_back(w[i]);
              if(score<0){
                  score=0;
                  str="";
              }
              
              if(score>mx){
                  mx=score;
                  ans=str;
              }
          }
          if(!found)return nans;
          return ans;
      }
};

//{ Driver Code Starts.
int main() 
{ 
    int t;
    cin>>t;
    while(t--)
    {
        string w;
        cin>>w;
        int n;
        cin>>n;
        char x[n];
        int b[n];
        for(int i = 0;i<n;i++)
            cin>>x[i];
        for(int i = 0;i<n;i++)
            cin>>b[i];
        Solution ob;
        cout << ob.maxSum(w,x,b,n) << endl;
    }
    return 0; 
}
// } Driver Code Ends