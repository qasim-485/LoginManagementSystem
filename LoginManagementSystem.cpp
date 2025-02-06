#include<iostream>
#include<vector>
#include<string>
using namespace std;
class User{
	private:
		string username, password;
	public:
		User(string name, string pass){
			username = name;
			password = pass;
		}
		string getUsername(){
			return username;
		}
		string getPassword(){
			return password;
		}
};
class UserManager{
	private:
		vector<User> users;
	public:
		void registerUser(){
			string username, password;
			cout<< "Enter your name: "<<endl;
			cin>>username;
			cout<< "Enter your password: "<<endl;
			cin>>password;
			
			User newUser(username, password);
			users.push_back(newUser);
		}
		bool LoginUser(string name, string pass){
			for(int i =0; i<users.size(); i++){
				if(users[i].getUsername() == name && users[i].getPassword() == pass){
					cout<<"Login Successfully"<<endl;
					return true;
				}
			}
				cout<<"Invalid User"<<endl;
				return false;
			
		}
		void showUser(){
			cout<<"------User List------"<<endl;
			for(int i=0; i<users.size(); i++){
				cout<<users[i].getUsername()<<endl;
			}
		}
		string searchUser(string username){
			for(int i=0; i<users.size(); i++){
				if(users[i].getUsername()== username){
					cout<<"User found"<<endl;
				}	
			}
		}
		string deleteUser(string username){
			for(int i=0; i<users.size(); i++){
				if(users[i].getUsername()== username){
					users.erase(users.begin() + i);
					cout<<"User removed successfully"<<endl;
					return 0;
				}	
			}
			cout << "User not found" << endl;
		}
};

int main(){
	UserManager usermanage;
	int option;
	char choice;
	do{
		system("cls");
		cout<< "1. Register User"<<endl;
		cout<< "2. Login User"<<endl;
		cout<< "3. Show User"<<endl;
		cout<< "4. Search User "<<endl;
		cout<< "5. Delete User "<<endl;
		cout<< "6. Exit "<<endl;
	    cout<<"Enter your choice"<<endl;
	    cin>>option;
		switch(option){
			case 1:{
				usermanage.registerUser();
				break;
			}
			case 2:{
				string username, password;
				cout<<"Enter your username: "<<endl;
				cin>>username;
				cout<<"Enter your password: "<<endl;
				cin>>password;
				usermanage.LoginUser(username, password);
				break;
			}
			case 3:{
				usermanage.showUser();
				break;
			}
			case 4:{
				string username;
				cout<<"Enter the name of the user you want to search"<<endl;
				cin>>username;
				usermanage.searchUser(username);
				break;
			}
			case 5:{
				string username;
				cout<<"Enter the name of the user you want to delete"<<endl;
				cin>>username;
				usermanage.deleteUser(username);
				break;
			}
			case 6:
				exit(1);
	    }
    
    cout<<"Do you want to continue [Yes/No] ? :"<<endl;
    cin>>choice;
    }
	while(choice == 'Y' || choice == 'y');
	
}
