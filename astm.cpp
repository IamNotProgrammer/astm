#include "astm.h"
#include <ctime>
#include <math.h>

double d_d(int y0, int m0, int d0, int h0, int mi0, int s0, int y, int m, int d, int h, int mi, int s)
	{

	struct std::tm a = { s0, mi0, h0, d0, m0 - 1, y0 - 1900 } ;

	struct std::tm b = { s, mi, h, d, m - 1, y - 1900 } ;

	std::time_t x = std::mktime(&a);

	std::time_t z = std::mktime(&b);

	long double difference = std::difftime(z, x) * 0.000011574074074074073 ;

	return difference ;

	}

double GMST(int y, int m, int d, int h, int mi, int s)
	{

	double D, T, gmst ;

	D = d_d(2000, 1, 1, 12, 0, 0, y, m, d, h, mi, s) ;

	T = D / 36525 ;	

	gmst = fmod( ( 24110.54841 + 8640184.812866 * T + 0.093104 * pow(T, 2) - 0.0000062 * pow(T, 3) ) * 0.0002777777777,  24.0 ) ;

	return gmst ;

	}

