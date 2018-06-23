#include<bits/stdc++.h>
using namespace std;
#define ff first
#define ss second

vector<pair<pair<int,string>,int> >v;
int B[10],A[10],TBr[10],C[10],TAT[10],W[10];
int main()
{
    cout << "Shortest Job First Scheduling"<<"\n";
    cout <<">>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>"<<"\n";
    cout <<"Number of process \n";
    int n,ww = 0;
    string s;
    cin >> n;
    for(int i = 0; i < n; i++){
        cin >> s >>  B[i] >> A[i];
        v.push_back(make_pair(make_pair(A[i],s),B[i]));
    }
    sort(v.begin(),v.end());
    for(int i = 0; i < v.size(); i++){
        TBr[i] = v[i].ss;
    }
    int p;
    for(int i = 0; i < n; i++){

        if(v[i+1].ff.ff > TBr[i]) {
           p = v[i+1].ff.ff - v[i].ss;
           p += TBr[i+1] + v[i].ss;
           TBr[i + 1] = p;
        }
        else{
             TBr[i+1] += TBr[i];

        }
    }
//     for(int i = 1; i <= n; i++){
//     cout << TBr[i]<< endl;
//    }
    for(int i = 0; i < n; i++){
        TAT[i] = TBr[i]  - v[i].ff.ff ;
    }

    for(int i = 0; i < n; i++){
        W[i] = TAT[i]  - v[i].ss;
    }
//    cout << " Tranced time " << endl;
//    for(int i = 1; i <= n; i++){
//    cout << TAT[i]<< endl;
//    }
//    cout << "Waiting Timr" << endl;
//    for(int i = 1; i <= n; i++){
//    cout << W[i]<< endl;
//    }
    cout << "Process " << "BrustTime " << "ArrivalTime " << "CompliationTime "<<"TruncateTime "
         <<"WaitingTime "<<"\n";
    for(int i = 0; i <n; i++){
        ww += W[i];
        cout <<" "<< v[i].ff.ss << "\t "<< v[i].ss << "\t\t"<< v[i].ff.ff << "\t\t" << TBr[i]<< "\t"<< TAT[i] << "\t\t"
             << W[i] <<endl;
    }
    cout << "Average waiting Time = " << double(ww) / double(n) << endl;


}
/*
3
p1 20 0
p2 1 1
p3 1 2
3
p1 20 2
p2 1 0
p3 1 1
*/

