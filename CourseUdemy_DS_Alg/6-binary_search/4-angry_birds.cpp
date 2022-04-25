//there is a long wire, which contain n bird nests at positions x1, x2,...xN
//B<=N
//2 birds inside same nest, become angry
//assign birds to nest so that minimum distance maximize --- what is largest minimum distance


//N=5 (nests)
//B=3 (birds)
//nests={1,2,4,8,9}
//output=3

//opc1 - brute force
//opc2 - binary search (buscando distancia)
 //no exemplo acima, diantancia de 0 a 8... mid é 4 (0,8)
 //para 4 tambem nao podemos encontrar uma solucao... (0,3) -> mid é 2
 //para 2, há uma solucao possivel... (3) -> 3 é possível

#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;

bool canPlaceBirds(int B, int N, vector<int> nests, int sep) {
    int birds=1; //sempre coloca o primeiro passaro na primeira posicao
    int location=nests[0];
    for (int i=1;i<N;i++) { //ver se pode colocar os outros, baseado nas diferencas
        int curr_location=nests[i];
        if (curr_location-location>=sep) {
            birds++;
            location=curr_location;
            if (birds==B) {
                return true;
            }
        }
    }
    return false;
}

int main() {
    int B=3;
    vector<int> nests={1,2,4,8,9};
    int N=nests.size();
    sort(nests.begin(),nests.end());

    //binary search
    int s=0;
    int e=nests[N-1] - nests[0];
    int ans=-1;
    while(s<=e) {
        int mid=(s+e)/2;
        bool canPlace=canPlaceBirds(B,N,nests,mid);
        if (canPlace) {
            ans=mid;
            s=mid+1;
        }
        else {
            e=mid-1;
        }
    }
    
    cout << ans << endl;
    return 0;
}