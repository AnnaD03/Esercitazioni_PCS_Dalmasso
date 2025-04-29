#pragma once

#include <iostream>
#include "Eigen/Eigen"
#include<vector>
#include<list>
#include<map>

using namespace std;
using namespace Eigen;

namespace PolygonalLibrary {

struct PolygonalMesh
{
	unsigned int NumCell0Ds = 0; //numero di Cell0D
    vector<unsigned int> Cell0DsId = {}; //vettore con id dei vertici (dimensione 1 x NumCell0D)
    MatrixXd Cell0DsCoordinates = {}; //matrice con le coordinate dei vertici (dimensione 2 x NumCell0D) (x,y)
    map<unsigned int, list<unsigned int>> MarkerCell0Ds = {}; //marker dei vertici

    unsigned int NumCell1Ds = 0; //numero di Cell1D
    vector<unsigned int> Cell1DsId = {}; //vettore con id dei lati (dimensione 1 x NumCell1D)
    MatrixXi Cell1DsExtrema = {}; //matrice con gli estremi dei lati (dimensione 2 x NumberCell1D) (fromId,toId)
    map<unsigned int, list<unsigned int>> MarkerCell1Ds = {}; //marker dei lati

    unsigned int NumCell2Ds = 0; //numero di Cell2D
    vector<unsigned int> Cell2DsId = {}; //vettore con id dei poligoni (dimensione 1 x NumCell2D)
    vector<vector<unsigned int>> Cell2DsVertices = {}; //vertici del poligono (dimensione 1 x NumCell2DVertices[NumCell2D])
    vector<vector<unsigned int>> Cell2DsEdges = {}; //lati del poligono (dimensione 1 x NumCell2DEdges[NumCell2D])
	map<unsigned int, list<unsigned int>> MarkerCell2Ds = {}; //marker dei poligoni	
};

}

