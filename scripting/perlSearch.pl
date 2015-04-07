#!/usr/bin/perl -w

use v5.10.0; #use version v5.10.0 while compiling

printf "You are running a Perl Search Script\n";
#prompt user for a file to search from and a word to search for
printf "Enter the file name if file exists in current directory or if not full File path : ";
chomp($fileIn = <STDIN>);
print "Enter a word to search for : ";
chomp($wordIn = <STDIN>);
	
open (tempFile, "<", $fileIn ) or die "Cannot open $fileIn: $!";
	my @lines = <tempFile>;
	$wordCount=0; $count=0;
	#iterate through an array that holds each line of the file
	foreach my $line (@lines) {
	$count++;	
	if ( $line =~ m/$wordIn/i ) { #look for a word through each line
		print "\tWord $wordIn was found on line $count    >>>>\t$line";
		$wordCount++;
	}
	}
	if ($wordCount==0){ 
	print "Word Not Found ! \n"
	}
close tempFile;
printf "You Have Exited Perl Search Script\n";
