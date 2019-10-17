#include <iostream>
#include <iomanip>
#include <chrono>
#include <ctime>
#include <math.h>

using namespace std::chrono ;


double d_d (int y0, int m0, int d0, int h0, int mi0, int s0, int y, int m, int d, int h, int mi, int s) // day difference
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

int main()
	{

	int y, y0 ;
	int m, m0 ;
	int d, d0 ;
	int h, h0, mi ;
	int H, M ;
	double D, s, S ;

//	std::cout << "Year 0: " ;
//	std::cin >> y0 ;

//	std::cout << "Month 0: " ;
//	std::cin >> m0 ;

//	std::cout << "day 0: " ;
//	std::cin >> d0 ;

//	std::cout << "hour 0: " ;
//	std::cin >> h0 ;

	std::cout << "Year: " ;	
	std::cin >> y ;

	std::cout << "Month: " ;
	std::cin >> m ;

	std::cout << "day: " ;
	std::cin >> d ;

	std::cout << "hour: " ;
        std::cin >> h ;

	std::cout << "minute: " ;
	std::cin >> mi ;

	std::cout << "second: " ;
	std::cin >> s ;

	high_resolution_clock::time_point t1 = high_resolution_clock::now() ;

	D = GMST(y, m, d, h, mi, s) ;
	H = int(D) ;
	M = int( (D - H) * 60) ;
	S = ( (D - H) * 60 - M ) * 60 ;

	std::cout << std::fixed ;
	std::cout << std::setprecision(15) ;
	std::cout << H << ":" << M << ":" << S << "\n" ;

	high_resolution_clock::time_point t2 = high_resolution_clock::now() ;

	auto duration = duration_cast<microseconds>(t2 - t1).count() ;

	std::cout << "\nczas: " << duration << " μs\n" ;  

	return 0 ;
	}
