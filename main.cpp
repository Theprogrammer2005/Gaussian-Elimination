/* code made by Mohamed AbdelWahab 
on 25-Aug-2025


*/

/*



1.1 Definition A linear combination of x1, ..., xn has the form
 a1x1 +a2x2 +a3x3 +... +anxn
 where the numbers a1
 an Rare the combination’s coefficients. A linear
 equation in the variables x1, ..., xn has the form a1x1 + a2x2 +a3x3 + +
 anxn = d where d bleongs to R is the constant.
 An n-tuple (s1 s2
 sn) Rn is a solution of, or satisfies, that equation
 if substituting the numbers s1, ..., sn for the variables gives a true statement:
 a1s1 +a2s2 + +ansn =d. A system of linear equations
 a11x1 + a12x2 + + a1nxn = d1
 a21x1 + a22x2 + + a2nxn = d2
 .
 .
 .
 am1x1 +am2x2 + +amnxn = dm
 has the solution (s1 s2
 sn) if that n-tuple is a solution of all of the equations.


*/

/*
 Theorem (Gauss’s Method) If a linear system is changed to another by one of
 these operations
 (1) an equation is swapped with another
 (2) an equation has both sides multiplied by a nonzero constant
 (3) an equation is replaced by the sum of itself and a multiple of another
 then the two systems have the same set of solutions
 */
#include <iostream>
#include <vector>
#include <string>
#include <sstream>
#include <cmath>


using namespace std;

// function to parse equation and extract coefficients
vector<double> parseEquation(const string& equation) {   //input is a string called by ref


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
    //check for b variable
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
        "a+b+c=4",
        "a-b+c=2",
        "2a+2b+c=7"
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
