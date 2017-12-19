<?php
// globals.php for  in /home/habi/Piscine1/PHP/micro_shell
//
// Made by HABI Acal
// Login   <habi_a@etna-alternance.net>
//
// Started on  Fri Oct 13 19:36:26 2017 HABI Acal
// Last update Fri Oct 13 19:36:27 2017 HABI Acal
//
$server = $_SERVER;
$pwd = $server['PWD'];
$oldPwd = $server['PWD'];
if (isset ($server['USER']))
	$user = $server['USER'];
else
	$user = "user";
?>
