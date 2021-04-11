#include "functions.hpp"

void Find_degree_V(Cities &Albania, vector<int> &max_degree_V) {
    
    int counter;
    int v_degree = 0;
    
    for (int i = 0; i < 15; i++) {
        
        counter = 0;
        
        for (int j = 0; j < 15; j++) {
            if (Albania.a_distance[i][j] == 1) {
                counter ++;
            }
        }
        
        if (v_degree < counter) {
            v_degree = counter;
        }
    }
    
    //---------------------------------------------------------------------------
    cout << "V_degree: " << v_degree << endl;
    //---------------------------------------------------------------------------
    
    for (int i = 0; i < 15; i++) {
        
        counter = 0;
        
        for (int j = 0; j < 15; j++) {
            if (Albania.a_distance[i][j] == 1) {
                counter ++;
            }
        }
        
        if (counter == v_degree) {
            max_degree_V.push_back(i);
        }
    }
    
    //---------------------------------------------------------------------------
    cout << "Vector max_degree_V: ";
    for (int i = 0; i < max_degree_V.size(); i++) {
        cout << max_degree_V[i] << " ";
    }
    cout << endl;
    //---------------------------------------------------------------------------
}
