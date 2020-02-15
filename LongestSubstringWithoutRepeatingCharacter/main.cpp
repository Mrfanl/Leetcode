#include<iostream>
#include<string>
#include<map>
#include<algorithm>
#include<assert.h>

using namespace std;

class Solution{
public:
    int lengthOfLongestSubstring(string s){
       map<char,int> mp;
       int i=0,j=0,res=0;
       int len = s.length();
       while(i<=j&&j<len){
            if(mp.find(s[j])==mp.end()){
                mp.insert(std::pair<char,int>(s[j],j));
                res = max(res,j-i+1);
                j++;
            }else{
                int pos = mp[s[j]];
                i = max(pos+1,i);
                mp[s[j]] = j;
                res = max(res,j-i+1);
                j++;
            }
       }
        return res;

    }
};

string stringToString(string input){
    assert(input.length()>=2);
    string result;
    for(int i=1;i<input.length()-1;i++){
        char currentChar = input[i];
        if(input[i]=='\\'){
            char nextChar = input[i+1];
            switch(nextChar){
            case '\"':result.push_back('\"');break;
            case '/':result.push_back('/');break;
            case '\\':result.push_back('\\');break;
            case 'b' : result.push_back('\b'); break;
            case 'f' : result.push_back('\f'); break;
            case 'r' : result.push_back('\r'); break;
            case 'n' : result.push_back('\n'); break;
            case 't' : result.push_back('\t'); break;
            default: break;
            }
            i++;
        }else{
            result.push_back(currentChar);
        }
    }
    return result;
}

int main(){
    string line;
    while(getline(cin,line)){
        string s = stringToString(line);
        int ret = Solution().lengthOfLongestSubstring(s);
        string out = to_string(ret);
        cout<<out<<endl;
    }
    return 0;
}
