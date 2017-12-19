#!/usr/bin/env php
<?php
// microshell.php for  in /home/habi/Piscine1/PHP/micro_shell
// 
// Made by HABI Acal
// Login   <habi_a@etna-alternance.net>
// 
// Started on  Fri Oct 13 13:36:07 2017 HABI Acal
// Last update Fri Oct 13 13:36:46 2017 HABI Acal
//
	require_once("init.php");
	require_once("check.php");
	require_once("function.php");
	require_once("globals.php");
	require_once("function_bis.php");
	require_once("spe_functions.php");

	$boolExit = false;
	if ($handle = fopen("php://stdin", "r"))
	{
		clear_php();
		cat_php("draw.txt");
		echo "Hellooooo !   :)\n\n";
		while (!$boolExit) 
		{
			$emptyCommand = false;
			my_shell();
			$command = fgets($handle);
			$command = ltrim($command);
			preg_match_all('/[\S]+/', $command, $first);
			preg_match_all('/[ ][\s\S][^\n]*/', $command, $after);
			if (isset($first[0][0]))
			{
				$command = $first[0][0];
				$command = ltrim($command);
			}
			else
				$emptyCommand = true;
			if (isset($after[0][0]))
			{
				$params = $after[0][0];
				$params = ltrim($params);
				$params = rtrim($params);
			}
			else
				$params = "";
			if ($command == "exit")
			{
				$boolExit = true;
				echo "\nSee you soon.... -_- \n\n";
			}
			elseif (!check_command($command) && !$emptyCommand)
				echo "{$command}: Command not found\n";
			elseif (!$emptyCommand)
			{
				$my_command = "$command" . "_php";
				$my_command($params);
			}
		}
		fclose($handle);
	}
?>