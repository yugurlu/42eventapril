<?php

$input = readline("Choose rock, paper, or scissors: ");
$input = strtolower($input);
$vrb = ['rock', 'paper', 'scissors'];
$pc = $vrb[array_rand($vrb)];

if($input != $pc)
{
	if($input == 'rock')
	{
		if($pc == 'paper')
		{
			print "Sorry, you lost. The computer chose paper.";
		}
		else
		{
			print "Congratulations! You won! The computer chose scissors.";
		}
	}
	else if($input == 'paper')
	{
		if($pc == 'scissors')
		{
			print "Sorry, you lost. The computer chose scissors.";
		}
		else
		{
			print "Congratulations! You won! The computer chose rock.";
		}
	}
	else if($input == 'scissors')
	{
		if($pc == 'rock')
		{
			print "Sorry, you lost. The computer chose rock.";
		}
		else
		{
			print "Congratulations! You won! The computer chose paper.";
		}
	}
}

?>
