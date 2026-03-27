#include <iostream>
#include "razionale.hpp"

int main(void)
{
	// 0 al denominatore
	razionale<int> inf_positivo(4,0);
	std::cout<<"4/0 = " << inf_positivo << "\n";
	razionale<int> inf_negativo(-4,0);
	std::cout<<"(-4)/0 = " << inf_negativo << "\n";
	razionale<int> NaN(0,0);
	std::cout<<"0/0 = " << NaN << "\n";
	
	// semplificazione
	razionale<int> r(4,12);
	std::cout<< "Il numero 4/12 si semplifica in " << r << "\n";
	
	// 0 al numeratore e un numero qualsiasi al denominatore
	razionale<int> zero(0,3);
	std::cout<< "0/3: " << zero << "\n";
	
	// un numero qualsiasi al numeratore e 1 al denominatore
	razionale<int> c(24,1);
	std::cout<<"24/1: " << c << "\n";
	
	// operazioni aritmetiche
	razionale<int> a(5,2);
	razionale<int> b(6,7);
	razionale<int> neg(-3,7);
	razionale<int> neg2(3,-7);
	
	std::cout << "5/2: " << a << "\n";
	std::cout << "-(3/7): " << neg << "\n";
	std::cout << "-(3/7): " << neg2 << "\n";
	
	// operazioni tra i due numeri
	std::cout << a << " + " << b << " = " << a + b << "\n"; 
	std::cout << a << " - " << b << " = " << a - b << "\n"; 
	std::cout << a << " * " << b << " = " << a * b << "\n"; 
	std::cout << a << " / " << b << " = " << a / b << "\n"; 
	
	// operazioni con lo 0
	std::cout << a << " / 0 = " << a / zero << "\n";
	std::cout << " 0 / " << a << " = " << zero / a << "\n";
	
	// operazioni tra un numero qualsiasi a numeratore e denominatore uguale a 0
	// inf positivo
	std::cout << a << " + Inf = " << a + inf_positivo << "\n";
	std::cout << a << " - Inf = " << a - inf_positivo << "\n";
	std::cout << a << " * Inf = " << a * inf_positivo << "\n";
	std::cout << a << " / Inf = " << a / inf_positivo << "\n";
	std::cout << "Inf - " << a << " = " << inf_positivo - a << "\n";
	std::cout << "Inf / " << a << " = " << inf_positivo / a << "\n";
	// inf negativo
	std::cout << a << " + (-Inf) = " << a + inf_negativo << "\n";
	std::cout << a << " - (-Inf) = " << a - inf_negativo << "\n";
	std::cout << a << " * (-Inf) = " << a * inf_negativo << "\n";
	std::cout << a << " / (-Inf) = " << a / inf_negativo << "\n";
	std::cout << "-Inf - " << a << " = " << inf_negativo - a << "\n";
	std::cout << "-Inf / " << a << " = " << inf_negativo / a << "\n";
	// NaN
	std::cout << a << " + NaN = " << a + NaN << "\n";
	std::cout << a << " - NaN = " << a - NaN << "\n";
	std::cout << a << " * NaN = " << a * NaN << "\n";
	std::cout << a << " / NaN = " << a / NaN << "\n";
	std::cout << "NaN - " << a << " = " << NaN - a << "\n";
	std::cout << "NaN / " << a << " = " << NaN / a << "\n";
	
	// operazioni tra inf e NaN
	// inf_positivo
	std::cout <<"Inf + NaN = " << inf_positivo + NaN << "\n";
	std::cout <<"Inf - NaN = " << inf_positivo - NaN << "\n";
	std::cout <<"Inf * NaN = " << inf_positivo * NaN << "\n";
	std::cout <<"Inf / NaN = " << inf_positivo / NaN << "\n";
	std::cout <<"NaN - Inf = " << NaN - inf_positivo << "\n";
	std::cout <<"NaN / Inf = " << NaN / inf_positivo << "\n";
	// inf_negativo
	std::cout <<"-Inf + NaN = " << inf_negativo + NaN << "\n";
	std::cout <<"-Inf - NaN = " << inf_negativo - NaN << "\n";
	std::cout <<"-Inf * NaN = " << inf_negativo * NaN << "\n";
	std::cout <<"-Inf / NaN = " << inf_negativo / NaN << "\n";
	std::cout <<"NaN - (-Inf) = " << NaN - inf_negativo << "\n";
	std::cout <<"NaN / (-Inf) = " << NaN / inf_negativo << "\n";
	
	// operazioni tra Inf e Inf
	// entrambi inf_positivo
	std::cout <<"Inf + Inf = " << inf_positivo + inf_positivo << "\n";
	std::cout <<"Inf - Inf = " << inf_positivo - inf_positivo << "\n";
	std::cout <<"Inf * Inf = " << inf_positivo * inf_positivo << "\n";
	std::cout <<"Inf / Inf = " << inf_positivo / inf_positivo << "\n";
	// entrambi inf_negativo
	std::cout <<"(-Inf) + (-Inf) = " << inf_negativo + inf_negativo << "\n";
	std::cout <<"(-Inf) - (-Inf) = " << inf_negativo - inf_negativo << "\n";
	std::cout <<"(-Inf) * (-Inf) = " << inf_negativo * inf_negativo << "\n";
	std::cout <<"(-Inf) / (-Inf) = " << inf_negativo / inf_negativo << "\n";
	// inf_positivo e inf_negativo
	std::cout <<"Inf + (-Inf) = " << inf_positivo + inf_negativo << "\n";
	std::cout <<"Inf - (-Inf) = " << inf_positivo - inf_negativo << "\n";
	std::cout <<"Inf * (-Inf) = " << inf_positivo * inf_negativo << "\n";
	std::cout <<"Inf / (-Inf) = " << inf_positivo / inf_negativo << "\n";
	std::cout <<"-Inf - Inf = " << inf_negativo - inf_positivo << "\n";
	std::cout <<"-Inf / Inf = " << inf_negativo / inf_positivo << "\n";
	
	// operazioni tra NaN e NaN
	std::cout <<"NaN + NaN = " << NaN + NaN << "\n";
	std::cout <<"NaN - NaN = " << NaN - NaN << "\n";
	std::cout <<"NaN * NaN = " << NaN * NaN << "\n";
	std::cout <<"NaN / NaN = " << NaN / NaN << "\n";
	
	// operazioni tra Inf/NaN e 0
	std::cout << "Inf * 0 = " << inf_positivo * zero << "\n";
	std::cout << "Inf / 0 = " << inf_positivo / zero << "\n";
	std::cout << "0 / Inf = " << zero / inf_positivo << "\n";
	std::cout << "-Inf * 0 = " << inf_negativo * zero << "\n";
	std::cout << "-Inf / 0 = " << inf_negativo / zero << "\n";
	std::cout << "0 / (-Inf) = " << zero / inf_negativo << "\n";
	std::cout << "NaN * 0 = " << NaN * zero << "\n";
	std::cout << "NaN / 0 = " << NaN / zero << "\n";
	std::cout << "0 / NaN = " << zero / NaN << "\n";
	
	// operazioni di assegnamento
	// due numeri
	razionale<int> t1(5,2);
	std::cout << " a += b : " << (t1 += b) << "\n";
	razionale<int> t2(5,2);
	std::cout << " a -= b : " << (t2 -= b) << "\n";
	razionale<int> t3(5,2);
	std::cout << " a *= b : " << (t3 *= b) << "\n";
	razionale<int> t4(5,2);
	std::cout << " a /= b : " << (t4 /= b) << "\n";
	// numero e 0
	razionale<int> t5(5,2);
	std::cout << " a += 0 : " << (t5 += zero) << "\n";
	razionale<int> t6(5,2);
	std::cout << " a -= 0 : " << (t6 -= zero) << "\n";
	razionale<int> t7(5,2);
	std::cout << " a *= 0 : " << (t7 *= zero) << "\n";
	razionale<int> t8(5,2);
	std::cout << " a /= 0 : " << (t8 /= zero) << "\n";
	// numero e inf_positivo
	razionale<int> t9(5,2);
	std::cout << " a += Inf : " << (t9 += inf_positivo) << "\n" ;
	razionale<int> t10(5,2);
	std::cout << " a -= Inf : " << (t10 -= inf_positivo) << "\n";
	razionale<int> t11(5,2);
	std::cout << " a *= Inf : " << (t11 *= inf_positivo) << "\n";
	razionale<int> t12(5,2);
	std::cout << " a /= Inf : " << (t12 /= inf_positivo) << "\n";
	// numero e NaN
	razionale<int> t13(5,2);
	std::cout << " a += NaN : " << (t13 += NaN) << "\n";
	razionale<int> t14(5,2);
	std::cout << " a -= NaN : " << (t14 -= NaN) << "\n";
	razionale<int> t15(5,2);
	std::cout << " a *= NaN : " << (t15 *= NaN) << "\n";
	razionale<int> t16(5,2);
	std::cout << " a /= NaN : " << (t16 /= NaN) << "\n";
	
	return 0;
} 