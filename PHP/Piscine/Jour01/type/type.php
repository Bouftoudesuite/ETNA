#!/usr/bin/env php
<?php
// type.php for  in /home/habi/Piscine1/PHP/Jour01/type
//
// Made by HABI Acal
// Login   <habi_a@etna-alternance.net>
//
// Started on  Mon Oct  9 18:24:26 2017 HABI Acal
// Last update Mon Oct  9 18:24:30 2017 HABI Acal
//
$length = 0;

while (isset($argv[1][$length]))
{
	++$length;
}
if ($argv[2] == "int")
{
	$int = (int)$argv[1];
	echo "{$argv[2]}({$int})\n";
}
if ($argv[2] == "bool")
{
	$bool = (bool)$argv[1];
	if ($bool == 1)
		$bool = "true";
	else
		$bool = "false";
	echo "{$argv[2]}({$bool})\n";
}
if ($argv[2] == "float")
{
	$float = (float)$argv[1];
	echo "{$argv[2]}({$float})\n";
}
if ($argv[2] == "string")
	echo "{$argv[2]}({$length}) \"{$argv[1]}\"\n";
?>
