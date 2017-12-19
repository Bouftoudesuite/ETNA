<?php
<<<<<<< HEAD

// check.php for  in /home/habi/Piscine1/PHP/micro_shell
//
// Made by HABI Acal
// Login   <habi_a@etna-alternance.net>
//
=======
// check.php for  in /home/habi/Piscine1/PHP/micro_shell
// 
// Made by HABI Acal
// Login   <habi_a@etna-alternance.net>
// 
>>>>>>> b252211eb32bfffafc97433c7117824224e54952
// Started on  Thu Oct 12 22:21:17 2017 HABI Acal
// Last update Thu Oct 12 22:21:18 2017 HABI Acal
//

<<<<<<< HEAD
function check_path($command, $path, $directory)
{
	if (!file_exists($path))
		echo "{$command}: {$path}: No such file or directory\n";
	elseif (!is_dir($path) && $directory)
		echo "{$command}: {$path}: Not a directory\n";
	elseif (is_dir($path) && !$directory)
		echo "{$command}: {$path}: Is a directory\n";
	elseif (!is_readable($path))
		echo "{$command}: {$path}: Not a directory\n";
	elseif ($handle = fopen($path, "r"))
	{
		if (!(filesize($path)))
			echo "";
		else
		{
			$content = fread($handle, filesize($path));
			fclose($handle);
			return ("verified");
		}
	}
	else
		echo "{$command}: {$path}: Cannot open file\n";
}

function check_path_cd($command, $path, $directory)
{
	global $pwd;
	if (!file_exists($pwd . "/" . $path))
		echo "{$command}: {$path}: No such file or directory\n";
	elseif (!is_dir($pwd . "/" . $path) && $directory)
		echo "{$command}: {$path}: Not a directory\n";
	elseif (is_dir($pwd . "/" . $path) && !$directory)
		echo "{$command}: {$path}: Is a directory\n";
	elseif (!is_readable($pwd . "/" . $path))
		echo "{$command}: {$path}: Not a directory\n";
	elseif ($handle = fopen($path, "r"))
	{
		if (!(filesize($path)))
			echo "";
		else
		{
			$content = fread($handle, filesize($path));
			fclose($handle);
			return ("verified");
		}
	}
	else
		echo "{$command}: {$path}: Cannot open file\n";
}

function check_command($command)
{
	if ($command == "clear")
		return (true);
	elseif ($command == "echo")
		return (true);
	elseif ($command == "pwd")
		return (true);
	elseif ($command == "ls")
		return (true);
	elseif ($command == "cd")
		return (true);
	elseif ($command == "cat")
		return (true);
	elseif ($command == "env")
		return (true);
	elseif ($command == "setenv")
		return (true);
	elseif ($command == "unsetenv")
		return (true);
	else
		return(false);
}
?>
=======
	function check_path($command, $path, $directory)
	{
		if (!file_exists($path))
	    	echo "{$command}: {$path}: No such file or directory\n";
	    elseif (!is_dir($path) && $directory)
	    	echo "{$command}: {$path}: Not a directory\n";
	    elseif (is_dir($path) && !$directory)
	    	echo "{$command}: {$path}: Is a directory\n";
		elseif (!is_readable($path))
		    echo "{$command}: {$path}: Not a directory\n";
		elseif ($handle = fopen($path, "r"))
		{
			if (!(filesize($path)))
				echo "";
			else
			{	
				$content = fread($handle, filesize($path));
				fclose($handle);
				return ("verified");
			}
		}
		else
			echo "{$command}: {$path}: Cannot open file\n";
	}

	function check_path_cd($command, $path, $directory)
	{
		global $pwd;
		if (!file_exists($pwd . "/" . $path))
	    	echo "{$command}: {$path}: No such file or directory\n";
	    elseif (!is_dir($pwd . "/" . $path) && $directory)
	    	echo "{$command}: {$path}: Not a directory\n";
	    elseif (is_dir($pwd . "/" . $path) && !$directory)
	    	echo "{$command}: {$path}: Is a directory\n";
		elseif (!is_readable($pwd . "/" . $path))
		    echo "{$command}: {$path}: Not a directory\n";
		elseif ($handle = fopen($path, "r"))
		{
			if (!(filesize($path)))
				echo "";
			else
			{	
				$content = fread($handle, filesize($path));
				fclose($handle);
				return ("verified");
			}
		}
		else
			echo "{$command}: {$path}: Cannot open file\n";
	}

	function check_command($command)
	{
		if ($command == "clear")
			return (true);
		elseif ($command == "echo")
			return (true);
		elseif ($command == "pwd")
			return (true);
		elseif ($command == "ls")
			return (true);
		elseif ($command == "cd")
			return (true);
		elseif ($command == "cat")
			return (true);
		elseif ($command == "env")
			return (true);
		elseif ($command == "setenv")
			return (true);
		elseif ($command == "unsetenv")
			return (true);
		else
			return(false);
	}
?>
>>>>>>> b252211eb32bfffafc97433c7117824224e54952
