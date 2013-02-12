#include <iostream>

using namespace std;

class BankAcct {

  private:  // member data
		int _acctNum;
		double _balance;

	public:  // member functions
		BankAcct ( int aNum ) {
			_acctNum = aNum;
			_balance = 0;
		}  // constructor 1

		BankAcct ( int aNum, double amt ) {
			_acctNum = aNum;
			_balance = amt;
		}  // constructor 2

		BankAcct () {
			_acctNum = _balance = 2;
		}  // default constructor

		bool withdraw ( double amount )
		{   
			if (amount < 0 || _balance < amount)
				return false; 
			_balance -= amount;
			return true;            
		}

		bool deposit ( double amount ) {
			if (amount < 0)
				return false;
			_balance += amount;
			return true;
		}

		double getBalance() { return _balance; }
};

void transfer (BankAcct& fromAcct, BankAcct& toAcct, double amt)
{
	fromAcct.withdraw( amt );
	toAcct.deposit( amt );
}

int main( )
{
	BankAcct ba1(1357);  // create an account
	ba1.deposit(1000);
	ba1.withdraw(500.25);

	cout << "Balance: " << ba1.getBalance() << endl;


	// -----------
	BankAcct ba2(5493, 300);

	transfer(ba2, ba1, 200.00);
	cout << "Balance: " << ba1.getBalance() << endl;

	return 0;
}
