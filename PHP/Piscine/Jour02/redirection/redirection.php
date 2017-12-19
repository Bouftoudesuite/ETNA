#!/usr/bin/env php
<?php
// redirection.php for  in /home/habi/Piscine1/PHP/Jour02/redirection
//
// Made by HABI Acal
// Login   <habi_a@etna-alternance.net>
//
// Started on  Tue Oct 10 10:40:48 2017 HABI Acal
// Last update Tue Oct 10 10:40:49 2017 HABI Acal
//
if ($argc == 4)
{
	$filename = $argv[3];
	$symbol = $argv[2];
	$string = $argv[1];
	if (($symbol != ">" && $symbol != ">>"))
		echo "Usage : ./redirection.php 'string' '[> >>]' 'File'\n";
	elseif (is_dir($filename))
		echo "redirection.php: {$filename}: Is a directory\n";
	elseif (!is_writable($filename) && file_exists($filename))
		echo "redirection.php: {$filename}: Permission denied\n";
	elseif ($symbol != '>')
	{
		$handle = fopen($filename, "a");
		fwrite($handle, $string);
		fwrite($handle, "\n");
		fclose($handle);
	}
	elseif ($symbol != '>>')
	{
		$handle = fopen($filename, "w");
		fwrite($handle, $string);
		fwrite($handle, "\n");
		fclose($handle);
	}
	else
		echo "redirection.php: {$filename}: Cannot open file\n";
}
else
	echo "Usage : ./redirection.php 'string' '[> >>]' 'File'\n";
?>
