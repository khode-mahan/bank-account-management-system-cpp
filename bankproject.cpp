#include<iostream>
#include<string>
#include<vector>
#include<cstdlib>
#include<ctime>
#include<fstream>
#include <sstream>
#include<limits>
using namespace std;

class person{
protected:
    string name;
    string id;

public:
    person(){
        name= "";
        id= "";
    }

    person(string n,string i){
        name = n;
        id = i;
    }

    void setname(string n){
        name = n;
    }

    void setid(string i){
        id = i;
    }
	
    string getname() const{
        return name;
    }

    string getid() const{
        return id;
    }
	
    virtual void display() const{
        cout<<"Name: "<<name<<endl;
        cout<<"ID: "<<id<<endl;
    }
};

class account : public person{
private:
    int password;
    int account_number;
    string shaba_number;
    string account_type;
    double balance;
    long long card_number;
    int cvv2;
    string expire_date;
    string open_date;
    bool active;
    double interest_rate;
    double daily_limit;

public:
    account(){
        password = 0;
        account_number = 0;
        shaba_number = "";
        account_type = "";
        balance = 0;
        card_number = 0;
        cvv2 = 0;
        expire_date = "";
        open_date = "";
        active = true;
        interest_rate = 0;
        daily_limit = 0;
    }

    account(string n,string i,int p,int a,string s,string ac,double b,long long cn,int cv,string ed,string od,double ir,double dl): person(n,i){

        password = p;
        account_number = a;
        shaba_number = s;
        account_type = ac;
        balance = b;
        card_number = cn;
        cvv2 = cv;
        expire_date = ed;
        open_date = od;
        interest_rate=ir;
        daily_limit = dl;
        active = true;
    }

    void setpassword(int p){
        if(p >= 1000 && p <= 9999){
			password = p;
		}
		
		else{
			cout << "Invalid password.\n";
		}
    }

    void setdaily_limit(double dl){
        if(dl > 0){
			daily_limit = dl;
		}
		
		else{
			cout << "Invalid daily limit.\n";
		}
    }

    void setinterest_rate(double ir){
        if(ir >= 0 && ir <= 100){
			interest_rate = ir;
		}
		
		else{
			cout << "Invalid interset rate";	
		}
	
}
	void setexpire_date(string ed){
    	expire_date = ed;
	}
		
	bool hasInterest() const{
    return account_type == "Short Term" || account_type == "Long Term";
}
	
	
    int getpassword() const{
        return password;
    }

    int getaccount_number() const{
        return account_number;
    }

    string getshaba_number() const{
        return shaba_number;
    }

    string getaccount_type() const{
        return account_type;
    }

    double getbalance() const{
        return balance;
    }

    long long getcard_number() const{ 
        return card_number;
    }

    int getcvv2() const{
        return cvv2;
    }

    string getexpire_date() const{
        return expire_date;
    }

    string getopen_date() const{
        return open_date;
    }

    bool getactive() const{
        return active;
    }

    double getinterest_rate() const{
        return interest_rate;
    }

    double getdaily_limit() const{
        return daily_limit;
    }
	
	void withdraw(double mablagh){
		balance -= mablagh;
	}
	
	void block(){
		active = false;
	}
	
	void unblock(){
		active = true;	
	}
	
	void deposit(double amount){
    if(amount > 0){
        balance += amount;
    }
    else{
        cout << "Invalid amount" << endl;
    }
}
	void applyInterest(){
    if(hasInterest()){
        balance += balance * interest_rate / 100;
    }
}

	void setaccount_number(int a){
    	account_number = a;
	}

	void setshaba_number(string s){
    	shaba_number = s;
	}

	void setaccount_type(string t){
    	account_type = t;
	}

	void setbalance(double b){
    	balance = b;
	}

	void setcard_number(long long c){
    	card_number = c;
	}

	void setcvv2(int c){
    	cvv2 = c;
	}

	void setopen_date(string od){
    	open_date = od;
	}

	void setactive(bool a){
    	active = a;
	}


    void display() const override{

        person::display();

        cout<<"Account Number: "<<account_number<<endl;
        cout<<"Shaba Number: "<<shaba_number<<endl;
        cout<<"Account Type: "<<account_type<<endl;
        cout<<"Balance: "<<balance<<endl;
        cout<<"Card Number: "<<card_number<<endl;
        cout<<"CVV2: "<<cvv2<<endl;
        cout<<"Expire Date: "<<expire_date<<endl;
        cout<<"Open Date: "<<open_date<<endl;
        cout<<"Status: "<<(active ? "Active" : "Blocked")<<endl;
        cout<<"Interest Rate: "<<interest_rate<<endl;
        cout<<"Daily Limit: "<<daily_limit<<endl;
    }
};

class bank{

private:

    vector<account> accounts;

    int generateAccountNumber(){
        return 100000 + rand()%900000;
    }

    long long generateCardNumber(){
        return 6037990000000000LL + rand()%1000000;
    }

    string generateShabaNumber(){
        return "IR" + to_string(100000000 + rand()%900000000);
    }

    int generateCVV2(){
        return 100 + rand()%900; 
    }

    string generateExpireDate(){
        int month = 1 + rand()%12;
        int year = 1404 + rand()%5; 

        string m = (month < 10 ? "0" + to_string(month) : to_string(month));
        return m + "/" + to_string(year);
    }

public:

	void saveToFile(){

    ofstream file("accounts.txt");

    for(int i=0;i<accounts.size();i++){

        file
        << accounts[i].getname() << '|'
        << accounts[i].getid() << '|'
        << accounts[i].getpassword() << '|'
        << accounts[i].getaccount_number() << '|'
        << accounts[i].getshaba_number() << '|'
        << accounts[i].getaccount_type() << '|'
        << accounts[i].getbalance() << '|'
        << accounts[i].getcard_number() << '|'
        << accounts[i].getcvv2() << '|'
        << accounts[i].getexpire_date() << '|'
        << accounts[i].getopen_date() << '|'
        << accounts[i].getactive() << '|'
        << accounts[i].getinterest_rate() << '|'
        << accounts[i].getdaily_limit()
        << endl;

    }

    file.close();
}

	void loadFromFile(){

    ifstream file("accounts.txt");

    if(!file)
        return;

    accounts.clear();

    string name,id,shaba,type,expire,open,line;
    int password,account_number,cvv2,active;
    double balance,interest,daily;
    long long card;

    while(getline(file,line)){

        stringstream ss(line);
        string temp;

        getline(ss,name,'|');
        getline(ss,id,'|');

        getline(ss,temp,'|');
        password=stoi(temp);

        getline(ss,temp,'|');
        account_number=stoi(temp);

        getline(ss,shaba,'|');
        getline(ss,type,'|');

        getline(ss,temp,'|');
        balance=stod(temp);

        getline(ss,temp,'|');
        card=stoll(temp);

        getline(ss,temp,'|');
        cvv2=stoi(temp);

        getline(ss,expire,'|');
        getline(ss,open,'|');

        getline(ss,temp,'|');
        active=stoi(temp);

        getline(ss,temp,'|');
        interest=stod(temp);

        getline(ss,temp,'|');
        daily=stod(temp);

        account a(name,id,password,account_number,
                  shaba,type,balance,
                  card,cvv2,expire,
                  open,interest,daily);

        a.setactive(active);

        accounts.push_back(a);
    }

    file.close();
}

    void createaccount(){

        string name;
        cout<<"Enter name: ";
        getline(cin,name);

        string id;
        cout<<"Enter ID: ";
        getline(cin,id);

        int password;
        cout<<"Enter password: ";
        cin>>password;

        cin.ignore();

        int account_number = generateAccountNumber();
        string shaba_number = generateShabaNumber();

        string Account_type;
        cout<<"Enter Account type: ";
        getline(cin,Account_type);

        double balance;
        cout<<"Balance: ";
        cin>>balance;

        long long card_number = generateCardNumber();
        int cvv2 = generateCVV2();
        string expire_date = generateExpireDate();

        cin.ignore();

        string open_date;
        cout<<"Open Date: ";
        getline(cin,open_date);

        double interest_rate;
        cout<<"Interest Rate: ";
        cin>>interest_rate;

        double daily_limit;
        cout<<"Daily Limit: ";
        cin>>daily_limit;

        account a(name,id,password,account_number,shaba_number,Account_type,balance,card_number,cvv2,expire_date,open_date,interest_rate,daily_limit);

        accounts.push_back(a);
		
		saveToFile();
		
        cout<<"\nAccount created successfully.\n";
        cout<<"Account Number: "<<account_number<<endl;
        cout<<"Card Number: "<<card_number<<endl;
        cout<<"Shaba Number: "<<shaba_number<<endl;
        cout<<"CVV2: "<<cvv2<<endl;
        cout<<"Expire Date: "<<expire_date<<endl;
    }

    void deleteaccount(){
    	
            int account_number;
            cout<<"Enter account_number: ";
            cin>>account_number;

            for(int i=0;i<accounts.size();i++){

                if(accounts[i].getaccount_number()==account_number){

                    if(accounts[i].getactive() != true){
                        cout<<"Account not active to delete!!!";
                        return;
                    }

                    if(accounts[i].getactive() == true){

                        int password;
                        cout<<"Enter password: ";
                        cin>>password;

                        if(accounts[i].getpassword()==password){
                            accounts.erase(accounts.begin()+i);
                            cout<<"Account deleted";
                            saveToFile();
                            return;
                        }
                        
                    else{
                        cout<<"Wrong password";
                        return;
                    }
                    
                    }

                }
            }

            cout<<"Account not found";
    }
    
    	void search_account(){
		int account_number;
		cout << "Enter account number: ";
		cin >> account_number;
		for(int i = 0; i < accounts.size(); i++){
			if(accounts[i].getaccount_number() == account_number){
				cout << "Account found";
				return;
			}
		}
		cout << "Account not found";
	}
	
	void change_password(){
		int account_number;
		cout << "Enter account_number: ";
		cin >> account_number;
		
		for(int i = 0; i < accounts.size(); i++){
			if(accounts[i].getaccount_number() == account_number){
				int password;
				cout << "Enter current password: ";
				cin >> password;
				if(accounts[i].getpassword() == password){
					
					int new_password;
					cout << "Enter new_password: ";
					cin >> new_password;
					
					if(new_password >= 1000 && new_password <= 9999){
						accounts[i].setpassword(new_password);
						saveToFile();
						cout << "Password changed";
					}
					
					else{
						cout << "Invalid password";	
					}
					
				}
				
				else{
					cout << "Wrong password";
				}
				
				return;
			}	
		}
		
		cout << "Account not found";	
	}
	
	void bardasht(){
		int account_number;
		cout << "Enter account number: ";
		cin >> account_number;
		for(int i = 0; i < accounts.size(); i++){
			if(accounts[i].getaccount_number() == account_number){
				
				if(!accounts[i].getactive()){
					cout << "Account is blocked";
					return;
				}
				
				int password;
				cout << "Enter password: ";
				cin >> password;
				if(accounts[i].getpassword() == password){
					double mablagh;
					cout << "Enter mablagh: ";
					cin >> mablagh;
					if(mablagh <= 0){
						cout << "Invalid choice";
						return;
					}
					
					if(mablagh > accounts[i].getdaily_limit()){
						cout << "daily limit exceeded";
						return;
					}
					
					if(mablagh > accounts[i].getbalance()){
						cout << "Insufficient balance";
						return;
					}
					
					else{
						accounts[i].withdraw(mablagh);
						
						cout << "mablagh  " << mablagh << " Bardashte shod, " << "balance: " << accounts[i].getbalance() << endl;
						saveToFile();
						return;
					}		
				}
				
				cout << "Wrong password";
				return;
			}

		}
	
		cout << "Account not found";
		return;
	}
	
	void masdood(){
		int account_number;
		cout << "Enter Account_number: ";
		cin >> account_number;
		for(int i = 0; i < accounts.size(); i++){
			if(accounts[i].getaccount_number() == account_number){
				if(accounts[i].getactive()){
					int password;
					cout << "Enter password: ";
					cin >> password;
					if(accounts[i].getpassword() == password){
						accounts[i].block();
						saveToFile();
						
						cout << "Account blocked successfully";
						return;
					}
					
					cout << "Wrong password";
					return;
				}
				
				cout << "Account blocked";
				return;
			}
		}
		
		cout << "Account not found";
		return;
	}
	
	void unblock(){
		int account_number;
		cout << "Enter account_number: ";
		cin >> account_number;
		for(int i = 0; i < accounts.size(); i++){
			if(accounts[i].getaccount_number() == account_number){
				if(accounts[i].getactive() == true){
					cout << "Account already active";
					return;
				}
				
				else{
					int password;
					cout << "Enter password: ";
					cin >> password;
					
					if(accounts[i].getpassword() != password){
						cout << "Wrong password";
						return;	
					}
					
					accounts[i].unblock();
					cout << "Account unblocked successfully";
					saveToFile();
					return;
				}
			}
		}
		
		cout << "Account not found";
	}
	
	void enteghal_by_account_number(){
		int account_number;
		cout << "Enter Account_number: ";
		cin >> account_number;
		
		for(int i = 0; i < accounts.size(); i++){
			if(accounts[i].getaccount_number() == account_number){
				
				if(!accounts[i].getactive()){
					cout << "Account blocked";
					return;
				}
				
				int password;
				cout << "Enter password: ";
				cin >> password;
				if(accounts[i].getpassword() != password){
					cout << "Wrong password";
					return;
				}
				
				int maccount_number;
				cout << "Enter maccount_number: ";
				cin >> maccount_number;
				
				if(account_number == maccount_number){
					cout << "Cannot transfer to same account";
					return;
				}
				
				for(int j = 0; j < accounts.size(); j++){
					if(accounts[j].getaccount_number() == maccount_number){
						
						if(!accounts[j].getactive()){
							cout << "Destination account blocked";
							return;
						}
						
						double mablagh;
						cout << "Enter mablagh: ";
						cin >> mablagh;
						
						if(mablagh <= 0){
							cout << "Invalid choice";
							return;
						}
						
						if(mablagh > accounts[i].getdaily_limit()){
							cout << "Daily limit exceeded";
							return;
						}
						
						if(mablagh > accounts[i].getbalance()){
							cout << "Insufficient balance";
							return;
						}
						
						accounts[i].withdraw(mablagh);
						accounts[j].deposit(mablagh);
						
						cout << "Enteghal movafagh, balance: " << accounts[i].getbalance() << endl;
						saveToFile();
						return;
					}
				}
				
				cout << "Destination account not found";
				return;
			}
		}
		
		cout << "Account not found";
		return;
	}
	
	void search_by_name(){
		string name;
		cout << "Enter name: ";
		getline(cin, name);
		
		for(int i = 0; i < accounts.size(); i++){
			if(accounts[i].getname() == name){
				cout << "Account Found";
				return;
			}
		}
		
		cout << "Account not found";
	}
	
	void edit(){
		int account_number;
		cout << "Enter account_number: ";
		cin >> account_number;
		
		for(int i = 0; i < accounts.size(); i++){
			if(accounts[i].getaccount_number() == account_number){
				if(accounts[i].getactive() == false){
					cout << "Account Not active";
					return;
				}
				int password;
				cout << "Enter password: ";
				cin >> password;
				
				if(accounts[i].getpassword() == password){
					string name;
					cout << "Enter new_name: ";
					cin.ignore();
					getline(cin, name);
					
					string id;
					cout << "Enter new_ID: ";
					getline(cin, id);
					
					accounts[i].setname(name);
					accounts[i].setid(id);
					
					cout << "Information edited";
					saveToFile();
					return;
				}
				
							else{
			
			cout << "Wrong password";
			return;	
	}
			}
			
		}
		
		cout << "Account not found";
	}
	
		void enteghal_by_shaba_number(){
		string shaba_number;
		cout << "Enter shaba_number: ";
		getline(cin, shaba_number);
		
		for(int i = 0; i < accounts.size(); i++){
			if(accounts[i].getshaba_number() == shaba_number){
				
				if(!accounts[i].getactive()){
					cout << "Account blocked";
					return;
				}
				
				int password;
				cout << "Enter password: ";
				cin >> password;
				if(accounts[i].getpassword() != password){
					cout << "Wrong password";
					return;
				}
				
				cin.ignore();
				
				string mshaba_number;
				cout << "Enter mshaba_number: ";
				getline(cin, mshaba_number);
				
				if(shaba_number == mshaba_number){
					cout << "Cannot transfer to same account";
					return;
				}
				
				for(int j = 0; j < accounts.size(); j++){
					if(accounts[j].getshaba_number() == mshaba_number){
						
						if(!accounts[j].getactive()){
							cout << "Destination account blocked";
							return;
						}
						
						double mablagh;
						cout << "Enter mablagh: ";
						cin >> mablagh;
						
						if(mablagh <= 0){
							cout << "Invalid choice";
							return;
						}
						
						if(mablagh > accounts[i].getdaily_limit()){
							cout << "Daily limit exceeded";
							return;
						}
						
						if(mablagh > accounts[i].getbalance()){
							cout << "Insufficient balance";
							return;
						}
						
						accounts[i].withdraw(mablagh);
						accounts[j].deposit(mablagh);
						
						cout << "Enteghal movafagh, balance: " << accounts[i].getbalance() << endl;
						saveToFile();
						return;
					}
				}
				
				cout << "Destination account not found";
				return;
			}
		}
		
		cout << "Account not found";
		return;
	}
	
void tamdid_engheza(){
    int account_number;
    cout << "Enter account_number: ";
    cin >> account_number;

    for(int i = 0; i < accounts.size(); i++){

        if(accounts[i].getaccount_number() == account_number){

            if(!accounts[i].getactive()){
                cout << "Account Not active";
                return;
            }

            int password;
            cout << "Enter password: ";
            cin >> password;

            if(accounts[i].getpassword() == password){

                string oldExpire = accounts[i].getexpire_date();

                string month = oldExpire.substr(0, 2);
                int year = stoi(oldExpire.substr(3));

                year += 4;

                string newExpire = month + "/" + to_string(year);

                accounts[i].setexpire_date(newExpire);

                cout << "Card renewed successfully" << endl;
                cout << "New Expire Date: " << newExpire << endl;
                saveToFile();
                return;
            }

            else{
                cout << "Wrong password";
                return;
            }
        }
    }

    cout << "Account not found";
}

void pardakht_sood(){
    int account_number;
    cout << "Enter account number: ";
    cin >> account_number;

    for(int i = 0; i < accounts.size(); i++){

        if(accounts[i].getaccount_number() == account_number){

            accounts[i].applyInterest();
            saveToFile();
			return;
        }
    }

    cout << "Account not found";
}

};

int main(){

    srand(time(0));

    bank b;
    b.loadFromFile();

    int choice;

    do{
        cout << "\n===== Bank Menu =====\n";
        cout << "1.  Create Account\n";
        cout << "2.  Delete Account\n";
        cout << "3.  Search Account (by number)\n";
        cout << "4.  Search Account (by name)\n";
        cout << "5.  Change Password\n";
        cout << "6.  Withdraw\n";
        cout << "7.  Block Account\n";
        cout << "8.  Unblock Account\n";
        cout << "9.  Transfer (by account number)\n";
        cout << "10. Transfer (by shaba number)\n";
        cout << "11. Edit Account Info\n";
        cout << "12. Renew Card (extend expire date)\n";
        cout << "13. Apply Interest\n";
        cout << "0.  Exit\n";
        cout << "Enter your choice: ";
        cin >> choice;
        cin.ignore();

        switch(choice){
            case 1:
                b.createaccount();
                break;
            case 2:
                b.deleteaccount();
                break;
            case 3:
                b.search_account();
                break;
            case 4:
                b.search_by_name();
                break;
            case 5:
                b.change_password();
                break;
            case 6:
                b.bardasht();
                break;
            case 7:
                b.masdood();
                break;
            case 8:
                b.unblock();
                break;
            case 9:
                b.enteghal_by_account_number();
                break;
            case 10:
                b.enteghal_by_shaba_number();
                break;
            case 11:
                b.edit();
                break;
            case 12:
                b.tamdid_engheza();
                break;
            case 13:
                b.pardakht_sood();
                break;
            case 0:
                cout << "Goodbye!\n";
                break;
            default:
                cout << "Invalid choice.\n";
        }

        cin.ignore(numeric_limits<streamsize>::max(), '\n');

    } while(choice != 0);

    return 0;
}