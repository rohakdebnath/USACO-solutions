#include <iostream>
#include <fstream>

using namespace std;

int main(void){
    int n;
    cin >> n;
    int arr[n];
    for(int i = 0; i < n; i++){
        cin >> arr[i];
    }
    int counter = 0;
    for(int i = 0; i < n; i++){
        int sum = 0;
        for(int j = i; j < n; j++){
            sum += arr[j];
            for(int k = i; k <= j; k++){
                if(sum == arr[k] * (j - i + 1)){
                    counter++;
                    break;
                }
            }
        }
    }
    cout << counter << "\n";
    return 0;
}
