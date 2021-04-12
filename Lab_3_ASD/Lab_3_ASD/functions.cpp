#include "functions.hpp"


void Find_degree_V(Cities &Albania, vector<vector<int>> &V_degree) {
    
    int vertices = 15;
    int counter;
    int v_degree;
    int max = 100;
    int last = V_degree.size() - 1;
    
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
        V_degree.resize(V_degree.size() + 1);
        last = V_degree.size() - 1;
        
        for (int i = 0; i < 15; i++) {
            
            counter = 0;
            
            for (int j = 0; j < 15; j++) {
                if (Albania.a_distance[i][j] == 1) {
                    counter ++;
                }
            }
            
            if (counter == v_degree) {
                vertices -= 1;
                V_degree[last].push_back(i);
            }
        }
        max = v_degree;
    }
}


int Coloring(vector<int> &a_colors, Cities &Albania, vector<vector<int>> &V_degree){
    
    for (int i = 0; i < 15; i++) {
        a_colors[i] = 0;
    }
    
    int color = 1;
    int max_color = 1;
    
    for (int i = 0; i < V_degree.size(); i++) {
        for (int j = 0; j < V_degree[i].size(); j++) {
            
            int l = 0;
            
            while (l < 15){
                if (Albania.a_distance[V_degree[i][j]][l] == 1){
                    if (a_colors[l] == color) {
                        color++;
                        l = 0;
                        
                        if (max_color < color) {
                            max_color = color;
                        }
                        
                        continue;
                    }
                }
                l++;
            }
            a_colors[V_degree[i][j]] = color;
            color = 1;
        }
    }
    
    Print_Groups(a_colors, max_color, Albania);
    
    return max_color;
}


bool Coloring(vector<int> &a_colors, Cities &Albania, vector<vector<int>> &V_degree, int quantity) {
    
    for (int i = 0; i < 15; i++) {
        a_colors[i] = 0;
    }
    
    int path [15][3];
    int i = 0;
    int j = 0;
    int l = 0;
    int deleted = -1;
    int counter = 1;
    bool the_end = false;
    int all_V = 0;
    
    while (all_V != 15) {
        
        if (!not_visited(V_degree[i][j], path, counter))  {
            if (j == V_degree[i].size() - 1) {
                i++; j = 0;
                if (i == V_degree.size()) {
                    break;
                }
            }
            else{
                j++;
            }
            continue;
        }
        
        
        path[counter - 1][0] = V_degree[i][j];
        path[counter - 1][1] = i;
        path[counter - 1][2] = j;
        a_colors[path[counter - 1][0]] = 1;
        l = 0;
        
        while (l < 15){
            if (Albania.a_distance[path[counter - 1][0]][l] == 1  &&  deleted != l) {
                
                if (a_colors[l] == a_colors[path[counter - 1][0]]) {
                    a_colors[path[counter - 1][0]] += 1;
                    
                    if (a_colors[path[counter - 1][0]] > quantity) {
                        do {
                            deleted = path[counter - 1][0];
                            path[counter - 1][0] = 0;
                            counter --;
                            all_V--;
                            
                            if (counter == 1) {
                                i = 0;
                                j = path[counter - 1][2] + 1;
                                if (j == 6) {
                                    return 0;
                                }
                                
                                counter = 0;
                                the_end = true;
                            }
                            else {
                                i = path[counter - 1][1];
                                j = path[counter - 1][2];
                            }
                            
                        } while (quantity < a_colors[V_degree[i][j]] + 1  &&  !the_end);
                        
                        if (!the_end) {
                            a_colors[V_degree[i][j]] = 1 + a_colors[V_degree[i][j]];
                            all_V++;
                        }
                        else {break;}
                    }
                    
                    l = 0;
                    continue;
                }
            }
            l++;
        }
        
        deleted = -1;
        counter++;
        
        if (the_end) {
            the_end = false;
            continue;
        }
        
        i = 0;
        j = 0;
    }
    
    Print_Groups(a_colors, quantity, Albania);
    return 1;
}


bool not_visited(int l, int path [][3], int counter) {

    bool result = true;
    for (int i = 0; i < counter - 1; i++) {
        if (path[i][0] == l) {
            result = false;
        }
    }
    
    return result;
    
}

void Print_Groups(vector<int> &a_colors, int max_color, Cities &Albania) {
    
    int color = 1;
    int i = 0;
    
    while (color < max_color + 1) {
        
        cout << "Color #" << color << ": ";
        
        while (i < 15) {
            
            if (a_colors[i] == color) {
                cout << Albania.a_cities[i] << ", ";
            }
            
            i++;
        }
        cout << endl;
        color++;
        i = 0;
    }
}
