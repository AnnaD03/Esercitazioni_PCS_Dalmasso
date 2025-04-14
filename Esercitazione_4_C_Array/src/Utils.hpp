#pragma once

#include <iostream>

using namespace std;

/* ImportVectors legge il file in input dove sono scritti i vettori utili alla risoluzione del problema
	- inputFilePath: path name del file in input
	- S: valore iniziale investito
	- n: dimensione dei vettori
	- w: frazione di S investita
	- r: tasso di rendimento di ogni investimento 
	- V: valore finale del portfolio
	- nomi: nomi delle variabili, letti nel file in input */
bool ImportVectors(const string& inputFilePath, double& S, size_t& n, double*& w, double*& r, double& V, 
					string& nomeS, string& nomeN, string& nomeW, string& nomeR);

/* ExportResult esporta i risultati richiesti in un file in output
	- outputFilePath: path name del file in output
	- S: valore iniziale investito
	- n: dimensione dei vettori
	- w: frazione di S investita
	- r: tasso di rendimento di ogni investimento
	- dotProduct: tasso di rendimento calcolato
	- V: valore finale del portfolio
	- nomi: nomi delle variabili, letti nel file in input */					
bool ExportResult(const string& outputFilePath, const double& S, const size_t& n, const double* const& w, const double* const& r, const double& dotProduct, 
					const double& V, const string& nomeS, const string& nomeN, const string& nomeW, const string& nomeR);

/* DotProduct calcola il prodotto scalare tra due vettori
	- n: dimensione dei vettori
	- v1: primo vettore
	- v2: secondo vettore */				
double DotProduct(const size_t& n, const double* const& v1, const double* const& v2);


/* ArrayToString converte un vettore in stringa
	- n: dimensione del vettore
	- v: vettore da trasformare */
string ArrayToString(const size_t& n, const double* const& v);



