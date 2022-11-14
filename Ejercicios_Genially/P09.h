/*
la encapsulaci�n es un m�todo para cambiar la forma en que otras cosas interact�an con algo.
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
La principal�diferencia�es que�abstracci�n�es un medio para representar cosas m�s simplemente,nos interesa 
saber qu� nos ofrece un objeto, pero no c�mo lo lleva a cabo.
*/

class Account {
public:
   Account( double d );   // Constructor.
   virtual double GetBalance();   // obtener balance.
   virtual void PrintBalance() = 0;   // Funci�n virtual pura.
private:
    double _balance;
};
