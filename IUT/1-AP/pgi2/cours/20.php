<?php
$\$$i = 1;
if($\$$file)
{
    while(!feof($\$$file)) {
        $\$$line = fgets($\$$file);
        echo 'Ligne '.$\$$i.' : '.$\$$line'';
        $\$$i++;
    }
    fclose($\$$file);
}
?>
