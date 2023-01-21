//{ Driver Code Starts
// Initial Template for C++
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
// User function Template for C++

class Solution{
  public:
    int minVal(int a, int b) {
        bitset<32> bina(a);
        bitset<32> binb(b);
        int count=0;
        for(int i=0;i<32;i++)if(binb[i]==1)count++;
        //cout<<count<<endl;
        vector<int> num;
        for(int i=31;i>=0;i--){
            //cout<<bina[i]<<" ";
            if(count==i+1){
                num.push_back(1);
                count--;
            }
            else{
                if(bina[i] and count>0){
                    num.push_back(1);
                    count--;
                }else{
                    num.push_back(0);
                }
            }
        }
        //cout<<endl;
        reverse(num.begin(),num.end());
        
        int ans=0;
        for(int i=0;i<32;i++){
            //cout<<num[i]<<" ";
          ans += num[i]*pow(2,i);  
        }
        return ans;
    }
};

//{ Driver Code Starts.

int main() {
    int t;
    cin >> t;
    while (t--) {
        int a, b;
        cin >> a >> b;

        Solution ob;
        cout << ob.minVal(a, b);

        cout << "\n";
    }

    return 0;
}
// } Driver Code Ends