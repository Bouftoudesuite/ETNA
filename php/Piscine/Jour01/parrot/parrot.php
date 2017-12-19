#!/usr/bin/env php
<?php
// parrot.php for  in /home/habi/Piscine1/PHP/Jour01/parrot
// 
// Made by HABI Acal
// Login   <habi_a@etna-alternance.net>
// 
// Started on  Mon Oct  9 15:58:06 2017 HABI Acal
// Last update Mon Oct  9 15:58:07 2017 HABI Acal
//
function human($str = "")
{
	global $g_str;
	global $count;

	$g_str = "$g_str" . "$str";
	++$count;
	if ($count)
	{
		$g_str = "$g_str" . " ... ";
	}
}

function parrot()
{
	global $g_str;
	global $count;

	if ($g_str && !$count) 
	{
		echo "$g_str" . "Coco ..." . "\n";
		$g_str = NULL;
	}
	elseif ($g_str && $count) 
	{
		echo "$g_str" . "Coco ..." . "\n";
		$g_str = NULL;
		$count = 0;
	}
	else
	{
		echo "Coco ?" . "\n";
	}
}
?>