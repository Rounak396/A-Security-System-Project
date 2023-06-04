#include <iostream>
#include <fstream>
#include <sstream>
#include <string>

using namespace std;

int main(){
    int a, i=0;
    string text, old, password0, password1, password2, pass, name, username, age, user, word, word1, address, phone_number, email_id, about_yourself;
    
    string creds[3], cp[3];
    
    cout<< "              Security System"<<endl;
    cout<< "             -----------------"<<endl;
    cout<< " "<<endl;
    cout<< "         -------------------------------      "<<endl;
    cout<< "        |        1. Register            |     "<<endl;
    cout<< "        |        2. Login               |     "<<endl;
    cout<< "        |        3. Change Password     |     "<<endl;
    cout<< "        |        4. End Program         |     "<<endl;
    cout<< "         -------------------------------      "<<endl;
    
    
    
    do{
        cout<<endl<<endl;
        cout<<"Enter your choice: ";
        cin>>a;
        
        switch(a){
                
                
                
            case 1: {
                cout<< "         --------------------------------------     "<<endl;
                cout<< "        |               Register               |    "<<endl;
                cout<< "         --------------------------------------     "<<endl;
                cout<<endl<<endl;
                cout<< "Enter Your Name: ";
                cin>>name;
                cout<< "Create Username: ";
                cin>>username;
                cout<< "Enter a Password: ";
                cin>>password0;
                cout<< "Enter Your Age: ";
                cin>>age;
                cout<< "Enter Your Address: ";
                cin>>address;
                cout<< "Enter Your Mobile No.: ";
                cin>>phone_number;
                cout<< "Enter Your Personal Email Address: ";
                cin>>email_id;
                cout<< "Write something about you: ";
                cin>>about_yourself;
                
                ofstream of1;
                of1.open("file.txt");
                
                if (of1.is_open()) {
                    of1<<name<<endl;
                    of1<<username<<endl;
                    of1<<password0<<endl;
                    of1<<age<<endl;
                    of1<<address<<endl;
                    of1<<phone_number<<endl;
                    of1<<email_id<<endl;
                    cout<<"Registration Successful"<<endl;
                }
                
                break;
            }
                
                
                
                
            case 2: {
                i=0;
                cout<< "         --------------------------------------     "<<endl;
                cout<< "        |                Login                 |    "<<endl;
                cout<< "         --------------------------------------     "<<endl;
                cout<<endl<<endl;
                
                ifstream of2;
                of2.open("file.txt");
                
                cout<< "Enter the Username: ";
                cin>>user;
                cout<< "Enter a Password: ";
                cin>>pass;
                
                if(of2.is_open()){
                    while(!of2.eof()){                   // When end of file is not reached
                        while(getline(of2, text)){       // Using this getline function the file
                                                         // will be read line-by-line
                            
                            istringstream iss(text);     // The istream string will be used to                                                              // stream the string using the
                                                         // extraction operator.
                            
                            iss >> word;                 // iss is the extraction operator and
                                                         // here we are storing.
                            creds[i]= word;
                            i++;                         // Here in the creds array we are                                                                  // storing the word and then we
                                                         // increament the index because
                                                         // one by one username, password etc.
                                                         // will be stored.
                        }
                        if(user==creds[1] && pass==creds[2]){
                            cout<<"Login Successfull"<<endl;
                            
                            cout<<"Details: "<<endl;
                            cout<<"Name: "<< name <<endl;
                            cout<<"Username: "<< username <<endl;
                            cout<<"Age: "<< age <<endl;
                            cout<<"Address: "<< address <<endl;
                            cout<<"Ph. No.: "<< phone_number <<endl;
                            cout<<"About: "<< about_yourself <<endl;
                        }
                        else{
                            cout<<endl<<endl;
                            cout<<"Incorrect Credentials"<<endl;
                            cout<<"            Press 2 to login again            "<<endl;
                            cout<<"            Press 3 to change password            "<<endl;
                            break;
                        }
                        
                    }
                }
                break;
            }
                
            
                
                
            case 3:{
                i=0;
                cout<< "         --------------------------------------     "<<endl;
                cout<< "        |           Change Password            |    "<<endl;
                cout<< "         --------------------------------------     "<<endl;
                cout<<endl<<endl;
                
                ifstream of0;
                of0.open("file.txt");
                cout<<"Enter the old password: ";
                cin>>old;
                if(of0.is_open()){
                    while(of0.eof()){
                        while(getline(of0, text)){
                            istringstream iss(text);
                            iss>>word1;
                            cp[i]=word1;
                            i++;
                        }
                        
                        if(old==cp[2]){
                            of0.close();
                            
                            ofstream of1;
                            
                            if(of1.is_open()){
                                cout<<"Enter a New Password: ";
                                cin>>password1;
                                cout<<"Enter Your Password again: ";
                                cin>>password2;
                                
                                if(password1 == password2){
                                    of1<<cp[1]<<endl;
                                    of1<<password1<<endl;
                                    cout<<"Password changed successfully."<<endl;
                                }
                                
                                else{
                                    of1<<cp[1]<<endl;
                                    of1<<old<<endl;
                                    cout<<"Password invalid."<<endl;
                                }
                            }
                            
                            else{
                                cout<<"Please enter a valid password."<<endl;
                                break;
                            }
                        }
                    }
                }
                break;
            }
                
                
                
            case 4:{
                cout<<"_______________________Thank You_______________________"<<endl;
                break;
            }
                
                
                
            default:
                cout<<"Enter a Valid Choice"<<endl;
                
        }
    }
    
    while(a!=4);
    return 0;
}
