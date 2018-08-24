/**
	- Composite -
	SEGURIDAD. Se puede acceder a los elementos compuestos
	a travéz de la función obtenerCompuesto, en caso de no ser compuesto
	retornará null(No se sobreescribe la función).
**/
#include <bits/stdc++.h>

using namespace std;

class Compuesto;
class Componente {
public:
	//...
	virtual Compuesto* obtenerCompuesto() {
		return nullptr;
	}
};

class Compuesto : public Componente {
public:
	void anadir(Componente* c) {}

	//...

	// Retorna el objeto compuesto
	virtual Compuesto* obtenerCompuesto() {
		return this;
	}
};

class Hoja : public Componente {
	// ...
};

int main() {

	Compuesto* unCompuesto = new Compuesto;
	Hoja* unaHoja = new Hoja;

	Componente* unComponente;
	Compuesto* prueba;

	unComponente = unCompuesto;
	if(prueba = unComponente->obtenerCompuesto()) {
		prueba->anadir(new Hoja);
		cout << "Se añadió Hoja a unCompuesto." << endl;
	} else {
		cout << "unCompuesto NO ES COMPUESTO. No se añadió Hoja a unCompuesto." << endl;
	}

	unComponente = unaHoja;
	if(prueba = unComponente->obtenerCompuesto()) {
		// No añadirá ya que unHoja no es un elemento compuesto.
		prueba->anadir(new Hoja);
		cout << "Se añadió Hoja a unaHoja." << endl;
	} else {
		cout << "unaHoja NO ES COMPUESTO. No se añadió Hoja a unaHoja." << endl;
	}

	return 0;
}
