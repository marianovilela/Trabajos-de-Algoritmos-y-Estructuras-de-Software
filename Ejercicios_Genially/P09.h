/*
la encapsulación es un método para cambiar la forma en que otras cosas interactúan con algo.
*/
private decimal _velocidadActual { get; set; }
public decimal VelocidadActual 
{
    get{
        return _velocidadActual + 2;
    }
    set{
        _velocidadActual = value;
    }
}
/*
La principal diferencia es que abstracción es un medio para representar cosas más simplemente,nos interesa 
saber qué nos ofrece un objeto, pero no cómo lo lleva a cabo.
*/

class Account {
public:
   Account( double d );   // Constructor.
   virtual double GetBalance();   // obtener balance.
   virtual void PrintBalance() = 0;   // Función virtual pura.
private:
    double _balance;
};
