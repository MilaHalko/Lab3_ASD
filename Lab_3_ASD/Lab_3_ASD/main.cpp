#include "class_Cities.cpp"
#include "functions.hpp"

int main() {
    
    Cities Albania;                     // object Albania contains cities & distances
    vector <vector<int>> V_degree;      // contains every vertices' degree
    Find_degree_V(Albania, V_degree);
    
    
    vector<int> a_colors;               // contains every vertices' colors
    a_colors.resize(15);
    
    
    string str;
    cout << "Would you like to color Albania with certain numbers' quantity? (Y/N): "; cin >> str;
    cout << endl;
    
    if (str == "N"  ||  str == "n"  ||  str == "No"  ||  str == "no") {
        int max_color = Coloring(a_colors, Albania, V_degree);
        cout << "Colors' number is " << max_color << "." << endl;
    }
    
    else {
        int quantity;
        cout << "Colors' quantity: "; cin >> quantity;
        cout << endl;
        if (!Coloring(a_colors, Albania, V_degree, quantity)) {
            cout << "Coloring using only " << quantity << " colors is not possible(" << endl;
        }
    }
        
    
    
    return 0;
}
