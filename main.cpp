#include <iostream>
#include <vector>
#include <string>
#include <sstream>
#include <cmath>

using namespace std;

// Function to parse equation and extract coefficients
vector<double> parseEquation(const string& equation) {  //parse equation
    vector<double> coeffs(4, 0); // a, b, c, constant
    
    string cleaned = equation;
    // Remove spaces
    cleaned.erase(remove(cleaned.begin(), cleaned.end(), ' '), cleaned.end());

  
    // Replace variable terms
    size_t pos = 0;
    if (cleaned[0] != '-' && cleaned[0] != '+') cleaned = "+" + cleaned;

    // Handle coefficients for a, b, c
    if ((pos = cleaned.find('a')) != string::npos) {
        int i = pos - 1;
        string num = "";
        bool neg = false;
        while (i >= 0 && (isdigit(cleaned[i]) || cleaned[i] == '.' || cleaned[i] == '-')) {
            num = cleaned[i] + num;
            if (cleaned[i] == '-') neg = true;
            i--;
        }
        if (num.empty() || num == "+") coeffs[0] = 1.0;
        else if (num == "-") coeffs[0] = -1.0;
        else coeffs[0] = stod(num);
    }

    if ((pos = cleaned.find('b')) != string::npos) {
        int i = pos - 1;
        string num = "";
        bool neg = false;
        while (i >= 0 && (isdigit(cleaned[i]) || cleaned[i] == '.' || cleaned[i] == '-')) {
            num = cleaned[i] + num;
            if (cleaned[i] == '-') neg = true;
            i--;
        }
        if (num.empty() || num == "+") coeffs[1] = 1.0;
        else if (num == "-") coeffs[1] = -1.0;
        else coeffs[1] = stod(num);
    }

    if ((pos = cleaned.find('c')) != string::npos) {
        int i = pos - 1;
        string num = "";
        bool neg = false;
        while (i >= 0 && (isdigit(cleaned[i]) || cleaned[i] == '.' || cleaned[i] == '-')) {
            num = cleaned[i] + num;
            if (cleaned[i] == '-') neg = true;
            i--;
        }
        if (num.empty() || num == "+") coeffs[2] = 1.0;
        else if (num == "-") coeffs[2] = -1.0;
        else coeffs[2] = stod(num);
    }

    // Handle constant term (after =)
    pos = cleaned.find('=');
    string constant = cleaned.substr(pos + 1);
    coeffs[3] = stod(constant);

    return coeffs;
}

// Gaussian elimination function
vector<double> gaussianElimination(vector<vector<double>>& matrix) {
    int n = matrix.size();

    // Forward elimination
    for (int i = 0; i < n; i++) {
        // Find pivot
        double pivot = matrix[i][i];
        if (abs(pivot) < 1e-10) {
            throw runtime_error("No unique solution exists");
        }

        // Make pivot 1
        for (int j = i; j <= n; j++) {
            matrix[i][j] /= pivot;
        }

        // Eliminate column
        for (int k = 0; k < n; k++) {
            if (k != i) {
                double factor = matrix[k][i];
                for (int j = i; j <= n; j++) {
                    matrix[k][j] -= factor * matrix[i][j];
                }
            }
        }
    }

    // Extract solution
    vector<double> solution(n);
    for (int i = 0; i < n; i++) {
        solution[i] = matrix[i][n];
    }

    return solution;
}

int main() {
    // Input equations
    vector<string> equations = {
        "a+2b+c=2",
        "a-b-c=0",
        "a+b=3"
    };

    // Parse equations into matrix
    vector<vector<double>> matrix(3, vector<double>(4));
    for (int i = 0; i < 3; i++) {
        matrix[i] = parseEquation(equations[i]);
    }

    try {
        // Solve using Gaussian elimination
        vector<double> solution = gaussianElimination(matrix);

        // Output solution
        cout << "Solution vector: [ ";
        for (double x : solution) {
            cout << x << " ";
        }
        cout << "]" << endl;

        // Output as variables
        cout << "a = " << solution[0] << endl;
        cout << "b = " << solution[1] << endl;
        cout << "c = " << solution[2] << endl;
    }
    catch (const exception& e) {
        cout << "Error: " << e.what() << endl;
    }

    return 0;
}
