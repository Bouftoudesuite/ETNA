#!/usr/bin/env php
<?php
// counter.php for  in /home/habi/Piscine1/PHP/Jour01/counter
// 
// Made by HABI Acal
// Login   <habi_a@etna-alternance.net>
// 
// Started on  Mon Oct  9 14:45:54 2017 HABI Acal
// Last update Mon Oct  9 14:48:31 2017 HABI Acal
//
function counter($nb = "")
{
	static $count = 0;

	if (!$nb)
	{
		return ($count);
	}
	else
	{
		$count += $nb;
	}
}
?>
