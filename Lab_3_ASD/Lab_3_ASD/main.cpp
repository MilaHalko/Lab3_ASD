#include "class_Cities.cpp"
#include "functions.hpp"

int main() {
    
    Cities Albania;
    bool result = true;
    
    for (int i = 0; i < 15; i++) {
        for (int j = 0; j < 15; j++) {
            if (Albania.a_distance[i][j] != Albania.a_distance[j][i]) {
                result = false;
            }
        }
    }
    
    //---------------------------------------------------------------------------
    cout << "Result: " << result << endl;
    //---------------------------------------------------------------------------
    
    vector <int> max_degree_V;
    
    Find_degree_V(Albania, max_degree_V);
    
    //---------------------------------------------------------------------------
    cout << "Vector max_degree_V in main: ";
    for (int i = 0; i < max_degree_V.size(); i++) {
        cout << max_degree_V[i] << " ";
    }
    cout << endl;
    //---------------------------------------------------------------------------
    
    vector<vector<string>> v_colors;
    v_colors.resize(1);
    
    
    
    return 0;
}
