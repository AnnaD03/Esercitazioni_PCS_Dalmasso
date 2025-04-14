#include <iostream>
#include <fstream>
#include <sstream>
#include <iomanip>
#include <string>
#include "Utils.hpp"

using namespace std;

//importazione dei dati dal file inputFilePath
bool ImportVectors(const string& inputFilePath, double& S, size_t& n, double*& w, double*& r, double& V, 
					string& nomeS, string& nomeN, string& nomeW, string& nomeR)
{
    //apertura file
    ifstream file;
    file.open(inputFilePath);

    if (file.fail())
    {
        cerr << "Errore nell'apertura del file" << endl;
        return false;
    }	

    string line;
	    
    //lettura prima riga (somma iniziale investita)
    getline(file, line);
	istringstream convertS(line);
	getline(convertS, nomeS, ';'); //la sottostringa fino al ';' viene assegnata a nomeS
	convertS >> S; //la sottostringa dopo al ';' viene assegnata a S
	
    //lettura seconda riga (numero assets)
    getline(file, line);
	istringstream convertN(line);
    getline(convertN, nomeN, ';'); //la sottostringa fino al ';' viene assegnata a nomeN
	convertN >> n; //la sottostringa dopo al ';' viene assegnata a N
	
	w = new double[n];
	r = new double[n];
	
    //lettura terza riga (intestazione dei vettori)
    getline(file, line);
	istringstream convertName(line);
	getline(convertName, nomeW, ';'); //la sottostringa fino al ';' viene assegnata a nomeW
	convertName >> nomeR; //la sottostringa dopo al ';' viene assegnata a nomeR

    //lettura righe rimanenti e assegnamento dei vettori w (fractions) e r (rate)
    for(size_t i = 0; i < n && getline(file, line); i++)
    {
		istringstream convertVal(line);		
		convertVal >> w[i];  //la sottostringa fino al ';' viene assegnata all'elemento i-esimo di w		
		convertVal.ignore(); //si ignora il ';'		
		convertVal >> r[i]; //la sottostringa dopo al ';' viene assegnata all'elemento i-esimo di r
        
		V += (1 + r[i]) * (S * w[i]); //aggiornamento del valore del portfolio
    }

    //chiusura file
    file.close();

    return true;
}

//esportazione dei risultati sul file outputFilePath
bool ExportResult(const string& outputFilePath, const double& S, const size_t& n, const double* const& w, const double* const& r, const double& dotProduct, 
					const double& V, const string& nomeS, const string& nomeN, const string& nomeW, const string& nomeR)
{
    //apertura file su cui esportare i risultati
    ofstream result;
    result.open(outputFilePath);

    if (result.fail())
    {
        cerr << "Errore nell'apertura del file" << endl;
        return false;
    }

    result << nomeS << " = " << fixed << setprecision(2) << S << ", " << nomeN << " = " << n << endl;
    result << nomeW << " = " << ArrayToString(n, w) << endl;
    result << nomeR << " = " << ArrayToString(n, r) << endl;
    result << "Rate of return of the portfolio: " << setprecision(4) << dotProduct << endl;
    result << "V: " << fixed << setprecision(2) << V << endl;

    //chiusura file 
    result.close();

    return true;
}

//calcolo prodotto scalare tra due vettori di lunghezza n (per il tasso di rendimento del portfolio)
double DotProduct(const size_t& n, const double* const& v1, const double* const& v2)
{
    double dotProduct = 0.0;
    for (unsigned int i = 0; i < n; i++)
        dotProduct += v1[i] * v2[i];

    return dotProduct;
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
