#include<iostream>
#include<cstdlib>
#include<string>
#include<vector>
#include<algorithm>
#include<sstream>

using namespace std;

struct ListNode{
    int val;
    ListNode *next;
    ListNode(int x):val(x),next(NULL){}
};

class Solution{
public:
    ListNode* addTwoNumbers(ListNode* l1,ListNode* l2){
        if(l1==NULL){
            return l2;
        }
        if(l2==NULL){
            return l1;
        }
        ListNode* dummyRoot = new ListNode(0);
        ListNode* ptr = dummyRoot;
        int carry = 0;
        while(l1!=NULL&&l2!=NULL){
            int sum = l1->val+l2->val+carry;
            carry = 0;
            if(sum>=10){
                ptr->next = new ListNode(sum-10);
                carry=1;
            }else{
                ptr->next = new ListNode(sum);
            }
            ptr = ptr->next;
            l1 = l1->next;
            l2 = l2->next;
        }
        while(l1!=NULL){
            int sum = l1->val+carry;
            if(sum>=10){
                ptr->next = new ListNode(sum-10);
                carry=1;
            }else{
                ptr->next = new ListNode(sum);
                carry = 0;
            }
            ptr = ptr->next;
            l1=l1->next;
        }
        while(l2!=NULL){
            int sum = l2->val+carry;
            if(sum>=10){
                ptr->next = new ListNode(sum-10);
                carry=1;
            }else{
                ptr->next = new ListNode(sum);
                carry = 0;
            }
            ptr = ptr->next;
            l2=l2->next;
        }
        if(carry>0){
            ptr->next = new ListNode(carry);
        }

        return dummyRoot->next;
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
    char delim = ',';
    string item;
    while (getline(ss,item,delim)){
        output.push_back(stoi(item));
    }
    return output;
}
ListNode* stringToListNode(string input){
    vector<int> list = stringToIntegerVector(input);
    ListNode* dummyRoot = new ListNode(0);
    ListNode* ptr = dummyRoot;
    for(int item:list){
        ptr->next = new ListNode(item);
        ptr = ptr->next;
    }
    ptr = dummyRoot->next;
    delete dummyRoot;
    return ptr;

}

string listNodeToString(ListNode* node){
    if(node==nullptr){
        return "[]";
    }
    string result;
    while(node){
        result += to_string(node->val)+",";
        node = node->next;
    }
    return "["+result.substr(0,result.length()-1)+"]";

}

int main(){
    string line;
    while(getline(cin,line)){
        ListNode* l1 = stringToListNode(line);
        getline(cin,line);
        ListNode* l2 = stringToListNode(line);
        ListNode* ret = Solution().addTwoNumbers(l1,l2);
        string out = listNodeToString(ret);
        cout<<out<<endl;
    }
}












