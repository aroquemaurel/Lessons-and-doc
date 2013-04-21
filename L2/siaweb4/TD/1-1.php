
	<?php
function multiplication($piValeur) {
echo '<table>';
		echo 'Table de multiplication par '.$piValeur.'<br/>';
		echo '<tr>';
		echo '<td>'.$piValeur.'*</td>'; 
		for($i=0 ; $i < 9 ; ++$i) {
			echo '<td>'.$i.'</td>';
		}
		echo '</tr>';
		echo '<tr>';
		echo '<td>=</td>';
		for($j=0 ; $j < 9 ; ++$j) {
			echo '<td>'.$i*$piValeur.'</td>';
		}
		echo '</tr>';
echo '</table>';
}
multiplication(42);
	?>
