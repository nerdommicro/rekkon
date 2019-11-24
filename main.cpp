
#include <iostream>
#include <stdlib.h>
#include <string.h>
using namespace std;

void MainMenu();
void main_menu_design();
void submenu();
string lhost;
string rhost;
string lport;
string rport;

int main() {
    cout << "Enter the local host IP: ";
    cin >> lhost;
    cout << "Enter the remote host IP: ";
    cin >> rhost;
    MainMenu();
    return 0;
}
void submenu() {
    string selections;
    cout << "Go Back to the Main Menu [y/N]? ";
    cin >> selections;
    if(selections == "y")
    {
       MainMenu();
    }
    else if(selections == "Y")
    {
        MainMenu();
    }
    else {
        exit(0);
    }
}

void main_menu_design() {
    cout << "------------------------------\n";
    cout << "|         Rekkon              |\n";
    cout << "------------------------------\n";
    cout << "Mishell Security @mishellsec\n";
    cout << "------------------------------\n";
    cout << "Local host IP: " << lhost;
    cout << "\nRemote host IP: " << rhost;
    cout << "\n------------------------------\n";
}
void MainMenu(){
    main_menu_design();
    string selection;
    string command;
    cout << " 1 - Nmap\n";
    cout << " 2 - Nikto\n";
    cout << " 3 - Dirbuster\n";
    cout << " 4 - Metasploit\n";
    cout << " 5 - Ftp\n";
    cout << " 6 - Searchsploit\n";
    cout << " 7 - Searchsploit -p\n";
    cout << " 8 - enum4linux\n";
    cout << " 9 - wireshark\n";
    cout << "10 - davtest\n";
    cout << "11 - Nmap [port]\n";
    cout << "12 - Open in Firefox \n";
    cout << "13 - Open in Firefox:[port]\n";
    cout << "14 - ifconfig\n";
    cout << "15 - cadaver\n";
    cout << "16 - Zombie Scan [port]\n";
    cout << "17 - Netcat Listener [port]\n";
    cout << "18 - Stop Apache\n";
    cout << "19 - Start Apache\n";
    cout << "20 - nmblookup\n";
    cout << " 0 - Exit\n";
    cout << "Enter your selection: ";
    cin >> selection;
    if(selection == "1"){
        command = "nmap -Pn -sC -sV " + rhost;
        system(command.c_str());
    }
    else if (selection == "2") {
        command = "nikto -h " + rhost;
        system(command.c_str());
    }
    
}



