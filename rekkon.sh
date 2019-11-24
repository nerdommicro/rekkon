#!/bin/bash
echo "Enter the remote ip address:"
read ipaddress
if [ ! -d $ipaddress ]; then
  	echo Creating directory $ipaddress
	mkdir $ipaddress
	echo done.
fi
echo "----------------------------------------------------"
echo "Run NMAP? (y/n)"
read selection
if [ "$selection" = "y" ]
then
	echo "Nmap writing to:" $ipaddress/nmap.nmap
	nmap -sC -sV $ipaddress > $ipaddress/nmap.nmap
	cat $ipaddress/nmap.nmap
	echo done.
fi
echo "----------------------------------------------------"
echo "Run Nikto? (y/n)"
read selection
if [ "$selection" = "y" ]
then
	echo "Enter port:"
	read port
	echo "Running nikto on $ipaddress"
	if [ "$port" = "443" ]
	then
		nikto -h "https://$ipaddress" 
	else
		nikto -h "http://$ipaddress:$port" 
	fi
	
	echo done.
fi
echo "----------------------------------------------------"
echo "Run Gobuster? (y/n)"
read selection
if [ "$selection" = "y" ]
then
	echo "Enter port:"
	read port
	echo "Running gobuster on $ipaddress"
	if [ "$port" = "443" ]
	then
		gobuster -w /usr/share/wordlists/dirbuster/directory-list-2.3-medium.txt -t 20 -u https://$ipaddress 
	else
		gobuster -w /usr/share/wordlists/dirbuster/directory-list-2.3-medium.txt -t 20 -u http://$ipaddress:$port
	fi
	echo done.
fi
echo "----------------------------------------------------"
echo "Run Davtest? (y/n)"
read selection
if [ "$selection" = "y" ]
then
	echo "Enter port:"
	read port
	echo "Running davtest on $ipaddress"
	if [ "$port" = "443" ]
	then
		davtest --url https://$ipaddress 
	else
		davtest --url http://$ipaddress:$port
	fi
	echo done.
fi
echo "----------------------------------------------------"
echo "Run enum4linux? (y/n)"
read selection
if [ "$selection" = "y" ]
then
	enum4linux $ipaddress
	echo done.
fi
echo "----------------------------------------------------"
echo "Run WMAP? (y/n)"
read selection
if [ "$selection" = "y" ]
then
	echo "Enter port:"
	read port
	echo "Running WMAP on $ipaddress"
	if [ "$port" = "443" ]
	then
		msfconsole -qx "load wmap;wmap_sites -a https://$ipaddress;wmap_targets -t https://$ipaddress;wmap_run -e"	
	else		
		msfconsole -qx "load wmap;wmap_sites -a http://$ipaddress:$port;wmap_targets -t http://$ipaddress:$port;wmap_run -e"
	fi	
	echo done.
fi




