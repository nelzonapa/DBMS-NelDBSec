#ifndef SUPERFICIE_INDEX_H
#define SUPERFICIE_INDEX_H

#include <iostream>
using namespace std;

class Superficie_Index
{
protected:
    int id_superficie;
    string route_fin_superficie;
    string route_inicio_superficie;
    int capacidad_superficie;
public:
    Superficie_Index();
    ~Superficie_Index();

    //-------------get---------------------
    int get_id_superficie();
    string get_route_fin_superficie();
    string get_route_inicio_superficie();
    int get_capacidad_superficie();

    //---------------set-------------------
    void set_id_superficie(int input);
    void set_route_fin_superficie(string);
    void set_route_inicio_superficie(string);
    void set_capacidad_superficie(int input);

    //------------------others-------------
    void print_data_superficie();
};


#endif