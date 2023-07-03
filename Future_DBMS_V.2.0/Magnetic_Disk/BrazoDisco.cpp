#include "BrazoDisco.h"

BrazoDisco::BrazoDisco(){}

BrazoDisco::~BrazoDisco(){}


//-------------------------PARTE_CREATE--------------------------
void BrazoDisco::crear_disco(MagneticDisk &disco_magnetic){
    BrazoDisco brazo_crea_disco;

    brazo_crea_disco.write_disco_info(disco_magnetic);

    brazo_crea_disco.crear_platos(disco_magnetic);
    // brazo_crea_disco.write_platos_info();//Header de platos en mantenimiento

    brazo_crea_disco.crear_superficies(disco_magnetic);
    // brazo_crea_disco.write_superficies_info();//Header de superficies en mantenimiento

    brazo_crea_disco.crear_pistas(disco_magnetic);
    // brazo_crea_disco.write_pistas_info();//Header de pistas en mantenimiento

    brazo_crea_disco.crear_sectores(disco_magnetic);
    // brazo_crea_disco.write_sectores_info();//Header de sectores en mantenimiento

    brazo_crea_disco.crear_bloques(disco_magnetic);
    // brazo_crea_disco.write_bloques_info();//Header de platos en mantenimiento

    std::cout<<"disc-created"<<endl;
}

void BrazoDisco::crear_platos(MagneticDisk &disco_magnetic){
    int _num_platos=disco_magnetic.get_num_platos();
    int _num_superficies=disco_magnetic.get_num_superficies();
    int _capacidad_disco_total=disco_magnetic.get_capacidad_total_magneticDisk();
    for (int i = 0; i < _num_platos; i++)
    {
        Plato plato;
        //para crear el archivo bin
        string num="_"+to_string(i+1)+".bin";
        string route_plato="Magnetic_Disk/Disco/Platos/plato";
        string final_route_plato=route_plato+num;
        cout<<"Route platos: "<<final_route_plato<<endl;//Route platos: Magnetic_Disk/Disco/Platos/plato_1.bin

        //Ingresaremos datos del plato
        plato.set_id_plato(i+1);
        //para los punteros direcciones de los archivos a leer
        //id inicial de superficie
        //id final de superficie
        int n=(_num_superficies/_num_platos);
        int id_fin_superficie=(i+1)*n;
        int id_inicio_superficie=((i+1)*n)-(n-1);
        string route_reference_superficie="Magnetic_Disk/Disco/Platos/Superficies/superficie_";
        string route_fin_superficie=route_reference_superficie+to_string(id_fin_superficie)+".bin";
        string route_inicio_superficie=route_reference_superficie+to_string(id_inicio_superficie)+".bin";
        
        //los demás set del PLATO;
        plato.set_route_fin_plato(route_fin_superficie);
        plato.set_route_inicio_plato(route_inicio_superficie);
        plato.set_capacidad_plato(_capacidad_disco_total/_num_platos);

        cout<<"Abrimos, creamos y escribimos: "<<i<<endl;
        ofstream archivo(final_route_plato,ios::binary);
        if (archivo.is_open()){
            archivo.write(reinterpret_cast<const char*>(&plato), sizeof(Plato));
            cout<<"Archivo binario creado: "<<final_route_plato<<" ..."<<endl;
        }
        else{
            cout<<"Error al crear el archivo binario: "<<final_route_plato<<endl;
        }
        archivo.close();
    }
    
}

void BrazoDisco::crear_superficies(MagneticDisk &disco_magnetic){
    int _num_superficies=disco_magnetic.get_num_superficies();      //
    int _num_pistas=disco_magnetic.get_num_pistas();
    int _capacidad_disco_total=disco_magnetic.get_capacidad_total_magneticDisk();

    for (int i = 0; i < _num_superficies; i++)      //
    {
        Superficie superficie;
        //para crear el archivo bin
        string num="_"+to_string(i+1)+".bin";
        string route_superficie="Magnetic_Disk/Disco/Platos/Superficies/superficie";
        string final_route_superficie=route_superficie+num;
        cout<<"Route superficie: "<<final_route_superficie<<endl;

        //Ingresaremos datos del superficie
        superficie.set_id_superficie(i+1);
        //para los punteros direcciones de los archivos a leer
        //id inicial de pista
        //id final de pista
        int n=(_num_pistas/_num_superficies);      //
        int id_fin_pista=(i+1)*n;
        int id_inicio_pista=(i+1)*n-(n-1);
        string route_reference_pista="Magnetic_Disk/Disco/Platos/Superficies/Pistas/pista_";
        string route_fin_pista=route_reference_pista+to_string(id_fin_pista)+".bin";
        string route_inicio_pista=route_reference_pista+to_string(id_inicio_pista)+".bin";
        //los demás set de la superficie;
        superficie.set_route_fin_superficie(route_fin_pista);
        superficie.set_route_inicio_superficie(route_inicio_pista);
        superficie.set_capacidad_superficie(_capacidad_disco_total/_num_superficies);      //

        //Abrimos, creamos y escribimos
        ofstream archivo(final_route_superficie,ios::binary);
        if (archivo.is_open()){
            archivo.write(reinterpret_cast<const char*>(&superficie), sizeof(Superficie));
            cout<<"Archivo binario creado: "<<final_route_superficie<<" ..."<<endl;
        }
        else{
            cout<<"Error al crear el archivo binario: "<<final_route_superficie<<endl;
        }
        archivo.close();
    }
}

void BrazoDisco::crear_pistas(MagneticDisk &disco_magnetic){
    int _num_pistas=disco_magnetic.get_num_pistas();      //
    int _num_sectores=disco_magnetic.get_num_sectores();
    int _capacidad_disco_total=disco_magnetic.get_capacidad_total_magneticDisk();
    
    for (int i = 0; i < _num_pistas; i++)      //
    {
        Pista pista;
        //para crear el archivo bin
        string num="_"+to_string(i+1)+".bin";
        string route_pista="Magnetic_Disk/Disco/Platos/Superficies/Pistas/pista";
        string final_route_pista=route_pista+num;
        cout<<"Route platos: "<<final_route_pista<<endl;

        //Ingresaremos datos del pista
        pista.set_id_pista(i+1);
        //para los punteros direcciones de los archivos a leer
        //id inicial de sector
        //id final de sector
        int n=(_num_sectores/_num_pistas);      //
        int id_fin_sector=(i+1)*n;
        int id_inicio_sector=(i+1)*n-(n-1);
        string route_reference_sector="Magnetic_Disk/Disco/Platos/Superficies/Pistas/Sectores/sector_";
        string route_fin_sector=route_reference_sector+to_string(id_fin_sector)+".bin";
        string route_inicio_sector=route_reference_sector+to_string(id_inicio_sector)+".bin";
        //los demás set de la pista;
        pista.set_route_fin_pista(route_fin_sector);
        pista.set_route_inicio_pista(route_inicio_sector);
        pista.set_capacidad_pista(_capacidad_disco_total/_num_pistas);      //

        //Abrimos, creamos y escribimos
        ofstream archivo(final_route_pista,ios::binary);
        if (archivo.is_open()){
            archivo.write(reinterpret_cast<const char*>(&pista), sizeof(Pista));
            cout<<"Archivo binario creado: "<<final_route_pista<<" ..."<<endl;
        }
        else{
            cout<<"Error al crear el archivo binario: "<<final_route_pista<<endl;
        }
        archivo.close();
    }
}

void BrazoDisco::crear_sectores(MagneticDisk &disco_magnetic){
    int _num_sectores=disco_magnetic.get_num_sectores();      //
    int _num_bloques=disco_magnetic.get_num_bloques();
    int _capacidad_disco_total=disco_magnetic.get_capacidad_total_magneticDisk();
    
    for (int i = 0; i < _num_sectores; i++)      //
    {
        Sector sector;
        //para crear el archivo bin
        string num="_"+to_string(i+1)+".bin";
        string route_sector="Magnetic_Disk/Disco/Platos/Superficies/Pistas/Sectores/sector";
        string final_route_sector=route_sector+num;
        cout<<"Route platos: "<<final_route_sector<<endl;

        //Ingresaremos datos de sector
        sector.set_id_sector(i+1);
        //para los punteros direcciones de los archivos a leer
        //id inicial de bloque
        //id final de bloque
        int n=(_num_bloques/_num_sectores);      //
        int id_fin_bloque=(i+1)*n;
        int id_inicio_bloque=(i+1)*n-(n-1);
        string route_reference_bloque="Magnetic_Disk/Disco/Platos/Superficies/Pistas/Sectores/Bloques/bloque_";
        string route_fin_bloque=route_reference_bloque+to_string(id_fin_bloque)+".bin";
        string route_inicio_bloque=route_reference_bloque+to_string(id_inicio_bloque)+".bin";
        //los demás set de la sector;
        sector.set_route_fin_sector(route_fin_bloque);
        sector.set_route_inicio_sector(route_inicio_bloque);
        sector.set_capacidad_sector(_capacidad_disco_total/_num_sectores);      //

        //Abrimos, creamos y escribimos
        ofstream archivo(final_route_sector,ios::binary);
        if (archivo.is_open()){
            archivo.write(reinterpret_cast<const char*>(&sector), sizeof(Sector));
            cout<<"Archivo binario creado: "<<final_route_sector<<" ..."<<endl;
        }
        else{
            cout<<"Error al crear el archivo binario: "<<final_route_sector<<endl;
        }
        archivo.close();
    }
}

void BrazoDisco::crear_bloques(MagneticDisk &disco_magnetic){
    int _num_bloques=disco_magnetic.get_num_bloques();
    int _capacidad_total_disco=disco_magnetic.get_capacidad_total_magneticDisk();
    int _capacidad_por_bloque=_capacidad_total_disco/_num_bloques;
    for (int i = 0; i < _num_bloques; i++)
    {
        //Nos ubicamos:
        string num="_"+to_string(i+1)+".bin";
        string route_bloque="Magnetic_Disk/Disco/Platos/Superficies/Pistas/Sectores/Bloques/bloque";
        string final_route_bloque=route_bloque+num;
        //Abrimos,creamos
        ofstream archivo(final_route_bloque,ios::binary);
        if (archivo.is_open()){
            cout<<"Archivo binario creado: "<<final_route_bloque<<endl;
            archivo.seekp(_capacidad_por_bloque-1);
            archivo.write("", 1);
            //Para que se cree con la capacidad correcta
            //Agregamos el HEADER DEL BLOQUE
            Header_Bloque header_bloque;
            header_bloque.set_cant_bytes_bloque(_capacidad_por_bloque);
            header_bloque.set_cant_bytes_restantes_bloque(_capacidad_por_bloque-sizeof(Header_Bloque));
            header_bloque.set_cant_bytes_usados_bloque(sizeof(Header_Bloque));
            header_bloque.set_direc_end_fixed_bloque(sizeof(Header_Bloque));
            header_bloque.set_direc_free_space_variable_bloque(_capacidad_por_bloque);
            archivo.seekp(0);
            archivo.write(reinterpret_cast<const char*>(&header_bloque), sizeof(Header_Bloque));
            cout<<"Header del Bloque "<<i+1<<" insertado"<<endl;
        }
        else{
            cout<<"Error al crear el archivo binario: "<<final_route_bloque<<endl;
        }
        archivo.close();
    }
}



//-------------------------WRITE_INFO--------------------------
void BrazoDisco::write_disco_info(MagneticDisk &disco_magnetic){
    const char* route_disc="Magnetic_Disk/Disco/magnetic_disk_info.bin";

    disco_magnetic.set_route_disk_magnetic(route_disc);
    ofstream archivo(route_disc,ios::binary);
    if (archivo.is_open()){
        cout<<"Archivo binario creado: "<<route_disc<<endl;
        archivo.write(reinterpret_cast<const char*>(&disco_magnetic), sizeof(MagneticDisk));
    } 
    else{
        cout<<"Error al crear el archivo binario: "<<route_disc<<endl;
    }
    archivo.close();
}

void BrazoDisco::write_platos_info(){
}

void BrazoDisco::write_superficies_info(){

}

void BrazoDisco::write_pistas_info(){

}

void BrazoDisco::write_sectores_info(){
    
}

void BrazoDisco::write_bloques_info(){

}

//-------------------------READ_INFO--------------------------
void BrazoDisco::read_disco_info(){
    const char* route_disc="Magnetic_Disk/Disco/magnetic_disk_info.bin";
    ifstream archivo(route_disc, ios::binary);
    MagneticDisk disco_magnetico;
    if (archivo.is_open()) {
        archivo.read(reinterpret_cast<char*>(&disco_magnetico), sizeof(MagneticDisk));
        cout<<"Datos leidos del archivo: "<<route_disc<<endl;
    } else {
        cout<<"Error al abrir el archivo binario para lectura."<<endl;
    }
    disco_magnetico.print_info_magnetic_disk();
    archivo.close();
    disco_magnetico.~MagneticDisk();
}

void BrazoDisco::read_plato_info(int _num_plato){
    int ubication_read_bin=0;
    string route_plato="Magnetic_Disk/Disco/Platos/plato_"+to_string(_num_plato)+".bin";

    ifstream archivo(route_plato, ios::binary);
    archivo.seekg(ubication_read_bin);

    Plato platito;
    if (archivo.is_open()) {
        archivo.read(reinterpret_cast<char*>(&platito), sizeof(Plato));
        cout<<"Datos leidos del archivo: "<<route_plato<<endl;
    } else {
        cout<<"Error al abrir el archivo binario para lectura."<<route_plato<<endl;
    }
    platito.print_data_Plato();
    archivo.close();
    platito.~Plato();
}

void BrazoDisco::read_superficie_info(int _num_superficie){
    int ubication_read_bin=0;
    string route_superficie="Magnetic_Disk/Disco/Platos/Superficies/superficie_"+to_string(_num_superficie)+".bin";

    ifstream archivo(route_superficie, ios::binary);
    archivo.seekg(ubication_read_bin);

    Superficie superficie;
    if (archivo.is_open()) {
        archivo.read(reinterpret_cast<char*>(&superficie), sizeof(Superficie));
        cout<<"Datos leidos del archivo: "<<route_superficie<<endl;
    } else {
        cout<<"Error al abrir el archivo binario para lectura."<<route_superficie<<endl;
    }
    superficie.print_data_superficie();
    archivo.close();
    superficie.~Superficie();
}

void BrazoDisco::read_pista_info(int _num_pista){
    int ubication_read_bin=0;
    string route_pista="Magnetic_Disk/Disco/Platos/Superficies/Pistas/pista_"+to_string(_num_pista)+".bin";

    ifstream archivo(route_pista, ios::binary);
    archivo.seekg(ubication_read_bin);

    Pista pista;
    if (archivo.is_open()) {
        archivo.read(reinterpret_cast<char*>(&pista), sizeof(Pista));
        cout<<"Datos leidos del archivo: "<<route_pista<<endl;
    } else {
        cout<<"Error al abrir el archivo binario para lectura."<<route_pista<<endl;
    }
    pista.print_data_pista();
    archivo.close();
    pista.~Pista();
}

void BrazoDisco::read_sector_info(int _num_sector){
    int ubication_read_bin=0;
    string route_sector="Magnetic_Disk/Disco/Platos/Superficies/Pistas/Sectores/sector_"+to_string(_num_sector)+".bin";

    ifstream archivo(route_sector, ios::binary);
    archivo.seekg(ubication_read_bin);

    Sector sector;
    if (archivo.is_open()) {
        archivo.read(reinterpret_cast<char*>(&sector), sizeof(Sector));
        cout<<"Datos leidos del archivo: "<<route_sector<<endl;
    } else {
        cout<<"Error al abrir el archivo binario para lectura."<<route_sector<<endl;
    }
    sector.print_data_sector();
    archivo.close();
    sector.~Sector();
}

void BrazoDisco::read_bloque_info(int _num_bloque){
    // int ubication_read_bin=0;
    // string route_sector="Magnetic_Disk/Disco/Platos/Superficies/Pistas/Sectores/Bloques/bloque_"+to_string(_num_bloque)+".bin";

    // ifstream archivo(route_sector, ios::binary);
    // archivo.seekg(ubication_read_bin);

    // //Estilo de lectura, puede ser FIXED AND VARIABLE LENGTH
    // Sector sector;
    // if (archivo.is_open()) {
    //     archivo.read(reinterpret_cast<char*>(&sector), sizeof(Sector));
    //     cout<<"Datos leidos del archivo: "<<route_sector<<endl;
    // } else {
    //     cout<<"Error al abrir el archivo binario para lectura."<<route_sector<<endl;
    // }
    // sector.print_data_sector();
    // archivo.close();
    // sector.~Sector();
    cout<<"read_bloque_info() En proceso..."<<endl;
}


//-----------------------Read Others-------------------------
void BrazoDisco::read_header_bloque(int _num_bloque){
    int ubication_read_bin=0;
    string route_sector="Magnetic_Disk/Disco/Platos/Superficies/Pistas/Sectores/Bloques/bloque_"+to_string(_num_bloque)+".bin";

    ifstream archivo(route_sector, ios::binary);
    archivo.seekg(ubication_read_bin);

    //Estilo de lectura, puede ser FIXED AND VARIABLE LENGTH
    Header_Bloque header_bloque;
    if (archivo.is_open()) {
        archivo.read(reinterpret_cast<char*>(&header_bloque), sizeof(Header_Bloque));
        cout<<"Datos leidos del archivo: "<<route_sector<<endl;
    } else {
        cout<<"Error al abrir el archivo binario para lectura."<<route_sector<<endl;
    }
    header_bloque.print_info_header_bloque();
    archivo.close();
    header_bloque.~Header_Bloque();
}


//-----------------------GET---------------------------

MagneticDisk& BrazoDisco::get_disco_magnetic_info(){
    const char* route_disc="Magnetic_Disk/Disco/magnetic_disk_info.bin";
    ifstream archivo(route_disc, ios::binary);
    MagneticDisk *ptr_disco_magnetico=new MagneticDisk();
    if (archivo.is_open()) {
        archivo.read(reinterpret_cast<char*>(&(*ptr_disco_magnetico)), sizeof(MagneticDisk));
        cout<<"Datos leidos del archivo: "<<route_disc<<endl;
    } else {
        cout<<"Error al abrir el archivo binario para lectura."<<endl;
    }
    // disco_magnetico.print_info_magnetic_disk();
    archivo.close();
    return (*ptr_disco_magnetico);
}

Header_Bloque& BrazoDisco::get_header_bloque(int _num_bloque){
    int ubication_read_bin=0;
    string route_sector="Magnetic_Disk/Disco/Platos/Superficies/Pistas/Sectores/Bloques/bloque_"+to_string(_num_bloque)+".bin";

    ifstream archivo(route_sector, ios::binary);
    archivo.seekg(ubication_read_bin);

    //Estilo de lectura, puede ser FIXED AND VARIABLE LENGTH
    Header_Bloque *ptr_header_bloque=new Header_Bloque();
    if (archivo.is_open()) 
    {
        archivo.read(reinterpret_cast<char*>(&(*ptr_header_bloque)), sizeof(Header_Bloque));
        // cout<<"Datos leidos del archivo: "<<route_sector<<endl;
    } 
    else 
    {
        cout<<"Error al abrir el archivo binario para get header bloque."<<route_sector<<endl;
    }
    archivo.close();
    return (*ptr_header_bloque);
}

int BrazoDisco::get_num_bloque_espacio_libre(int _space_necesitado){
    //Para leer el header de los bloques
    Header_Bloque *ptr_header_bloque=new Header_Bloque();

    //Primero quiero saber cuántos bloques hay
    BrazoDisco brazo;
    MagneticDisk *ptr_disco_magnetico=new MagneticDisk();
    (*ptr_disco_magnetico)=brazo.get_disco_magnetic_info();
    int num_bloques=(*ptr_disco_magnetico).get_num_bloques();
    for (size_t i = 1; i <=num_bloques; i++)
    {
        (*ptr_header_bloque)=brazo.get_header_bloque(i);
        int space_libre=(*ptr_header_bloque).get_cant_bytes_restantes_bloque();
        if (_space_necesitado<space_libre)
        {
            return i;
        }
        
    }
    
    
}

int BrazoDisco::calcular_espacio_necesario(MapaPares &_map_atributos,vector<string> &_vec_atributos,vector<string> &_vec_valores_ingresar){
    
    int espacio_ocuparemos=0;
    string atributo_key;
    string valor_atributo;
    for (int i = 0; i < _vec_atributos.size(); i++)
    {
        atributo_key=_vec_atributos[i];
        valor_atributo=_vec_valores_ingresar[i];
        //Cuenta el tamaño de todos los atributos
        // cout<<valor_atributo<<" ";
        if (valor_atributo=="NULL")
        {
            continue;//no suma ese espacio, son los 1's del NULLBITMAP
        }
        else
        {
            espacio_ocuparemos=espacio_ocuparemos+(_map_atributos[atributo_key].second);
        }
        
    }
    // cout<<"espacio gaaaaaaa: "<<espacio_ocuparemos<<endl;

    int tam_vec_valores_ingresar=_vec_valores_ingresar.size();
    int tam_vec_atributos=_vec_atributos.size();
    // cout<<tam_vec_valores_ingresar<<endl;

    for (int i=tam_vec_atributos; i<tam_vec_valores_ingresar; i++)
    {
        string valor_aux=_vec_valores_ingresar[i];
        //CODE TABLA
        // cout<<valor_aux<<" ";
        if (i==tam_vec_atributos)
        {
            espacio_ocuparemos=espacio_ocuparemos+4;
        }
        //BOOL TIPO DE VARIABLE
        else if (i==tam_vec_atributos+1)
        {
            espacio_ocuparemos=espacio_ocuparemos+1;
        }
        //EL NULLBITMAP
        else if (i==tam_vec_atributos+2)
        {
            const char* nullbitmap=valor_aux.c_str();
            espacio_ocuparemos=espacio_ocuparemos+strlen(nullbitmap);
        }
        //FINALMENTE EL ID EXTRA
        else if(i==tam_vec_atributos+3)
        {
            espacio_ocuparemos=espacio_ocuparemos+4;
        }
    }
    return espacio_ocuparemos;
}

//--------------WRITE VARIABLE DATA-----------
void BrazoDisco::caminar_por_slots_tupla_variable_data_insertar_slot(Slot &slot_tupla_enviado, int num_bloque, int direc_slot_escrito){
    // BrazoDisco brazo;
    // Header_Bloque *ptr_header_bloque=new Header_Bloque();
    // (*ptr_header_bloque)=brazo.get_header_bloque(num_bloque);//obtenemos info del header del bloque

    Slot slot_ya_escrito;//slot auxiliar
    string route_bloque="Magnetic_Disk/Disco/Platos/Superficies/Pistas/Sectores/Bloques/bloque_"+to_string(num_bloque)+".bin";
    ifstream archivo(route_bloque, ios::binary);
    archivo.seekg(direc_slot_escrito);
    archivo.read(reinterpret_cast<char*>(&slot_ya_escrito), sizeof(Slot));
    if (slot_ya_escrito.get_direc_sig_slot()!=0)
    {
        caminar_por_slots_tupla_variable_data_insertar_slot(slot_tupla_enviado,num_bloque,slot_ya_escrito.get_direc_sig_slot());
    }
    else{
        BrazoDisco brazo;
        Header_Bloque *ptr_header_bloque=new Header_Bloque();
        (*ptr_header_bloque)=brazo.get_header_bloque(num_bloque);//obtenemos el header del bloque

        int direccion_slot_nuevo=(*ptr_header_bloque).get_direc_end_fixed_bloque();
        slot_ya_escrito.set_direc_sig_slot(direccion_slot_nuevo);
        slot_tupla_enviado.set_direc_sig_slot(0);
        //ahora si escribimos el slot
        archivo.close();
        ofstream archivo_new_write(route_bloque, ios::binary | ios::app);//ios app para no eliminar contenido anterior
        archivo_new_write.seekp(direccion_slot_nuevo);
        archivo_new_write.write(reinterpret_cast<const char *>(&slot_tupla_enviado), sizeof(Slot));

        int longitud_tupla_total=slot_tupla_enviado.get_size_length();
        //-------------ACTUALIZAMOS HEADER_BLOQUE -----------
        (*ptr_header_bloque).set_cant_bytes_restantes_bloque((*ptr_header_bloque).get_cant_bytes_restantes_bloque()-(longitud_tupla_total+sizeof(Slot)));
        (*ptr_header_bloque).set_cant_bytes_usados_bloque((*ptr_header_bloque).get_cant_bytes_usados_bloque()+(longitud_tupla_total+sizeof(Slot)));
        (*ptr_header_bloque).set_direc_end_fixed_bloque((*ptr_header_bloque).get_direc_end_fixed_bloque()+(sizeof(Slot)));
        (*ptr_header_bloque).set_direc_free_space_variable_bloque((*ptr_header_bloque).get_direc_free_space_variable_bloque()-longitud_tupla_total);
        (*ptr_header_bloque).set_num_general_records_bloque((*ptr_header_bloque).get_num_general_records_bloque()+1);
        (*ptr_header_bloque).set_num_records_variable_bloque((*ptr_header_bloque).get_num_records_variable_bloque()+1);
        
        archivo_new_write.close();
    }

    
}

void BrazoDisco::insert_variable_length_data(MapaPares &_map_atributos,vector<string> &_vec_atributos,vector<string> &_vec_valores_ingresar){
    BrazoDisco brazo;
    Header_Bloque *ptr_header_bloque=new Header_Bloque();
    int espacio_ocuparemos=brazo.calcular_espacio_necesario(_map_atributos,_vec_atributos,_vec_valores_ingresar);
    //AHORA
    // cout<<"obtenemos el bloque con espacio libre"<<endl;
    cout<<"espacio a ocupar: "<<espacio_ocuparemos<<endl;
    int num_bloque_space=brazo.get_num_bloque_espacio_libre(espacio_ocuparemos);
    cout<<"bloque donde se escribira: "<<num_bloque_space<<endl;

    //YA TENEMOS EL HEADER DEL BLOQUE
    (*ptr_header_bloque)=brazo.get_header_bloque(num_bloque_space);

    /*
    Cómo ya sabemos a qué bloque ingresar, procedemos a ingresar el dato en ese bloque:
    */
    string route_bloque="Magnetic_Disk/Disco/Platos/Superficies/Pistas/Sectores/Bloques/bloque_"+to_string(num_bloque_space)+".bin";

    //Abriremos el archivo:
    ofstream archivo(route_bloque, ios::binary | ios::app);//ios app para no eliminar contenido anterior
    //ahora verificamos si se abrió:
    if (archivo.is_open()) 
    {   
        /*----------- Comenzamos ESCRITURA -----------*/
        //
        int tam_vec_valores_ingresar=_vec_valores_ingresar.size();
        int tam_vec_atributos=_vec_atributos.size();
        int cant_slots_atributo=tam_vec_atributos;
        vector<Slot> vec_slots_para_ingresar;
        //escribiremos los datos y su slot:
        Slot slot_atributo;
        Slot slot_tupla;

        string atributo_key;
        string valor_atributo;

        //Ahora debemos ubicarnos donde nos indique el HEADER_DEL_BLOQUE:
        int ubication_write_bin=(*ptr_header_bloque).get_direc_free_space_variable_bloque();
        int longitud_tupla_total=0;

        //-------------LOS ATRIBUTOS -----------
        for (int i=(tam_vec_atributos-1); i>=0; i--)
        {
            atributo_key=_vec_atributos[i];
            valor_atributo=_vec_valores_ingresar[i];
            int size_atributo=(_map_atributos[atributo_key].second);
            string tipo_data_atributo=(_map_atributos[atributo_key].first);

            // retrocede la cantidad que debe para escribir data
            ubication_write_bin = ubication_write_bin - size_atributo;
            archivo.seekp(ubication_write_bin);


            // Para escribir debemos detectar el tipo de dato
            if (valor_atributo=="NULL")
            {
                continue;   //no ingresa el que no tiene dato
                //pero se tiene que ingresar el slot? NO, porque no tiene nada
                // slot_atributo.set_offset(ubication_write_bin);
                // slot_atributo.set_size_length();
                // vec_slots_para_ingresar.push_back();
            }
            else if (tipo_data_atributo == "int")
            {
                int number = stoi(valor_atributo);
                archivo.write(reinterpret_cast<const char *>(&number), size_atributo);
                longitud_tupla_total=longitud_tupla_total+size_atributo;

                //Ahora guardamos su Slot:
                slot_atributo.set_offset(ubication_write_bin);
                slot_atributo.set_size_length(size_atributo);
                vec_slots_para_ingresar.push_back(slot_atributo);


            }
            else if (tipo_data_atributo == "float")
            {
                float decimal = stof(valor_atributo);
                archivo.write(reinterpret_cast<const char *>(&decimal), size_atributo);
                longitud_tupla_total=longitud_tupla_total+size_atributo;

                //Ahora guardamos su Slot:
                slot_atributo.set_offset(ubication_write_bin);
                slot_atributo.set_size_length(size_atributo);
                vec_slots_para_ingresar.push_back(slot_atributo);
            }
            else if (tipo_data_atributo == "bool")
            {
                bool booleano = (valor_atributo == "true");
                archivo.write(reinterpret_cast<const char *>(&booleano), size_atributo);
                longitud_tupla_total=longitud_tupla_total+size_atributo;

                //Ahora guardamos su Slot:
                slot_atributo.set_offset(ubication_write_bin);
                slot_atributo.set_size_length(size_atributo);
                vec_slots_para_ingresar.push_back(slot_atributo);
            }
            else if (tipo_data_atributo == "string")
            {
                const char *atributo_string = valor_atributo.c_str();
                archivo.write(atributo_string, size_atributo);
                longitud_tupla_total=longitud_tupla_total+size_atributo;

                //Ahora guardamos su Slot:
                slot_atributo.set_offset(ubication_write_bin);
                slot_atributo.set_size_length(size_atributo);
                vec_slots_para_ingresar.push_back(slot_atributo);
            }
        }

        int num_slots=vec_slots_para_ingresar.size();

        //-------------AHORA ingresamos los SLOTS_ATRIBUTO -----------
        for (int i=(num_slots-1); i>=0; i--)
        {
            ubication_write_bin=ubication_write_bin-sizeof(Slot);
            archivo.seekp(ubication_write_bin);
            Slot *ptr_slot_vec=&vec_slots_para_ingresar[i];

            //escribe el slot
            archivo.write(reinterpret_cast<const char *>(&(*ptr_slot_vec)), sizeof(Slot));
            longitud_tupla_total=longitud_tupla_total+sizeof(Slot);

        }

        //-------------AHORA el NULLBITMAP -----------
        //el nullbitmap esta guardado al final del vector de valores:
        const char* nullbitmap=_vec_valores_ingresar[tam_vec_valores_ingresar-1].c_str();
        //ahora ingresamos el nullbitmap
        ubication_write_bin=ubication_write_bin-strlen(nullbitmap);
        archivo.seekp(ubication_write_bin);
        archivo.write(nullbitmap, strlen(nullbitmap));

        longitud_tupla_total=longitud_tupla_total+strlen(nullbitmap);

        //-------------AHORA EL SLOT_TUPLA -----------
        //dirección de donde comienza
        slot_tupla.set_offset(ubication_write_bin);
        //Damos la longitud total de la tupla
        slot_tupla.set_size_length(longitud_tupla_total);
        //Ahora vemos la dirección que guarda del siguiente SLOT_TUPLA:
        //Caso en el que puede llegar a ser el primer registro de tipo variable:
        if ((*ptr_header_bloque).get_num_records_variable_bloque()==0)
        {
            //ESCRIBIMOS EL SLOT_TUPLA
            ubication_write_bin= (*ptr_header_bloque).get_direc_end_fixed_bloque();
            (*ptr_header_bloque).set_direc_primer_record_variable_length(ubication_write_bin);//en si el primer slot
            slot_atributo.set_direc_sig_slot(0);

            //escribimos el primer slot
            archivo.seekp(ubication_write_bin);
            archivo.write(reinterpret_cast<const char *>(&slot_tupla), sizeof(Slot));
            
            //-------------ACTUALIZAR HEADER_BLOQUE -----------
            (*ptr_header_bloque).set_cant_bytes_restantes_bloque((*ptr_header_bloque).get_cant_bytes_restantes_bloque()-(longitud_tupla_total+sizeof(Slot)));
            (*ptr_header_bloque).set_cant_bytes_usados_bloque((*ptr_header_bloque).get_cant_bytes_usados_bloque()+(longitud_tupla_total+sizeof(Slot)));
            (*ptr_header_bloque).set_direc_end_fixed_bloque((*ptr_header_bloque).get_direc_end_fixed_bloque()+(sizeof(Slot)));
            (*ptr_header_bloque).set_direc_free_space_variable_bloque((*ptr_header_bloque).get_direc_free_space_variable_bloque()-longitud_tupla_total);
            (*ptr_header_bloque).set_num_general_records_bloque((*ptr_header_bloque).get_num_general_records_bloque()+1);
            (*ptr_header_bloque).set_num_records_variable_bloque((*ptr_header_bloque).get_num_records_variable_bloque()+1);
        }
        else    //caso de no ser el primer variable data
        {
            //En este caso el slot tupla que queremos ingresar es el H2
            BrazoDisco brazo;
            Header_Bloque *ptr_header_bloque=new Header_Bloque();
            (*ptr_header_bloque)=brazo.get_header_bloque(num_bloque_space);//obtenemos el header del bloque
            int direc_primer_record_variable_length=ptr_header_bloque->get_direc_primer_record_variable_length();

            caminar_por_slots_tupla_variable_data_insertar_slot(slot_tupla,num_bloque_space,direc_primer_record_variable_length);
        }
        
    } 
    else 
    {
        cout<<"Error al abrir el archivo binario para get header bloque en insert variable length: "<<route_bloque<<endl;
    }
    archivo.close();
    
}

//----------------------READ VARIABLE DATA-----------------

void caminar_por_slots_tupla_variable_data_imprimir(int num_bloque,int direc_slot_escrito){
    Slot slot_ya_escrito;//slot auxiliar
    string route_bloque="Magnetic_Disk/Disco/Platos/Superficies/Pistas/Sectores/Bloques/bloque_"+to_string(num_bloque)+".bin";
    ifstream archivo(route_bloque, ios::binary);
    archivo.seekg(direc_slot_escrito);
    archivo.read(reinterpret_cast<char*>(&slot_ya_escrito), sizeof(Slot));
    if (slot_ya_escrito.get_direc_sig_slot()!=0)
    {
        slot_ya_escrito.print_data_slot();
        cout<<endl;
        caminar_por_slots_tupla_variable_data_imprimir(num_bloque,slot_ya_escrito.get_direc_sig_slot());
    }
    else{
        cout<<"Ya no se tienen mas registros"<<endl;
    }
}

void BrazoDisco::read_variable_length_data_per_block(int num_block){
    BrazoDisco brazo;
    Header_Bloque *ptr_header_bloque=new Header_Bloque();
    (*ptr_header_bloque)=brazo.get_header_bloque(num_block);

    int direccion_primer_slot=(*ptr_header_bloque).get_direc_primer_record_variable_length();
    caminar_por_slots_tupla_variable_data_imprimir(num_block,direccion_primer_slot);
}

void BrazoDisco::read_variable_length_data(int _id_record){
    // int ubication_read;
    // BrazoDisco brazo;
    // Header_Bloque *ptr_header_bloque=new Header_Bloque();

}

//----------------------WRITE FIXED DATA---------------------

void BrazoDisco::insert_fixed_length_data(MapaPares &_map_atributos,vector<string> &_vec_atributos,vector<string> &_vec_valores_ingresar){
    BrazoDisco brazo;
    Header_Bloque *ptr_header_bloque=new Header_Bloque();
    //primero necesitamos saber cuánto espacio ocuparemos
    int espacio_ocuparemos;
    //obtenemos el bloque con espacio libre
    int num_bloque_space=brazo.get_num_bloque_espacio_libre(espacio_ocuparemos);
    (*ptr_header_bloque)=brazo.get_header_bloque(num_bloque_space);//necesitamos algun bloque
}

//----------------------READ FIXED DATA-----------------






