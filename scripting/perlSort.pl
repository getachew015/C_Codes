#!/usr/bin/perl 

use v5.10.0; #use version v5.10.0 while compiling
use warnings;

#prompt for file names to sort and save the sorted file to
print "You are running a Perl Sort Script\n";

printf "Enter the file name if file exists in current directory or if not full File path : ";
chomp($unSortedFile = <STDIN>);
print "Enter file name to write the sorted file to : ";
chomp($tempFile = <STDIN>);

#Exits out of program if file is not found or wrong entry is made 
open (tempFile, "<", $unSortedFile ) or die "Cannot open $unSortedFile: $!";
my @line = <tempFile>;
$a=0; $b=0;
sub by_value { "\L$a" cmp "\L$b" } #sub routine to sort
#create a hash table by mapping each line with its own value as a key value
%hashedline = map { $_ => $_ }@line ;
by_value(%hashedline); #pass hash to the sub routine
my @sorted = sort by_value values %hashedline;


#prompt user if he/she wants to see the sorted file
print "The File is Sorted Enter 1 to view or any number to Escape\n";
chomp($value = <STDIN>);
if ( $value==1 ){
	print @sorted;
}

close tempFile;
print "You have Exited Perl Sort Script\n";



