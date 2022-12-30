/* *************************************************
 *	Brian Moye && Georgia Dabbs
 *
*/

#include <iostream>;

using namespace std;

class Money
{
	private:
		int dollars;
		int cents;
	
	public:
		Money();
		Money(int dol);
		Money(int dol, int cen);
		
		void setDollars(int dol);
		void setCents(int cen);
		
		int getDollars()const;
		int getCents()const;
		
		void input();
		void output()const;
		
		friend Money operator+ (const Money& left, const Money& right);
		friend Money operator- (const Money& left, const Money& right);

		friend ostream& operator<< (ostream& os, const Money& right);
		friend istream& operator>> (istream is, Money& right);
		
		//Relational
};


// Constructors
Money::Money()
{
	dollars = 0;
	cents = 0;
}

Money::Money(int dol)
{
	dollars = dol;
	cents = 0;
}

Money::Money(int dol, int cen)
{
	dollars = dol;
	cents = cen;
}

// Methods
void Money::setDollars(int dol)
{
	dollars = dol;
}

void Money::setCents(int cen)
{
	cents = cen;
}

int Money::getDollars()const
{
	return dollars;
}

int Money::getCents()const
{
	return cents;
}

ostream& operator<< (ostream& os, const Money& right)
{
	cout << "$" << right.dollars << "." << right.cents;
}

istream& operator>> (istream is, Money& right)
{
	
}

void Money::input()
{
	char decimal;
	cin >> dollars;
	cin >> decimal;
	cin >> cents;
}

void Money::output()const
{
	if (cents < 10)
	{
		cout << dollars << ".0" << cents;
	}
	else 
	{
		cout << dollars << "." << cents;
	}
}

Money operator+ (const Money& left, const Money& right)
{
	Money temp;
	temp.cents = left.cents + right.cents
	if(temp.cents >= 100)
	{
		temp.cents = temp.cents % 100;
		temp.dollars += temp.cents / 100;
	}
	temp.dollars += left.dollars + right.dollars;
}

Money operator- (const Money& left, const Money& right)
{
	
}

int main() 
{
	

	return 0;
}