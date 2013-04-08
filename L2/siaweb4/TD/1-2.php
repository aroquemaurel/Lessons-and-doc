<?php
function operation($pcOperation, $ploperande1, $plOperande2) {
	$return = 0;
	switch($pcOperation) {
		case '+':
			$return = $ploperande1 + $plOperande2;
			break;
		case '-':
			$return = $ploperande1 - $plOperande2;
			break; 
		case '*':
			$return = $ploperande1 * $plOperande2;
			break;
		case '%':
			$return = $ploperande1 % $plOperande2;
			break;
		default:
			echo("Erreur");
	}


	return $return;
}

if( isset($_GET['operande1']) && isset($_GET['operande2']) && isset($_GET['operation'])) {
	echo $_GET['operande1']. ' '.$_GET['operation'].' '.$_GET['operande2'].' = ' . 
		operation($_GET['operation'], $_GET['operande1'}, $_GET['operande2']);
} else {
	echo "Try again";
}
