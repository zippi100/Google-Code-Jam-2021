#include <iostream>
#include <iomanip>
#include <string>

using namespace std;

int main(){
    
    int t, cj, jc;
    int cjCount, jcCount;
    int xVal, yVal;
    int pos;
    
    string data;
    
    cin >> t;
    
    for (int i = 1; i <= t; ++i)
    {
        cin >> cj >> jc;
        //cin.ignore(1000,'\n');
        
        cin >> data;
        //cout << data << endl << cj << endl << jc << endl;
        xVal = yVal = cjCount = jcCount = 0;
        for (int j = 0; j < data.length(); ++j)
        {
            if (j == 0){
                //do nothing
            }
            else if ((data[j] == 'C' 
            || data[j] =='J') 
            && data[j-1] == '?')
            {
                for (int k = 0; k < j; ++k ){
                    data[k] = data[j];
                }
            }
            else if (data[j] == '?' 
            && data[j-1] == 'C')
            {
                data[j] = 'C';
            }
            else if (data[j] == '?' 
            && data[j-1] == 'J')
            {
                data[j] = 'J';
            }
            
            
            
        }
        
        //cout << "Qm:" << qmCount << " C:" << cCount << " J:" << jCount << endl; 
        
        //cout << "New String: " << data << endl;
        
        for (int j = 0; j < data.length() - 1; ++j){
            if (data[j] == 'C' && data[j+1] == 'J')
            {
                ++cjCount;
                
            }
            if (data[j] == 'J' && data[j+1] == 'C'){
                ++jcCount;
            }
        }
        
        for (int j = 1; j <= cjCount; ++j){
            xVal += cj;
        }
        
        for (int j = 1; j <= jcCount; ++j ){
            yVal += jc;
        }
        
        cout << "Case #" << i << ": " << xVal + yVal << endl;
        
    }
    
    return 0;
}
