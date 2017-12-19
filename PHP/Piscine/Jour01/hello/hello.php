#!/usr/bin/env php
<?php
// hello.php for  in /home/habi/Piscine1/PHP/Jour01/hello
// 
// Made by HABI Acal
// Login   <habi_a@etna-alternance.net>
// 
// Started on  Mon Oct  9 10:17:43 2017 HABI Acal
// Last update Mon Oct  9 10:17:52 2017 HABI Acal
//
function hello($str = "")
{
	if ($str)
	{
		echo "Hello " . "$str" . " !\n";
	}
	else
	{
		echo "Hello " . "world !" . "\n";
	}
}
?>
