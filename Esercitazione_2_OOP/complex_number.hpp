#pragma once

template<typename T> requires std::floating_point<T>
class complex_number
{
    T m_real, m_imag; //attributi privati
	
public:
	//costruttore di default
    complex_number()
        : m_real(0), m_imag(0)
    {}
    
	//costruttore definito dall'utente (prende come parametro un numero e lo rende complesso con parte immaginaria nulla)
    explicit complex_number(T r)
        : m_real(r), m_imag(0)
    {
        std::cout << "chiamato il costruttore di conversione" << std::endl;
    }
    
	//costruttore definito dall'utente (prende come parametri parte reale e parte immaginaria)
    complex_number(T r, T i)
        : m_real(r), m_imag(i)
    {}
    
	//restituisce la parte reale (senza modificare l'istanza su cui è chiamato)
    T real(void) const {
        return m_real;
    }
    
	//restituisce la parte immaginaria (senza modificare l'istanza su cui è chiamato)
    T imaginary(void) const {
        return m_imag;
    }
	
	//restituisce il complesso coniugato dell'istanza su cui è chiamato
	complex_number conjugate(void) const {	
		return complex_number(m_real, -m_imag);
	}
    
	//overload operatore di somma += (tra numeri complessi)
    complex_number& operator+=(const complex_number& other) {
        m_real = m_real + other.m_real;
        m_imag = m_imag + other.m_imag;
        return *this;
	}
	
	//overload operatore di somma + (tra numeri complessi)
	complex_number operator+(const complex_number& other) const {
        complex_number cn = *this;
        cn += other;
        return cn;
    }

	//overload operatore di somma += (con numero di tipo T a destra)
     complex_number& operator+=(const T& other) {
        m_real += other;
        return *this;
	}
	
	//overload operatore di somma + (con numero di tipo T a destra)
	complex_number operator+(const T& other) const {
        complex_number cn = *this;
        cn += other;
        return cn;
    }
	
	//overload operatore di moltiplicazione *= (tra numeri complessi)
	complex_number& operator*=(const complex_number& other) {
        m_real = m_real * other.m_real - m_imag * other.m_imag;
        m_imag = m_real * other.m_imag + m_imag * other.m_real;
        return *this;
	}
	
	//overload operatore di moltiplicazione * (tra numeri complessi)
	complex_number operator*(const complex_number& other) const {
        complex_number cn = *this;
        cn *= other;
        return cn;
    }
	
	//overload operatore di moltiplicazione *= (con numero di tipo T a destra)
     complex_number& operator*=(const T& other) {
        m_real *= other;
		m_imag *= other;
        return *this;
	}
	
	//overload operatore di moltiplicazione * (con numero di tipo T a destra)
	complex_number operator*(const T& other) const {
        complex_number cn = *this;
        cn *= other;
        return cn;
    }    
};

//overload operatore di somma + (con numero di tipo T a sinistra) per la commutatività
template<typename T>
complex_number<T> operator+(const T& other, const complex_number<T>& cn)
{
    return cn + other;
}

//overload operatore di moltiplicazione * (con numero di tipo T a sinistra) per la commutatività
template<typename T>
complex_number<T> operator*(const T& other, const complex_number<T>& cn)
{
    return cn * other;
}

//overload operatore << per stampare un numero complesso
template<typename T>
std::ostream& operator<<(std::ostream& os, const complex_number<T>& cn) {
    if (cn.real() != 0.0 && cn.imaginary() != 0.0)
		if (cn.imaginary() < 0.0)
			os << cn.real() << cn.imaginary() << "i";
		else
			os << cn.real() << "+" << cn.imaginary() << "i";
    else if (cn.real() == 0.0)
        os << cn.imaginary() << "i";
	else if (cn.imaginary() == 0.0)
		os << cn.real();

    return os;
}

