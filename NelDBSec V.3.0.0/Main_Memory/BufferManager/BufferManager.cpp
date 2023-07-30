#include "BufferManager.h"

BufferManager::BufferManager(int input){
    set_num_frames(input);
    BufferPool *ptr_buffer_pool=new BufferPool(input);
    TablaMetadata *ptr_tabla_metadata=new TablaMetadata(input);
    Pagina *ptr_pagina_retornar=new Pagina();
}

BufferManager::~BufferManager(){}


void BufferManager::set_num_frames(int input){
    this->num_frames=input;
}


void BufferManager::apuntar_buffPool(){
    BufferPool buffPool(this->num_frames);
    (*this->ptr_buffer_pool)=buffPool;
}

void BufferManager::apuntar_tablaMetadata(){
    TablaMetadata tablaMetadata(this->num_frames);
    (*this->ptr_tabla_metadata)=tablaMetadata;
}

void BufferManager::apuntar_diskManager(){
    DiskManager diskManager;
    (*this->ptr_diskManager)=diskManager;
}

void BufferManager::agregarPagina_BuffPool_tablaMetadata(int id_pag){
    // (*this->ptr_tabla_metadata).
    bool tabla_vacia=(*this->ptr_tabla_metadata).tabla_vacia();
    if (tabla_vacia==false)
    {
        Pagina *ptr_pagina_aux=new Pagina();
        (*ptr_pagina_aux).insert_aux_dataPagina();
        // (*ptr_pagina_aux).print_info_pagina();
        (this->ptr_pagina_retornar)=ptr_pagina_aux;
        //digamos que ya se recibió esta pagina del DISK MANAGER
        (*this->ptr_tabla_metadata).agregar_pagina_tabla_metadata(id_pag);
        cout<<"____________-"<<endl;
        // (*this->ptr_tabla_metadata).imprimir_toda_tabla_metadata();
        //Ahora agregamos al buffer pool:
        (*this->ptr_buffer_pool).agregar_pagina((*ptr_pagina_aux),(*this->ptr_pagina_retornar).get_id_pagina());
    }
    else
    {
        bool existe_pagina=(*this->ptr_tabla_metadata).comprobar_existe_pagina(id_pag);
        if (existe_pagina == true)
        {
            cout<<"BuffManager: Su pagina ya existe en memoria"<<endl;
        }
        else
        {
            cout<<"BuffManager: Su pagina NO existe en memoria, solicitando al Disk Manager..."<<endl;
            // this->ptr_diskManager.
            Pagina pagina_aux;
            pagina_aux.insert_aux_dataPagina();
            (*this->ptr_pagina_retornar)=pagina_aux;
            //digamos que ya se recibió esta pagina del DISK MANAGER
            (this->ptr_tabla_metadata)->agregar_pagina_tabla_metadata((*this->ptr_pagina_retornar).get_id_pagina());

            //Ahora agregamos al buffer pool:
            (this->ptr_buffer_pool)->agregar_pagina((*this->ptr_pagina_retornar),(*this->ptr_pagina_retornar).get_id_pagina());
        }
    }
    
}

Pagina& BufferManager::get_pagina_retornar(){
    return (*this->ptr_pagina_retornar);
}

void BufferManager::mostrar_tabla_metadata(){
    this->ptr_tabla_metadata->imprimir_toda_tabla_metadata();
}










/*-----------------------------------LRU----------------------------------*/

// void BufferManager::inicializar_buffer_pool(vector<Pagina> &_Buffer_pool_vect){
//     for (int i = 0; i < _Buffer_pool_vect.size(); ++i) {
//         _Buffer_pool_vect[i].page_id = -1;
//         _Buffer_pool_vect[i].dirty_bit = false;
//         _Buffer_pool_vect[i].pin_count = 0;
//         _Buffer_pool_vect[i].last_used = 0;
//         _Buffer_pool_vect[i].ptr_bloque=nullptr;
//     }
// }

// int BufferManager::encontrar_page_Buffer_Pool(vector<Pagina> _Buffer_pool_vect,int page_id){
//     for (int i = 0; i < _Buffer_pool_vect.size(); ++i) {
//         if (_Buffer_pool_vect[i].page_id == page_id) {
//             return i;
//         }
//     }
//     return -1;
// }

// int encontrar_pagina_last_used(vector<Pagina> &_Buffer_pool_vect) {
//     int pagina_last_used = 0;//para detectar la última página usada
//     for (int i = 0; i < _Buffer_pool_vect.size(); ++i) {
//         //comparamos los valores de last_used
//         if (_Buffer_pool_vect[i].last_used < _Buffer_pool_vect[pagina_last_used].last_used) {
//             pagina_last_used = i;
//         }
//     }
//     return pagina_last_used;
// }

// void reemplazar_pagina_buffer_pool(vector<Pagina> &_Buffer_pool_vect, int page_id, int pagina_last_used, int new_last_used) {
//     _Buffer_pool_vect[pagina_last_used].page_id = page_id;
//     _Buffer_pool_vect[pagina_last_used].dirty_bit = false;
//     _Buffer_pool_vect[pagina_last_used].pin_count = 0;
//     _Buffer_pool_vect[pagina_last_used].last_used = new_last_used;
// }

// void BufferManager::LRU(vector<Pagina> &_Buffer_pool_vect,int page_id){
//     // int page_id;//numero o id del bloque/pagina enviado
//     int index=encontrar_page_Buffer_Pool(_Buffer_pool_vect,page_id);
//     if (index != -1) 
//     {
//         _Buffer_pool_vect[index].last_used=(_Buffer_pool_vect[index].last_used)+1;
//         //lo que se aumenta en uso: (_Buffer_pool_vect[index].last_used)+1

//     }
//     else 
//     {
//         int pagina_last_used = encontrar_pagina_last_used(_Buffer_pool_vect);
//         reemplazar_pagina_buffer_pool(_Buffer_pool_vect, page_id, pagina_last_used, (_Buffer_pool_vect[pagina_last_used].last_used)+1);
//     }

//     //PARTE DE IMPRIMIR ESTADO
//     cout<<"Estado del buffer pool despues de acceder a la pagina "<<page_id<<":"<<endl;
//     for (int j = 0; j < _Buffer_pool_vect.size(); ++j) {
//         cout<<"Frame ID: " <<j<< ", Page ID: "<<_Buffer_pool_vect[j].page_id<<", Dirty Bit: "<<_Buffer_pool_vect[j].dirty_bit
//                  <<", Pin Count: "<<_Buffer_pool_vect[j].pin_count<<", Last Used: "<<_Buffer_pool_vect[j].last_used<<endl;
//     }
//     cout<<endl;
//     return;
// }

// /*-----------------------------------END----------------------------------*/

// vector<Pagina>& BufferManager::get_buffer_pool(){
//     vector<Pagina> *ptr_buffer_pool=new vector<Pagina>();
//     // (*ptr_buffer_pool)=this->Buffer_pool_vect;
//     return (*ptr_buffer_pool);
// }
