#ifndef DESCUENTO_H
#define DESCUENTO_H


class Descuento{
    private:
        int dni_cliente;
        bool estado;
        float porcentaje;
        float monto_descuento;
    public:
        //gets
        int get_DNI(){return dni_cliente;}
        bool get_Estado(){return estado;}
        float get_Porcentaje(){return porcentaje;}
        float get_Monto_Descuento(){return monto_descuento;}
        //sets
        void set_DNI(int d){dni_cliente=d;}
        void set_Estado(bool e){estado=e;}
        void set_Porcentaje(float p){porcentaje=p;}
        void set_Monto_Descuento(float m){monto_descuento=m;}
        void mostrar();
        bool leer(int);
        bool escribir();
        bool sobre_escribir(int);
        //backup
        bool backup_escribir();
        //constructor
      //  Descuento(bool,float,float);



};

#endif // DESCUENTO_H
