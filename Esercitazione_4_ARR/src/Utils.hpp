#pragma once


//#include "ClassObj.hpp"
#include <iostream>

using namespace std;

//int foo(ClassObj obj);


double DotProduct(const size_t& n, const double* const& v1, const double* const& v2);

bool ImportVectors(const string& inputFilePath, double& S, size_t& n, double*& w, double*& r, double& V);

void PrintResult(const double& S, const size_t& n, const double* const& w, const double* const& r, const double& dotProduct, const double& V);

bool ExportResult(const string& outputFilePath, const double& S, const size_t& n, const double* const& w, const double* const& r, const double& dotProduct, const double& V);

string ArrayToString(const size_t& n, const double* const& v);



