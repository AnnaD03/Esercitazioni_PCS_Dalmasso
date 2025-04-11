#include <iostream>
#include <fstream>
#include <sstream>
#include <iomanip>
#include "Utils.hpp"

using namespace std;

//calcolo prodotto scalare tra due vettori di lunghezza n
double DotProduct(const size_t& n, const double* const& v1, const double* const& v2)
{
    double dotProduct = 0.0;
    for (unsigned int i = 0; i < n; i++)
        dotProduct += v1[i] * v2[i];

    return dotProduct;
}

//importazione dei dati dal file inputFilePath
bool ImportVectors(const string& inputFilePath, double& S, size_t& n, double*& w, double*& r, double& V)
{
    //apertura file
    ifstream file;
    file.open(inputFilePath);

    if (file.fail())
    {
        cerr << "Errore nell'apertura del file" << endl;
        return false;
    }
	
	
	unsigned int location = 0;
	double w_i = 0.0;
	double r_i = 0.0;

    string line;
	    
    //lettura prima riga 
    getline(file, line);
    location = line.find(';');
	istringstream convertS;
    convertS.str(line.substr(location + 1, line.length()));
	convertS >> S;
	
    //lettura seconda riga
    getline(file, line);
    location = line.find(';');
	istringstream convertN;
    convertN.str(line.substr(location + 1, line.length()));
	convertN >> n;
	
	w = new double[n];
	r = new double[n];
	
    //salto terza riga (intestazione dei vettori)
	string tmp;
    getline(file, tmp);

	unsigned int i = 0;

    //lettura righe rimanenti e assegnamento dei vettori w (fractions) e r (rate)
    while(getline(file, line))
    {
        location = line.find(';');
		
		istringstream convertW;
		convertW.str(line.substr(0, location));
		convertW >> w_i;
		w[i] = w_i;
		
		istringstream convertR;
		convertR.str(line.substr(location + 1, line.length()));
		convertR >> r_i;
		r[i] = r_i;
        
		V += (1 + r_i) * (S * w_i); //aggiornamento del valore del portfolio
		
		i++;
    }

    //chiusura file
    file.close();

    return true;
}

//esportazione dei risultati sul file outputFilePath
bool ExportResult(const string& outputFilePath, const double& S, const size_t& n, const double* const& w, const double* const& r, const double& dotProduct, const double& V)
{
    //apertura file su cui esportare i risultati
    ofstream result;
    result.open(outputFilePath);

    if (result.fail())
    {
        cerr << "Errore nell'apertura del file" << endl;
        return false;
    }

    result << "S = " << fixed << setprecision(2) << S << ", n = " << n << endl;

    result << "w = " << ArrayToString(n, w) << endl;

    result << "r = " << ArrayToString(n, r) << endl;

    result << "Rate of return of the portfolio: " << setprecision(4) << dotProduct << endl;
    result << "V: " << fixed << setprecision(2) << V << endl;

    //chiusura file 
    result.close();

    return true;
}

//trasformazione di un array in una stringa
string ArrayToString(const size_t& n, const double* const& v)
{
    string str;
    ostringstream toString;
    toString << "[ ";
    for (unsigned int i = 0; i < n; i++)
        toString << v[i] << " ";
    toString << "]";

    return toString.str();
}
