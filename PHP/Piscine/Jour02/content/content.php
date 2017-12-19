#!/usr/bin/env php
<?php
// content.php for  in /home/habi/Piscine1/PHP/Jour02/content
//
// Made by HABI Acal
// Login   <habi_a@etna-alternance.net>
//
// Started on  Tue Oct 10 09:12:28 2017 HABI Acal
// Last update Tue Oct 10 09:12:29 2017 HABI Acal
//
function content($filename)
{
	if (!file_exists($filename))
		echo "content.php: {$filename}: No such file or directory\n";
	elseif (is_dir($filename))
		echo "content.php: {$filename}: Is a directory\n";
	elseif (!is_readable($filename))
		echo "content.php: {$filename}: Permission denied\n";
	elseif ($handle = fopen($filename, "r"))
	{
		if (!(filesize($filename)))
			echo "";
		else
		{
			$content = fread($handle, filesize($filename));
			echo "$content";
			fclose($handle);
		}
	}
	else
		echo "content.php: {$filename}: Cannot open file\n";
}

$i = 1;
while ($i < $argc)
{
	content($argv[$i]);
	++$i;
}
?>
