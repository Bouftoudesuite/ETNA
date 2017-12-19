<?php
// spe_functions.php for  in /home/habi/Piscine1/PHP/micro_shell
//
// Made by HABI Acal
// Login   <habi_a@etna-alternance.net>
//
// Started on  Fri Oct 13 11:07:01 2017 HABI Acal
// Last update Fri Oct 13 11:07:09 2017 HABI Acal
//
function str_replace_first($from, $to, $subject)
{
	$from = '/'. preg_quote($from, '/') . '/';
	return preg_replace($from, $to, $subject, 1);
}

function bubble($tab)
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

function my_print_ls($tab, $path)
{
	$i = 0;
	while (isset($tab[$i]))
	{
		if (is_dir($path .'/'. $tab[$i]) && $tab[$i][0] != '.' && $tab[$i][0] != '..')
			echo $tab[$i] . "/" . "\n";
		elseif (is_file($path .'/'. $tab[$i]) && is_executable($path .'/'. $tab[$i]) && $tab[$i][0] != '.' && $tab[$i][0] != '..')
			echo $tab[$i] . "*" . "\n";
		elseif (is_file($path .'/'. $tab[$i]) && $tab[$i][0] != '.' && $tab[$i][0] != '..')
			echo $tab[$i] . "\n";
		elseif (is_link($path .'/'. $tab[$i]) && $tab[$i][0] != '.' && $tab[$i][0] != '..')
			echo $tab[$i] . "@" . "\n";
		++$i;
	}
}
