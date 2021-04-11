#include "functions.hpp"

void Find_degree_V(Cities &Albania, vector<vector<int>> &max_degree_V) {
    
    int vertices = 15;
    int counter;
    int v_degree;
    int max = 100;
    int last = max_degree_V.size() - 1;
    
    while (vertices != 0) {
        
        v_degree = 0;
        
        for (int i = 0; i < 15; i++) {
            
            counter = 0;
            
            for (int j = 0; j < 15; j++) {
                if (Albania.a_distance[i][j] == 1) {
                    counter ++;
                }
            }
            
            if (v_degree < counter  &&  counter < max) {
                v_degree = counter;
            }
        }
        
        //---------------------------------------------------------------------------
        cout << "V_degree: " << v_degree << endl;
        //---------------------------------------------------------------------------
        
        max_degree_V.resize(max_degree_V.size() + 1);
        last = max_degree_V.size() - 1;
        
        for (int i = 0; i < 15; i++) {
            
            counter = 0;
            
            for (int j = 0; j < 15; j++) {
                if (Albania.a_distance[i][j] == 1) {
                    counter ++;
                }
            }
            
            if (counter == v_degree) {
                vertices -= 1;
                max_degree_V[last].push_back(i);
            }
        }
        max = v_degree;
        
        //---------------------------------------------------------------------------
        cout << "Vector max_degree_V: ";
        for (int j = 0; j < max_degree_V[max_degree_V.size() - 1].size(); j++) {
            cout << max_degree_V[last][j] << " ";
        }
        cout << endl;
        //---------------------------------------------------------------------------
    }
}
