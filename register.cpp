#include <bits/stdc++.h>
#include <windows.h>
using namespace std;

void login();
void reg();
void forgot();

int main() {
    int operand;
    string temp;
    cout<<"\t\tPlease Enter an Operation\n";
    cout<<"\tEnter 1 to Login\n";
    cout<<"\tEnter 2 to Register an account\n";
    cout<<"\tEnter 3 if you forgot your password\n";
    cout<<"\tEnter 4 to exit this program\n";

    cout<<"\t\nEnter your command: ";
    cin>>operand;
    cout<<"\n";
    getline(cin, temp);

    switch (operand) {
        case 1 : 
            login();
            break;
        case 2 :
            reg();
            break;
        case 3 :
            forgot();
            break;
        case 4 :
            cout << "\nSystem Exited\n";
            break;
        default : 
            system("cls");
            cout << "\t\tInvalid Operation\n";
            Sleep(2000);
            main();
    }    

    return 0;
}

void login() {
    bool done = false;
    string userId, userPassword, Id, Password;
    cout<<"Username: ";
    cin>>userId;
    cout<<"\n";
    cout<<"Password: ";
    cin>>userPassword;
    cout<<"\n";

    ifstream fin("data.txt");
    while (fin>>Id>>Password) {
        if (Id==userId && Password==userPassword) {
            done = 1;
            cout<<"\t\tLogin Complete\n\t\tWelcome, "<<userId;
            cout<<endl;
            Sleep(1000);
            main();
        }
    }
    fin.close();

    if (!done) {
        cout<<"\tUsername or password is incorrect\n";
        Sleep(1000);
        main();
    }
}

void reg() {
    ifstream fin("data.txt");
    string userId, userPassword, Id, Password;

    cout<<"Enter a Username: ";
    getline(cin,userId);
    cout<<"\n";

    //check if userId is valid
    regex alpha("[a-zA-Z0-9]+");
    regex space("/s");

    if ( !(userId.length() >= 5 && userId.length() <= 15) ) {
        cout<<"\tUsername must be 5-15 characters long\n\n";
        Sleep(1000);
        reg();
        fin.close();
        return;
    }   
    if (!regex_match(userId,alpha)) {
        cout<<"\tUsername must not contain special characters\n\n";
        Sleep(1000);
        reg();
        fin.close();
        return;
    }
    if (regex_match(userId, space)) {
        cout<<"\tUsername must not contain spaces\n\n";
        Sleep(1000);
        reg();
        fin.close();
        return;
    }
    //


    //check if userId is taken or not
    bool found = false;
    if (!fin.fail()) {
        while (fin>>Id>>Password) {
            if (Id==userId) {
                found = true;
                cout<<"\tUser is already taken\n\tPlease Enter a new one\n";
                Sleep(1000);
                reg();
                return;
            }
        }
    }
    fin.close();
    //


    if (!found) {
        // check password validity
        regex specchar(".*[@$!%*?&].*");
        regex upperchar(".*[A-Z].*");

        while (true) {

            cout<<"Enter a Password: ";
            getline(cin,userPassword);
            cout<<"\n";

            if (userPassword.length() <= 3) {
                cout<<"\tPassword must be more than 4 characters long\n";
                Sleep(1000);
                continue;
            }
            if (!regex_match(userPassword, upperchar)) {
                cout<<"\tPassword must contain an uppercase letter\n";
                Sleep(1000);
                continue;
            }
            if (!regex_match(userPassword, specchar)) {
                cout<<"\tPassword must contain a special character\n\t eg. {!, @, ?, %, &}\n";
                Sleep(1000);
                continue;
            }
            if (regex_match(userPassword, space)) {
                cout<<"\tPassword must not contain spaces\n";
                Sleep(1000);
                continue;
            }

            break;
        }
        //

        ofstream fout("data.txt", ios::app);
        cout<<"\t\t\tRegistration Complete\n";
        fout<<userId<<' '<<userPassword<<endl;
        Sleep(1000);
        main();
    }
    
}

void forgot() {
    bool found = false;
    string userId, userPassword, Id, Password;
    cout<<"\tPlease enter your Username: ";
    cin>>userId;

    ifstream fin("data.txt");
    while (fin>>Id>>Password) {
        if (userId == Id) {
            found = true;
            cout<<"\n\tYour Password is: "<<Password;
            Sleep(1000);
            cout<<endl;
            cout<<"Returning......\n";
            Sleep(2000);
            cout<<endl;
            main();
        }
    }
    fin.close();
    
    if (!found) {
        cout<<"\n\t\tYour Username is not found";
        Sleep(1000);
        cout<<"Returning......";
        Sleep(1000);
        main();
    }

}

