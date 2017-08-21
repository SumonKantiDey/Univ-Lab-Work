#include <bits//stdc++.h>
using namespace std;
map<string,int>mp;
int T[100];
int main()
{
    //freopen("in.txt", "r", stdin);
    cout << "Round-Robin scheduling\n";
    cout << "------------------------------------\n";
    int n, time_slice;
    cout << "\nNumber of processe?\n";
    cin >> n;

    int t[n+1]; // burst time
    string p[n+1]; //string p[10]
    int s[100]; // waiting counter
    string an[100]; // process counter

    cout << "\nInput process number and burst time\n";
    for(int i = 1; i <= n; i++) {
        cin >> p[i] >> t[i];
        mp[p[i]] = i;
        T[i] = t[i];
    }


    cout << "\nInput time slice\n";
    cin >> time_slice;

    for(int i = 0; i < 100; i++) s[i] = 0;

    int loop = 1,m;
    while(1) {
        bool f = 0;
        for(int i = 1; i <= n; i++)
        {
             if(t[i]) {
                if(t[i] >= time_slice) {
                    s[loop] = s[loop-1] + time_slice;
                    t[i] -= time_slice;
                }
                else {
                    s[loop] = s[loop-1] + t[i];
                    t[i] = 0;
                }
                f = 1;
                an[loop] = p[i];
                m = i;
                loop++;
             }
        }
        if(!f) {
           an[loop] = p[m];
           break;
        }

    }
    //cout << loop << endl;

    cout << "\nWaiting time for individual process\n";


    int tot_time = 0;
    map<string, int> cur;
    for(int i = 1; i <= loop; i++) {
        cout << an[i] << " = " <<  s[i-1] << "\n";
    }
    int tmp = 1,C[100];
    int k = mp[an[loop]],hobe;
    for(int i = 1; i <= n; i++){
        if(k == i){
           hobe = i;
           C[hobe] = s[loop-1];
        }
    }
    for(int i = 1; i <= n; i++){
        for(int j = loop; j >= 0; j--){
            if(mp[an[j]] == tmp && tmp != hobe){
                C[i] = s[j];
                break;
            }
        }
        tmp++;
    }
    cout << "Waiting time for every process : " << endl;
    for(int i = 1; i<= n; i++){
        tot_time += (C[i] - T[i]);
        cout <<"process " << p[i] << " waiting time is = " << C[i] - T[i] << endl;
    }

    cout << "\nAverage Waiting time for all process = " << (tot_time+0.0)/n << "\n";

    return 0;
}
/*
4
p1 21
p2 3
p3 6
p4 2
Time Slice
5

3
p1 24
p2 3
p3 3
Time Slice
4
*/
