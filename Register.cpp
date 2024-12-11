#include <bits/stdc++.h>
#include <windows.h>
using namespace std;

void login();
void reg();
void forgot();

int main() {
    int operand;
    cout<<"\t\tPlease Enter an Operation\n";
    cout<<"\tEnter 1 to Login\n";
    cout<<"\tEnter 2 to Register an account\n";
    cout<<"\tEnter 3 if you forgot your password\n";
    cout<<"\tEnter 4 to exit this program\n";

    cout<<"\t\nEnter your command: ";
    cin>>operand;
    cout<<"\n";

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
    cin>>userId;
    cout<<"\n";

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
        cout<<"Enter a Password: ";
        cin>>userPassword;
        cout<<"\n";

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

