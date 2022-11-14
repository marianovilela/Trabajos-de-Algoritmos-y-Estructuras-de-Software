
class Ejem 
{
public:
    int x;
protected:
    int y;
private:
    int z;
};

class Clase_Publico : public Ejem
{
    // x: es publico
    // y: es protegido
    // z: no tiene acceso desde Clase_Publico
};
/*
las herencias públicas son las herencias en la que todos los miembros 
públicos y protegidos de la clase base conservan esos mismos niveles de acceso 
respectivamente en las clases derivadas como en el Clase_Publico.
*/

class Clase_Protegido : protected Ejem
{
    // x: es protegido
    // y: es protegido
    // z: no tiene acceso desde Clase_Protegido
};
/*
las herencias protegidas son las herencias en la que todos los miembros 
públicos de la clase base adquieren el nivel de acceso protegido en las clases 
derivadas, mientras que los miembros protegidos conservan su nivel de acceso. 
*/