<table>
	<?php
		$valeur = 9;
		echo 'Table de multiplication par '.$valeur.'<br/>';
		echo '<tr>';
		echo '<td>'.$valeur.'*</td>'; 
		for($i=0 ; $i < 9 ; ++$i) {
			echo '<td>'.$i.'</td>';
		}
		echo '</tr>';
		echo '<tr>';
		echo '<td>=</td>';
		for($j=0 ; $j < 9 ; ++$j) {
			echo '<td>'.$i*$valeur.'</td>';
		}
		echo '</tr>';
	?>
</table>
