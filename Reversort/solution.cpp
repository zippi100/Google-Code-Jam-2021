#include <iostream>
#include <iomanip>
#include <vector>

using namespace std;

int main(){
    
    int t, size, value, cost, tempBegin, tempEnd;
    int minValuePos, minValue;
    
    vector<int> arr;
    
    cin >> t;
    
    for (int i = 1; i <= t; ++i){
        cin >> size;
        cost = 0;
        for (int j = 0; j < size; ++j){
            cin >> value;
            arr.push_back(value);
        }
        
        
        for (int k = 0; k < size - 1; ++k){
            minValuePos = k;
            minValue = arr[k];
            for (int j = k + 1; j < size; ++j){
                if (minValue > arr[j]){
                    minValue = arr[j];
                    minValuePos = j;
                }
            }
            tempEnd = minValuePos;
            for (int p = k; p <= tempEnd; ++p)
            {
                tempBegin = arr[p];
                arr[p] = arr[tempEnd];
                arr[tempEnd] = tempBegin;
                --tempEnd;
                
            }
            
            cost += (minValuePos + 1) - (k + 1) + 1; 
            
        }
    
        cout << "Case #" << i << ": " << cost << endl;
        arr.clear();
        
    }
    return 0;
}
