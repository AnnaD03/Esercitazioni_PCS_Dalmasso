#include <iostream>
#include <fstream>
#include <sstream>
#include <iomanip>
#include "src/Utils.hpp"
// #include "ClassObj.hpp" // error if pragma once is not used in ClassObj

using namespace std;

int main()
{
    string inputFileName = "./data.txt";
    size_t n = 0;
	double S = 0.0;
	double V = 0.0;
    double* w = nullptr;
    double* r = nullptr;

    if (!ImportVectors(inputFileName, S, n, w, r, V))
    {
        cerr << "Something goes wrong with import"<< endl;
        return -1;
    }
    else
        cout << "File importato correttamente" << endl;
		double dotProduct = DotProduct(n, w, r);
		cout << "S = " << fixed << setprecision(2) << S << ", n = " << n << endl;

		cout << "w = " << ArrayToString(n, w) << endl;

		cout << "r = " << ArrayToString(n, r) << endl;

		cout << "Rate of return of the portfolio: " << setprecision(4) << dotProduct << endl;
		cout << "V: " << fixed << setprecision(2) << V << endl;


    string outputFileName = "./result.txt";
    if (!ExportResult(outputFileName, S, n, w, r, dotProduct, V))
    {
        cerr << "Something goes wrong with export" << endl;
        return -1;
    }
    else
        cout << "File esportato correttamente" << endl;

    delete[] w;
    delete[] r;

    return 0;
}


