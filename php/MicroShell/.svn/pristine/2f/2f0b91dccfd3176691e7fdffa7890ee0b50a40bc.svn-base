<?php
// function.php for  in /home/habi/Piscine1/PHP/micro_shell
// 
// Made by HABI Acal
// Login   <habi_a@etna-alternance.net>
// 
// Started on  Thu Oct 12 23:07:26 2017 HABI Acal
// Last update Thu Oct 12 23:07:27 2017 HABI Acal
//
	function clear_php()
	{
		echo "\033c";
	}

	function echo_php($params)
	{
		$params = str_replace("\"", "\0", $params);
		$params = str_replace("'", "\0", $params);
		$params = str_replace("\\", "\0", $params);
		$params = preg_replace('/[\s][\s]+/', " ", $params);
		if ($params != "\n")
			echo "{$params}\n";
		else
			echo "\n";
	}

	function pwd_php()
	{
		global $pwd;
		echo "$pwd" . "\n";
	}

	function cd_php($path)
	{
		global $pwd;
		global $oldPwd;
		global $server;
		if ($path == "" || $path == "\n")
		{
			$pwd = $server['HOME']; 
			chdir($pwd);
		}
		elseif ($path == "..")
		{
			$prevPwd = preg_replace('/[\/][\w%.#%&*\-]+$/', "", $pwd);
			$oldPwd = $pwd;
			$pwd = $prevPwd;
			chdir($pwd);
		}
		elseif ($path == "-")
		{
			chdir($pwd);
			$swap = $pwd;
			$pwd = $oldPwd;
			$oldPwd = $swap;
		}
		elseif ($path[0] == "/")
		{
			chdir($path);
			$oldPwd = $pwd;
			$pwd = $path;	
		}
		elseif (check_path_cd("cd", $path, true) == "verified")
		{
			chdir($path);
			$oldPwd = $pwd;
			$pwd .= "/" . $path;
		}
	}

	function ls_php($path)
	{
		$i = 0;
		global $pwd;
		if ($path == "") 
			$path = $pwd;
		elseif ($path == "\n")
			$path = $pwd;
		elseif ($path == "..")
			$path = preg_replace('/[\/][\w%.#%&*\-]+$/', "", $pwd);
		if (check_path("ls", $path, true) == "verified")
		{
			$myDirectory = opendir($path);
			while($entry = @readdir($myDirectory))
			{
			    	$tab[$i] = $entry;
			    	++$i;
	 		}
	 		$tab = bubble($tab);
  			my_print_ls($tab, $path);
  			closedir($myDirectory);
	 	}
	}
?>