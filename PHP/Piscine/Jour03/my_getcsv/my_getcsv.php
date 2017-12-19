<?php
// my_getcsv.php for  in /home/habi/Piscine1/PHP/Jour03/my_getcsv
//
// Made by HABI Acal
// Login   <habi_a@etna-alternance.net>
//
// Started on  Wed Oct 11 20:18:16 2017 HABI Acal
// Last update Wed Oct 11 20:18:39 2017 HABI Acal
//
function my_while($delimiteur, $end, $tab, $tab_return)
{
	$i = 0;
	$j = 0;
	$k = 0;
	$tmp = "";
	while (isset($tab[$i]))
	{
		if ($tab[$i] == $delimiteur)
		{
			$tab_return[$j][$k] = $tmp;
			$tmp = "";
			++$k;
		}
		elseif ($tab[$i] == $end)
		{
			$tab_return[$j][$k] = $tmp;
			$tmp = "";
			++$j;
			$k = 0;
		}
		else
			$tmp .= $tab[$i];
		++$i;
	}
	return ($tab_return);
}

function my_getcsv($handle, $delimiteur = ",", $end = "\n")
{
	$tab = fread($handle, 1000000);
	$tab_return = array(array());
	$tab_return = my_while($delimiteur, $end, $tab, $tab_return);
	return ($tab_return);
}
?>
