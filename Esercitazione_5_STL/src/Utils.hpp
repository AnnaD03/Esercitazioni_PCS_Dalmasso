#pragma once

#include <iostream>
#include "PolygonalMesh.hpp"

using namespace std;

namespace PolygonalLibrary
{
/*Importazione della polygonal mesh and verifica che la mesh sia corretta
  mesh: PolygonalMesh struct
  restituisce il risultato della lettura, true se ha successo, false altrimenti */
bool ImportMesh(PolygonalMesh& mesh);

/*Importazione dei vertici della mesh dal file Cell0Ds.csv
  mesh: PolygonalMesh struct
  restituisce il risultato della lettura, true se ha successo, false altrimenti */
bool ImportCell0Ds(PolygonalMesh& mesh);

/*Importazione dei lati della mesh dal file Cell1Ds.csv
  mesh: PolygonalMesh struct
  restituisce il risultato della lettura, true se ha successo, false altrimenti */
bool ImportCell1Ds(PolygonalMesh& mesh);

/*Importazione dei poligoni della mesh dal file Cell2Ds.csv
  mesh: PolygonalMesh struct
  restituisce il risultato della lettura, true se ha successo, false altrimenti */
bool ImportCell2Ds(PolygonalMesh& mesh);

}

