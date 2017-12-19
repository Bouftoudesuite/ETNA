<?php
// function_bis.php for  in /home/habi/Piscine1/PHP/micro_shell
<<<<<<< HEAD
//
// Made by HABI Acal
// Login   <habi_a@etna-alternance.net>
//
// Started on  Fri Oct 13 20:59:19 2017 HABI Acal
// Last update Fri Oct 13 20:59:19 2017 HABI Acal
//
function cat_php($params)
{
	$i = 0;
	preg_match_all('/[\S]+/', $params, $matches);
	if ($params == "")
		echo "cat: Invalid arguments\n";
	while (isset($matches[0][$i]))
	{
		if (check_path("cat", $matches[0][$i], false) == "verified")
		{
			$filename = $matches[0][$i];
			$handle = fopen($matches[0][$i], "r");
			$text = fread($handle, filesize($matches[0][$i]));
			echo "$text" . "\n";
			fclose($handle);
		}
		++$i;
	}
}

function env_php()
{
	global $server;
	$i = 0;
	$keys = array_keys($server);
	while (isset($keys[$i]))
	{
		if ($keys[$i] == "argv")
			echo $keys[$i] . "=" . $server[$keys[$i]][0] . "\n";
		else
			echo $keys[$i] . "=" . $server[$keys[$i]] . "\n";
		++$i;
	}
}

function setenv_php($params)
{
	global $server;
	preg_match_all('/[\S]+/', $params, $matches);
	if (isset($matches[0][1]) && !isset($matches[0][2]))
		$server[$matches[0][0]] = $matches[0][1];
	else
		echo "setenv: Invalid arguments\n";
}

function unsetenv_php($params)
{
	global $server;
	preg_match_all('/[\S]+/', $params, $matches);
	if (isset($matches[0][0]) && !isset($matches[0][1]))
		unset($server[$matches[0][0]]);
	else
		echo "unsetenv: Invalid arguments\n";
}
?>
=======
// 
// Made by HABI Acal
// Login   <habi_a@etna-alternance.net>
// 
// Started on  Fri Oct 13 20:59:19 2017 HABI Acal
// Last update Fri Oct 13 20:59:19 2017 HABI Acal
//
	function cat_php($params)
	{
		$i = 0;
		preg_match_all('/[\S]+/', $params, $matches);
		if ($params == "")
			echo "cat: Invalid arguments\n";
		while (isset($matches[0][$i]))
		{
			if (check_path("cat", $matches[0][$i], false) == "verified")
			{
				$filename = $matches[0][$i];
				$handle = fopen($matches[0][$i], "r");
				$text = fread($handle, filesize($matches[0][$i]));
				echo "$text" . "\n";
				fclose($handle);
			}
			++$i;
		}
	}

	function env_php()
	{
		global $server;
		$i = 0;
		$keys = array_keys($server);
		while (isset($keys[$i]))
		{
			if ($keys[$i] == "argv")
				echo $keys[$i] . "=" . $server[$keys[$i]][0] . "\n";
			else
				echo $keys[$i] . "=" . $server[$keys[$i]] . "\n";
			++$i;
		}
	}

	function setenv_php($params)
	{
		global $server;
		preg_match_all('/[\S]+/', $params, $matches);
		if (isset($matches[0][1]) && !isset($matches[0][2])) 
			$server[$matches[0][0]] = $matches[0][1];
		else
			echo "setenv: Invalid arguments\n";
	}

	function unsetenv_php($params)
	{
		global $server;
		preg_match_all('/[\S]+/', $params, $matches);
		if (isset($matches[0][0]) && !isset($matches[0][1])) 
			unset($server[$matches[0][0]]);
		else
			echo "unsetenv: Invalid arguments\n";
	}
?>
>>>>>>> b252211eb32bfffafc97433c7117824224e54952
