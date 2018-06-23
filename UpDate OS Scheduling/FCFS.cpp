#include<bits/stdc++.h>
using namespace std;
string pp[10];
int B[10],A[10],TBr[10],C[10],TAT[10],W[10];
int main()
{
    cout << "First Come First-Served Scheduling"<<"\n";
    cout <<">>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>"<<"\n";
    cout <<"Number of process \n";
    int n,ww = 0;
    cin >> n;
    for(int i = 1; i <= n; i++){
        cin >> pp[i-1] >>  B[i] >> A[i];
        TBr[i] = B[i];
    }
    int p;
    for(int i = 1; i <= n; i++){

        if(A[i+1] > TBr[i]) {
           p = A[i+1] - B[i];
           p += TBr[i+1] + B[i];
           TBr[i + 1] = p;
        }
        else{
             TBr[i+1] += TBr[i];

        }
    }
//    for(int i = 1; i <= n; i++){
//    cout << TBr[i]<< endl;
//    }
    for(int i = 1; i <= n; i++){
        TAT[i] = TBr[i]  - A[i];
    }

    for(int i = 1; i <= n; i++){
        W[i] = TAT[i]  - B[i];
    }
//    cout << " Tranced time " << endl;
//    for(int i = 1; i <= n; i++){
//    cout << TAT[i]<< endl;
//    }
//    cout << "Waiting Timr" << endl;
//    for(int i = 1; i <= n; i++){
//    cout << W[i]<< endl;
//    }
    cout << "Process " << "BrustTime " << "ArrivalTime " << "CompliationTime "<<"TrunciatTime "
         <<"WainingTime "<<"\n";
    for(int i = 1; i <=n; i++){
        ww += W[i];
        cout <<" "<< pp[i-1] << "\t "<< B[i] << "\t\t"<< A[i] << "\t\t" << TBr[i]<< "\t"<< TAT[i] << "\t\t"
             << W[i] <<endl;
    }
    cout << "Average waiting Time = " << double(ww) / double(n) << endl;


}
/*
5
p1 4 0
p2 3 1
p3 1 2
p4 2 3
p5 5 4

3
p1 24 0
p2 3 0
p3 3 0

3
p1 2 0
p2 1 3
p3 6 5

4
p1 4 0
p2 9 2
p3 8 4
p4 3 3
*/
