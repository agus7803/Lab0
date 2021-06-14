#ifndef DTFECHAHORA_HPP
#define DTFECHAHORA_HPP


class dtFechaHora{
    private:
    int dia,mes,anio,hora,minuto;
    public:
    //Constructores
    dtFechaHora();
    dtFechaHora(int dia,int mes,int anio,int hora,int minuto);
    //Getters
    int getdia();
    int getmes();
    int getanio();
    int gethora();
    int getminuto();
    //Destructor
    ~dtFechaHora();

};
#endif

