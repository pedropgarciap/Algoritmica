#include "miscelanea.hpp"

int MAXRANGE = 10000000;

void rellenarVector(vector<int> &v){

    for (int i = 0; i < v.size(); i++) {
        
	    v[i] = rand()%MAXRANGE;
    }
}

bool estaOrdenado(const vector<int> &v){

    for(int i = 0; i < v.size()-1; i++){

        if(v[i] > v[i+1]){

            return false;
        }
    }       

    return true;
}

bool QuickSort(int iz, int de, int n, vector<int> &v){

    int i, j, x, aux;
    i = iz; 
    j = de; 
    x = v[(iz + de)/2]; 

    do{ 
        while(v[i] < x)
        { 
            i++;
        } 
 
        while(v[j] > x)
        { 
            j--;
        } 
 
        if( i <= j )
        { 
            aux = v[i]; 
            v[i] = v[j]; 
            v[j] = aux; 
            i++;  
            j--; 
        }
         
    }while( i <= j ); 
 
    if(iz < j) 
        QuickSort(iz, j, n, v); 
    if(i < de) 
        QuickSort(i, de, n, v); 

    //return estaOrdenado(v);
    return true;
}

bool QuickSortDyV(int iz, int de, int n, vector<int> &v, int limite){

    if(n <= limite){

        insertionSort(v, iz, de);
    }

    else{

        int i, j, x, aux;
        i = iz; 
        j = de; 
        x = v[(iz + de)/2]; 

        do{ 
            while(v[i] < x)
            { 
                i++;
            } 
    
            while(v[j] > x)
            { 
                j--;
            } 
    
            if( i <= j )
            { 
                aux = v[i]; 
                v[i] = v[j]; 
                v[j] = aux; 
                i++;  
                j--; 
            }
            
        }while( i <= j ); 
    
        if(iz < j) 
            QuickSortDyV(iz, j, j-iz, v, limite); 
        if(i < de) 
            QuickSortDyV(i, de, de-i, v, limite); 
    }

    //return estaOrdenado(v);
    return true;   
}

bool OrdenarFusion(vector<int> &v){

    if(v.size() <= 1){

        insertionSort(v);
    }

    else{

        vector<int> u((v.size()/2), 0);
        vector<int> w(v.size()-(v.size()/2), 0);

        for (int i = 0; i < (v.size()/2); i++)
        {
            u[i] = v[i];
        }
        
        for (int i = (v.size()/2); i < v.size(); i++)
        {
            w[i-(v.size()/2)] = v[i];
        }

        OrdenarFusion(u);
        OrdenarFusion(w);
        fusionar(u,w,v);
    }

    //return estaOrdenado(v);
    return true;
}

bool OrdenarFusionDyV(vector<int> &v, int limite){

    if(v.size() <= limite){

        insertionSort(v);
    }

    else{

        vector<int> u((v.size()/2), 0);
        vector<int> w(v.size()-(v.size()/2), 0);

        for (int i = 0; i < (v.size()/2); i++)
        {
            u[i] = v[i];
        }
        
        for (int i = (v.size()/2); i < v.size(); i++)
        {
            w[i-(v.size()/2)] = v[i];
        }

        OrdenarFusionDyV(u, limite);
        OrdenarFusionDyV(w, limite);
        fusionar(u,w,v);
    }

    //return estaOrdenado(v);
    return true;
}

void fusionar(vector<int> &u, vector<int> &w, vector<int> &v){

    int i = 0, j = 0;
    u.push_back(INT_MAX);
    w.push_back(INT_MAX);

    for (int k = 0; k < v.size(); k++)
    {
        if(u[i] < w[j]){

            v[k] = u[i];
            i++;
        }

        else{

            v[k] = w[j];
            j++;
        }
    }
}

void insertionSort(vector<int> &v){

    int i, key, j;
    for (i = 1; i < v.size(); i++)
    {
        key = v[i];
        j = i - 1;
 
        while (j >= 0 && v[j] > key)
        {
            v[j + 1] = v[j];
            j = j - 1;
        }
        v[j + 1] = key;
    }
}

void insertionSort(vector<int> &v, int izq, int der){

    int i, key, j;
    for (i = izq; i <= der; i++)
    {
        key = v[i];
        j = i - 1;
 
        while (j >= izq && v[j] > key)
        {
            v[j + 1] = v[j];
            j = j - 1;
        }
        v[j + 1] = key;
    }
}
