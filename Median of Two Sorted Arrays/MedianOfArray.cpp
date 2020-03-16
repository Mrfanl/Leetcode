#include<iostream>
#include<vector>
#include<string>
#include<sstream>
#include<algorithm>

using namespace std;

class Solution{
public:
    double findMedianSortedArrays(vector<int> &nums1,vector<int> &nums2){
        int m = nums1.size();
        int n = nums2.size();
        if(m>n){
            vector<int> tmp = nums1;
            nums1 = nums2;
            nums2 = tmp;
            int t = m;
            m = n;
            n = t;
        }
        int start = 0,end = m;
        int i= 0 ,j = 0;
        while(start<=end){
            i = (start+end)/2;
            j = (m+n+1)/2 - i;
            if((i<end)&&(nums1[i]<nums2[j-1])) start++;
            else if((i>start)&&(nums1[i-1]>nums2[j])) end--;
            else{
                int maxLeft = 0;
                if(i==0) maxLeft = nums2[j-1];
                else if(j==0) maxLeft = nums1[i-1];
                else maxLeft = max(nums1[i-1],nums2[j-1]);
                if((m+n)%2!=0) return maxLeft;
                int minRight = 0;
                if(i==m) minRight = nums2[j];
                else if(j==n) minRight = nums1[i];
                else minRight = min(nums1[i],nums2[j]);
                return (maxLeft+minRight)/2.0;
            }
        }
        return 0;
    }
};

void trimLeftTrailingSpaces(string &input){
    input.erase(input.begin(),find_if(input.begin(),input.end(),[](int ch){
        return !isspace(ch);
    }));
}

void trimRightTrailingSpaces(string &input){
    input.erase(find_if(input.rbegin(),input.rend(),[](int ch){
        return !isspace(ch);
    }).base(),input.end());
}

vector<int> stringToIntegerVector(string input){
    vector<int> output;
    trimLeftTrailingSpaces(input);
    trimRightTrailingSpaces(input);
    input = input.substr(1,input.length()-2);
    stringstream ss;
    ss.str(input);
    string item;
    char delim = ',';
    while(getline(ss,item,delim)){
        output.push_back(stoi(item));
    }
    return output;
}

int main(){
    string line;
    while(getline(cin,line)){
        vector<int> nums1 = stringToIntegerVector(line);
        getline(cin,line);
        vector<int> nums2 = stringToIntegerVector(line);
        double ret=Solution().findMedianSortedArrays(nums1,nums2);
        string out = to_string(ret);
        cout<<out<<endl;
    }
    return 0;
}

