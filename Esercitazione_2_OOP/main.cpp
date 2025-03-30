#include <iostream>
#include "complex_number.hpp"

int main(void) {
    using cnf = complex_number<float>;
	using cnd = complex_number<double>;
    
	//verifica con T float
	
    cnf c1(1.3f, -4.6f);
    cnf c2(2.5f, 7.8f);
   
    cnf c3 = c1 + c2;
	
    std::cout << c1 << " + " << c2 << " = " << c3 << std::endl;
	
	cnf c4 = c1 * c2;
    std::cout << c1 << " * " << c2 << " = " << c4 << std::endl;
	
	std::cout << "La parte reale di " << c1 << " è: " << c1.real() << std::endl;
	
	std::cout << "La parte immaginaria di " << c3 << " è: " << c3.imaginary() << std::endl;
	
    std::cout << "Il coniugato di " << c1 << " è: " << c1.conjugate() << std::endl; 
	
	std::cout << "Il coniugato di " << c3 << " è: " << c3.conjugate() << std::endl; 
	
	c1 += c2;
	std::cout << c1 << std::endl;
        
    cnf c5 = cnf(3.0f, 4.0f) + 2.5f;
    std::cout << "(" << cnf(3.0f,4.0f) << ") + 2.5 = " << c5 << std::endl;
	
	cnf c6 = cnf(3.1f, 4.2f) * 2.5f;
    std::cout << "(" << cnf(3.0f,4.0f) << ") * 2.5 = " << c6 << std::endl;

    cnf c7 = 5.0f + cnf(0.0f, 8.2f);
    std::cout << "5.0 + (" << cnf(0.0f, 8.2f) << ") = " << c7 << std::endl;
	
	cnf c8 = 5.0f * cnf(0.0f, 8.2f);
    std::cout << "5.0 * (" << cnf(0.0f, 8.2f) << ") = " << c8 << std::endl;
	
	
	//verifica con T double
		
	cnd c11(-2.3, -4.6);
    cnd c12(-1.5, 7.0);
   
    cnd c13 = c11 + c12;
	
    std::cout << c11 << " + " << c12 << " = " << c13 << std::endl;
	
	cnd c14 = c11 * c12;
    std::cout << c11 << " * " << c12 << " = " << c14 << std::endl;
	
	std::cout << "La parte reale di " << c13 << " è: " << c13.real() << std::endl;
	
	std::cout << "La parte immaginaria di " << c14 << " è: " << c14.imaginary() << std::endl;
	
    std::cout << "Il coniugato di " << c11 << " è: " << c11.conjugate() << std::endl; 
	
	std::cout << "Il coniugato di " << c12 << " è: " << c12.conjugate() << std::endl; 
	
	c11 *= c12;
	std::cout << c11 << std::endl;
        
    cnd c15 = cnd(3.1, 4.2) + 5.81;
    std::cout << "(" << cnd(3.1,4.2) << ") + 5.81 = " << c15 << std::endl;
	
	cnd c16 = cnd(3.1, 4.2) * 4.31;
    std::cout << "(" << cnd(3.1,4.2) << ") * 4.31 = " << c16 << std::endl;

    cnd c17 = -3.02 + cnd(4.3, 0.0);
    std::cout << "-3.02 + (" << cnd(4.3, 0.0) << ") = " << c17 << std::endl;
	
	cnd c18 = 2.33 * cnd(0.0, 4.3);
    std::cout << "2.33 * (" << cnd(0.0, 4.3) << ") = " << c18 << std::endl;
	
	cnd c19 = cnd(7.95);
	std::cout << c19 << std::endl;	
    
    return 0;
}
