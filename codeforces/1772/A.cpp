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

    int t; 
    cin >> t; 
    while(t--){
    	char a, b ,c;
    	cin >> a >> b >> c;  
    	cout << a-'0' + c-'0' << endl; ; 

    }


    return 0;
}
