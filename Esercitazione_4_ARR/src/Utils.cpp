#include "Utils.hpp"

#include "iostream"
#include "fstream"
#include "sstream"

#include <iomanip>

using namespace std;

/*int foo(ClassObj obj)
{
    return obj.a;
}*/

double DotProduct(const size_t& n, const double* const& v1, const double* const& v2)
{
    double dotProduct = 0.0;
    for (unsigned int i = 0; i < n; i++)
        dotProduct += v1[i] * v2[i];

    return dotProduct;
}

bool ImportVectors(const string& inputFilePath, double& S, size_t& n, double*& w, double*& r, double& V)
{
    // Open File
    ifstream file;
    file.open(inputFilePath);

    if (file.fail())
    {
        cerr << "errore nell'apertura del file" << endl;
        return false;
    }
	
	
	unsigned int location = 0;
	double w_i = 0.0;
	double r_i = 0.0;

    string line;
	    
    // Read and set investement
    getline(file, line);
    location = line.find(';');
	istringstream convertS;
    convertS.str(line.substr(location + 1, line.length()));
	convertS >> S;
	
    // Read and set number of assets
    getline(file, line);
    location = line.find(';');
	istringstream convertN;
    convertN.str(line.substr(location + 1, line.length()));
	convertN >> n;
	
	w = new double[n];
	r = new double[n];
	
    // skip unnecessary line
    getline(file, line);

	unsigned int i = 0;

    // Get first vector
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
        
		V += (1 + r_i) * (S * w_i); //aggiorno il valore del portfolio
		
		i++;
    }

    // Close File
    file.close();

    return true;
}


bool ExportResult(const string& outputFilePath, const double& S, const size_t& n, const double* const& w, const double* const& r, const double& dotProduct, const double& V)
{
    // Open File
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

    // Close File
    result.close();

    return true;
}

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
