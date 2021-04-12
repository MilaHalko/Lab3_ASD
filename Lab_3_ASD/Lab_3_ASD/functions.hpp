#include "libraries.hpp"
#include "class_Cities.hpp"

void Find_degree_V(Cities &Albania, vector<vector<int>> &V_degree);
int Coloring(vector<int> &a_colors, Cities &Albania, vector<vector<int>> &V_degree);
bool Coloring(vector<int> &a_colors, Cities &Albania, vector<vector<int>> &V_degree, int quantity);
bool not_visited(int l, int path [][3], int counter);
void Print_Groups(vector<int> &a_colors, int max_color, Cities &Albania);
