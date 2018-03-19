<?php

$pdo = new PDO('mysql:dbname=codecamp;host=localhost', 'codecamp', 'jbae123');
$pdo->setAttribute(PDO::ATTR_ERRMODE, PDO::ERRMODE_EXCEPTION);
$req = $pdo->prepare('SELECT depot.ID, depot.name, depot.chemin, MAX(version.version) 
					  AS nb_ver 
					  FROM version 
					  INNER JOIN depot 
					  INNER JOIN version_depot 
					  ON version_depot.ID_version = version.ID 
					  AND version_depot.ID_depot = depot.ID 
					  GROUP BY depot.ID');
$req->execute();
$result = $req->fetchAll();
$terminal = "zenity --list   --title=\"Liste de tous les paquets\" --column=\"N° du paquet\" --column=\"Nom du paquet\" --column=\"Version du paquet\" --height 400 --width 450 ";
$i = 0;
foreach ($result as $results) 
{
	$terminal .= $result[$i]['ID'] . " " . $result[$i]['name'] . " " . $result[$i]['nb_ver'] . "    ";
	$i++;
}

$exec = exec($terminal);
$i = 0;
	foreach ($result as $results) 
	{
		if ($result[$i]['ID'] == $exec)
		{
			$chemin = $result[$i]['chemin'] . "/v" . $result[$i]['nb_ver'] . ".tar.gz";
			break;
		}
		$i++;
	}
	$url = "http://172.16.2.76/" . $chemin;
	file_put_contents($result[$i]['name'] .".tar.gz", fopen($url , 'r'));
	$decompress = exec("tar -xzf ". $result[$i]['name'] .".tar.gz");
	$command = "sh ". $result[$i]['name'] . "/setup.sh";
	$execute_install = shell_exec($command);
	echo $execute_install;
	$remove_install = "rm -r ". $result[$i]['name'] .".tar.gz ". $result[$i]['name'] ."/";
	$execute_remove_install = shell_exec($remove_install);
	echo $execute_remove_install;
	
?>