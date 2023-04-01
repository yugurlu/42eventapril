
print "Enter a string: ";
my $input = <STDIN>;
chomp($input);
$input = lc($input);

if($input eq reverse($input))
{
	print "The string is a palindrome!\n";
}
else
{
	print "The string is not a palindrome.\n";
}
