#pragma once

#include <concepts> 
#include <iostream>
#include <numeric>

template<typename I> requires std::integral<I>
class razionale
{
	I num_;
	I den_;
	
	void semplificazione()
	{ 	
		// caso NaN
		if (den_==0 && num_==0) {
			return;
		}
		
		// caso +infinito, -infinito, con denominatore 0
		if (den_==0) {
			if (num_>0) {
				num_=1;
			} else {
				num_=-1;
			}
			return;
		}
		
		// rappresentiamo lo zero in un unico modo
		if (num_==0) {
			den_=1;
			return;
		}
		
		// rappresentazione unica e coerente delle frazioni
		if (den_<0) {
			num_ = -num_;
			den_ = -den_;
		}
		
		// funzioni ai minimi termini
		I mcd = std::gcd(num_,den_);  
		if (mcd > 1) { //esculo i numeri primi tra loro
			num_ /= mcd;
			den_ /= mcd;
		}
		
	}
		
public:
	//costruttore di defoult
	razionale()
		: num_(I{0}), den_(I{1})
	{}
	
	//costruttore user-defined
	razionale(const I& num, const I& den)
		: num_(num), den_(den)
	{
		semplificazione();
	}
	
	// restituisco i valori del numeratore e donominatore
	I num() const{ return num_;}
	I den() const{ return den_;}
	
	
	// implementazione canonica dell'incremento
	razionale& operator+=(const razionale& other) {
		// se uno è NaN, il risultato è NaN
		if (( den_ == 0 && num_ == 0) || (other.den_ == 0 && other.num_ == 0)) {
			num_ = 0;
			den_ = 0;
			return *this;
		}
		
		// se entrambi sono infiniti di segno opposto allora NaN
		if (den_ == 0 && other.den_ == 0 && num_ != other.num_) {
			num_ = 0;
			den_ = 0;
			return *this;
		}
		
		// il primo operando è infinito allora il risultato è inifinito
		if (den_== 0) {
			return *this;
		}
		
		// se il secondo operando è infinito, il risultato è infinito
		if (other.den_ == 0) {
			num_ = other.num_;
			den_ = other.den_;
			return *this;
		}
		
		num_ = num_ * other.den_ + other.num_ * den_;
		den_ = den_ * other.den_;
		semplificazione();
		return *this;
	}
	
	// implementazione canonica della somma
	razionale operator+(const razionale& other) const {
		razionale ret = *this;
		ret += other;
		return ret;
	}
	
	// implementazione cononica dell'incremento negativo
	razionale& operator-=(const razionale& other) {
		// se uno dei due è NaN, il risultato è NaN
		if (( den_ == 0 && num_ == 0) || (other.den_ == 0 && other.num_ == 0)) {
			num_ = 0;
			den_ = 0;
			return *this;
		}
		
		// se sono infiniti dello stesso segno, il risultato è NaN
		if (den_ == 0 && other.den_ == 0 && num_ == other.num_) {
			num_ = 0;
			den_ = 0;
			return *this;
		}
		
		// se il primo operando è infinito, il risultato resta infinito
		if (den_== 0) {
			return *this;
		}
		
		// se il secondo operando è infinito, allora il risultato è infinito di segno opposto
		if (other.den_ == 0) {
			num_ = -other.num_;
			den_ = 0;
			return *this;
		}

		num_ = num_ * other.den_ - other.num_ *den_;
		den_ = den_ * other.den_;
		semplificazione();
		return *this;
	}
	
	// implementazionde della sottrazione
	razionale operator-(const razionale& other) const {
		razionale ret = *this;
		ret -= other;
		return ret;
	}
	
	// implementazione canonica di *=
	razionale& operator*=(const razionale& other) {
		// se uno dei due operando è NaN, il risultato è NaN
		if (( den_ == 0 && num_ == 0) || (other.den_ == 0 && other.num_ == 0)) {
			num_ = 0;
			den_ = 0;
			return *this;
		}
		
		// 0*Inf = NaN
		if ((num_== 0 && den_ != 0 && other.den_ == 0) || (other.num_ == 0 && other.den_ != 0 && 				den_ == 0)) {
			num_ = 0;
			den_ = 0;
			return *this;
		}
		
		num_ *= other.num_;
		den_ *= other.den_;
		semplificazione();
		return *this;
	}
	
	// implementazione della moltiplicazione
	razionale operator*(const razionale& other) const {
		razionale ret = *this;
		ret *= other;
		return ret;
	}
	
	// implementazione canonica di /=
	razionale& operator/=(const razionale& other) {
		// se uno dei due è NaN, il risultato è NaN
		if ((den_ == 0 && num_ == 0) || (other.den_ == 0 && other.num_ == 0)) {
			num_ = 0;
			den_ = 0;
			return *this;
		}
		
		// divisione per zero finito
		if (other.num_ == 0 && other.den_ != 0) {
			// 0/0 = NaN
			if (num_ == 0 && den_ != 0) {
				num_ = 0;
				den_ = 0;
			} else {
				// numero finito/0 = Inf o -Inf
				if (num_ > 0) {
					num_ = 1;
				} else {
					num_ = -1;
				}
				den_ = 0;
			}
			return *this;
		}
		
		// Inf/Inf = NaN
		if (den_ == 0 && other.den_ == 0) {
			num_ = 0;
			den_ = 0;
			return *this;
		}
		
		// finito/Inf = 0
		if (other.den_ == 0) {
			num_ = 0;
			den_ = 1;
			return *this;
		}
		
		num_ *= other.den_; // moltiplichiamo per il reciproco
		den_ *= other.num_;
		semplificazione();
		return *this;
	}
	
	// implementazione canonica della divisione
	razionale operator/(const razionale& other) const {
		razionale ret = *this;
		ret /= other;
		return ret;
	}	
};

template<typename I> requires std::integral<I>
std::ostream&
operator<<(std::ostream& os, const razionale<I>& r)
{
	if (r.den() == 0 && r.num() == 0) {
		os << "NaN";
		return os;
	}
	
	if (r.den() == 0) {
		if (r.num() > 0) {
			os << "+Inf";
		} else {
			os << "-Inf";
		}
		return os;
	}
	
	os << r.num() << "/" << r.den();
	return os;
}