<?php
require_once('connect.php');

if(!($connnexion = mysql_pconnect(SERVEUR,NOM,PASSE))) {
	echo "Beurk";
	exit;
}

if(!mysql_select_db(BASE,$connexion)) {
	echo "beurk bis";
	exit;
}
$ne = (isset($_POST['ne'])) ? $_POST['ne'] : '';
$resultat = mysql_query("select np, nomp from projet where ne='".$ne."'");
echo '<ul>';
while($projet = mysql_fetch_object($resultat)) {
	echo '<li>'.$projet->ne.': '.$projet->nom.'</li>';
}
