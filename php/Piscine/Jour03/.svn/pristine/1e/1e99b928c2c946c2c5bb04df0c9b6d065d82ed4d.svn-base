#!/usr/bin/env php
<?php
// capitalize_file.php for  in /home/habi/Piscine1/PHP/Jour03/capitalize_file
// 
// Made by HABI Acal
// Login   <habi_a@etna-alternance.net>
// 
// Started on  Wed Oct 11 09:48:10 2017 HABI Acal
// Last update Wed Oct 11 09:48:11 2017 HABI Acal
//
	function check($filename)
	{
		if (!file_exists($filename))
	    	echo "capitalize_file: {$filename}: No such file or directory\n";
	    elseif (is_dir($filename))
	    	echo "capitalize_file: {$filename}: Is a directory\n";
		elseif (!is_readable($filename) || !is_writable($filename))
		    echo "capitalize_file: {$filename}: Permission denied\n";
		elseif ($handle = fopen($filename, "r"))
		{
			if (!(filesize($filename)))
				echo "";
			else
			{	
				$content = fread($handle, filesize($filename));
				fclose($handle);
				return ("verified");
			}
		}
		else
			echo "capitalize_file: {$filename}: Cannot open file\n";
	}

	function special_check($text, $lettre, $next_lettre)
	{
		if (($text[$lettre] == "!" || $text[$lettre] == ".") &&	
							($text[$next_lettre] == " " || 
							$text[$next_lettre] == "\t" || 
							$text[$next_lettre] == "\n") && 
							$text[$next_lettre + 1] >= "a" && 
							$text[$next_lettre + 1] <= "z")
			return (1);
		else
			return (0);
	}

	function capitalize($filename)
	{
		$lettre = 0;
		$next_lettre = $lettre + 1;
		$maj = false;
		$handle = fopen($filename, "r");
		$text = fread($handle, filesize($filename));
		fclose($handle);
		$handle_bis = fopen($filename, "w");
		while (isset($text[$lettre]) && isset($text[$next_lettre + 1]))
		{
			if ($text[$lettre] >= "A" && $text[$lettre] <= "Z" && !$maj) 
				$maj = true;
			if ($text[$lettre] >= "a" && $text[$lettre] <= "z" && !$maj)
			{
				$text[$lettre] = chr(ord($text[$lettre]) - 32);
				$maj = true;
			}
			if (special_check($text, $lettre, $next_lettre))
				$text[$next_lettre + 1] = chr(ord($text[$next_lettre + 1]) - 32);
			++$lettre;
			++$next_lettre;
		}
		fwrite($handle_bis, $text);
		fclose($handle_bis);
	}

	if (check($argv[1]) == "verified")
		capitalize($argv[1]);
?>