#include<stdio.h>
#include <stdlib.h>
#include <string.h>

void mainMenu();
void main_menu_design();
void submenu();
char lhost[15];
char rhost[15];
char lport[6];
char rport[6];

#define ANSI_COLOR_RED     "\x1b[31m"
#define ANSI_COLOR_GREEN   "\x1b[32m"
#define ANSI_COLOR_YELLOW  "\x1b[33m"
#define ANSI_COLOR_BLUE    "\x1b[34m"
#define ANSI_COLOR_MAGENTA "\x1b[35m"
#define ANSI_COLOR_CYAN    "\x1b[36m"
#define ANSI_COLOR_RESET   "\x1b[0m"

int main() {
    printf(ANSI_COLOR_RED "Enter the local host IP: " ANSI_COLOR_RESET);
    scanf("%s", lhost);
    printf(ANSI_COLOR_RED"Enter the remote host IP: " ANSI_COLOR_RESET);
    scanf("%s", rhost);
    mainMenu();    
    return 0;
}
void submenu() {
    char selections[1];
    printf (ANSI_COLOR_BLUE "Go Back to Main Menu [y/N]? " ANSI_COLOR_RESET);
    scanf("%s", selections);
    if (strcmp(selections, "y") == 0) {
        mainMenu();
    }
    else if (strcmp(selections, "Y") == 0) {
        mainMenu();
    }
    else {
        exit(0);
    }
    
}
void main_menu_design() {
    printf ("---------------------------\n");
    printf ("|         Rekkon          |\n");
    printf ("---------------------------\n");
    printf (ANSI_COLOR_MAGENTA "Mishell Security @mishellsec\n" ANSI_COLOR_RESET);
    printf(ANSI_COLOR_YELLOW);
    printf ("       .---.               \n");
    printf ("      /     \\              \n");
    printf ("      \\.@-@./              \n");
    printf ("      /`\\_/`\\              \n");
    printf ("     //  _  \\              \n");
    printf ("    | \\     )|_              \n");
    printf ("   /`\\_`>  <_/ \\              \n");
    printf ("   \\__/'---'\\__/              \n");
    printf(ANSI_COLOR_RESET);
    printf ("-------------------------------\n");
    printf(ANSI_COLOR_RED "Local host IP: %s" ANSI_COLOR_RESET, lhost);
    printf(ANSI_COLOR_RED"\nRemote host IP: %s" ANSI_COLOR_RESET, rhost);
    printf ("\n------------------------------\n");
    
}

void mainMenu() { 
    main_menu_design();
    char selection[3];
    char command[50]; 
    printf("Main Menu\n");
    printf(" 1 - Nmap\n");
    printf(" 2 - Nikto\n");
    printf(" 3 - Dirbuster\n");
    printf(" 4 - Metasploit\n");
    printf(" 5 - Ftp\n");
    printf(" 6 - Searchsploit\n");
    printf(" 7 - Searchsploit -p\n");
    printf(" 8 - enum4linux\n");
    printf(" 9 - wireshark\n");
    printf("10 - davtest %s \n", rhost);
    printf("11 - Nmap [port]\n");
    printf("12 - Open in Firefox %s \n", rhost);
    printf("13 - Open in Firefox [port]\n");
    printf("14 - ifconfig\n");	
    printf("15 - cadaver\n");		
    printf("16 - Zombie Scan\n");
    printf("17 - Netcat Listener\n");	
    printf("18 - Stop Apache\n");
    printf("19 - Start Apache\n");	
    printf("20 - nmblookup\n");
    printf("0 - Exit\n");
    printf(ANSI_COLOR_BLUE"Enter your selection: " ANSI_COLOR_RESET);
    scanf("%s", selection);    
        
    if (strcmp(selection, "1") == 0) {
        snprintf(command, sizeof(command), "nmap -Pn -sC -sV %s", rhost);
        system(command);
    }
    else if (strcmp(selection, "2") == 0) {
        snprintf(command, sizeof(command), "nikto -h %s", rhost);
        system(command);        
    }
    else if (strcmp(selection, "3") == 0) {
        snprintf(command, sizeof(command), "dirb %s", rhost);
        system(command);        
    }
    else if (strcmp(selection, "4") == 0) {
        snprintf(command, sizeof(command), "msfconsole");
        system(command);               
    }
    else if (strcmp(selection, "5") == 0) {
        snprintf(command, sizeof(command), "ftp %s", rhost);
        system(command);
    }
    else if (strcmp(selection, "6") == 0) {
        char searchterm[200];
        printf(ANSI_COLOR_BLUE "Enter search term: "ANSI_COLOR_RESET);
        scanf("%s", searchterm);
        snprintf(command, sizeof(command), "searchsploit %s", searchterm); 
        system(command);
    }
    else if (strcmp(selection, "7") == 0) {
        char searchterm[200];
        printf(ANSI_COLOR_BLUE "Enter exploit id to copy: "ANSI_COLOR_RESET);
        scanf("%s", searchterm);
        snprintf(command, sizeof(command), "searchsploit -p %s", searchterm); 
        system(command);
    }
    else if (strcmp(selection, "8") == 0) {
        snprintf(command, sizeof(command), "enum4linux %s", rhost); 
        system(command);
    }
    else if (strcmp(selection, "9") == 0) {
        snprintf(command, sizeof(command), "sudo wireshark"); 
        system(command);
    }
    else if (strcmp(selection, "10") == 0) {
        snprintf(command, sizeof(command), "davtest -url http://%s", rhost); 
        system(command);
    }
    else if (strcmp(selection, "11") == 0) {
        char remote_port[6];
        printf(ANSI_COLOR_BLUE "Enter port to scan: "ANSI_COLOR_RESET);
        scanf("%s", remote_port);
        snprintf(command, sizeof(command), "nmap -Pn -sC -sV -p%s %s", remote_port, rhost); 
        system(command);
    }
     else if (strcmp(selection, "12") == 0) {
        snprintf(command, sizeof(command), "firefox %s", rhost); 
        system(command);
    }
    else if (strcmp(selection, "13") == 0) {
        char remote_port[6];
        printf(ANSI_COLOR_BLUE "Enter port to open: "ANSI_COLOR_RESET);
        scanf("%s", remote_port);
        snprintf(command, sizeof(command), "firefox %s:%s", rhost, remote_port); 
        system(command);
    }
    else if (strcmp(selection, "14") == 0) {
        snprintf(command, sizeof(command), "ifconfig"); 
        system(command);
    }
    else if (strcmp(selection, "15") == 0) {
        snprintf(command, sizeof(command), "cadaver %s", rhost); 
        system(command);
    }
    else if (strcmp(selection, "16") == 0) {
        char remote_port[6];
        printf(ANSI_COLOR_BLUE "Enter port to use for scan: "ANSI_COLOR_RESET);
        scanf("%s", remote_port);
        snprintf(command, sizeof(command), "hping3 -s -r -p %s %s", remote_port, rhost); 
        system(command);
    }
    else if (strcmp(selection, "17") == 0) {
        char local_port[6];
        printf(ANSI_COLOR_BLUE "Enter port to listen on: "ANSI_COLOR_RESET);
        scanf("%s", local_port);
        snprintf(command, sizeof(command), "nc -l -v -p %s", local_port); 
        system(command);
    }
    else if (strcmp(selection, "18") == 0) {
        snprintf(command, sizeof(command), "service apache stop"); 
        system(command);
    }
    else if (strcmp(selection, "19") == 0) {
        snprintf(command, sizeof(command), "service apache start"); 
        system(command);
    }
    else if (strcmp(selection, "20") == 0) {
        snprintf(command, sizeof(command), "nmblookup -A %s", rhost); 
        system(command);
    }
    else {
        exit(0);
    }
    
    submenu();
    
    
}










