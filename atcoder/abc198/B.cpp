#include <bits/stdc++.h>
#define el "\n"
#define fastio                        \
    ios_base::sync_with_stdio(false); \
    cin.tie(NULL); \
    cout.tie(NULL)

using namespace std;
#define ll long long
int main()
{
    fastio;
#ifndef ONLINE_JUDGE
    freopen("input", "rt", stdin);
#endif
#ifndef ONLINE_JUDGE
    freopen("output", "wt", stdout);
#endif
    string s;
    cin >>s;
    while(true){
        if(*(s.end()-1) == '0'){
            s.pop_back();
        }else if (s[0] == '0')
        {
            s.erase(s.begin());
        }else{break; }
    }
    string z =s  ;
    
    reverse(s.begin(),s.end());
    if(z ==s ){
        cout << "Yes" <<endl; 
    }else {
        cout << "No" <<endl; 
    }

    return 0;
}
