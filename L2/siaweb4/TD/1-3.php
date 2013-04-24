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

$resultat = mysql_query('select ne, nome from equipe');
echo '<form method="post" action="traitement.php">';
	echo '<select name="equipe">';
	while($equipe = mysql_fetch_object($resultat)) {
		echo '<option value="'.$equipe->ne.'">'.$equipe->nome.'</option>';
	}
	echo '</select>';
	echo '<input type="submit" />
echo '</form>';
