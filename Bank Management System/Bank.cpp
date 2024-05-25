//L232531
//L232519
//L232618





#include<iostream>
#include<string>
#include<cstring>
#include<fstream>
#include <sstream>
using namespace std;



string intToString(int money) {
	stringstream ss;
	ss << money;
	return ss.str();
}

int calculateSize(string num)
{
	int digits = 0;
	for (int i = 0; num[i] != '\0'; i++)
	{
		digits++;
	}
	return digits;
}

bool OnlyDigits(string num)
{
	for (int i = 0; num[i] != '\0'; i++)
	{
		if (!(num[i] >= 48 && num[i] <= 57))
		{
			return false;
		}

	}
	return true;
}

bool HasEightDigits(int n)
{
	int count = 0;
	while (n != 0)
	{
		n = n / 10;
		count++;
	}
	if (count == 8)
	{
		return true;
	}
	else
		return false;
}

int stringToInt(const std::string& str) {
	return std::stoi(str);
}


class UserDetails
{
private:
	string AccountHolderName;
	string MobileNumber;
	string CNIC;
public:


	UserDetails()
	{
		AccountHolderName = "";
		MobileNumber = "";
		CNIC = "";
	}

	string getUserAccountHolderName()
	{
		return AccountHolderName;
	}

	string getUserMobileNumber()
	{
		return MobileNumber;
	}

	string getUserCNIC()
	{
		return CNIC;
	}

	void setUserAccountHolderName(string AN)
	{
		AccountHolderName = AN;
	}

	void setUserMobileNumber(string N)
	{
		MobileNumber = N;
	}

	void setUserCNIC(string C)
	{
		CNIC = C;

	}


};


class Account
{
private:
	UserDetails User;
	string pin;
	string UserName;
	string Password;
	int AccountNumber;
	double AccountBalance;
	string AccountStatus;
	string* TransactionHistory;
	int Tsize;
	string AccountType;

public:
	Account()
	{
		pin = "";
		UserName = "";
		Password = "";
		AccountNumber = 0;
		AccountBalance = 0;
		AccountStatus = "";
		TransactionHistory = nullptr;
		Tsize = 0;
		AccountType;
	}


	string getPin()
	{
		return pin;
	}

	void setPin(string c)
	{
		pin = c;
	}


	string getUserName()
	{
		return UserName;
	}

	string getPassword()
	{

		return Password;
	}

	int getAccountNumber()
	{
		return AccountNumber;
	}

	double getAccountBalance()
	{
		return AccountBalance;
	}

	string getAccountStatus()
	{
		return AccountStatus;
	}



	void setUserName(string u)
	{
		UserName = u;
	}

	void setPassword(string p)
	{
		Password = p;
	}

	void setAccountNumber(int AN)
	{
		AccountNumber = AN;
	}

	void setAccountBalance(double AB)
	{
		AccountBalance = AB;
	}

	void setAccountStatus(string AS)
	{
		AccountStatus = AS;
	}

	void setTransactionHistory(string* s)
	{
		TransactionHistory = s;

	}

	string* getTransactionHistory()
	{
		return TransactionHistory;
	}

	void incTsize()
	{
		Tsize++;
	}

	int getTsize()
	{
		return Tsize;
	}


	string getAccountHolderName()
	{
		return User.getUserAccountHolderName();
	}

	string getMobileNumber()
	{
		return User.getUserMobileNumber();
	}

	string getCNIC()
	{
		return User.getUserCNIC();
	}

	void setAccountHolderName(string AN)
	{
		User.setUserAccountHolderName(AN);
	}

	void setMobileNumber(string N)
	{
		User.setUserMobileNumber(N);

	}

	void setCNIC(string C)
	{
		User.setUserCNIC(C);
	}

	void setAccountType(string T)
	{
		AccountType = T;
	}

	string getAccountType()
	{
		return AccountType;
	}

	void displayTransactionHistory()
	{
		for (int i = 0; i < Tsize; i++)
		{

			cout << "\t\t\t\t\t\t ";
			cout << TransactionHistory[i] << endl << endl;
		}
	}


	virtual void DepositMoney()
	{

	}

	virtual void TaxDeduction()
	{

	}

	virtual void WithdrawMoney()
	{

	}


	virtual void TransactionHist(double money, int fun, string* TransactionHistory)
	{

	}

};



class SavingsAccount : public Account
{
public:



	void TransactionHist(double money, int fun, string* TransactionHistory) override
	{

		incTsize();
		string* temp1 = getTransactionHistory();

		string* temp = new string[getTsize()];
		if (getTsize() != 1)
		{
			for (int i = 0; i < getTsize() - 1; i++)
			{

				temp[i] = temp1[i];

			}
		}
		string mon;

		if (fun == 1)
		{
			mon = intToString(money);
			temp[getTsize() - 1] = "Deposited money was " + mon;

			//deposit
		}
		else if (fun == 2)
		{
			mon = intToString(money);
			temp[getTsize() - 1] = "Withdrawn money was " + mon;
			//withdraw
		}
		else if (fun == 3)
		{
			mon = intToString(money);
			temp[getTsize() - 1] = "Sent money was " + mon;
			//send
		}

		setTransactionHistory(temp);

	}

	void DepositMoney() override
	{



		string m = "";
		double AccountBalance = 0;
		if (getAccountBalance() == 0)
		{


			while (true)
			{
				cout << "\t \t \t        Deposit Amount \t \t \t  : ";
				cin >> m;

				if (!OnlyDigits(m))
				{
					cout << "\t\t\t\t\t\t\t\t\t             Invalid Amount" << endl;
					continue;
				}
				else
				{

					AccountBalance = stod(m);
					if (AccountBalance < 500)
					{
						if (getAccountBalance() == 0)
						{
							cout << "\t\t\t\t\t\t\t\t\t                You can't deposit less than 500$ " << endl;
							continue;
						}
					}
					else
					{
						break;
					}
				}
			}
		}
		else
		{
			while (true)
			{
				cout << "\t \t \t        Deposit Amount \t \t    : ";
				cin >> m;

				if (!OnlyDigits(m))
				{
					cout << "\t\t\t\t\t\t\t\t\t             Invalid Amount" << endl;
					continue;
				}
				else
				{
					AccountBalance = stod(m);
					break;
				}
			}
		}

		TransactionHist(AccountBalance, 1, getTransactionHistory());

		AccountBalance += getAccountBalance();
		setAccountBalance(AccountBalance);
		cout << endl;
	}


	void WithdrawMoney() override
	{
		double AccountBalance = 0;
		cout << "\t \t \t\t  Current Balance : " << getAccountBalance() << endl << endl;

		while (true)
		{
			cout << "\t \t \t\t  Enter amount you want to withdraw : ";
			cin >> AccountBalance;
			if (AccountBalance <= 0)
			{
				cout << "\t\t\t\t\t\t        Invalid Amount " << endl;
				continue;
			}

			if (AccountBalance > getAccountBalance())
			{
				cout << "\t\t\t\t\t\t        Insufficient balance " << endl;
				continue;
			}

			break;
		}
		string p;

		cout << endl;

		int MultipleAttempts = 0;
		int flag = 0;
		while (true)
		{
			cout << "\t \t \t\t  Enter your Pin                    : ";


			cin >> p;
			MultipleAttempts++;

			if (MultipleAttempts == 4)
			{
				cout << "\n\n\n";
				cout << "\t\t\t      ======================================================" << endl;
				cout << "\t\t\t            Withdrawl failed due to multiple attempts!         " << endl;
				cout << "\t\t\t             Please contact your bank for assistance.        " << endl;
				cout << "\t\t\t      ======================================================" << endl;
				flag = 1;
				break;
			}

			if (p != getPin())
			{
				cout << "\t\t\t\t\t\t        Incorrect Pin " << endl;
				cout << "" << endl;
				continue;
			}
			break;
		}
		if (flag == 0)
		{
			double newAccountBalance = 0;
			TransactionHist(AccountBalance, 2, getTransactionHistory());
			newAccountBalance = getAccountBalance() - AccountBalance;
			cout << "\t\t\t\t\t\t    ** Withdrawl Successful **" << endl;
			setAccountBalance(newAccountBalance);
		}
		/*else
		{
			return getAccountBalance();
		}*/
	}



};

class CurrentAccount : public Account
{
public:

	void TransactionHist(double money, int fun, string* TransactionHistory) override
	{

		incTsize();
		string* temp1 = getTransactionHistory();

		string* temp = new string[getTsize()];
		if (getTsize() != 1)
		{
			for (int i = 0; i < getTsize() - 1; i++)
			{

				temp[i] = temp1[i];

			}
		}
		string mon;

		if (fun == 1)
		{
			mon = intToString(money);
			temp[getTsize() - 1] = "Deposited money was " + mon;

			//deposit
		}
		else if (fun == 2)
		{
			mon = intToString(money);
			temp[getTsize() - 1] = "Withdrawn money was " + mon;
			//withdraw
		}
		else if (fun == 3)
		{
			mon = intToString(money);
			temp[getTsize() - 1] = "Sent money was " + mon;
			//send
		}

		setTransactionHistory(temp);

	}

	void DepositMoney() override
	{
		string m = "";
		double AccountBalance = 0;
		if (getAccountBalance() == 0)
		{


			while (true)
			{
				cout << "\t \t \t        Deposit Amount \t \t \t  : ";
				cin >> m;

				if (!OnlyDigits(m))
				{
					cout << "\t\t\t\t\t\t\t\t\t            Invalid Amount" << endl;
					continue;
				}
				else
				{

					AccountBalance = stod(m);
					if (AccountBalance < 1000)
					{
						if (getAccountBalance() == 0)
						{
							cout << "\t\t\t\t\t\t\t\t\t            You can't deposit less than 1000$ " << endl;
							continue;
						}
					}
					else
					{
						break;
					}
				}
			}
		}
		else
		{
			while (true)
			{
				cout << "\t \t \t        Deposit Amount \t \t  : ";
				cin >> m;

				if (!OnlyDigits(m))
				{
					cout << "\t\t\t\t\t\t\t\t\t            Invalid Amount" << endl;
					continue;
				}
				else
				{
					AccountBalance = stod(m);
					break;
				}
			}
		}

		TransactionHist(AccountBalance, 1, getTransactionHistory());

		AccountBalance += getAccountBalance();
		setAccountBalance(AccountBalance);
		cout << endl;
	}

	void WithdrawMoney() override
	{
		double AccountBalance = 0;
		cout << "\t \t \t\t  Current Balance : " << getAccountBalance() << endl << endl;

		while (true)
		{
			cout << "\t \t \t\t  Enter amount you want to withdraw : ";
			cin >> AccountBalance;
			if (AccountBalance <= 0)
			{
				cout << "\t\t\t\t\t\t        Invalid Amount " << endl;
				continue;
			}

			if (AccountBalance > getAccountBalance())
			{
				cout << "\t\t\t\t\t\t        Insufficient balance " << endl;
				continue;
			}

			break;
		}
		string p;

		cout << endl;

		int MultipleAttempts = 0;
		int flag = 0;
		while (true)
		{
			cout << "\t \t \t\t  Enter your Pin                    : ";
			cin >> p;
			MultipleAttempts++;

			if (MultipleAttempts == 4)
			{
				cout << "\n\n\n";
				cout << "\t\t\t      ======================================================" << endl;
				cout << "\t\t\t            Withdrawl failed due to multiple attempts!         " << endl;
				cout << "\t\t\t             Please contact your bank for assistance.        " << endl;
				cout << "\t\t\t      ======================================================" << endl;
				flag = 1;
				break;
			}

			if (p != getPin())
			{
				cout << "\t\t\t\t\t\t        Incorrect Pin " << endl;
				cout << "" << endl;
				continue;
			}
			break;
		}
		if (flag == 0)
		{
			double newAccountBalance = 0;
			TransactionHist(AccountBalance, 2, getTransactionHistory());
			newAccountBalance = getAccountBalance() - AccountBalance;
			cout << "\t\t\t\t\t\t    ** Withdrawl Successful **" << endl;
			setAccountBalance(newAccountBalance);
		}
		/*else
		{
			return getAccountBalance();
		}*/
	}




};


class Bank
{
private:
	Account** Account_list;
	int nAccounts;
	int user;
public:


	Bank()
	{
		Account_list = nullptr;
		nAccounts = 0;
		user = 0;
	}


	int findAccount(int RecieverAN)
	{
		for (int i = 0; i < nAccounts; i++)
		{
			if (RecieverAN == Account_list[i]->getAccountNumber())
			{
				return i;
			}
		}

		return -1;
	}

	int indexfinder()
	{
		string username;
		int flag = 0;
		int index = 0;
		while (flag == 0)
		{
			cout << "\t\t       Username : ";
			cin >> username;
			for (int i = 0; i < nAccounts && flag == 0; i++)
			{
				if (username == Account_list[i]->getUserName())
				{
					flag = 1;
					index = i;
				}

			}
			if (flag == 0)
			{
				cout << "\t\t\t\t\t\tInvalid..!" << endl;
				continue;
			}

		}
		cout << endl;
		return index;

	}

	bool checkPassword()
	{
		int attempts = 5;
		string pass;

		for (int i = 0; i < attempts; ++i)
		{
			cout << "\t\t       Password : ";
			cin >> pass;
			if (pass == Account_list[user]->getPassword())
			{
				return true;
			}
			else
			{
				cout << "\t\t\t\t\t\tIncorrect password. " << attempts - i - 1 << " tries left" << endl;
			}
		}
		cout << endl << endl;
		Account_list[user]->setAccountStatus(AccountStatusClose());
		cout << "\t\t\t==========================================================" << endl;
		cout << "\t\t\t     Your account has been temporarily closed due to       " << endl;
		cout << "\t\t\t         multiple unsuccessful login attempts..!       " << endl;
		cout << "\t\t\t==========================================================" << endl;
		cout << endl;
		return false;
	}


	void Load()
	{
		ifstream UserNameIn("username.txt");
		ifstream PasswordIn("password.txt");
		ifstream AccountNumberIn("accountNumber.txt");
		ifstream AccountBalanceIn("balance.txt");
		ifstream AccountStatusIn("accountStatus.txt");
		ifstream AccountHolderNameIn("HolderName.txt");
		ifstream MobileNumberIn("mobileNumber.txt");
		ifstream CNICIn("Cnic.txt");
		ifstream PinIn("Pin.txt");
		ifstream nAccountsIn("nAccounts.txt");
		ifstream AccountTypeIn("AccountType.txt");


		string AccountHolderName;
		string MobileNumber;
		string CNIC;
		string pin;
		string UserName;
		string Password;
		int AccountNumber;
		double AccountBalance;
		string AccountStatus;
		string AccountType;


		int n = 0;
		while (nAccountsIn >> nAccounts)
		{
			n++;
		}
		nAccounts = n;
		if (nAccounts == 0)
		{
			Account_list = nullptr;
			return;
		}
		Account** temp = new Account * [nAccounts];

		for (int i = 0; i < nAccounts; i++)
		{
			AccountTypeIn >> AccountType;
			if (AccountType == "Saving")
			{
				temp[i] = new SavingsAccount;
			}
			else if (AccountType == "Current")
			{
				temp[i] = new CurrentAccount;
			}
			AccountHolderNameIn >> AccountHolderName;
			temp[i]->setAccountHolderName(AccountHolderName);

			MobileNumberIn >> MobileNumber;
			temp[i]->setMobileNumber(MobileNumber);

			CNICIn >> CNIC;
			temp[i]->setCNIC(CNIC);

			UserNameIn >> UserName;
			temp[i]->setUserName(UserName);

			PasswordIn >> Password;
			temp[i]->setPassword(Password);

			PinIn >> pin;
			temp[i]->setPin(pin);

			temp[i]->setAccountType(AccountType);

			AccountNumberIn >> AccountNumber;
			temp[i]->setAccountNumber(AccountNumber);

			AccountBalanceIn >> AccountBalance;
			temp[i]->setAccountBalance(AccountBalance);

			AccountStatusIn >> AccountStatus;
			temp[i]->setAccountStatus(AccountStatus);


		}

		delete[] Account_list;

		Account_list = temp;

	}

	void Save()
	{

		ofstream UserNameOut("username.txt", ios::trunc);
		ofstream PasswordOut("password.txt", ios::trunc);
		ofstream AccountNumberOut("accountNumber.txt", ios::trunc);
		ofstream AccountBalanceOut("balance.txt", ios::trunc);
		ofstream AccountStatusOut("accountStatus.txt", ios::trunc);
		ofstream AccountHolderNameOut("HolderName.txt", ios::trunc);
		ofstream MobileNumberOut("mobileNumber.txt", ios::trunc);
		ofstream CNICOut("Cnic.txt", ios::trunc);
		ofstream PinOut("Pin.txt", ios::trunc);
		ofstream nAccountsOut("nAccounts.txt", ios::trunc);
		ofstream AccountTypeOut("AccountType.txt", ios::trunc);

		for (int i = 0; i < nAccounts; i++)
		{
			AccountHolderNameOut << Account_list[i]->getAccountHolderName() << endl;
			MobileNumberOut << Account_list[i]->getMobileNumber() << endl;
			CNICOut << Account_list[i]->getCNIC() << endl;
			UserNameOut << Account_list[i]->getUserName() << endl;
			PasswordOut << Account_list[i]->getPassword() << endl;
			PinOut << Account_list[i]->getPin() << endl;
			AccountBalanceOut << Account_list[i]->getAccountBalance() << endl;
			AccountNumberOut << Account_list[i]->getAccountNumber() << endl;
			AccountStatusOut << Account_list[i]->getAccountStatus() << endl;
			nAccountsOut << i << endl;
			AccountTypeOut << Account_list[i]->getAccountType() << endl;

		}



		cout << endl << "Data stored successfuly..!" << endl;
	}

	void Startmenu()
	{
		Load();
		cout << endl << endl;
		cout << "\t \t \t\t\t|=============================|" << endl;
		cout << "\t \t \t\t\t|                             |" << endl;
		cout << "\t \t \t\t\t|         WELCOME TO          |" << endl;
		cout << "\t \t \t\t\t|                             |" << endl;
		cout << "\t \t \t\t\t|     Arcadia Money Club      |" << endl;
		cout << "\t \t \t\t\t|                             |" << endl;
		cout << "\t \t \t\t\t|=============================|" << endl;

		int res = 1;

		cout << endl << endl;
		cout << " \t \t \t\t||*********************************************||" << endl;
		cout << " \t \t \t\t||                                             ||" << endl;
		cout << " \t \t \t\t||                 HOME PAGE                   ||" << endl;
		cout << " \t \t \t\t||                                             ||" << endl;
		cout << " \t \t \t\t||      1. Sign-Up                             ||" << endl;
		cout << " \t \t \t\t||                                             ||" << endl;
		cout << " \t \t \t\t||      2. Sign-In                             ||" << endl;
		cout << " \t \t \t\t||                                             ||" << endl;
		cout << " \t \t \t\t||      0. Quit                                ||" << endl;
		cout << " \t \t \t\t||                                             ||" << endl;
		cout << " \t \t \t\t||*********************************************||" << endl << endl << endl;
		cout << " \t \t \t\tEnter Your choice(0-2) : ";

		cin >> res;

		while (res != 0)
		{
			if (res == 1)
			{
				signUp();
			}

			if (res == 2 && nAccounts != 0)
			{
				cout << endl << endl << endl;
				cout << "\t    ::Sign-In     " << endl << endl;

				int flag = 0;
				user = indexfinder();
				if (Account_list[user]->getAccountStatus() == "Closed")
				{
					flag = 1;
				}

				bool pass = true;
				if (flag == 0)
				{
					pass = checkPassword();

				}
				else if (flag == 1)
				{
					Account_list[user]->setAccountStatus(AccountStatusClose());
					cout << "\n";
					cout << "\t\t\t==========================================================" << endl;
					cout << "\t\t\tThis account is currrently closed, you cant login for now." << endl;
					cout << "\t\t\t      Please contact customer support to get hep..!       " << endl;
					cout << "\t\t\t==========================================================" << endl;
					cout << "\n\n";
				}

				if (pass == true && flag == 0)
				{
					cout << "\t\t\t\t\t\tSigning In... ... ..." << endl;
					cout << "\n\n";
					signIn();
				}

			}
			else if (res == 2 && nAccounts == 0)
			{
				cout << endl;
				cout << "\t\t\t\t===================================================" << endl;
				cout << "\t\t\t\t| No accounts exist in the bank! You must Sign-Up |" << endl;
				cout << "\t\t\t\t===================================================" << endl;
				cout << endl << endl;

			}


			cout << endl << endl << endl;
			cout << " \t \t \t\t||*********************************************||" << endl;
			cout << " \t \t \t\t||                                             ||" << endl;
			cout << " \t \t \t\t||                 HOME PAGE                   ||" << endl;
			cout << " \t \t \t\t||                                             ||" << endl;
			cout << " \t \t \t\t||      1. Sign-Up                             ||" << endl;
			cout << " \t \t \t\t||      2. Sign-In                             ||" << endl;
			cout << " \t \t \t\t||      0. Quit                                ||" << endl;
			cout << " \t \t \t\t||                                             ||" << endl;
			cout << " \t \t \t\t||*********************************************||" << endl << endl << endl;
			cout << " \t \t \t\tEnter Your choice(0-2) : ";


			cin >> res;

		}
		Save();
	}


	string CreateHolderName()
	{
		string AccountHolderName = "";
		cout << "\t \t \t        Enter your name \t \t  : ";
		getline(cin, AccountHolderName);
		cout << endl;
		return AccountHolderName;

	}

	string CreateUniqueMobileNumber()
	{
		string MobileNumber = "";
		while (true)
		{
			cout << "\t \t \t        Enter your mobile number \t  : ";
			cin >> MobileNumber;

			if (OnlyDigits(MobileNumber) && calculateSize(MobileNumber) == 11)
			{
				bool isUnique = true;

				for (int i = 0; i < nAccounts; i++)
				{
					if (MobileNumber == Account_list[i]->getMobileNumber())
					{
						cout << "\t\t\t\t\t\t\t\t\t             Mobile Number already in use." << endl;
						isUnique = false;
						break;
					}
				}

				if (isUnique)
				{
					break;
				}
			}
			else
			{
				cout << "\t\t\t\t\t\t\t\t\t             Invalid Mobile Number" << endl;
			}
		}
		cout << endl;
		return MobileNumber;
	}

	string CreateUniqueCNIC()
	{
		string CNIC = "";
		while (true)
		{
			cout << "\t \t \t        Enter your CNIC (without '-') \t  : ";
			cin >> CNIC;

			if (!(OnlyDigits(CNIC) && calculateSize(CNIC) == 13))
			{
				cout << "\t\t\t\t\t\t\t\t\t             Invalid CNIC" << endl;
				continue;
			}

			bool isUnique = true;
			for (int i = 0; i < nAccounts; i++)
			{
				if (CNIC == Account_list[i]->getCNIC())
				{
					cout << "\t\t\t\t\t\t\t\t\t             CNIC already in use." << endl;
					isUnique = false;
					break;
				}
			}


			if (isUnique)
			{
				break;
			}

		}

		cout << endl;
		return CNIC;
	}




	string CreateUserName()
	{
		string U = "";
		bool isUnique = false;
		cin.ignore();
		while (!isUnique)
		{
			cout << "\t \t \t        Enter User name \t \t  : ";
			getline(cin, U);


			if (U.length() < 5)
			{
				cout << "\t\t\t\t\t\t\t\t\t             Username must have min 5 letters" << endl;
				continue;
			}

			isUnique = true;
			for (int i = 0; i < nAccounts; i++)
			{
				if (U == Account_list[i]->getUserName())
				{
					cout << "\t\t\t\t\t\t\t\t\t             Username already in use" << endl;
					isUnique = false;
					break;
				}
			}
		}
		cout << endl;
		return U;
	}

	string CreatePassword()
	{
		int check = 1;
		string Password = "";
		while (check == 1)
		{
			cout << "\t \t \t        Create Password (Min 4 Max 8 size): ";
			getline(cin, Password);

			if (calculateSize(Password) <= 8 && calculateSize(Password) >= 4)
			{
				check = 0;
			}
			else
			{
				cout << "\t\t\t\t\t\t\t\t\t             Invalid password " << endl;
			}
		}
		cout << endl;
		return Password;
	}

	string CreatePin()
	{
		string pin = "";
		int flag = 1;
		while (flag == 1)
		{
			cout << "\t \t \t        Enter a 4-bit Security Pin \t  : ";
			getline(cin, pin);
			if (OnlyDigits(pin) && calculateSize(pin) == 4)
			{
				flag = 0;

			}
			else
			{
				cout << "\t\t\t\t\t\t\t\t\t             Invalid pin " << endl;
			}

		}

		cout << endl;
		return pin;
	}


	string AccountStatusOpen()
	{
		string status = "Open";

		cout << "\t \t \t        Account status\t \t \t  : " << status << endl << endl;
		return status;
	}

	string AccountStatusClose()
	{
		string status = "Closed";

		cout << "\t\t       Account status : " << status << endl << endl;
		return status;
	}




	void TransactionHistory(double money, int fun, string* TransactionHistory)
	{

		Account_list[user]->incTsize();
		string* temp1 = Account_list[user]->getTransactionHistory();

		string* temp = new string[Account_list[user]->getTsize()];
		if (Account_list[user]->getTsize() != 1)
		{
			for (int i = 0; i < Account_list[user]->getTsize() - 1; i++)
			{

				temp[i] = temp1[i];

			}
		}
		string mon;

		if (fun == 1)
		{
			mon = intToString(money);
			temp[Account_list[user]->getTsize() - 1] = "Deposited money was " + mon;

			//deposit
		}
		else if (fun == 2)
		{
			mon = intToString(money);
			temp[Account_list[user]->getTsize() - 1] = "Withdrawn money was " + mon;
			//withdraw
		}
		else if (fun == 3)
		{
			mon = intToString(money);
			temp[Account_list[user]->getTsize() - 1] = "Sent money was " + mon;
			//send
		}

		Account_list[user]->setTransactionHistory(temp);

	}


	void SendMoney(int Reciever, double money)
	{
		if (Account_list[Reciever]->getAccountStatus() == "Closed")
		{
			cout << "\n\n";
			cout << "\t\t\t        ==================================================" << endl;
			cout << "\t\t\t                This account is currently closed !         " << endl;
			cout << "\t\t\t                  You cant transfer money to it.       " << endl;
			cout << "\t\t\t        ==================================================" << endl;
			cout << "\t \t  " << endl;
			return;
		}
		double r = Account_list[Reciever]->getAccountBalance();
		cout << "\t\t\t\t\t\t        Sending money to " << Account_list[Reciever]->getAccountHolderName() << endl << endl;
		r = r + money;
		Account_list[Reciever]->setAccountBalance(r);

		TransactionHistory(money, 3, Account_list[user]->getTransactionHistory());
		r = Account_list[user]->getAccountBalance();
		r = r - money;
		Account_list[user]->setAccountBalance(r);
		cout << "\t\t\t\t\t\t        Transaction Successful....!" << endl;

	}

	void displayAccountNumber()
	{
		cout << Account_list[user]->getAccountNumber();
	}

	void ChangePassword(string CurrenPassword)
	{

		int check = 1;
		string Password = "";
		while (check == 1)
		{
			cout << "\t \t \t\t  Create New Password (Min 4 Max 8 size): ";
			getline(cin, Password);

			
			if (calculateSize(Password) <= 8 && calculateSize(Password) >= 4)
			{
				if (Password == CurrenPassword)
				{
					cout << "\t\t\t\t\t\t                      You must Enter a New Password " << endl;
					check = 1;
				}
				else
				{
					check = 0;
				}
			}
			
			else
			{
				cout << "\t\t\t\t\t\t                      Invalid password " << endl;
			}
		}
		cout << endl;
		Account_list[user]->setPassword(Password);
	}


	void grow()
	{

		Account** temp = new Account * [nAccounts + 1];

		for (int i = 0; i < nAccounts; ++i) {
			temp[i] = Account_list[i];
		}

		delete[] Account_list;

		Account_list = temp;

	}


	void DeleteAccount()
	{
		int newSize = 0;
		int j = 0;
		for (int i = 0; i < nAccounts; i++)
		{
			if (i != user)
			{
				newSize++;
			}
		}

		Account** temp = new Account * [newSize];

		for (int i = 0; i < nAccounts; i++)
		{
			if (i != user && j <= newSize)
			{
				temp[j] = Account_list[i];
				j++;
			}
		}
		delete[] Account_list;

		Account_list = temp;
		nAccounts = newSize;

		cout << "\n\n";
		cout << "\t\t\t      ====================================================" << endl;
		cout << "\t\t\t                 Account Deleted Successfully!         " << endl;
		cout << "\t\t\t      ====================================================" << endl;
		cout << "\n\n";
	}


	void signUp()
	{
		grow();

		int type = 0;
		cout << "\n\n\n\n\n\n\n\n";
		cout << "\t\t\t ::Sign-Up" << endl;
		cout << "\n\n\n";
		cout << "\t \t \t\t\t  ==============================" << endl;
		cout << "\t \t \t\t\t  |   1. Current Account       |" << endl;
		cout << "\t \t \t\t\t  |                            |" << endl;
		cout << "\t \t \t\t\t  |   2. Savings Account       |" << endl;
		cout << "\t \t \t\t\t  ==============================" << endl;

		while (true)
		{
			cout << "\t \t \t\t\t  Enter your choice (1-2): ";


			cin >> type;

			if (type == 1)
			{
				cout << "\n\n\n\n";
				cout << " \t \t \t\t\t   Creating Current Account " << endl << endl;

				Account_list[nAccounts] = new CurrentAccount;
				Account_list[nAccounts]->setAccountType("Current");
				break;
			}
			else if (type == 2)
			{
				cout << "\n\n\n\n";
				cout << " \t \t \t\t\t   Creating Savings Account " << endl << endl;
				Account_list[nAccounts] = new SavingsAccount;
				Account_list[nAccounts]->setAccountType("Saving");
				break;

			}
			else
			{
				cout << "\t \t \t\t\t  \t \t Invalid Choice" << endl;
				continue;
			}
		}
		cin.ignore();

		Account_list[nAccounts]->setAccountHolderName(CreateHolderName());

		Account_list[nAccounts]->setMobileNumber(CreateUniqueMobileNumber());

		Account_list[nAccounts]->setCNIC(CreateUniqueCNIC());


		Account_list[nAccounts]->setUserName(CreateUserName());

		Account_list[nAccounts]->setPassword(CreatePassword());

		Account_list[nAccounts]->setPin(CreatePin());


		string m = "";
		double AccountBalance = 0;

		Account_list[nAccounts]->DepositMoney();

		//Account_list[nAccounts]->setAccountBalance(AccountBalance);

		cout << "\t \t \t        Account Type\t \t \t  : " << Account_list[nAccounts]->getAccountType() << endl << endl;

		Account_list[nAccounts]->setAccountStatus(AccountStatusOpen());


		srand(time(0));
		int newAccountNumber;
		bool uniqueAccountNumber = false;
		while (!uniqueAccountNumber)
		{
			newAccountNumber = rand() % 90000000 + 10000000;
			uniqueAccountNumber = true;
			if (nAccounts > 1)
			{

				for (int i = 0; i < nAccounts; i++)
				{
					if (Account_list[i]->getAccountNumber() == newAccountNumber)
					{
						uniqueAccountNumber = false;
						break;
					}
				}
			}
		}
		Account_list[nAccounts]->setAccountNumber(newAccountNumber);

		cout << "\t \t \t        Account Number\t \t \t  : " << Account_list[nAccounts]->getAccountNumber() << endl << endl;

		//display();

		cout << endl << endl;

		nAccounts++;
	}


	void signIn()
	{
		cout << endl << endl << endl;
		cout << "\t \t \t \t============================================================" << endl;
		cout << "\t \t \t \t                   Welcome to Your Account                  " << endl;
		cout << "\t \t \t \t                                                             " << endl;
		cout << "\t \t \t \t     Name   :  " << Account_list[user]->getAccountHolderName() << endl; 
		cout << "\t \t \t \t     Mobile :  " << Account_list[user]->getMobileNumber() << endl;
		cout << "\t \t \t \t                                                          " << endl;
		cout << "\t \t \t \t=============================================================" << endl;

		cout << endl << endl;
		cout << "\t \t \t \t |=========================================================|" << endl;
		cout << "\t \t \t \t |                                                         |" << endl;
		cout << "\t \t \t \t |    1. Deposit Money                                     |" << endl;
		cout << "\t \t \t \t |    2. Withdraw Money                                    |" << endl;
		cout << "\t \t \t \t |    3. Transfer money                                    |" << endl;
		cout << "\t \t \t \t |    4. Show Account Statement                            |" << endl;
		cout << "\t \t \t \t |    5. Show Transaction History                          |" << endl;
		cout << "\t \t \t \t |    6. Sign Out                                          |" << endl;
		cout << "\t \t \t \t |    7. Delete Account                                    |" << endl;
		cout << "\t \t \t \t |    8. Display Account Number                            |" << endl;
		cout << "\t \t \t \t |    9. Change Password                                   |" << endl;
		cout << "\t \t \t \t |                                                         |" << endl;
		cout << "\t \t \t \t |=========================================================|" << endl << endl;


		cout << endl;
		int d = 0;
		int choice = 0;
		while (true && d!=1)
		{
			cout << "\t \t \t \t Enter Your choice(1-9) : ";
			cin >> choice;

			if (choice < 1 || choice > 9) {
				cout << "\t \t \t \t \t \t \tInvalid choice" << endl;
				continue;
			}

			if (choice == 1)
			{
				cout << "\n\n\n";
				cout << "\t\t\t\t\t\t    ===================" << endl;
				cout << "\t\t\t\t\t\t    *  Deposit Money  *" << endl;
				cout << "\t\t\t\t\t\t    ===================" << endl;
				cout << "\n\n\n";
				Account_list[user]->DepositMoney();
				cout << "\t\t\t\t\t\t    ** Deposit Successful **" << endl;

			}

			else if (choice == 2)
			{
				cout << "\n\n\n";
				cout << "\t\t\t\t\t\t    ===================" << endl;
				cout << "\t\t\t\t\t\t    * Withdrawl Money *" << endl;
				cout << "\t\t\t\t\t\t    ===================" << endl;
				cout << "\n\n\n";
				Account_list[user]->WithdrawMoney();
			}

			else if (choice == 3)
			{
				cout << "\n\n\n";
				cout << "\t\t\t\t\t\t    ================" << endl;
				cout << "\t\t\t\t\t\t    *Transfer Money*" << endl;
				cout << "\t\t\t\t\t\t    ================" << endl;
				cout << "\n\n\n";

				int RecieverAN;

				int MultipleAttempts = 0;
				string strRecieverAN = "";
				while (true)
				{
					
					cout << "\t \t \t\t  Reciever's Account Number : ";
					cin >> strRecieverAN;
					if (MultipleAttempts == 4)
					{
						cout << "\n\n";
						cout << "\t\t\t      ======================================================" << endl;
						cout << "\t\t\t           Transaction failed due to multiple attempts !         " << endl;
						cout << "\t\t\t              Please contact your bank for assistance.        " << endl;
						cout << "\t\t\t      ======================================================" << endl;
						break;
					}

					if (!OnlyDigits(strRecieverAN))
					{
						MultipleAttempts++;
						cout << "\t\t\t\t\t\t        Invlid Account Number!" << endl;
						continue;
					}
					else
					{
						RecieverAN = stringToInt(strRecieverAN);
					}
					MultipleAttempts++;

					

					if (RecieverAN <= 0 || !HasEightDigits(RecieverAN))
					{
						cout << "\t\t\t\t\t\t        Invlid Account Number!" << endl;
						continue;
					}
					else if (findAccount(RecieverAN) == -1)
					{
						cout << "\t\t\t\t\t\t        Account not found!" << endl;
						continue;
					}
					break;
				}

				double money = 0;
				cout << endl;

				if (MultipleAttempts < 4)
				{
					MultipleAttempts = 0;
					while (true)
					{
						cout << "\t \t \t\t  Amount : ";
						cin >> money;

						MultipleAttempts++;

						if (MultipleAttempts == 4)
						{
							cout << "\n\n";
							cout << "\t\t\t      ======================================================" << endl;
							cout << "\t\t\t           Transaction failed due to multiple attempts !         " << endl;
							cout << "\t\t\t              Please contact your bank for assistance.        " << endl;
							cout << "\t\t\t      ======================================================" << endl;
							break;
						}

						if (money <= 0)
						{
							cout << "\t\t\t\t\t\t        Invlid Amount" << endl;
							continue;
						}

						if (money > Account_list[user]->getAccountBalance())
						{
							cout << "\t\t\t\t\t\t        Insufficient Balance!" << endl;
							continue;
						}
						break;
					}
				}
				cout << endl;
				if (MultipleAttempts < 4)
				{
					MultipleAttempts = 0;
					int MultipleAttempts = 0;
					string p;
					while (true)
					{

						cout << "\t \t \t\t  Pin Code : ";
						cin >> p;
						MultipleAttempts++;

						if (MultipleAttempts == 4)
						{
							cout << "\n\n";
							cout << "\t\t\t      ======================================================" << endl;
							cout << "\t\t\t           Transaction failed due to multiple attempts !         " << endl;
							cout << "\t\t\t              Please contact your bank for assistance.        " << endl;
							cout << "\t\t\t      ======================================================" << endl;
							break;
						}


						else if (p != Account_list[user]->getPin())
						{
							cout << "\t\t\t\t\t\t        Incorrect Pin! " << endl;
							continue;
						}

						else
						{
							int r = findAccount(RecieverAN);
							cout << endl;
							SendMoney(r, money);
							break;
							cout << endl;
						}
					}
				}

				cout << endl;
			}

			else if (choice == 4)
			{
				cout << "\n\n\n";
				cout << "\t \t \t \t =========================================================" << endl;
				cout << "\t \t \t \t                                                          " << endl;
				cout << "\t \t \t \t                    **Account Statement**                 " << endl;
				cout << "\t \t \t \t                                                          " << endl;
				cout << "\t \t \t \t                 Your Current Balance : $" << Account_list[user]->getAccountBalance() << endl;
				cout << "\t \t \t \t                                                          " << endl;
				cout << "\t \t \t \t =========================================================" << endl;
				cout << "\n\n\n";

			}

			else if (choice == 5)
			{
				cout << "\n\n\n";
				cout << "\t\t\t\t\t\t   ====================" << endl;
				cout << "\t\t\t\t\t\t   *Transaction History*" << endl;
				cout << "\t\t\t\t\t\t   ====================" << endl;
				cout << "\n\n";

				Account_list[user]->displayTransactionHistory();
				cout << "\n\n\n";


			}

			else if (choice == 6)
			{
				cout << "\n\n\n";
				cout << "\t\t\t\t\t\t   ====================" << endl;
				cout << "\t\t\t\t\t\t   *   Signing Out... *" << endl;
				cout << "\t\t\t\t\t\t   ====================" << endl;
				cout << "\n\n\n";

				break;
			}

			else if (choice == 7)
			{
				cout << "\n\n\n";
				cout << "\t\t\t\t\t\t   ====================" << endl;
				cout << "\t\t\t\t\t\t   * Deleting Account *" << endl;
				cout << "\t\t\t\t\t\t   ====================" << endl;
				cout << "\n\n\n";


				string p = "";
				int MultipleAttempts = 0;
				while (true)
				{
					if (MultipleAttempts < 4)
					{
					

						cout << "\t \t \t\t  Password : ";
						cin >> p;
						if (p != Account_list[user]->getPassword())
						{
							MultipleAttempts++;
							cout << "\t\t\t\t\t\t        Incorect Password" << endl;
							continue;
						}
						else
						{
							DeleteAccount();
							d = 1;
							break;
							
						}
					}
					else if (MultipleAttempts > 4)
					{
						cout << "\n\n";
						cout << "\t\t\t      ======================================================" << endl;
						cout << "\t\t\t                 Request to delete account failed. !         " << endl;
						cout << "\t\t\t              Please contact your bank for assistance.        " << endl;
						cout << "\t\t\t      ======================================================" << endl;
						break;
					}


				}
				cout << "\n\n\n";
			}
			
			else if (choice == 8)
			{
				cout << "\n\n\n";
				cout << "\t\t\t\t\t\t===========================" << endl;
				cout << "\t\t\t\t\t\t Account Number : ";
				displayAccountNumber();
				cout << endl;
				cout << "\t\t\t\t\t\t===========================" << endl;
				cout << "\n\n\n";

			}

			else if (choice == 9)
			{
				cout << "\n\n\n";
				cout << "\t\t\t\t\t\t    ===================" << endl;
				cout << "\t\t\t\t\t\t    *Changing Password*" << endl;
				cout << "\t\t\t\t\t\t    ===================" << endl;
				cout << "\n\n\n";


				string p = "";
				int MultipleAttempts = 0;
				while (true)
				{
					if (MultipleAttempts > 4)
					{
						cout << "\n\n";
						cout << "\t\t\t      ======================================================" << endl;
						cout << "\t\t\t                 Request to Change Password failed. !         " << endl;
						cout << "\t\t\t              Please contact your bank for assistance.        " << endl;
						cout << "\t\t\t      ======================================================" << endl;
						cout << "\n\n";
						break;
					}
					cout << "\t \t \t\t  Current Password                     : ";
					cin >> p;
					if (p != Account_list[user]->getPassword())
					{
						MultipleAttempts++;
						cout << "\t\t\t\t\t\t        Incorect Password" << endl;
						continue;
					}
					else
					{
						cout << "\n\n";
						cin.ignore();
						ChangePassword(p);
						cout << "\n\n";
						cout << "\t\t\t\t\t\t**Password Changed Successfully**" << endl;
						cout << "\n\n";
						break;

					}
				}
					

				cout << "\n\n\n";


			}
			if (d != 1)
			{
				cout << endl << endl << endl;
				cout << "\t \t \t \t |=========================================================|" << endl;
				cout << "\t \t \t \t |                                                         |" << endl;
				cout << "\t \t \t \t |    1. Deposit Money                                     |" << endl;
				cout << "\t \t \t \t |    2. Withdraw Money                                    |" << endl;
				cout << "\t \t \t \t |    3. Transfer money                                    |" << endl;
				cout << "\t \t \t \t |    4. Show Account Statement                            |" << endl;
				cout << "\t \t \t \t |    5. Show Transaction History                          |" << endl;
				cout << "\t \t \t \t |    6. Sign Out                                          |" << endl;
				cout << "\t \t \t \t |    7. Delete Account                                    |" << endl;
				cout << "\t \t \t \t |    8. Display Account Number                            |" << endl;
				cout << "\t \t \t \t |    9. Change Password                                   |" << endl;
				cout << "\t \t \t \t |                                                         |" << endl;
				cout << "\t \t \t \t |=========================================================|" << endl << endl;
			}

		}


	}



};

int main()
{
	Bank B;
	B.Startmenu();

}