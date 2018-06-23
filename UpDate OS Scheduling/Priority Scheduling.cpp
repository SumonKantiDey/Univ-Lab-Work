#include <bits//stdc++.h>
using namespace std;

#define F first
#define S second
#define pb push_back
#define mp make_pair
int main()
{
    //freopen("in.txt", "r", stdin);
    cout << "Priority Scheduling\n";
    cout << "------------------------------------\n";
    cout << "\nNumber of processe?\n";
    int n;
    cin >> n;

    int s[n+1];
    vector< pair<int, pair<int, string> > > v;

    cout << "\nInput process number and burst time\n";
    for(int i = 1; i <= n; i++)
    {
        string name;
        int time, priority;
        cin >> name >> time >> priority;
        v.pb(mp(priority, mp(time, name)));
    }

    sort(v.begin(), v.end());
    for(int i = 0; i <= n; i++) s[i] = 0;
    for(int i = 1; i <= n; i++) {
        s[i] = s[i-1] + v[i-1].S.F;
    }

    cout << "\nWaiting time for individual process\n";

    int tot_time = 0;
    for(int i = 1; i <= n; i++) {
        cout << v[i-1].S.S << " = " <<  s[i-1] << endl;
        tot_time += s[i-1];
    }

    cout << "\nAverage Waiting time for all process = " << (tot_time+0.0)/n << "\n";

    return 0;
}
/*
Priority Scheduling
------------------------------------

Number of processe?
4

Input process number and burst time
p1 8 2
p2 5 1
p3 4 3
p4 3 4

Waiting time for individual process
p2 = 0
p1 = 5
p3 = 13
p4 = 17

Average Waiting time for all process = 8.75
*/
