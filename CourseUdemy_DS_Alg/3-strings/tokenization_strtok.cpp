#include <iostream>
#include <vector>
#include <cstring>
using namespace std;

int main() {
    char input[1000];
    cin.getline(input,1000);

    char *token = strtok(input, " ");
    
    while (token !=NULL) {
        //Null is not to start from beginning
        cout <<token << endl;
        token = strtok(NULL, " ");
    }
    
    
    return 0;
}