#!/usr/bin/env php
<?php
// login.php for  in /home/habi/Piscine1/PHP/Jour03/login
//
// Made by HABI Acal
// Login   <habi_a@etna-alternance.net>
//
// Started on  Wed Oct 11 19:03:46 2017 HABI Acal
// Last update Wed Oct 11 19:03:48 2017 HABI Acal
//
function check_length_login($argv, $i)
{
	$k = 0;
	while (isset($argv[$i][$k]))
		++$k;
	if ($k >= 3 && $k <= 8)
		return (true);
	else
		return (false);
}

function alphanum($argv, $i)
{
	$k = 0;
	while (isset($argv[$i][$k]))
	{
		if (!(($argv[$i][$k] >= "a" && $argv[$i][$k] <= "z") ||
		($argv[$i][$k] >= "0" && $argv[$i][$k] <= "9") ||
		$argv[$i][$k] == "-" || $argv[$i][$k] == "_"))
			return (false);
		++$k;
	}
	return (true);
}

function length($argv, $i)
{
	$k = 0;
	while (isset($argv[$i][$k]))
		++$k;
	return ($k);
}

$i = 1;
$len = 0;
while ($i < $argc)
{
	$len = length($argv, $i);
	if (!check_length_login($argv, $i))
		echo "{$argv[$i]}: ko\n";
	elseif (!alphanum($argv, $i))
		echo "{$argv[$i]}: ko\n";
	elseif ($argv[$i][0] == "-")
		echo "{$argv[$i]}: ko\n";
	elseif ($argv[$i][$len - 2] != "_")
		echo "{$argv[$i]}: ko\n";
	else
		echo "{$argv[$i]}: ok\n";
	++$i;
}
?>
