#!/usr/bin/env python
# -*- coding: utf-8 -*-
import sys
import os
from subprocess import call

class Color:
	PURPLE = '\033[95m'
	RED = '\033[91m'
	BRIGHTGREEN = '\033[40m'
	BOLD = '\033[1m'
	END = '\033[0m'

def submenu():
	selection = raw_input(Color.PURPLE + "Go Back to Main Menu [y/N]:" + Color.END)
	if selection == "y":
		main_menu()
	else:
		print "Exiting..."
		sys.exit(1)

def main():
	if len(sys.argv) < 2:
		print "Usage: michellerecon.py localhostip remotehostip"
		print "Exiting..."
		sys.exit(1)
	else:
		main_menu()

def main_menu_design():
	call('clear')	
	print "-------------------------------"
	print "|            Rekkon           |" 
	print "-------------------------------"
	print "Mishell Security @mishellsec"
	print "       .---."
	print "      /     \\"
	print "      \.@-@./"
	print "      /`\_/`\\"
	print "     //  _  \\"
	print "    | \\     )|_"
	print "   /`\\_`>  <_/ \\"
	print "   \\__/'---'\\__/"
	print "\n-------------------------------"
	print "Local Host IP: " + sys.argv[1]	
	print "Remote Host IP: " + sys.argv[2]
	print "-------------------------------"
	

def main_menu():
   	try:
		main_menu_design()
		localhostip = sys.argv[1]
		remotehostip = sys.argv[2]
		print " 1 - Nmap " 
		print " 2 - Nikto " 
		print " 3 - Gobuster " 
		print " 4 - Handler linux/x86 "
		print " 5 - Handler windows/reverse_tcp"
		print " 6 - Searchsploit"
		print " 7 - Searchsploit -p"
		print " 8 - enum4linux"
		print " 9 - wireshark"
		print "10 - davtest " + remotehostip
		print "11 - Nmap [port]"
		print "12 - Open in Firefox " + remotehostip
		print "13 - Open in Firefox [port]"
		print "14 - ifconfig"	
		print "15 - cadaver"		
		print "16 - Zombie Scan"
		print "17 - Netcat Listener"	
		print "18 - Stop Apache"
		print "19 - Start Apache"	
		print "20 - SMB Enum Shares"
		print "--------------------------------"
		print "99 - More Options"
		print " 0 - Exit\n"	
		selection = int(raw_input(Color.PURPLE + "Enter your selection: " + Color.END))

		if selection == 1:
			call(["nmap", "-Pn", "-sC", "-sV", remotehostip])						
		elif selection == 2: 
			call(["nikto", "-h", remotehostip])						
		elif selection == 3: 
			call(["gobuster", "-w", "/usr/share/wordlists/dirbuster/directory-list-2.3-medium.txt", "-t", "20", "-u", "http://" + remotehostip])			
		elif selection == 4:
			lport = raw_input("Enter Local Port to use: ")
			os.system("msfconsole -qx \"use exploit/multi/handler;set payload linux/x86/shell/reverse_tcp;set LPORT " + lport + ";set LHOST " + localhostip +";exploit\"")			
		elif selection == 5:
			lport = raw_input("Enter Local Port to use: ")
			os.system("msfconsole -qx \"use exploit/multi/handler;set payload windows/meterpreter/reverse_tcp;set LPORT " + lport + ";set LHOST " + localhostip +";exploit\"")			
		elif selection == 6: 
			searchterm = raw_input("Enter search term: ")
			call(["searchsploit", searchterm])			
		elif selection == 7: 
			searchterm = raw_input("Enter exploit id to copy: ")
			call(["searchsploit", "-p", searchterm])			
		elif selection == 8:
			call(["enum4linux", remotehostip])			 
		elif selection == 9:
			call(["sudo", "wireshark"])			 
		elif selection == 10:		
			call(["davtest", "-url", "http://" + remotehostip])			
		elif selection == 11:
			port = raw_input("Enter port to scan: ")
			call(["nmap", "-Pn", "-sC", "-sV", "-p", port, remotehostip])
		elif selection == 12:
			call(["firefox", remotehostip])	
		elif selection == 13:
			port = raw_input("Enter port for ip: ")
			call(["firefox", remotehostip + ":" + port])
		elif selection == 14:
			call(["ifconfig"])		
		elif selection == 15:
			call(["cadaver", remotehostip])
		elif selection == 16:
			port = raw_input("Enter port to use for scan: ")
			call(["hping3", "-s", "-r", "-p", port, remotehostip])
		elif selection == 17:
			port = raw_input("Enter port to listen on: ")
			call(["nc", "-l", "-v", "-p", port])
		elif selection == 18:
			call(["service", "apache", "stop"])
		elif selection == 19:
			call(["service", "apache", "start"])
		elif selection == 20:
			os.system("msfconsole -qx \"use auxiliary/scanner/smb/smb_enumshares;set RHOSTS " + remotehostip + ";run;exit\"")
		elif selection == 99:
			menu20()			
		else:
			sys.exit(1)

		submenu()

     	except:
	  	sys.exit(1) 

def menu20():
	try:
		main_menu_design()
		localhostip = sys.argv[1]
		remotehostip = sys.argv[2]
		print "21 - Test " 
		
		print "--------------------------------"
		print "98 - Main Menu"
		#print "99 - More Options"
		print " 0 - Exit\n"	
		selection = int(raw_input(Color.PURPLE + "Enter your selection: " + Color.END))
		if selection == 21:
			print "Test 21"			
		elif selection == 98:
			main_menu()			
		else:
			sys.exit(1)
		submenu()
	except:
		sys.exit(1) 

main()



