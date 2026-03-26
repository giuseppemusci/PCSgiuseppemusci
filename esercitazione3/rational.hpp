#pragma once
#include <concepts>
#include <iostream>
#include <cmath>
using namespace std;


template<typename I> requires std::integral<I>
class rational
{
	I num_;
	I den_;
	bool Inf; //variabili booleane per gestire il caso
	bool NaN; // Inf e NaN
public:
    /* Costruttore di default */
    rational()
        : num_(I{0}), den_(I{1}), Inf(bool{false}), NaN(bool{false}) {}
    
    /* Costruttore user-defined */
    rational(const I& pnum, const I& pden)
        : num_(pnum), den_(pden), Inf(bool{false}), NaN(bool{false})  {
		if (den_< 0){
			num_ *= -1;
			den_ *= -1;}
		if (den_ == 0) {
            if (num_ == 0) { NaN = true; }
            else { Inf = true; }
		}
		simplify();	
	}
	
	I num()const{
		if (NaN) {cerr<<"{NaN}";}   //non l'ho fatto per Inf perchè si può usare per vedere il segno
		return num_;}
	I den()const{                 //ho voluto aggiungere un avviso quando nel codice si attiva den() o num()
		if (Inf){cerr<<"{Inf}";}  // su NaN o Inf perchè sarebbe meglio prendere tutto il rational
		else if (NaN){cerr<<"{NaN}";} // per comprendere con cosa si sta lavorando
			return den_;}
	bool isInf() const { return Inf; } //per poterli vedere in operator<<
    bool isNaN() const { return NaN; }
	
	/* Implementazione canonica dell'incremento */
	rational& operator+=(const rational& other) {
		if (NaN || other.NaN){NaN=true;}
		else if (Inf){
			if (other.Inf && num_*other.num_<0){
				Inf = false;
				NaN = true;}
		else if (other.Inf){
			*this = other;}
		}
		else{
			num_ *= other.den_;
			num_ += other.num_*den_;
			den_ *= other.den_;}
		simplify();
        return *this;
    }
	/* Implementazione canonica della somma */
	rational operator+(const rational& other) const {
        rational ret = *this;
        ret += other;
        return ret;
    }
	/* Implementazione canonica del decremento */
	rational& operator-=(const rational& other) {
		if (NaN || other.NaN){NaN=true;}
		else if (Inf){
			if (other.Inf && num_*other.num_>0){
				Inf = false;
				NaN = true;}
		else if (other.Inf){
			*this = rational(-1,0)*other;}
		}
		else{
			num_ *= other.den_;
			num_ -= other.num_*den_;
			den_ *= other.den_;
		}
		simplify();
        return *this;
    }
	/* Implementazione canonica della differenza */
	rational operator-(const rational& other) const {
        rational ret = *this;
        ret -= other;
        return ret;
    }
	/* Implementazione canonica di *= */
    rational& operator*=(const rational& other) {
		if (NaN || other.NaN){NaN=true;}
		else if (Inf || other.Inf){
				Inf = true;
				num_ *= other.num_;
				if (num_ == 0){
					Inf = false;
					NaN = true;}
		}
		else{
			num_ *= other.num_;
			den_ *= other.den_;
		}
		simplify();
        return *this;
    }
	/* Implementazione canonica del prodotto */
    rational operator*(const rational& other) const {
        rational ret = *this;
        ret *= other;
        return ret;
    }
	/* Implementazione canonica di /= */
    rational& operator/=(const rational& other) {
		if (NaN || other.NaN){NaN=true;}
		else if (Inf){
			if (other.Inf){
				Inf = false;
				NaN = true;}
			else {
			num_*= other.num_;}
		}
		else if (other.Inf){
			num_ = 0;}
		else{
			num_ *= other.den_;
			den_ *= other.num_;
		}
		simplify();
        return *this;
    }
	/* Implementazione canonica della divisione */
    rational operator/(const rational& other) const {
        rational ret = *this;
        ret /= other;
        return ret;
    }
	
	void simplify(){
		if (not Inf && not NaN){ // per 
			I a = abs(num_);
			I b = abs(den_);
			while (b!=0){
				I resto = a%b;
				a = b;
				b = resto;
			}
			num_ /= a;
			den_ /= a;
			if (num_==0){den_=1;} // 0 standard
		}
		else if (Inf){
			num_ /= abs(num_);
			den_ = 0;}
		else if (NaN){
			num_ = 0;          //risolve anche i casi Inf,NaN
			den_ = 0;}
		return;
	}	
};

template<typename I>
std::ostream&
operator<<(std::ostream& os, const rational<I>& r){
	if (r.isInf()){
		if (r.num()<0){os << "rational -Inf";}
		else {os << "rational Inf";}
	}
	else if (r.isNaN()) {
		os << "rational NaN";
	}
	else if (r.den() == 1) {os << r.num();} //numeri interi
	else{
		os << r.num() << "/" << r.den();
	}
    return os;
}
