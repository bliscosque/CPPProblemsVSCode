//my solution considers best for all...

#include <bits/stdc++.h>
using namespace std;


int MV;
void MaxValue(int n, vector<int> v, int i, int j, bool Oswald, int sumP) {
    cout << "Calling with i: " << i << " j: " << j << " Oswald " << Oswald << " sumP: " << sumP << endl;
    if (i==j) { 
        if (Oswald) {
            cout << "osw sol with: " << sumP << " and " << v[i] << endl;
            MV=max(MV,sumP+v[i]);
        }
        else {
            cout << "nao osw sol with: " << sumP  << endl;
            MV=max(MV,sumP);
        }
        return;
    }
    if (Oswald) {
        cout << "Osw trying:  " << v[i] << endl;
        MaxValue(n,v,i+1,j,!Oswald,sumP+v[i]);

        
        cout << "Osw trying: : " << v[j] << endl;
        MaxValue(n,v,i,j-1,!Oswald,sumP+v[j]);
    }
    else {
        cout << "Nao Os... i:  " << v[i] << endl;
        MaxValue(n,v,i+1,j,!Oswald,sumP);
        cout << "Nao Os... j:  " << v[j] << endl;
        MaxValue(n,v,i,j-1,!Oswald,sumP); 
    }
}


int MaxValue(int n, vector<int> v){
    MV=INT_MIN;
    int j=n-1;
    MaxValue(n,v,0,j, true,0);
    return MV;

}
int main() {
    vector<int> v= {1,2,3};
    int n=v.size();
    cout << MaxValue(n,v) << endl;
}



/* solution from course

#include <bits/stdc++.h>
using namespace std;

int game(int n, vector<int> v, int s, int e){

    if(s==e || s==e-1){
        return max(v[s],v[e]);
    }

    int op1=v[s] + min(game(n,v,s+2,e),game(n,v,s+1,e-1));
    int op2=v[e] + min(game(n,v,s+1,e-1),game(n,v,s,e-2));
    return max(op1,op2); 
}

int MaxValue(int n, vector<int> v){
    int res=game(n,v,0,n-1);
    return res;
}

*/