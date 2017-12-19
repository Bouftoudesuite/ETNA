#!/usr/bin/env php
<?php
// count_word_sort.php for  in /home/habi/Piscine1/PHP/Jour04/count_word_sort
// 
// Made by HABI Acal
// Login   <habi_a@etna-alternance.net>
// 
// Started on  Thu Oct 12 09:08:51 2017 HABI Acal
// Last update Thu Oct 12 09:08:52 2017 HABI Acal
//
	function check($filename)
	{
		if (!file_exists($filename))
	    	echo "count_word_sort: {$filename}: No such file or directory\n";
	    elseif (is_dir($filename))
	    	echo "count_word_sort: {$filename}: Is a directory\n";
		elseif (!is_readable($filename))
		    echo "count_word_sort: {$filename}: Permission denied\n";
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
			echo "count_word_sort: {$filename}: Cannot open file\n";
	}

	function my_str_word_count_and_array($text)
	{
		$i = 0;
		$k = 0;
		$tmp = "";
		$tab_return = [];
		while (isset($text[$i]))
		{
			if ($text[$i] == "." || $text[$i] == "\n" ||
									$text[$i] == "\t" || 
									$text[$i] == "," ||
									$text[$i] == " ")
			{
				if ($tmp)
				{
					$tab_return[$k] = $tmp;
					$tmp = "";
					++$k;
				}
			}
			else
				$tmp .= $text[$i];
			++$i;
		}
		return ($tab_return);
	}

	function remove_doublon($tab, &$repere)
	{
		$i = 0;
		$j = 1;
		$new_tab = [];
		$nombre = 1;
		$compteur = 1;
		while (isset($tab[$i]))  
		{
			while (isset($tab[$j]))
			{
    			if (strcmp($tab[$i], $tab[$j]) == 0)
    			{
    				$tab[$j] = $nombre;
    				++$nombre;
    				++$compteur;
    			}
    			++$j;
			}
			$repere[$i] = $compteur;
			++$i;
			$j = $i + 1;
			$compteur = 1;
		}
		return ($tab);
	}

	function new_tab($tab, &$repere)
	{
		$i = 0;
		$j = 0;
		$new_tab = [];
		while (isset($tab[$i]))
		{
			if (!($tab[$i] >= "0" && $tab[$i] <= "9999"))
			{
				$new_tab[$j] = $tab[$i];
				$repere[$j] = $repere[$i];
				++$j;
			}
			++$i;
		}
		return ($new_tab);
	}

	function buble($tab)
	{
		$i = 0;
	    $j = 0;
	    $vide = "";
	    $little = 0;
	    while (isset($tab[$j]))
	    {
	        while (isset($tab[$i]))
	    	{
	      	    if (strcmp($tab[$little], $tab[$i]) > 0)
	                $little = $i;
	      	    $i++;
	    	}
	    	$vide = $tab[$j];
			$tab[$j] = $tab[$little];
			$tab[$little] = $vide;
	    	$j++;
	    	$little = $j;
	    	$i = $little;
	    }
	    return ($tab);
	}

	$filename = $argv[1];
	if (check($filename) == "verified")
	{
		$handle = fopen($filename, "r");
		$text = fread($handle, filesize($filename));
		fclose($handle);
		$repere = [];
		$tab = [];
		$tab = my_str_word_count_and_array($text);
		$tab = buble($tab);
		$tab = remove_doublon($tab, $repere);
		$tab = new_tab($tab, $repere);
		$i = 0;
		while (isset($tab[$i]))
		{
	    	echo $tab[$i] . " => " . $repere[$i] . "\n";
	    	++$i;
		}
	}
?>