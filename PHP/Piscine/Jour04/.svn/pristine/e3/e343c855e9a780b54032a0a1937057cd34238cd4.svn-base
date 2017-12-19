#!/usr/bin/env php
<?php
// word.php for  in /home/habi/Piscine1/PHP/Jour04/word
// 
// Made by HABI Acal
// Login   <habi_a@etna-alternance.net>
// 
// Started on  Thu Oct 12 14:20:40 2017 HABI Acal
// Last update Thu Oct 12 14:20:40 2017 HABI Acal
//
	$i = 0;
	$matches = [];
	if (preg_match_all('/[\w]+/', $argv[1], $matches))
	{
		while (isset($matches[0][$i]))
		{
			echo "{$matches[0][$i]}\n";
			++$i;
		}
	}
?>