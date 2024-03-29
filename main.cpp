#include<bits/stdc++.h>
#include<windows.h>
using namespace std;

//global functions
void write_acc(string namex, int accountNox, int balancec, string typex, string filename); //function to write record in  file
void write_loan( int accountNox, int loanA, string timeper,int Monthly , string filename);//function to write record in  file
void updateData(int,string,int); //function to update data in file
void modify_acc(int);    //function to modify record of file
void delete_acc(int);    //function to delete record of file
void display_all();        //function to display all account details
void depositAmount( int); // function to desposit for given account
void withdrawAmount(int); // function to withdraw for given account
void intro();    //introductory screen function
void showStudentLoanDtails(int);
bool verifyAccount(int num); //to verify and extract details from file
bool verifyLoan(int num);
//for int into string conversion
string intIntoString(int x) {

	string s = to_string(x);
	return s;
}
//for string into int conversion
int StringtoInt(string x) {

	stringstream ss;
	ss << x;
	int i;
	ss >> i;
	return i;
}

//Clases
class bank {
private:
	string bankName;
	string bankAddress;
	
	int loanAmount;
	string TimePeriod;
	int MonthlyInstallemnt;

public:
	bank() {
		 bankName="State Bank of India";
		 bankAddress="Khardha, Kolkata -700116, West Bengal";
	}
	bank(string bankNamex, string bankAddressx) {
		bankName = bankNamex;
		bankAddress = bankAddressx;
	}
	bank(int loanAmountx,string TimePeriodx,int MonthlyInstallemntx) {
		loanAmount = loanAmountx;
		TimePeriod = TimePeriodx;
		MonthlyInstallemnt = MonthlyInstallemntx;
	}
	//getter setters
	void setBankName(string bankNamex) {
		bankName = bankNamex;
	}
	string getBankName() {
		return bankName;
	}
	void setBankAddress(string bankAddressx) {
		bankAddress = bankAddressx;
	}
	string getBankAddress() {
		return bankAddress;
	}
	void setLoanAmount(int loan) {
		loanAmount = loan;
	}
	int getLoanAmount() {
		return loanAmount;
	}
	void setTimePeriod(string time) {
		TimePeriod = time;
	}
	string getTimePeriod() {
		return TimePeriod;
	}
	void setMonthlyInstallemnt(int loan) {
		MonthlyInstallemnt = loan;
	}
	int getMonthlyInstallemnt() {
		return MonthlyInstallemnt;
	}

	//abstract function
	virtual void studentLoan() = 0; 
};

//abstract class and extended class from bank
class account : public bank {
	string name;
	int accountNo;

	int balance;
	string type;

public:
	//default constructor
	account() {

	}
	account(string bankNamex, string bankAddessx, string namex, int accountNox, int balancec, string typex):bank(bankNamex, bankAddessx) {
		 name=namex;
		 accountNo=accountNox;
		
		 balance=balancec;
		 type=typex;
	}
	account(int loanA, string timeper, int Monthly, string namex, int accountNox, int balancec, string typex) :bank(loanA, timeper, Monthly) {
		name = namex;
		accountNo = accountNox;

		balance = balancec;
		type = typex;
	}
	//getter seetters
	void setName(string namex) {
		name = namex;
	}
	string getName() {
		return name;
	}
	void setAccounNo(int AccountNo) {
		accountNo = AccountNo;
	}
	int getAccountNo() {
		return accountNo;
	}
	void setBalance(int balancex) {
		balance = balancex;
	}
	int getBalance() {
		return balance;
	}
	void setType(string typex) {
		type = typex;
	}
	string getType() {
		return type;
	}


	//****functions*******
		//function to create a new account
	void create_acc() {
		int typec;
		crlabel:
		cout << "\n\nEnter The Account Number :";
		cin >> accountNo;
		if (verifyAccount(accountNo) == true) {
			cout << "\n\t Account Already Exist......\n\t\tPlease Enter details again.....";
			Sleep(2000);
			system("cls");
			goto crlabel;
			
		}
		cout << "\n\tEnter Name of The Account Holder : ";
		cin.clear();
		cin.ignore();
		getline(std::cin, name);//for string input
		cout << "\n\tEnter Type of Account\n\t1. Current Account \n\t2. Savings account  "<<endl;
		cout<<"\tEnter Type : ";
	cin >> typec;
		if (typec == 1)
			type = "Current";
		else if (typec == 2)
			type = "Savings";
		cout << "\tEnter The Initial amount you want to deposit : ";
		cin >> balance;
	
		
		
			//write into file 
		write_acc(name, accountNo, balance, type,"accounts.txt");
			cout << "\n\n\t\tCongrats Account Has Been Created......"<<endl;
		
	}
	//function to show account details
	void show_acc(int num) {
		if (verifyAccount(num) == true) {
			cout << "\n\t\t " << getBankName();
			cout << "\n\t\t " << getBankAddress();

			cout << "\n*****************************************";
			cout << "\n\t\t ACCOUNT DETAILS";
			cout << "\n\t Account no. : " << accountNo;
			cout << "\n\t Account Holder Name : " << name;
			cout << "\n\t Account Type : " << type;
			cout << "\n\t Account Balance: Rs " << balance << "\\-";
			cout << "\n*****************************************";
		}
		else {
			cout << "\n\t\tAccount does not exist...."<<endl;
		}
	};    
	void modify();    //function to modify account details
	   //function to accept deposit amount
	void deposit(int d) {
		balance = balance + d;
	}; 
	//function to subtract withdrawal amount
	void withdraw(int d) {
		balance = balance - d;
	};    
	   
	//virtual function for student loan
	void studentLoan() {
		int loanA;
		string timeper;
		int AccountNo;
		int installment;
		int choice;
	label:
		cout << "\n\nWelcome to student loan "<<endl;
		cout << "\tEnter your account no : ";
		cin >> AccountNo;
		if (verifyAccount(AccountNo) == true) {

			if (verifyLoan(AccountNo) == true) {
				cout << "\n\tYou Already have taken Laon!!! Please pay the installment first....";

			}

			else {
				labelAA:
				cout << "\n\tEnter loan amount you want to take : ";
				cin >> loanA;
				cout<<endl;
				if (loanA < 0 && loanA<10000) {
					cout << "\n\tAmount cant be negative and should be greater than 10000\n\tEnter again";
					Sleep(2000);
					system("cls");
					goto labelAA;
				}
				cout << "\nselect time period \n\t 1. 1 year \n\t 2. 3 years \n\t 3. 5 years\nChoose : ";
				cin >> choice;
				if (choice != 1 && choice != 2 && choice != 3) {
					cout << "\n\t\tWrong choice enter again.."<<endl;
					Sleep(2000);
					system("cls");
					goto label;
				}
				switch (choice) {
				case 1:
					timeper = "1 year";
					installment = loanA / 12;
					cout << "\n\tYour monthly Insatallment is Rs " << installment << " \\-";
					break;

				case 2:
					timeper = "3 year";
					installment = loanA / 36;
					cout << "\n\tYour monthly Insatallment is Rs " << installment << " \\-";
					break;
				case 3:
					timeper = "5 year";
					installment = loanA / 60;
					cout << "\n\tYour monthly Insatallment is Rs " << installment << " \\-";
				}
				write_loan(AccountNo, loanA, timeper, installment, "studentLoan.txt");
				cout << "\n\t\tCongratulation!!! you have succefully recieved loan.......";
			}
		}
		else
			cout << "\n\t\t...Account does not exist......";

		
	}
	
};


//global instance
account ac;

//main
int main() {
	int choice;
	system("cls");
	system("color 0a");
	
	char ch;
	int num;
	intro();
	menuLabel:
	do
	{
		system("cls");   //Clear The Screen
		cout << "\nBank MENU"<<endl;
		cout << "\t01. NEW ACCOUNT"<<endl;
		cout << "\t02. DEPOSIT"<<endl;
		cout << "\t03. WITHDRAW"<<endl;
		cout << "\t04. BALANCE ENQUIRY"<<endl;
		cout << "\t05. COMPLETE ACCOUNT HOLDERS LIST"<<endl;
		cout << "\t06. CLOSE AN ACCOUNT"<<endl;
		cout << "\t07. MODIFY AN ACCOUNT"<<endl;
		cout << "\t08. Student Loan Application"<<endl;
		cout << "\t09. Student Loan Details"<<endl;
		cout << "\tPress q to EXIT"<<endl;
		cout << "Select Your Option (1-9) : ";
		cin >> ch;
		system("cls");   //Clear The Screen

		//conditions
		switch (ch)
		{
		case '1':
			system("cls");
			ac.create_acc();
			cout << "\n\tPress 1 to go back main menu ";
			while (1) {
				cin >> choice;
				if (choice == 1) {
					break;
					system("cls");
					goto menuLabel;

				}
				else {
					cout << "\n\tPlease enter 1 to go back to main menu";
				}

			}
			break;
		case '2':
			system("cls");
			cout << "\n\n\tEnter The Account Number : "; cin >> num;
			depositAmount(num);
			cout << "\n\tPress 1 to go back main menu ";
			while (1) {
				cin >> choice;
				if (choice == 1) {
					break;
					system("cls");
					goto menuLabel;

				}
				else {
					cout << "\n\tPlease enter 1 to go back to main menu";
				}

			}
			break;
		case '3':
			system("cls");
			cout << "\n\n\tEnter The Account Number : "; cin >> num;
			withdrawAmount(num);
			cout << "\n\tPress 1 to go back main menu ";
			while (1) {
				cin >> choice;
				if (choice == 1) {
					break;
					system("cls");
					goto menuLabel;

				}
				else {
					cout << "\n\tPlease enter 1 to go back to main menu";
				}

			}
			break;
		case '4':
			system("cls");
			cout << "\n\n\tEnter The Account Number : "; cin >> num;
			ac.show_acc(num);
			cout << "\n\tPress 1 to go back main menu ";
			while (1) {
				cin >> choice;
				if (choice == 1) {
					break;
					system("cls");
					goto menuLabel;

				}
				else {
					cout << "\n\tPlease enter 1 to go back to main menu";
				}

			}
			break;
		case '5':
			system("cls");
			display_all();
			cout << "\n\tPress 1 to go back main menu ";
			while (1) {
				cin >> choice;
				if (choice == 1) {
					break;
					system("cls");
					goto menuLabel;

				}
				else {
					cout << "\n\tPlease enter 1 to go back to main menu";
				}

			}
			break;
		case '6':
			system("cls");
			cout << "\n\n\tEnter The Account Number : "; cin >> num;
			delete_acc(num);
			cout << "\n\tPress 1 to go back main menu ";
			while (1) {
				cin >> choice;
				if (choice == 1) {
					break;
					system("cls");
					goto menuLabel;

				}
				else {
					cout << "\n\tPlease enter 1 to go back to main menu";
				}

			}
			break;
		case '7':
			system("cls");
			cout << "\n\n\tEnter The Account Number : "; cin >> num;
			modify_acc(num);
			cout << "\n\tPress 1 to go back main menu ";
			while (1) {
				cin >> choice;
				if (choice == 1) {
					break;
					system("cls");
					goto menuLabel;

				}
				else {
					cout << "\n\tPlease enter 1 to go back to main menu";
				}

			}
			break;
		case '8':
			system("cls");
			ac.studentLoan();
			cout << "\n\tPress 1 to go back main menu ";
			while (1) {
				cin >> choice;
				if (choice == 1) {
					break;
					system("cls");
					goto menuLabel;

				}
				else {
					cout << "\n\tPlease enter 1 to go back to main menu";
				}

			}
			break;
		case '9':
			system("cls");
			system("cls");
			cout << "\n\n\tEnter The Account Number : "; cin >> num;
			showStudentLoanDtails(num);
			cout << "\n\tPress 1 to go back main menu ";
			while (1) {
				cin >> choice;
				if (choice == 1) {
					break;
					system("cls");
					goto menuLabel;

				}
				else {
					cout << "\n\tPlease enter 1 to go back to main menu";
				}

			}
			break;

		case 'q':
			system("cls");
			cout << "\n\n\tThanks For Visiting Our Bank!"<<endl;
			break;
		default:cout << "\a";
		}
		

	} while (ch != 'q');
	return 0;
}

//function declaration

void intro()
{

	cout << "\n\n\n\t\t\t\tWelcome To BANK MANAGEMENT SYSTEM";
	//Note: All the data of the new account entered will be stored in the file
	cout << "\n\n\n\t\t\t\tPlease wait while loading\n\n";
	char a = 177, b = 219;
	cout << "\t\t\t\t";
	for (int i = 0; i <= 15; i++)
		cout << a;
	cout << "\r";
	cout << "\t\t\t\t";
	for (int i = 0; i <= 15; i++)
	{
		cout << b;
		Sleep(200);
	}
}

bool verifyAccount(int num) {
	string name;
	string accountNo;
	string balance;
	string type;

	char ch;
	string line;
		char usedDelimi=','; 
		int delimiterCounter = 0;
		//file handling
		string filename = "accounts.txt";
		ifstream srcFile(filename.c_str());
		
		if (srcFile.is_open())
		{
			while (getline(srcFile, line))
			{
				//Gets line of your source file into line variable
				delimiterCounter = 0;
				for (int i = 0; i < line.length(); i++) {
					ch = line.at(i);
					//if , seperator found in file
					if (ch == usedDelimi) {
						delimiterCounter++;
						continue;
					}

					 if (delimiterCounter==0) {
						 name.push_back(ch);
					}
					 else if (delimiterCounter == 1) {
						 accountNo.push_back(ch);
					 }
					 else if (delimiterCounter == 2) {
						 balance.push_back(ch);
					 }
					 else if (delimiterCounter == 3) {
						 type.push_back(ch);
					 }
					
				}

				if (StringtoInt(accountNo) == num) {
					ac.setName(name);
					ac.setAccounNo(StringtoInt(accountNo));
					ac.setBalance(StringtoInt(balance));

					ac.setType(type);

					return true;
					break;
				}
				name.clear();
				accountNo.clear();
				balance.clear();
				type.clear();
			}
		}
		else {
			cout << "\n Unable to open file";
		}
		srcFile.close();
		return false;
	
}
void write_acc(string namex, int accountNox, int balancec, string typex,string filename) {
	ofstream myfile;
	myfile.open(filename,ios::app);
	if(!myfile){
		cerr<<"\n\t\tfile can not open"<<endl;
		exit(1);
	}
	myfile <<"\n"<< namex << ',' << accountNox << ',' << balancec << ',' << typex;
	myfile.close();

}
void updateData(int num,string update,int choice) {
	string fileName = "accounts.txt";
	char ch;
	char usedDelimi = ',';
	int delimiterCounter = 0;
	string line;
	ifstream fin;
	ofstream fout;
	string name;
	string accountNo;
	string balance;
	string type;
	fin.open(fileName);

	if (fin.is_open()) {

		fout.open("temp.txt", ios::out | ios::binary);
		while (getline(fin, line))
		{
			delimiterCounter = 0;
			for (int i = 0; i < line.length(); i++) {

				ch = line.at(i);
				if (ch == usedDelimi) {
					delimiterCounter++;
					continue;
				}

				if (delimiterCounter == 0) {
					name.push_back(ch);
				}
				else if (delimiterCounter == 1) {
					accountNo.push_back(ch);
				}
				else if (delimiterCounter == 2) {
					balance.push_back(ch);
				}
				else if (delimiterCounter == 3) {
					type.push_back(ch);
				}


			}
			if (StringtoInt(accountNo) == num) {
				if (choice == 1)//for acount no
					write_acc(update, StringtoInt(accountNo), StringtoInt(balance), type, "temp.txt");
				else if (choice == 2)//for account no 
					write_acc(name, StringtoInt(update), StringtoInt(balance), type, "temp.txt");

				else if (choice == 3)//for balance
					write_acc(name, StringtoInt(accountNo), StringtoInt(update), type, "temp.txt");
				else if (choice == 4)//for type
					write_acc(name, StringtoInt(accountNo), StringtoInt(balance), update, "temp.txt");
			}
			else {
				if(!(name==""||accountNo==""||balance==""||type==""))
				write_acc(name, StringtoInt(accountNo), StringtoInt(balance), type, "temp.txt");
			}
			name.clear();
			accountNo.clear();
			balance.clear();
			type.clear();
		}
		fin.close();
		fout.close();
		remove("accounts.txt");
		rename("temp.txt", "accounts.txt");
	}
	else
		cout << "\n\t\t File not Found.....";

}
void DeleteData(int check) {
	string fileName = "accounts.txt";
	char ch;
	char usedDelimi = ',';
	int delimiterCounter = 0;
	string line;
	ifstream fin;
	ofstream fout;
	string name;
	string accountNo;
	string balance;
	string type;
	fin.open(fileName);

	if (fin.is_open()) {
		
		fout.open("temp.txt", ios::out | ios::binary);
		while (getline(fin, line))
		{
			delimiterCounter = 0;
			for (int i = 0; i < line.length(); i++) {

				ch = line.at(i);
				if (ch == usedDelimi) {
					delimiterCounter++;
					continue;
				}

				if (delimiterCounter == 0) {
					name.push_back(ch);
				}
				else if (delimiterCounter == 1) {
					accountNo.push_back(ch);
				}
				else if (delimiterCounter == 2) {
					balance.push_back(ch);
				}
				else if (delimiterCounter == 3) {
					type.push_back(ch);
				}
				

			}
			if (StringtoInt(accountNo) == check) {
				
			}
			else
				write_acc(name, StringtoInt(accountNo), StringtoInt(balance), type, "temp.txt");
			name.clear();
			accountNo.clear();
			balance.clear();
			type.clear();
		}
		fin.close();
		fout.close();
		remove("accounts.txt");
		rename("temp.txt","accounts.txt");
	}
	else
		cout << "\n File not Found";

}
void depositAmount(int num) {
	if (verifyAccount(num) == true) {
	label2:
		cout << "\n\tEnter The Ammount you want to Deposit : ";
		int am;
		cin >> am;
		if (am < 0) {
			cout << "\nAmmount cant be negative Enter again: ";
			goto label2;
		}
		else {
			ac.deposit(am);
			updateData(num, intIntoString(ac.getBalance()), 3);
			cout << "\n\tAmmount Successfully deposit..."<<endl;
			cout<<"\tTotal amont in your bank is : "<<ac.getBalance()<<endl;
		}
	}
	else {
		cout << "\nAccount Dont exist";
	}
}
void delete_acc(int x) {
	if (verifyAccount(x) == true) {
		
		DeleteData(x);
		cout << "\n\t\tAccount Succefully deleted!!!";
	}
	else
		cout << "\n\t\tAccount Dont exist.........";
}
void withdrawAmount(int num) {
	if (verifyAccount(num) == true) {
	label2:
		cout << "\n\n\tEnter The Ammount you want to Withdraw : ";
		int am;
		cin >> am;
		if (am < 0) {
			cout << "\n\t\tAmmount cant be negative\n\t Enter again: ";
			Sleep(2000);
			system("cls");
			goto label2;
		}
		else {
			if (am > ac.getBalance())
			{
				cout << "\n\t\tInsufficient Balance.....";

			}
			else {
				ac.withdraw(am);
				updateData(num, intIntoString(ac.getBalance()), 3);
				cout << "\n\tAmmount Successfully Withdraw"<<endl;
				cout<<"\n\tTotla amont in your account is :"<<ac.getBalance()<<endl;
			}
		}
	}
	else {
		cout << "\n\t\tAccount Dont exist.......";
	}
}
void display_all() {
	account ac;
	cout << "\n\t\t " << ac.getBankName();
	cout << "\n\t\t " << ac.getBankAddress();
	cout << "\n\t\tAll Accounts  ";
	string name;
	string accountNo;
	string balance;
	string type;

	char ch;
	string line;
	char usedDelimi = ',';
	int delimiterCounter = 0;
	//file handling
	string filename = "accounts.txt";
	ifstream srcFile(filename.c_str());

	if (srcFile.is_open())
	{
		while (getline(srcFile, line))
		{
			//Gets line of your source file into line variable
			delimiterCounter = 0;
			for (int i = 0; i < line.length(); i++) {
				ch = line.at(i);
				//if , seperator found in file
				if (ch == usedDelimi) {
					delimiterCounter++;
					continue;
				}

				if (delimiterCounter == 0) {
					name.push_back(ch);
				}
				else if (delimiterCounter == 1) {
					accountNo.push_back(ch);
				}
				else if (delimiterCounter == 2) {
					balance.push_back(ch);
				}
				else if (delimiterCounter == 3) {
					type.push_back(ch);
				}

			}
			if (name == "") {

			}
			else {
				cout << "\n*****************************************";
				cout << "\n\t\t ACCOUNT DETAILS";
				cout << "\n\t Account no. : " << accountNo;
				cout << "\n\t Account Holder Name : " << name;
				cout << "\n\t Account Type : " << type;
				cout << "\n\t Account Balance: Rs " << balance << "\\-";
				cout << "\n*****************************************";
			}
			name.clear();
			accountNo.clear();
			balance.clear();
			type.clear();
		}
	}
	else {
		cout << "\n\t\tUnable to open file.......";
	}
	srcFile.close();


}
void modify_acc(int num) {
	if (verifyAccount(num) == true) {
		ac.show_acc(num);
		cout << "\n Enter \n\t 1.  Edit acccount holder's name \n\t 2.  Edit account no \n\t 3.  Edit account type\nChoose : ";
		int choice;
		string name;
		string no;
		string type;
		cin >> choice;
		
		switch(choice) {
		case 1:
			cout << "Enter account holder's Name :";
			
			cin.clear();
			cin.ignore();
			getline(cin, name);
			updateData(num, name, 1);
			break;
		case 2:
			cout << "Enter new Acount no. :";
		
			cin.clear();
			cin.ignore();
			getline(cin, no);
			updateData(num, no, 2);
			break;
		case 3:
			cout << "Enter new Type :";
			
			cin.clear();
			cin.ignore();
			getline(cin, type);
			updateData(num, type, 4);
			break;
		}
		ac.show_acc(num);
		cout << "\n\t\tAccount Succefully updates!!!";
	}
	else
		cout << "\n\t\tAccount Dont exist.....";
}
void write_loan(int accountNox, int loanA, string timeper, int Monthly, string filename) {
	ofstream myfile;
	myfile.open(filename, ios::app);
	myfile << "\n" << accountNox << ',' << loanA << ',' << timeper << ',' << Monthly;
	myfile.close();
}
void showStudentLoanDtails(int num) {
	if (verifyAccount(num) == true) {


		if (verifyLoan(num) == true)
		{
			string loan;
			string plan;
			string accountNo;
			string inst;
			char ch;
			string line;
			char usedDelimi = ',';
			int delimiterCounter = 0;
			//file handling
			string filename = "studentLoan.txt";
			ifstream srcFile(filename.c_str());

			if (srcFile.is_open())
			{
				while (getline(srcFile, line))
				{
					//Gets line of your source file into line variable
					delimiterCounter = 0;
					for (int i = 0; i < line.length(); i++) {
						ch = line.at(i);
						//if , seperator found in file
						if (ch == usedDelimi) {
							delimiterCounter++;
							continue;
						}

						if (delimiterCounter == 0) {
							accountNo.push_back(ch);
						}
						else if (delimiterCounter == 1) {
							loan.push_back(ch);
						}
						else if (delimiterCounter == 2) {
							plan.push_back(ch);
						}
						else if (delimiterCounter == 3) {
							inst.push_back(ch);
						}

					}

					if (StringtoInt(accountNo) == num) {
						cout << "\n\t\t " << ac.getBankName();
						cout << "\n\t\t " << ac.getBankAddress();

						cout << "\n*****************************************";
						cout << "\n\t\t Loan DETAILS";
						cout << "\n\t Account no. : " << ac.getAccountNo();
						cout << "\n\t Loan Amount : " << loan;
						cout << "\n\t Installment plan : " << plan;
						cout << "\n\t Monthly Installment: Rs " << inst << "\\-";
						cout << "\n*****************************************";


					}
					loan.clear();
					plan.clear();
					inst.clear();
					accountNo.clear();
				}

			}
			else {
				cout << "\n\t\tUnable to open file.....";
			}
		}
		else
			cout << "\n\t\tThis Account has no Loan details!!!";
	}
	else
		cout << "\n\t\tAccount Not Exist....";
}

bool verifyLoan(int num) {
	string type;

	char ch;
	string line;
	char usedDelimi = ',';
	int delimiterCounter = 0;
	//file handling
	string filename = "studentLoan.txt";
	ifstream srcFile(filename.c_str());

	if (srcFile.is_open())
	{
		while (getline(srcFile, line))
		{
			//Gets line of your source file into line variable
			delimiterCounter = 0;
			for (int i = 0; i < line.length(); i++) {
				ch = line.at(i);
				//if , seperator found in file
				if (ch == usedDelimi) {
					delimiterCounter++;
					continue;
				}

				if (delimiterCounter == 0) {
					type.push_back(ch);
				}
				

			}

			if (StringtoInt(type) == num) {


				return true;
				break;
			}
		
			type.clear();
		}
	}
	else {
		cout << "\n\t\tUnable to open file......";
	}
	srcFile.close();
	return false;


}