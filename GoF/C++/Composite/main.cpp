// La clase Equipo define una interfaz para todos los equipos de la jerarquía de parte-todo.

#include <bits/stdc++.h>

using namespace std;

class Equipo {
public:
	const string nombre() {
		return _nombre;
	}
	virtual Vatio potencia();
	virtual Moneda precioNeto();
	virtual Moneda precioConDescuento();

	virtual void anadir(Equipo*);
	virtual void eliminar(Equipo*);
	virtual Iterador<Equipo*>* crearIterador();

	virtual ~Equipo();
protected:
	Equipo(const string);
private:
	const string _nombre;
};

// Las subclases de Equipo podrían incluir clases Hoja que representen unidades de disco, circuitos integrados e interruptores:
class Diquetera : public Equipo {
public:
	Disquetera(const string);

	virtual Vatio potencia();
	virtual Moneda precioNeto();
	virtual Moneda precioConDescuento();

	virtual ~Disquetera();
};


// EquipoCompuesto es la clase base de los equipos que contienen otros equipos. Es también una sub-clase de Equipo.
class EquipoCompuesto : public Equipo {
public:
	virtual Vatio potencia();
	virtual Moneda precioNeto();
	virtual Moneda precioConDescuento();
	virtual void anadir(Equipo*);
	virtual void eliminar(Equipo*);
	virtual Iterador<Equipo*>* crearIterador();
	virtual ~EquipoCompuesto();
protected:
	EquipoCompuesto(const string);
private:
	list<Equipo*> _equipo;
};


// Ahora podemos representar un chasis de computadora como una subclase de EquipoCompuesto llamada Chasis. Chasis hereda las operaciones relativas a los hijos de EquipoCompuesto.

class Chasis : public EquipoCompuesto {
public:
	Chasis(const char*);

	virtual Vatio potencia();
	virtual Moneda precioNeto();
	virtual Moneda precioConDescuento();

	virtual ~Chasis();
};


// Podemos definir otros contenedores de equipos tales como Armario y Bus de forma similar. Eso nos da todo lo necesario para ensamblar componentes en una computadora personal (bastante sencillo):

Armario* armario = new Armario("Armario de PC");
Chasis* chasis = new Chasis("Chasis de PC");
armario->Anadir(chasis);
Bus* bus = new Bus("Bus MCA");
bus->Anadir(new Tarjeta("Token Ring de 16 Mbs"));
chasis->Anadir(bus);
chasis->Anadir(new Disquetera("Disquetera de 3,5 pulgadas"));
cout << "El precio neto es " << chasis->precioNeto() << endl;