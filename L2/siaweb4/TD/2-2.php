<html>
<head>
	<title>Résultat de la recherche</title>
</head>
<body>
	<?php
	function afficherProjets($result) {
		echo '<table>';
		echo '<tr>';
			echo '<td>Titre</td>';
			echo '<td>Editeur</td>';
			echo '<td>Année</td>';
			echo '<td>ANnée de parution</td>';
			echo '<td>Format</td>';
			echo '<td>Prix</td>';
		echo '</tr>';
		while($projet = mysql_fetch_object($result)) {
			echo '<tr>';
				echo '<td>'.$projet->titre.'</td>';
				echo '<td>'.$projet->editeur.'</td>';
				echo '<td>'.$projet->anneeparution.'</td>';
				echo '<td>'.$projet->format.'</td>';
				echo '<td>'.$projet->prix.'</td>';
			echo '</tr>';
		}
		echo '</table>';
	}
	require_once('connect.php');
	$connexion = mysql_pconnect(SERVEUR, NOM, PASSE);
	if(!$connexion) {
		echo "Beurk";
		exit;
	}
	if(!mysql_select_db(BASE, $connexion) {
		echo "BEEUUURK";
		exit;
	}
	
	$titre = (isset($_GET['titre']) ? $_GET['titre'] : null;
	$auteur = (isset($_GET['auteur']) ? $_GET['titre'] : null;
	$formats = (isset($_GET['format']) ? $_GET['format'] : null;
	
	$requete = "select titre, editeur, anneeparution from livre, auteur";
	$condition = '';
	if(isset($titre) || isset($auteur) || isset($formats)) {
		$requete .= ' WHERE ';
	}

	if(!isset($titre)) {
		echo 'Titre obligatoire';
	} else {
		$condition .= " titre LIKE '%".$titre."%'";
	}

	if(!isset($auteur)) {
		if($condition != '') {
			$condition .= ' AND ';
		}
		$condition .= "auteur.na = ecrire.na as na 
						AND livre.na = na 
						AND auteur.nom LIKE '%".$auteur.$"%'";
	}

	if(!isset($format)) {
		$condition .= (
			if($condition != '') {
				$condition .= ' AND ';
			}
		);
		$condFormat = '';
		foreach($formats as $format) {
			if($condFormat != '') {
				$condFormat .= ' OR ';
			}
			$condFormat.= " ANNEEPARUTION = '.$format.'";
		}
		$condition .= $condFormat;
	}

	$requete .= $condition;
	$result = mysql_query($requete);
	
	afficherProjets($result);
