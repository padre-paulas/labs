#include <iostream>
#include <vector>
#include <string>
#include <iomanip>

using namespace std;

int main() {
    vector<string> cities = {"Berehove", "Mukachevo", "Rakhiv", "Tiachiv", "Uzhhorod", "Khust"};
    int n = cities.size();

    int adjMatrix[6][6] = {
        {0, 30, 0, 0, 67, 68},  
        {30, 0, 0, 0, 42, 64},  
        {0, 0, 0, 70, 0, 0},   
        {0, 0, 70, 0, 0, 31},   
        {67, 42, 0, 0, 0, 0},  
        {68, 64, 0, 31, 0, 0}   
    };

    int incMatrix[6][7] = {
        {0, 1, 1, 0, 1, 0, 0}, 
        {1, 0, 1, 1, 0, 0, 0}, 
        {0, 0, 0, 0, 0, 0, 1},
        {0, 0, 0, 0, 0, 1, 1}, 
        {1, 1, 0, 0, 0, 0, 0}, 
        {0, 0, 0, 1, 1, 1, 0}  
    };

    string edgeLabels[] = {"42", "67", "30", "64", "68", "31", "70"};

    cout << "--- Adjacency Matrix (Distances in km) ---" << endl;
    cout << setw(12) << " ";
    for(const auto& city : cities) cout << setw(10) << city;
    cout << endl;

    for (int i = 0; i < n; i++) {
        cout << setw(12) << cities[i];
        for (int j = 0; j < n; j++) {
            cout << setw(10) << adjMatrix[i][j];
        }
        cout << endl;
    }

    cout << "\n--- Incident Matrix ---" << endl;
    cout << setw(12) << " ";
    for(const auto& edge : edgeLabels) cout << setw(5) << edge;
    cout << endl;

    for (int i = 0; i < n; i++) {
        cout << setw(12) << cities[i];
        for (int j = 0; j < 7; j++) {
            cout << setw(5) << incMatrix[i][j];
        }
        cout << endl;
    }

    return 0;
}