#include <iostream>
#include <fstream>
#include <sstream>
#include <iomanip>
#include <string>
#include "src/Utils.hpp"

using namespace std;

int main()
{
    string inputFileName = "./data.txt";
	string outputFileName = "./result.txt";
    size_t n = 0;
	double S = 0.0;
	double V = 0.0;
    double* w = nullptr;
    double* r = nullptr;
	string nomeS;
	string nomeN;
	string nomeW;
	string nomeR;

    if (!ImportVectors(inputFileName, S, n, w, r, V, nomeS, nomeN, nomeW, nomeR))
    {
        cerr << "Errore nell'importazione del file" << endl;
        return -1;
    }
    else
        cout << "File 'data.txt' importato correttamente" << endl;
	
		double dotProduct = DotProduct(n, w, r);
		
		cout << nomeS << " = " << fixed << setprecision(2) << S << ", " << nomeN << " = " << n << endl;
		cout << nomeW << " = " << ArrayToString(n, w) << endl;
		cout << nomeR << " = " << ArrayToString(n, r) << endl;
		cout << "Rate of return of the portfolio: " << setprecision(4) << dotProduct << endl;
		cout << "V: " << fixed << setprecision(2) << V << endl;


    if (!ExportResult(outputFileName, S, n, w, r, dotProduct, V, nomeS, nomeN, nomeW, nomeR))
    {
        cerr << "Errore nell'esportazione del file" << endl;
        return -1;
    }
    else
        cout << "File 'result.txt' esportato correttamente" << endl;

    delete[] w;
    delete[] r;

    return 0;
}


