#include <iostream>
#include <string>

using namespace std;


class Calkowita{

    friend ostream &operator<<(ostream &wyjscie, const Calkowita &c);
    friend istream &operator>>(istream &wejscie, Calkowita &c);
    friend bool operator==(const Calkowita &c, const Calkowita &d);
	friend bool operator!=(const Calkowita &c, const Calkowita &d);
	friend bool operator<(const Calkowita &c, const Calkowita &d);
	friend bool operator>(const Calkowita &c, const Calkowita &d);
	friend bool operator<=(const Calkowita &c, const Calkowita &d);
	friend bool operator<=(const Calkowita &c, const Calkowita &d);
	friend Calkowita &operator-(Calkowita &c);

public:
    string wartosc;
    bool minus;
    Calkowita()
    {
        wartosc = "0";
        minus = false;
    }
    Calkowita(string liczba);
    Calkowita(long liczba);
    long to_long();
};

Calkowita::Calkowita(string liczba){
    minus = liczba[0] == '-';
    if(minus == true)
    {
			wartosc = liczba.substr(1);
			if(wartosc == "0") minus = false;
    }
    else
    {
			wartosc = liczba;
    }
}

Calkowita::Calkowita(long liczba){
    if (liczba>=0)
        {
            wartosc=liczba;
            minus=false;
        }
        else
        {
            long konwersja = -liczba;
            wartosc = to_string(konwersja);
            minus = true;
        }
}

long Calkowita::to_long()
{
    long przekonwertowana = stol(wartosc);
    if(minus == true)
    {
        przekonwertowana = -przekonwertowana;
    }
    return przekonwertowana;
}

ostream& operator<<(ostream& wyjscie, const Calkowita &c)
{
    if(c.minus == true) wyjscie <<"-"<< c.wartosc;
    else wyjscie<<c.wartosc;
    return wyjscie;
}

istream& operator>>(istream& wejscie, Calkowita &c)
{
    string temp;
    wejscie >> temp;
    c = Calkowita(temp);
    return wejscie;
}

bool operator==(const Calkowita &c, const Calkowita &d)
{
    if(c.minus == d.minus) return c.wartosc == d.wartosc;
	else return false;
}

bool operator!=(const Calkowita &c, const Calkowita &d)
{
    if(c == d) return false;
    else return true;
}

bool operator<(const Calkowita &c, const Calkowita &d)
{
    if(c.minus == true && d.minus == false) return true;
    if(c.minus == false && d.minus == true) return false;
    if(c.wartosc.compare(d.wartosc) < 0 && (c.minus == true && d.minus == true)) return false;
    if(c.wartosc.compare(d.wartosc) > 0 && (c.minus == true && d.minus == true)) return true;
    if(c.minus == false && d.minus == false) return c.wartosc.compare(d.wartosc);
    return false;
}

bool operator>(const Calkowita &c, const Calkowita &d)
{
    if(c<d) return false;
    if(c==d) return false;
    return true;
}

bool operator<=(const Calkowita &c, const Calkowita &d)
{
    if(c == d) return true;
    return (c<d);
}

bool operator>=(const Calkowita &c, const Calkowita &d)
{
    if(c == d) return true;
    return (c>d);
}

Calkowita &operator-(Calkowita &c)
{
    if(c.wartosc.compare("0") == 0)
    {
        c.minus = false;
        return c;
    }
    if(c.minus)
    {
        c.minus = false;
        return c;
    }
    else
    {
        c.minus = true;
        return c;
    }
}

int main()
{
    Calkowita a,b;
    cin >> a;
    cin >> b;
    cout << (a == b) << endl;
    cout << (a != b)<< endl;
    cout << (a < b) << endl;
    cout << (a > b) << endl;
    cout << (a <= b) << endl;
    cout << (a >= b) << endl;
    cout << -a << endl;
    return 0;
}
