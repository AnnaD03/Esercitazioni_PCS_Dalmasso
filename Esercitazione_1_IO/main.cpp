#include <iostream>
#include <fstream>
#include <string>
#include <iomanip>

double map_values(double &val)
{
	int a = 1;
	int b = 5;
	int c = -1;
	int d = 2;
	
	double new_value = c + (d - c) * (val - a) / (b - a);
	
	return new_value;
}

int main()
{
	const std::string ifilename = "data.txt";	
    std::ifstream ifs(ifilename); 
	
    if (ifs.fail()) //controllo errori nell'apertura corretta del file data.txt
	{
        std::cerr << "Errore nell'apertura del file " << ifilename << std::endl; 
        return 1;
    }
	
	const std::string ofilename = "result.txt";
	std::ofstream ofs(ofilename);
	
	if (ofs.fail()) //controllo errori nell'apertura corretta del file result.txt
	{
        std::cerr << "Errore nell'apertura del file " << ofilename << std::endl; 
        return 1;
    }
	
	double value; //variabile ausiliaria in cui si memorizzano i valori letti nelle righe del file
	double sum = 0.0;
	double mean = 0.0;
	unsigned int index = 1;
	
	ofs << "# N Mean" << std::endl;

    while (ifs >> value) 
	{
		sum += map_values(value);
		mean = sum/index;
		ofs << index << " " << std::setprecision(16) << std::scientific << mean << std::endl;
		index++;
    }
	
	ifs.close();
	ofs.close();
	
    return 0;
}
