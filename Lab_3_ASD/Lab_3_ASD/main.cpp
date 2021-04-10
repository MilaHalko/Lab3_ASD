#include "functions.hpp"

int main() {
    
    Cities city;
    bool result = true;
    
    for (int i = 0; i < 15; i++) {
        for (int j = 0; j < 15; j++) {
            if (city.a_distance[i][j] != city.a_distance[j][i]) {
                result = false;
            }
        }
    }
    
    cout << "Result: " << result << endl;
    
    return 0;
}
