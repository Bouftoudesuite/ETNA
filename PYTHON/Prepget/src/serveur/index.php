<?php
header('Content-Type: application/json');
require 'vendor/autoload.php';

use Slim\Http\Request;
use Slim\Http\Response;

$app = new \Slim\App();

// Routes

function getPDO() {
	$pdo = new PDO('mysql:dbname=codecamp;host=localhost', 'codecamp', 'jbae123');
	$pdo->setAttribute(PDO::ATTR_ERRMODE, PDO::ERRMODE_EXCEPTION);
	return $pdo;
}

function request($string, $array){
	$res = getPDO()->prepare($string);
	$res->execute($array);
	$result = $res->fetchAll();
	return $result;
}

function check_uid($uid) {
	$array = array(':uid' => $uid);
	$result = request('SELECT ID FROM Utilisateurs WHERE uid = :uid', $array);
	$to_ret = false;

	if (isset($result[0]['ID']))
	{
		$to_ret = true;
	}
	return $to_ret;
}

function check_owner($uid, $name) {	
	$uid_c = request('SELECT uid AS uid 
		FROM Utilisateurs 
		INNER JOIN depot_Utilisateur 
		ON Utilisateurs.ID = ID_utilisateur 
		INNER JOIN depot 
		ON depot.name = :name 
		AND depot.ID = depot_Utilisateur.ID_depot', array(':name' => $name));
	$to_ret = false;

	if ($uid == $uid_c[0]['uid'])
	{
		$to_ret = true;
	}
	return $to_ret;
}

function check_exist($name) {
	$array = array(':name' => $name);
	$req = request('SELECT depot.ID AS dep_ID
		FROM version 
		INNER JOIN depot ON depot.name = :name  
		INNER JOIN version_depot
		ON version_depot.ID_version = version.ID 
		AND version_depot.ID_depot = depot.ID', $array);
	if (!isset($req[0])) 
	{
		$request = request('SELECT ID FROM depot WHERE name = :name', $array);
		if (isset($request[0])){
			$res = getPDO()->prepare('DELETE FROM depot_Utilisateur WHERE ID_depot = :id');
			$res->execute(array(':id' => $request[0]['ID']));
			$res = getPDO()->prepare('DELETE FROM depot WHERE name = :name');
			$res->execute($array);
			rmdir("paquet/".$name."/");
		}
	}
}

$app->get('/api/search/{uid}/{name}/{version}', function ($request, $response, $args) {
	$to_echo = "[{\"Login\" : false}]";
	$uid = 	$args['uid'];
	if (check_uid($uid)){
		$name =  $args['name'];
		$version = $args['version'];
		$array = array('name' => $name, 'version' => $version);

		$result = request('SELECT depot.name AS name_dep 
			FROM version 
			INNER JOIN depot ON depot.name = :name 
			INNER JOIN version_depot ON version.version = :version   
			AND version_depot.ID_version = version.ID 
			AND version_depot.ID_depot = depot.ID', $array);

		$to_echo = "[{\"paquet\": null, \"path\": null, \"version\": null}]";

		if (isset($result[0]))
		{
			$to_echo = "[{\"paquet\": \"" . $result[0]['name_dep'] . "\", \"path\": null, \"version\": " . $version . "}]";
		}
		else 
		{	
			$result = request('SELECT depot.name AS name_dep FROM depot WHERE name LIKE :name', array('name' => "%" . $name . "%"));
			if(isset($result[0]))
			{
				$to_echo = "[{\"paquet\": \"" . $result[0]['name_dep'] . "\", \"path\": null, \"version\": null}]";
			}
		}
	}
	echo $to_echo;
});

$app->get('/api/search/{uid}/{name}', function ($request, $response, $args) {
	$to_echo = "[{\"Login\" : false}]";
	$uid = 	$args['uid'];
	if (check_uid($uid)){
		$name = $args['name'];
		$array = array('name' => "%" . $name . "%");
		$result = request('SELECT version.version AS nb_ver, depot.name AS dep_name
			FROM version 
			INNER JOIN depot ON depot.name LIKE :name
			INNER JOIN version_depot   
			ON version_depot.ID_version = version.ID 
			AND version_depot.ID_depot = depot.ID', $array);
		$to_echo = "[{\"paquet\": null, \"path\": null, \"version\": null}]";

		if (isset($result[0]['nb_ver'])) 
		{
			$to_echo = "[";
			foreach ($result as $result_one_by_one) 
			{
				$to_echo .= "{\"paquet\": \"" . $result_one_by_one['dep_name'] . "\", \"path\": null, \"version\": " . $result_one_by_one['nb_ver']. "}, ";
			}
			$to_echo .= "]";
			$to_echo = preg_replace("/, ]/", "]", $to_echo);
		}
	}
	echo $to_echo;
});

$app->get('/api/download/{uid}/{name}', function ($request, $response, $args) {
	$to_echo = "[{\"Login\" : false}]";
	$uid = 	$args['uid'];
	if (check_uid($uid)){
		$name = $args['name'];
		$to_echo = "[{\"path\": null, \"version\": null}]";
		$array = array('name' => $name);
		$result = request('SELECT version.version AS nb_ver, depot.chemin AS pwd_dep, version.chemin AS pwd_ver
			FROM version 
			INNER JOIN depot ON depot.name = :name
			INNER JOIN version_depot   
			ON version_depot.ID_version = version.ID 
			AND version_depot.ID_depot = depot.ID
			ORDER BY version.version DESC
			LIMIT 1', $array);
		if (isset($result[0]['nb_ver'])) 
		{
			$to_echo = "[{\"path\": \"". $result[0]['pwd_dep'] . $result[0]['pwd_ver'] . "\", \"version\": ". $result[0]['nb_ver'] . "}]";
		}
	}
	echo $to_echo;
});

$app->get('/api/download/{uid}/{name}/{version}', function ($request, $response, $args) {
	$to_echo = "[{\"Login\" : false}]";
	$uid = 	$args['uid'];
	if (check_uid($uid)){
		$name = $args['name'];
		$version = $args['version'];
		$to_echo = "[{\"path\": null, \"version\": null}]";
		$array = array('name' => $name, 'version' => $version);

		$result = request('SELECT depot.chemin AS pwd_dep, version.chemin AS pwd_ver
			FROM version 
			INNER JOIN depot ON depot.name = :name 
			INNER JOIN version_depot ON version.version = :version   
			AND version_depot.ID_version = version.ID 
			AND version_depot.ID_depot = depot.ID', $array);

		if (isset($result[0]))
		{
			$to_echo = "[{\"path\": \"". $result[0]['pwd_dep'] . $result[0]['pwd_ver'] . "\", \"version\": ". $version . "}]";
		}
	}	
	echo $to_echo;
});

$app->get('/api/delete/{uid}/{name}/{version}', function ($request, $response, $args) {
	$uid = $args['uid'];
	$name = $args['name'];
	$version = $args['version'];
	$to_echo = "[{\"delete\": 1}]";
	$array = array('name' => $name, 'version' => $version);
	$id = request('SELECT version.ID AS ID
		FROM version 
		INNER JOIN depot ON depot.name = :name 
		INNER JOIN version_depot ON version.version = :version   
		AND version_depot.ID_version = version.ID 
		AND version_depot.ID_depot = depot.ID', $array);

	if (isset($id[0]) && check_owner($uid, $name))
	{
		$res = getPDO()->prepare('DELETE FROM version_depot WHERE ID_depot = :id');
		$res->execute(array(':id' => $id[0]['ID']));
		$res = getPDO()->prepare('DELETE FROM version_depot 
			WHERE ID_version = :id; 
			DELETE FROM version 
			WHERE ID = :id');
		$res->execute(array(':id' => $id[0]['ID']));
		unlink("paquet/".$name."/v".$version.".tar.gz");
		$to_echo = "[{\"delete\": 0}]";
	}
	check_exist($name);
	echo $to_echo;
});

$app->get('/api/delete/{uid}/{name}', function ($request, $response, $args) {
	$uid = $args['uid'];
	$name = $args['name'];
	$to_echo = "[{\"delete\": 1}]";
	$array = array('name' => $name);

	$id = request('SELECT version.ID AS ver_ID, depot.ID AS dep_ID, version.version AS nb_ver
		FROM version 
		INNER JOIN depot ON depot.name = :name
		INNER JOIN version_depot
		ON version_depot.ID_version = version.ID
		AND version_depot.ID_depot = depot.ID', $array);

	if (isset($id[0]) && check_owner($uid, $name))
	{
		$res = getPDO()->prepare('DELETE FROM version_depot WHERE ID_depot = :id');
		$res->execute(array(':id' => $id[0]['dep_ID']));
		foreach ($id as $ver_ID)
		{
			$res = getPDO()->prepare('DELETE FROM version WHERE ID = :id');
			$res->execute(array(':id' => $ver_ID['ver_ID']));
			unlink("paquet/".$name."/v". $ver_ID['nb_ver'].".tar.gz");
		}
		$to_echo = "[{\"delete\": 0}]";
		check_exist($name);
	}
	echo $to_echo;
});

$app->get('/api/search_depot/{uid}', function ($request, $response, $args) {
	$uid = $args['uid'];
	$to_echo = "[{\"Login\" : false}]";
	$array = array('uid' => $uid);
	$result = request('SELECT depot.name, MAX(version.version) 
		AS nb_ver 
		FROM version 
		INNER JOIN depot 
		INNER JOIN version_depot 
		ON version_depot.ID_version = version.ID 
		AND version_depot.ID_depot = depot.ID 
		INNER JOIN depot_Utilisateur 
		ON depot_Utilisateur.ID_depot = depot.ID 
		INNER JOIN Utilisateurs 
		ON Utilisateurs.ID = depot_Utilisateur.ID_utilisateur 
		AND Utilisateurs.uid = :uid 
		GROUP BY depot.ID', $array);

	if (check_uid($uid))
	{	if (isset($result[0]))
		{
			$to_echo = "[";
			foreach ($result as $result_one_by_one) 
			{
				$to_echo .= "{\"paquet\": \"" . $result_one_by_one['name'] . "\", \"version\": ". $result_one_by_one['nb_ver']. "}, ";
			}
			$to_echo .= "]";
			$to_echo = preg_replace("/, ]/", "]", $to_echo);
		}
		else
		{
			$to_echo = "[{\"none\": 0}]";
		}
	}
	echo $to_echo;
});

$app->post('/api/upload/{uid}/{name}/{version}', function ($request, $response, $args) {
	$uid = $args['uid'];
	$name = $args['name'];
	$version = $args['version'];
	$chemin_depot_db = "public/paquet/".$name;
	$chemin_depot = "/var/www/html/". $chemin_depot_db;
	$chemin_version = "/v".$version.".tar.gz";
	$to_echo = "[{\"Login\" : false}]";
	

	$date = date("Y-m-d H:i:s");
	
	if (check_uid($uid))
	{
		$to_echo = "[{\"paquet\": false, \"insert\": false}]";
		if (!is_dir($chemin_depot))
		{
			mkdir($chemin_depot, 0777, true);
			if (move_uploaded_file($_FILES['file']['tmp_name'], $chemin_depot . $chemin_version))
			{
				$res = getPDO()->prepare('INSERT INTO `depot` (`name`, `Date_creation`, `Date_modification`, `chemin`, `Image`) VALUES (:name, NOW(), NOW(), :chemin, :image)');
				$res->execute(array(':name' => $name, ':chemin' => $chemin_depot_db));
				$res = getPDO()->prepare('INSERT INTO `version` (`version`, `chemin`, `Date_creation`, `Date_modification`) VALUES (:version, :chemin, NOW(), NOW())');
				$res->execute(array(':version' => $version, ':chemin' => $chemin_version));
				
				$ids = request('SELECT MAX(depot.ID) as ID_dep, MAX(version.ID) as ID_ver FROM depot INNER JOIN version', array());
				$ids_bis = request('SELECT ID FROM Utilisateurs WHERE :uid = uid', array(':uid' => $uid));
				
				$res = getPDO()->prepare('INSERT INTO `version_depot` VALUES (:ID_ver, :ID_dep)');
				$res->execute(array(':ID_dep' => $ids[0]['ID_dep'], ':ID_ver' => $ids[0]['ID_ver']));
				$res = getPDO()->prepare('INSERT INTO `depot_Utilisateur` VALUES (:ID_dep, :ID_user)');
				$res->execute(array(':ID_dep' => $ids[0]['ID_dep'], ':ID_user' => $ids_bis[0]['ID']));
				$to_echo = "[{\"paquet\": true, \"insert\": true}]";
			}
		}
		else
		{
			if(!file_exists($chemin_depot . $chemin_version))
			{
				if (move_uploaded_file($_FILES['file']['tmp_name'], $chemin_depot . $chemin_version))
				{
					$res = getPDO()->prepare('INSERT INTO `version` (`version`, `chemin`, `Date_creation`, `Date_modification`) VALUES (:version, :chemin, NOW(), NOW())');
					$res->execute(array(':version' => $version, ':chemin' => $chemin_version));
					$ids = request('SELECT depot.ID as ID_dep, MAX(version.ID) as ID_ver FROM depot INNER JOIN version ON depot.name = :name', array(":name" => $name));
					$res = getPDO()->prepare('INSERT INTO `version_depot` VALUES (:ID_ver, :ID_dep)');
					$res->execute(array(':ID_dep' => $ids[0]['ID_dep'], ':ID_ver' => $ids[0]['ID_ver']));
					$to_echo = "[{\"paquet\": false, \"insert\": true}]";
				}
			}
			else
			{
				$to_echo = "[{\"version\": false}]";
			}
		}
		echo $to_echo;
	}
});

$app->get('/api/search_user/{name}', function ($request, $response, $args) {
	$name = $args['name'];
	$to_echo = "[{\"exist\": false}]";

	$result = request('SELECT Prenom
		FROM Utilisateurs 
		WHERE Prenom = :name', array(':name' => $name));
	if (isset($result[0]['Prenom']) && $result[0]['Prenom'] != "NULL")
	{
		$to_echo = "[{\"exist\": true}]";
	}
	echo $to_echo;
});

$app->get('/api/create/{uid}/{name}/{mdp}', function ($request, $response, $args) {
	$uid = $args['uid'];
	$name = $args['name'];
	$mdp = $args['mdp'];
	$to_echo = "[{\"uuid\": null}]";

	$result = request('SELECT ID, Prenom, mdp, uid 
		FROM Utilisateurs 
		WHERE Prenom = :name', array(':name' => $name));

	if (isset($result[0]['ID']) && $name != "NULL"){
		if($result[0]['Prenom'] == $name && $result[0]['mdp'] == $mdp){
			$uid = ($uid != $result[0]['uid']) ? uniqid() : $uid;
			$to_echo = "[{\"uuid\": \"" . $uid . "\"}]";
			$res = getPDO()->prepare('UPDATE Utilisateurs SET uid = :uid WHERE Prenom = :login');
			$res->execute(array(':login' => $name, ':uid' => $uid));
		}
	}
	elseif ($uid == "NULL" && (!isset($result[0]['ID']) || ($name == "NULL" && $mdp == "NULL")))
	{
		$uid = uniqid();
		$uid = $name . $uid;
		$to_echo = "[{\"uuid\": \"" . $uid . "\"}]";
		$res = getPDO()->prepare('INSERT INTO Utilisateurs (Prenom, mdp, uid, Date_creation) VALUES (:login, :mdp, :uuid, NOW())');
		$res->execute(array(':login' => $name, ':mdp' => $mdp, ':uuid' => $uid));
	}
	echo $to_echo;
});

$app->get('/api/search_uid/{uid}', function ($request, $response, $args) {
	$uid = $args['uid'];
	$to_echo = "[{\"uuid\": false}]";
	if (check_uid($uid))
	{
		$to_echo = "[{\"uuid\": true}]";
	}
	echo $to_echo;
});

$app->post('/api/connect_application/{login}/{password}', function ($request, $response, $args) {
	$login = $args['login'];
	$password = $args['password'];
	$password = hash('sha512', $password);
	$to_echo = json_encode(array('uuid' => 'false'));
	$SQLogin = getPDO()->prepare("SELECT uid FROM `Utilisateurs` WHERE `Prenom` = :login AND `mdp` = :password");
	$SQLogin->execute(array(':login' => $login, ':password' => $password));
	$ok = $SQLogin->fetch();
	if ($ok != false)
	{
		$to_echo = json_encode(array('uuid' => $ok['uid']));
	}
	echo $to_echo;
});

$app->run();