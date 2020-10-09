#ifndef RLS_H
#define RLS_H
#include <vector>
#include <cmath>
//regresion_lineal_simple
// Y = b1X + b0
using std::vector;

struct regresion{
	double b0;
	double b1;
	double sy;
	
	double syx;
	double r2;
};

class rls{
public:
	//void recta(double &b1, double &b0){
	regresion calcular( vector<double> x, 
				    vector<double> y){
		
		regresion resultado;
		int i;
		int n = x.size();
		double sx = 0.0;
		double sxy = 0.0;
		double sx2 = 0.0;
		double sy = 0.0;
		
		for (i = 0; i < n; i++){
			sx += x[i];
			sxy += x[i] * y[i];
			sx2 += x[i] * x[i];
			sy += y[i];
		}
		
		double xprom = sx / (double)n;
		double yprom = sy / (double)n;
		
		resultado.b1 = (sxy - (yprom*sx))/( sx2 - (xprom*sx));
		resultado.b0 = yprom - (resultado.b1*xprom);
		
		double st = 0.0;
		double sr = 0.0;
		for(i = 0; i < n; i++){
			st  += pow( y[i] - yprom, 2);
			sr += pow( y[i] - ((resultado.b1 * x[i]) +resultado.b0), 2);
		}
		
		resultado.sy = sqrt(st/(double)(n - 1));
		resultado.syx = sqrt(sr/(double)(n - 2));
		
		resultado.r2 = (st - sr)/st;
		
		return resultado;
	}
};
#endif
