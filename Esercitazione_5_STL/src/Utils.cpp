#include "Utils.hpp"
#include <iostream>
#include <fstream>
#include <sstream>

namespace PolygonalLibrary
{
bool ImportMesh(PolygonalMesh& mesh)
{

    if(!ImportCell0Ds(mesh))
        return false;
	else{
		cout << "Marker Cell0D:" << endl;
		if (mesh.MarkerCell0Ds.size() != 0){
			for(auto it = mesh.MarkerCell0Ds.begin(); it != mesh.MarkerCell0Ds.end(); it++)
			{
				cout << "Marker id: " << it -> first << "\t" << "Valori: ";
				for(const unsigned int id : it -> second)
					cout << id << " ";
				cout << endl;
			}
		}
		else{
			cout << "Tutti i marker sono nulli" << endl;
		}
	}

    if(!ImportCell1Ds(mesh))
        return false;
	else{
		cout << "Marker Cell1D:" << endl;
		if (mesh.MarkerCell1Ds.size() != 0){
			for(auto it = mesh.MarkerCell1Ds.begin(); it != mesh.MarkerCell1Ds.end(); it++)
			{
				cout << "Marker id: " << it -> first << "\t" << "Valori: ";
				for(const unsigned int id : it -> second)
					cout << id << " ";
				cout << endl;
			}
		}
		else{
			cout << "Tutti i marker sono nulli" << endl;
		}
	}

    if(!ImportCell2Ds(mesh))
        return false;
	else{
		cout << "Marker Cell2D:" << endl;
		if (mesh.MarkerCell2Ds.size() != 0){
			for(auto it = mesh.MarkerCell2Ds.begin(); it != mesh.MarkerCell2Ds.end(); it++)
			{
				cout << "Marker id: " << it -> first << "\t" << "Valori: ";
				for(const unsigned int id : it -> second)
					cout << id << " ";

				cout << endl;
			}
		}
		else{
			cout << "Tutti i marker sono nulli" << endl;
		}
	}

    return true;
}
// ***************************************************************************
bool ImportCell0Ds(PolygonalMesh& mesh) 
{
    ifstream file("./Cell0Ds.csv");

    if(file.fail())
        return false;

    list<string> listLines; //si leggono tutte le righe memorizzandole in una lista temporanea

    string line;
    while (getline(file, line))
        listLines.push_back(line);

    file.close();

    listLines.pop_front(); //rimozione dell'header

    mesh.NumCell0Ds = listLines.size(); //si ricava il numero di vertici

    if (mesh.NumCell0Ds == 0)
    {
        cerr << "Nel file non risultano Cell0D" << endl;
        return false;
    }

    mesh.Cell0DsId.reserve(mesh.NumCell0Ds); //si ridimensiona la capacità per il vettore
    mesh.Cell0DsCoordinates = Eigen::MatrixXd::Zero(3, mesh.NumCell0Ds); //si salvano le coordinate (x,y) degli n vertici del file (mentre z=0 essendo in 2D)

    for (const string& line : listLines)
    {
        istringstream converter(line);

        unsigned int id;
        unsigned int marker;
        char sep; //variabile temporanea per leggere il separatore ";"

        converter >> id >> sep >> marker >> sep >> mesh.Cell0DsCoordinates(0, id) >> sep >> mesh.Cell0DsCoordinates(1, id);

        mesh.Cell0DsId.push_back(id);

        //Memorizzazione dei marker
        if(marker != 0)
        {
            const auto it = mesh.MarkerCell0Ds.find(marker);
            if(it == mesh.MarkerCell0Ds.end())
            {
                mesh.MarkerCell0Ds.insert({marker, {id}}); //si inserisce un nuovo marker se non ancora presente nella mappa 
            }
            else
            {
                it -> second.push_back(id); 
            }
        }
    }

    return true;
}
// ***************************************************************************
bool ImportCell1Ds(PolygonalMesh& mesh)
{
    ifstream file("./Cell1Ds.csv");

    if(file.fail())
        return false;

    list<string> listLines;
    string line;
    while (getline(file, line))
        listLines.push_back(line);

    file.close();

    listLines.pop_front(); //rimozione dell'header

    mesh.NumCell1Ds = listLines.size(); //si ricava il numero di lati

    if (mesh.NumCell1Ds == 0)
    {
        cerr << "Nel file non risultano Cell1D" << endl;
        return false;
    }

    mesh.Cell1DsId.reserve(mesh.NumCell1Ds); //si ridimensiona la capacità per il vettore
    mesh.Cell1DsExtrema = Eigen::MatrixXi(2, mesh.NumCell1Ds); //si salvano i due estremi di ogni lato

	unsigned int j = 0; //contatore dei lati di lunghezza nulla
	
    for (const string& line : listLines)
    {
        istringstream converter(line);

        unsigned int id;
        unsigned int marker;
		char sep;

        converter >> id >> sep >> marker >> sep >> mesh.Cell1DsExtrema(0, id) >> sep >> mesh.Cell1DsExtrema(1, id);
		
        mesh.Cell1DsId.push_back(id);

        //Memorizzazione dei marker
        if(marker != 0){
            const auto it = mesh.MarkerCell1Ds.find(marker);
            if(it == mesh.MarkerCell1Ds.end())
            {
                mesh.MarkerCell1Ds.insert({marker, {id}});
            }
            else
            {
                it->second.push_back(id);
            }
        }
		
		//Test: lunghezza dei lati non nulla
		if(mesh.Cell1DsExtrema(0, id) == mesh.Cell1DsExtrema(1, id)){
			j++;
			cout << "Il lato " << id << " ha lunghezza nulla" << endl;
		}
    }
		
	if(j == 0)
		cout << "TEST SUPERATO: non ci sono lati di lunghezza nulla" << endl;
	else{
		cerr << "TEST FALLITO: ci sono " << j << " lati di lunghezza nulla" << endl;
		return false;
	}

    return true;
}
// ***************************************************************************
bool ImportCell2Ds(PolygonalMesh& mesh)
{
    ifstream file("./Cell2Ds.csv");

    if(file.fail())
        return false;

    list<string> listLines;
    string line;
    while (getline(file, line))
        listLines.push_back(line);

    file.close();

    listLines.pop_front(); //rimozione dell'header

    mesh.NumCell2Ds = listLines.size(); //si ricava il numero di poligoni

    if (mesh.NumCell2Ds == 0)
    {
        cerr << "Nel file non risultano Cell2D" << endl;
        return false;
    }

    mesh.Cell2DsId.reserve(mesh.NumCell2Ds);
    mesh.Cell2DsVertices.reserve(mesh.NumCell2Ds);
    mesh.Cell2DsEdges.reserve(mesh.NumCell2Ds);
	
	unsigned int k = 0; //contatore dei poligoni di area nulla

    for (const string& line : listLines)
    {
        istringstream converter(line);

        unsigned int id;
		unsigned int marker;
		char sep;
		
		unsigned int numV;
		unsigned int vert;
        vector<unsigned int> vertices;
		
		unsigned int numE;
		unsigned int edge;
        vector<unsigned int> edges;
		

        converter >> id >> sep >> marker >> sep >> numV;
		vertices.reserve(numV);
        for(unsigned int i = 0; i < numV; i++){
            converter >> sep >> vert;
			vertices.push_back(vert);
		}
		
		converter >> sep >> numE;
		edges.reserve(numE);
        for(unsigned int i = 0; i < numE; i++){
            converter >> sep >> edge;
			edges.push_back(edge);
		}

        mesh.Cell2DsId.push_back(id);
        mesh.Cell2DsVertices.push_back(vertices);
        mesh.Cell2DsEdges.push_back(edges);

        //Memorizzazione dei marker
        if(marker != 0){
            const auto it = mesh.MarkerCell2Ds.find(marker);
            if(it == mesh.MarkerCell2Ds.end())
            {
                mesh.MarkerCell2Ds.insert({marker, {id}}); //si inserisce un nuovo marker (se non ancora presente)
            }
            else
            {
                mesh.MarkerCell2Ds[marker].push_back(id); //si aggiorna il valore della chiave
            }
        }
		
		//Test: area dei poligoni non nulla
		double area = 0.0;
		
		for(unsigned int i = 0; i < numV; i++){
			unsigned int j = (i + 1) % numV;
			
			const MatrixXd& coord = mesh.Cell0DsCoordinates;
			double x_i = coord(0, vertices[i]);
			double y_i = coord(1, vertices[i]);
			double x_j = coord(0, vertices[j]);
			double y_j = coord(1, vertices[j]);
			
			area += (x_i * y_j) - (x_j * y_i);
		}
		area = 0.5 * abs(area);
		
		if(area < 1e-16){
			k++;
			cout << "Il poligono " << id << " ha area nulla" << endl;
		}
    }
		
	if(k == 0)
		cout << "TEST SUPERATO: non ci sono poligoni di area nulla" << endl;
	else{
		cerr << "TEST FALLITO: ci sono " << k << " poligoni con area nulla" << endl;
		return false;
	}

    return true;
}

}
