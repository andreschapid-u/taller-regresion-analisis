#include<iostream>
#include "rls.h"
#include "rls_potencia.h"
#include "rls_exponencial.h"

using std::cout;
using std::endl;
using std::vector;

void caso_1();
void caso_2();
void caso_3();
void caso_4();
void imprimir_tabla_datos(vector<double>, vector<double>);
void imprimir_rls(regresion);
void imprimir_potencia(regresion_potencia);
void imprimir_exponencial(regresion_exponencial);

int main (int argc, char *argv[]) {
	
	caso_1();
	caso_2();
	caso_3();
	caso_4();
	return 0;
}

void caso_1(){
	vector<double> x {1.0, 2.0, 3.0, 4.0, 5.0, 6.0, 7.0, 8.0, 9.0};
	vector<double> y {1.0, 1.5, 2.0, 3.0, 4.0, 5.0, 8.0, 10.0, 13.0};
	
	rls rl;
	regresion resultado_rls = rl.calcular(x,y);
	
	rls_potencia rls_pot;
	regresion_potencia resultado_pot = rls_pot.calcular(x, y);
	
	rls_exponencial rls_exp;
	regresion_exponencial resultado_exp = rls_exp.calcular(x, y);
	
	cout << "\tCASO 1" << endl;
	imprimir_tabla_datos(x, y);
	imprimir_rls(resultado_rls);
	imprimir_potencia(resultado_pot);
	imprimir_exponencial(resultado_exp);
	
	system("pause");
	system("cls");
}

void caso_2(){
	vector<double> x {1.0, 2.0, 3.0, 4.0, 5.0};
	vector<double> y {0.5, 0.7, 3.4, 5.7, 8.4};
		
	rls rl;
	regresion resultado_rls = rl.calcular(x,y);
	
	rls_potencia rls_pot;
	regresion_potencia resultado_pot = rls_pot.calcular(x, y);
	
	rls_exponencial rls_exp;
	regresion_exponencial resultado_exp = rls_exp.calcular(x, y);
	
	cout << "\tCASO 2" << endl;
	imprimir_tabla_datos(x, y);
	imprimir_rls(resultado_rls);
	imprimir_potencia(resultado_pot);
	imprimir_exponencial(resultado_exp);
	
	system("pause");
	system("cls");
}	

void caso_3(){
	vector<double> x {0.4, 0.8, 1.2, 1.6, 2, 2.3};
	vector<double> y {750, 1000, 1400, 2000, 2700, 3750};
	
	rls rl;
	regresion resultado_rls = rl.calcular(x,y);
	
	rls_potencia rls_pot;
	regresion_potencia resultado_pot = rls_pot.calcular(x, y);
	
	rls_exponencial rls_exp;
	regresion_exponencial resultado_exp = rls_exp.calcular(x, y);
	
	cout << "\tCASO 3" << endl;
	imprimir_tabla_datos(x, y);
	imprimir_rls(resultado_rls);
	imprimir_potencia(resultado_pot);
	imprimir_exponencial(resultado_exp);
	
	system("pause");
	system("cls");
}

void caso_4(){
	vector<double> x {0.25, 0.75, 1.25, 1.5, 2};
	vector<double> y {-0.45, -0.6, 0.7, 1.88, 6};
	
	rls rl;
	regresion resultado_rls = rl.calcular(x,y);
	
	rls_potencia rls_pot;
	regresion_potencia resultado_pot = rls_pot.calcular(x, y);
	
	rls_exponencial rls_exp;
	regresion_exponencial resultado_exp = rls_exp.calcular(x, y);
	
	cout << "\tCASO 4" << endl;
	imprimir_tabla_datos(x, y);
	imprimir_rls(resultado_rls);
	imprimir_potencia(resultado_pot);
	imprimir_exponencial(resultado_exp);
	
	//system("pause");
	//system("cls");
}
void imprimir_rls(regresion resultado){
	cout << "Regredion lineal simple" << endl;
	cout << "Y = " << resultado.b1 << "X + " << resultado.b0 << endl;
	cout << "Dev. Estandar Sy =  " << resultado.sy << endl;
	cout << "Err. Estandar Aprox. Sy/x =  " << resultado.syx << endl;
	cout << "Coef. de determinacion r2 =  " << resultado.r2 << endl << endl;
}

void imprimir_potencia(regresion_potencia r_p){
	cout << "Potencial" << endl;
	cout << "Y = "<<r_p.c<<" * X^("<<r_p.a<<")\n";
	cout << "Dev. Estandar Sy =  " << r_p.sy << endl;
	cout << "Err. Estandar Aprox. Sy/x =  " << r_p.syx << endl;
	cout << "Coef. de determinacion r2 =  " << r_p.r2 << endl << endl;
	
}
void imprimir_exponencial(regresion_exponencial r_e){
	cout << "Exponencial" << endl;
	cout << "Y = "<< r_e.c << " * e^(" << r_e.a << "X)\n";
	cout << "Dev. Estandar Sy =  " << r_e.sy << endl;
	cout << "Err. Estandar Aprox. Sy/x =  " << r_e.syx << endl;
	cout << "Coef. de determinacion r2 =  " << r_e.r2 << endl << endl;
}
	
void imprimir_tabla_datos(vector<double> x, vector<double> y){
	cout << "x\t\ty" << endl;
	for(int i =0; i < x.size(); i++){
		cout << x[i] << "\t\t" << y[i] << endl;
	}
	cout << endl;
}


