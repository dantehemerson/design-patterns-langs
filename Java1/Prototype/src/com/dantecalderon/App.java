package com.dantecalderon;

import com.dantecalderon.model.CuentaAHImpl;

public class App {
	
	public static void main(String[] args) {
		
		CuentaAHImpl cuentaAhorro = new CuentaAHImpl();
		
		cuentaAhorro.setMonto(200);
		
		CuentaAHImpl cuentaClonada = (CuentaAHImpl) cuentaAhorro.clonar();
		
		if(cuentaClonada != null) {
			System.out.println(cuentaClonada);
		}
		
		// Compara referencia en memoria
		System.out.println(cuentaClonada == cuentaAhorro);
	}

}
