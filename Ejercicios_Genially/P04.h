
/*
Una clase abstracta es aquella de la que no se pueden declarar instancias, dicho de otra manera no se pueden declarar objetos de una clase abstracta.
Para crear una clase abrstarcta se utiliza: virtual
*/

class Poligono
{
    int num_lados;
    public:
    void setNumLados(int n){ num_lados = n; } //metodo concreto
    virtual double calcularArea() = 0; //metodo abstracto
    virtual double calcularPerimetro() = 0; //metodo abstracto
};

class Triangulo: public Poligono
{
    public:
    double calcularArea()
    {
        //formula para calcular el area de un triangulo
    }
    
    double calcularPerimetro()
    {
        //formula para calcular el perimetro de un triangulo
    }
};

class Hexagono: public Poligono
{
    public:
    double calcularArea()
    {
        //formula para calcular el area de un hexagono
    }
    
    double calcularPerimetro()
    {
        //formula para calcular el area de un hexagono
    }
};