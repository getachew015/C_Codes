#!/bin/bash

#Main shell Script that calls two other perl scripts to perform sort and search on a file


#Menu To be displayed
menu (){
	printf "Menu : \n" 
	printf "1) Enter 1 to Sort a file with shell script: \n"
	printf "2) Enter 2 to Sort a file with Perl script: \n"
	printf "3) Enter 3 to Search for a word in a file with Perl script: \n"	
	printf "4) Enter 4 to Exit: "
	read option
}

#shell function to sort file and redirect sorted file to another file
shellSort(){
		#this will return the current directory the script is running
		current_dir=$(pwd)
		printf "Enter the file name if file exists in current directory or if not full File path : ";
		read unSortedFile		
		if [[ $unSortedFile = "" ]]
		then		
		echo "File name has to be Entered !"
		echo "Usage: file.txt or /home/documents/file.txt"
		exit 1 #Program exited with error b/c of no input
		else if [ ! -f "$unSortedFile" ] 
		then
		echo "File Not found !"
		else	
		printf "Enter a file name to write/save the sorted File to : "
		read sortedFile
		sort $unSortedFile > $sortedFile	
		echo "File $unSortedFile has been sorted and saved as $sortedFile "		
		fi
		fi
}

#Shell Script Displaying Options in an infinite while loop
while true
do
	echo "Enter Your Menu Selection : "
	menu
	#Switch between the menu options
	    case "$option" in
	        "1")	  shellSort	;; #call internal shellSort function
	        "2")	./perlSort.pl	;; #start up a perl script to sort
	        "3")    ./perlSearch.pl	;; #start up a perl script to search
	        "4")	exit 0		;; #exit
	        *) printf "Wrong Entry Made ! Please Enter a number between 1 and 4 \n";;
	    esac

done

