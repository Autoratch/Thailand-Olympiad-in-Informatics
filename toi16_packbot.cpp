#include <bits/stdc++.h>
using namespace std;
stack<int>cost;
stack<char>st;
map<char,int>val;

int cal(int a,int b,int op){
    // cout << a << " "  << b << " OP " << op << endl;
    int ret;
    if(op == 1) ret =  (a+b)*4/100 + a + b;
    if(op == 2) ret =  (a+b)*8/100 + a + b;
    if(op == 3) ret =  (a+b)*16/100 + a + b;
    // cout << " = " << ret << endl;
    return ret;
    
}

void kid(){
    if(st.empty()) return;

    char top = st.top();
    st.pop();
    int ctop = cost.top();
    cost.pop();

    if(st.empty() || val[st.top()] < val[top] || st.top() == '['){
        st.push(top);
        cost.push(ctop);
        return;
    }

    while(!st.empty() && val[st.top()] >= val[top]  && cost.size() >= 2){
        if(st.top() == '[') break;
        int a = cost.top();
        cost.pop();
        int b = cost.top();
        cost.pop();
        char op = st.top();
        st.pop();
        //cout << a << " " << b << endl;
        cost.push(cal(a,b,val[op]));

    }
    cost.push(ctop);
    st.push(top);
}
int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    string str;
    cin >> str;
    int si = str.size();
    val['1'] = 1;
    val['2'] = 2;
    val['3'] = 3;
    val['['] = 4;

    for(int i = 0;i<si;i++){
        //cout << st.size() << " , " << cost.size() << endl;
        // cout << str[i] << endl;
        if(str[i] >= 'A' && str[i] <= 'Z'){
            // cout << "Push 20" << endl;
            cost.push(20);
            kid();
        }
        else{
            // cout << "No" << endl;
            if(str[i] == ']'){
                while(!st.empty() && st.top() != '['){
                    int b = cost.top();
                    cost.pop();
                    int a = cost.top();
                    cost.pop();
                    char op = st.top();
                    st.pop();
                    cost.push(cal(a,b,val[op]));
                }
                st.pop();

                kid();
            }
            else{
                st.push(str[i]);
            }
           
        }


    }
    while(!st.empty()){
        
        int a = cost.top();
        cost.pop();
        int b = cost.top();
        cost.pop();
        char op = st.top();
        st.pop();
        
        cost.push(cal(a,b,val[op]));
    }
    
    cout << cost.top();
}