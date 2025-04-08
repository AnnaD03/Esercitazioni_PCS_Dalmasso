#include <iostream>
#include <iomanip>
#include "Eigen/Eigen"

using namespace std;
using namespace Eigen;

//Risoluzione di un sistema lineare Ax=b tramite la fattorizzazione A=QR
VectorXd sol_PALU(const MatrixXd& A, const VectorXd& b)
{
	VectorXd sol_PALU;
	if(abs(A.determinant()) < 1.0e-15){
		cerr << "La matrice è singolare" << endl;
	}
	else{
		sol_PALU = A.partialPivLu().solve(b);
	}
	return sol_PALU;
	
}

//Risoluzione di un sistema lineare Ax=b tramite la fattorizzazione PA=LU (cioè con pivoting parziale)
VectorXd sol_QR(const MatrixXd& A, const VectorXd& b)
{
	VectorXd sol_QR;
	if(abs(A.determinant()) < 1.0e-15){
		cerr << "La matrice è singolare" << endl;
	}
	else{
		sol_QR = A.householderQr().solve(b);
	}
	return sol_QR;
}

//Calcolo dell'errore relativo della soluzione (in norma 2)
double err_rel(const VectorXd& x_err, const VectorXd& x_ex)
{
	double err_rel = (x_err - x_ex).norm() / x_ex.norm();
	return err_rel;
}

int main()
{
	Vector2d x_ex(-1.0e+00, -1.0e+00);
	
	cout << "Sistema 1" << endl;
	
	Matrix2d A1 {
		{5.547001962252291e-01, -3.770900990025203e-02},
		{8.320502943378437e-01, -9.992887623566787e-01},
	};
	
	Vector2d b1(-5.169911863249772e-01, 1.672384680188350e-01);
	
	Vector2d sol_PALU1 = sol_PALU(A1, b1);
	cout << "Risoluzione con PALU" << endl;
	cout << "Soluzione: \n" << scientific << setprecision(15) << sol_PALU1 << endl;
	cout << "Errore relativo: " << scientific << setprecision(15) << err_rel(sol_PALU1, x_ex) << endl;
	
	Vector2d sol_QR1 = sol_QR(A1, b1);
	cout << "Risoluzione con QR" << endl;
	cout << "Soluzione: \n" << scientific << setprecision(15) << sol_QR1 << endl;
	cout << "Errore relativo: " << scientific << setprecision(15) << err_rel(sol_QR1, x_ex) << endl;
	
	
	cout << "Sistema 2" << endl;
	
	Matrix2d A2 {
		{5.547001962252291e-01, -5.540607316466765e-01},
		{8.320502943378437e-01, -8.324762492991313e-01},
	};
	
	Vector2d b2(-6.394645785530173e-04, 4.259549612877223e-04);
	
	Vector2d sol_PALU2 = sol_PALU(A2, b2);
	cout << "Risoluzione con PALU" << endl;
	cout << "Soluzione: \n" << scientific << setprecision(15) << sol_PALU2 << endl;
	cout << "Errore relativo: " << scientific << setprecision(15) << err_rel(sol_PALU2, x_ex) << endl;
	
	Vector2d sol_QR2 = sol_QR(A2, b2);
	cout << "Risoluzione con QR" << endl;
	cout << "Soluzione: \n" << scientific << setprecision(15) << sol_QR2 << endl;
	cout << "Errore relativo: " << scientific << setprecision(15) << err_rel(sol_QR2, x_ex) << endl;
	
	
	cout << "Sistema 3" << endl;
	
	Matrix2d A3 {
		{5.547001962252291e-01, -5.547001955851905e-01},
		{8.320502943378437e-01, -8.320502947645361e-01},
	};
	
	Vector2d b3(-6.400391328043042e-10, 4.266924591433963e-10);
	
	Vector2d sol_PALU3 = sol_PALU(A3, b3);
	cout << "Risoluzione con PALU" << endl;
	cout << "Soluzione: \n" << scientific << setprecision(15) << sol_PALU3 << endl;
	cout << "Errore relativo: " << scientific << setprecision(15) << err_rel(sol_PALU3, x_ex) << endl;
		
	Vector2d sol_QR3 = sol_QR(A3, b3);
	cout << "Risoluzione con QR" << endl;
	cout << "Soluzione: \n" << scientific << setprecision(15) << sol_QR3 << endl;
	cout << "Errore relativo: " << scientific << setprecision(15) << err_rel(sol_QR3, x_ex) << endl;
		
	
    return 0;
}
