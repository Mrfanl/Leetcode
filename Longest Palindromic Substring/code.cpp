#include<iostream>
#include<string>
#include<sstream>
#include<vector>

using namespace std;

class Solution{
public:
    string longestPalindrome(string s){
        int n = s.size();
        if(n<2) return s;
        string str;
        for(int i=0;i<2*n+1;i++){
            if(i%2==0) str+="#";
            else str+=s.at(i/2);
        }
        int id = -1;
        int right = -1;
        vector<int> p(2*n+1);
        cout<<str<<endl;
        for(int i=0;i<2*n+1;i++){
            int tmp = right;
            int j = 2*id-i;
            if(i>right){
                right=i;
                while((right+1<2*n+1)&&(2*i-right-1>=0)&&(str[2*i-right-1]==str[right+1])){
                    right++;
                }
                if(right>tmp) id=i;
                p[i] = right-i;
            }
            else if(p[j]+i<right) p[i] = p[j];
            else{
                p[i] = right-i;
                while((right+1<n*2+1)&&(2*i-right-1>=0)&&(str[right+1]==str[2*i-right-1])){
                    right++;
                    p[i]++;
                }
                if(right>tmp) id = i;
            }
            cout<<p[i]<<endl;
        }
        int max = 0;
        id = 0;
        for(int i=0;i<2*n+1;i++){
            if(max<p[i]) {id = i;max=p[i];}
        }
        cout<<"max: ";
        cout<<max<<endl;
        return s.substr((id-max+1)/2,max);
    }
};

int main(){
    string line;
    while(getline(cin,line)){
        string ret = Solution().longestPalindrome(line);
        cout<<ret<<endl;
    }
}
