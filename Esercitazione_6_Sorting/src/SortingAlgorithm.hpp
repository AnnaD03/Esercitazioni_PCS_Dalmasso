#pragma once

#include <iostream>
#include <vector>
#include<algorithm>

using namespace std;

namespace SortLibrary {

template<typename T>
concept Sortable = requires(T& t) {
    {t < t} -> std::convertible_to<bool>;
};

//BubbleSort

template<Sortable T>
void BubbleSort(vector<T>& v)
{
    const unsigned int n = v.size();

    for(size_t i = 0; i < n - 1; i++)
    {
        for(size_t j = i + 1; j < n; j++)
        {
            if(v[j] < v[i]){
				// swap:
				const T tmp = v[i];
				v[i] = v[j];
				v[j] = tmp;
			}
        }        
    }
}

//HeapSort (implementazione utilizzando funzioni da documentazione online)

template<Sortable T>
void HeapSort(vector<T>& v)
{
    make_heap(v.begin(), v.end()); //creazione di un max-heap (albero completo con ogni nodo con valore >= ai valori dei figli) 

    for (auto i = v.end(); i != v.begin(); --i) { //(i -> heap_end)
        pop_heap(v.begin(), i); //si sposta il massimo alla fine
        //il massimo ora è a (i - 1), cioè si accorcia l'heap da ordinare
    }
}
}
