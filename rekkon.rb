#!/usr/bin/ruby
$lhost = "127.0.0.1"
$rhost = "192.168.1.1"
$lport = "4444"
$rport = "80"

class String
  def red; "\e[31m#{self}\e[0m" end
  def green; "\e[32m#{self}\e[0m" end
  def yellow; "\e[33m#{self}\e[0m" end
  def blue; "\e[34m#{self}\e[0m" end
  def magenta; "\e[35m#{self}\e[0m" end
  def cyan; "\e[36m#{self}\e[0m" end
end

def submenu
	print "Go Back to Main Menu [y/N]:".red
  selection = gets.strip
  case selection
    when "y"
      main_menu
    when "Y"
      main_menu
    when "yes"
      main_menu
    else
      print "Exiting..."
      exit(0)
    end
end

def main
  print "Enter the local host IP: ".red
  $lhost = gets
  print "Enter the remote host IP: ".red
  $rhost = gets 
  main_menu
end

def main_menu_design
  localhost = "\nLocal Host IP: " << $lhost
  remotehost = "\nRemote Host IP: " << $rhost
	system "clear"
	print "\n-------------------------------"
	print "\n|            Rekkon           |" 
	print "\n-------------------------------"
	print "\nMishell Security @michellesec".magenta
	print "\n       .---.".yellow
	print "\n      /     \\".yellow
	print "\n      \\.@-@./".yellow
	print "\n      /`\\_/`\\\\".yellow
	print "\n     //  _  \\\\".yellow
	print "\n    | \\\\     )|_".yellow
	print "\n   /`\\\\_`>  <_/ \\\\".yellow
	print "\n   \\\\__/'---'\\\\__/".yellow
	print "\n-------------------------------"
	print localhost.red
  print remotehost.red
	print "-------------------------------\n"
end	

def main_menu
    main_menu_design
    print " 1 - Nmap\n" 
  	print " 2 - Nikto\n" 
  	print " 3 - Dirbuster\n" 
  	print " 4 - Metasploit"
  	print " 5 - Ftp"
  	print " 6 - Searchsploit\n"
  	print " 7 - Searchsploit -p\n"
  	print " 8 - enum4linux\n"
  	print " 9 - wireshark\n"
  	print "10 - davtest " + $rhost
  	print "11 - Nmap [port]\n"
  	print "12 - Open in Firefox " + $rhost
  	print "13 - Open in Firefox [port]\n"
  	print "14 - ifconfig\n"	
  	print "15 - cadaver\n"		
  	print "16 - Zombie Scan\n"
  	print "17 - Netcat Listener\n"	
  	print "18 - Stop Apache\n"
  	print "19 - Start Apache\n"	
  	print "20 - nmblookup\n" 	
  	print " 0 - Exit\n"	
  	print "Enter your selection: ".red
    selection = gets.strip
    case selection
      when "1"
        system "nmap -Pn -sC -sV " + $rhost
      when "2"
        system "nikto -h " + $rhost
      when "3"
        system "dirb " + $rhost
      when "4"
        system "msfconsole"
      when "5"
        system "ftp " + $rhost
      when "6"
        print "Enter Search term: "
        searchterm = gets
        system "searchsploit " + searchterm
      when "7"
        print "Enter exploit id to copy: "
        searchterm = gets
        system "searchsploit -p " + searchterm
      when "8"
        system "enum4linux " + $rhost
      when "9"
        system "sudo wireshark"
      when "10"
        system "davtest " + $rhost
      when "11"
        print "Enter port to scan: "
        port2 = gets.strip
        system "nmap -Pn -sC -sV -p" + port2 + " " + $rhost 
      when "12"
        system "firefox " + $rhost
      when "13"
        print "Enter port to scan: "
        port2 = gets.strip
        system "firefox " + $rhost + ":" + port2
      when "14"
        system "ifconfig"
      when "15"
        system "cadaver " + $rhost
      when "16"
        print "Enter port to use for scan: "
        port2 = gets.strip
        system "hping3 -s -r -p " + port2 + " " + $rhost
      when "17"
        print "Enter port to listen on: "
        port2 = gets.strip
        system "nc -l -v -p " + port2
      when "18"
        system "service apache stop"
      when "19"
        system "service apache start"
      when "20"
        system "nmblookup -A " + $rhost
      else
        exit(0)
    end
    
    submenu
	
  
  
  
end

main