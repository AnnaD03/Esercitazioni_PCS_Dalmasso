#pragma once

#include <iostream>

using namespace std;

bool ImportVectors(const string& inputFilePath, double& S, size_t& n, double*& w, double*& r, double& V, 
					string& nomeS, string& nomeN, string& nomeW, string& nomeR);
					
bool ExportResult(const string& outputFilePath, const double& S, const size_t& n, const double* const& w, const double* const& r, const double& dotProduct, 
					const double& V, const string& nomeS, const string& nomeN, const string& nomeW, const string& nomeR);
					
double DotProduct(const size_t& n, const double* const& v1, const double* const& v2);

string ArrayToString(const size_t& n, const double* const& v);



