#include <cmath> //contiene floor
#include <iostream>
#include <numeric> //contiene iota
#include <iostream>
#include <sstream>
#include <chrono> 

#include "SortingAlgorithm.hpp"
using namespace std;

template<typename T>
string ArrayToString(const vector<T>& v)
{
    string str;
    ostringstream toString;
    toString << "[ ";
    for (const T& e: v)
        toString << e << " ";
    toString << "]";

    return toString.str();
}

struct ClassObj{
    double value;
};

inline bool operator< (const ClassObj& lhs, const ClassObj& rhs) { //definizione dell'operatore < per la struct ClassObj
	return lhs.value < rhs.value; 
}

int main(int argc, char *argv[])
{

    cout << "argc: " << argc << endl;
    for(int a = 0; a < argc; a++)
        cout << argv[a] << " ";
    cout << endl;

    size_t m = 100;
    if(argc > 1)
    {
        istringstream convert(argv[1]);
        convert >> m;
        cout << "lunghezza vettore: " << m << endl;
    }
    else
        cerr << "lunghezza vettore (default): " << m << endl;


	//Test con diversi vettori

    vector<int> v1(m); //vettore ordinato in modo crescente
    iota(v1.begin(), v1.end(), -4); // l'ultimo argomento è il valore di partenza

    //cout << "v1: " << endl;
    //cout << ArrayToString(v1) << endl;

    srand(2);
    vector<double> v2(m); //vettore di numeri random tra 0 e 1
    for(size_t i = 0; i < m; i++)
        v2[i] = rand() / ((double)RAND_MAX); 

    //cout << "v2: " << endl;
    //cout << ArrayToString(v2) << endl;

    vector<int> v3(m, 0); //vettore parzialmente ordinato
    for(size_t i = floor(m * 0.5) + 1; i < m; i++)
        v3[i] = rand() % 1000;

    copy(v1.begin(), v1.begin() + floor(m * 0.5) + 1, v3.begin()); 

    //cout << "v3: " << endl;
    //cout << ArrayToString(v3) << endl;
	
	vector<double> v4(m); //vettore ordinato in modo decrescente
	iota(v4.begin(), v4.end(), 1);
	reverse(v4.begin(), v4.end());	
	
	//cout << "v4: " << endl;
    //cout << ArrayToString(v4) << endl;


    unsigned int num_experiment = 1000;

    //BubbleSort

    double time_elapsed_bubble_v1 = 0.0;
    for(unsigned int t = 0; t < num_experiment; t++)
    {
        vector<int> v(v1);

        std::chrono::steady_clock::time_point start_time = std::chrono::steady_clock::now();
        SortLibrary::BubbleSort<int>(v);
        std::chrono::steady_clock::time_point end_time = std::chrono::steady_clock::now();
        time_elapsed_bubble_v1 += std::chrono::duration_cast<std::chrono::microseconds>(end_time - start_time).count();
		
		/*if(t == num_experiment - 1)
			cout << "vettore ordinato con BubbleSort: " << ArrayToString(v) << endl; */
    }
    time_elapsed_bubble_v1 /= num_experiment;

    cout << "Tempo medio ordinamento di v1 (con BubbleSort): " << time_elapsed_bubble_v1 << " µs" << endl;

    double time_elapsed_bubble_v2 = 0.0;
    for(unsigned int t = 0; t < num_experiment; t++)
    {
        vector<double> v(v2);

        std::chrono::steady_clock::time_point start_time = std::chrono::steady_clock::now();
        SortLibrary::BubbleSort<double>(v);
        std::chrono::steady_clock::time_point end_time = std::chrono::steady_clock::now();
        time_elapsed_bubble_v2 += std::chrono::duration_cast<std::chrono::microseconds>(end_time - start_time).count();
		
		/*if(t == num_experiment - 1)
			cout << "vettore ordinato con BubbleSort: " << ArrayToString(v) << endl; */
    }
    time_elapsed_bubble_v2 /= num_experiment;

    cout << "Tempo medio ordinamento di v2 (con BubbleSort): " << time_elapsed_bubble_v2 << " µs" << endl;


    double time_elapsed_bubble_v3 = 0.0;
    for(unsigned int t = 0; t < num_experiment; t++)
    {
        vector<int> v(v3);

        std::chrono::steady_clock::time_point start_time = std::chrono::steady_clock::now();
        SortLibrary::BubbleSort<int>(v);
        std::chrono::steady_clock::time_point end_time = std::chrono::steady_clock::now();
        time_elapsed_bubble_v3 += std::chrono::duration_cast<std::chrono::microseconds>(end_time - start_time).count();
		
		/*if(t == num_experiment - 1)
			cout << "Vettore ordinato con BubbleSort: " << ArrayToString(v) << endl; */
    }
    time_elapsed_bubble_v3 /= num_experiment;

    cout << "Tempo medio ordinamento di v3 (con BubbleSort): " << time_elapsed_bubble_v3 << " µs" << endl;
	
	
	double time_elapsed_bubble_v4 = 0.0;
    for(unsigned int t = 0; t < num_experiment; t++)
    {
        vector<double> v(v4);

        std::chrono::steady_clock::time_point start_time = std::chrono::steady_clock::now();
        SortLibrary::BubbleSort<double>(v);
        std::chrono::steady_clock::time_point end_time = std::chrono::steady_clock::now();
        time_elapsed_bubble_v4 += std::chrono::duration_cast<std::chrono::microseconds>(end_time - start_time).count();
		
		/*if(t == num_experiment - 1)
			cout << "Vettore ordinato con BubbleSort: " << ArrayToString(v) << endl; */
    }
    time_elapsed_bubble_v4 /= num_experiment;

    cout << "Tempo medio ordinamento di v4 (con BubbleSort): " << time_elapsed_bubble_v4 << " µs" << endl;


	//HeapSort

    double time_elapsed_heap_v1 = 0.0;
    for(unsigned int t = 0; t < num_experiment; t++)
    {
        vector<int> v(v1);

        std::chrono::steady_clock::time_point start_time = std::chrono::steady_clock::now();
        SortLibrary::HeapSort<int>(v);
        std::chrono::steady_clock::time_point end_time = std::chrono::steady_clock::now();
        time_elapsed_heap_v1 += std::chrono::duration_cast<std::chrono::microseconds>(end_time - start_time).count();
		
		/*if(t == num_experiment - 1)
			cout << "Vettore ordinato con HeapSort: " << ArrayToString(v) << endl; */
    }
    time_elapsed_heap_v1 /= num_experiment;

    cout << "Tempo medio ordinamento di v1 (con HeapSort): " << time_elapsed_heap_v1 << " µs" << endl;

    double time_elapsed_heap_v2 = 0.0;
    for(unsigned int t = 0; t < num_experiment; t++)
    {
        vector<double> v(v2);

        std::chrono::steady_clock::time_point start_time = std::chrono::steady_clock::now();
        SortLibrary::HeapSort<double>(v);
        std::chrono::steady_clock::time_point end_time = std::chrono::steady_clock::now();
        time_elapsed_heap_v2 += std::chrono::duration_cast<std::chrono::microseconds>(end_time - start_time).count();
		
		/*if(t == num_experiment - 1)
			cout << "Vettore ordinato con HeapSort: " << ArrayToString(v) << endl; */
    }
    time_elapsed_heap_v2 /= num_experiment;

    cout << "Tempo medio ordinamento di v2 (con HeapSort): " << time_elapsed_heap_v2 << " µs" << endl;


    double time_elapsed_heap_v3 = 0.0;
    for(unsigned int t = 0; t < num_experiment; t++)
    {
        vector<int> v(v3);

        std::chrono::steady_clock::time_point start_time = std::chrono::steady_clock::now();
        SortLibrary::HeapSort<int>(v);
        std::chrono::steady_clock::time_point end_time = std::chrono::steady_clock::now();
        time_elapsed_heap_v3 += std::chrono::duration_cast<std::chrono::microseconds>(end_time - start_time).count();
		
		/*if(t == num_experiment - 1)
			cout << "Vettore ordinato con HeapSort: " << ArrayToString(v) << endl; */
    }
    time_elapsed_heap_v3 /= num_experiment;

    cout << "Tempo medio ordinamento di v3 (con HeapSort): " << time_elapsed_heap_v3 << " µs" << endl;
	
	
	double time_elapsed_heap_v4 = 0.0;
    for(unsigned int t = 0; t < num_experiment; t++)
    {
        vector<double> v(v4);

        std::chrono::steady_clock::time_point start_time = std::chrono::steady_clock::now();
        SortLibrary::HeapSort<double>(v);
        std::chrono::steady_clock::time_point end_time = std::chrono::steady_clock::now();
        time_elapsed_heap_v4 += std::chrono::duration_cast<std::chrono::microseconds>(end_time - start_time).count();
		
		/*if(t == num_experiment - 1)
			cout << "Vettore ordinato con HeapSort: " << ArrayToString(v) << endl; */
    }
    time_elapsed_heap_v4 /= num_experiment;

    cout << "Tempo medio ordinamento di v4 (con HeapSort): " << time_elapsed_heap_v4 << " µs" << endl;


    return 0;
}

