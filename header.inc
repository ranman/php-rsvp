<?php
   require_once('config.inc'); 
   global $why;
   global $title;
   global $where;
   global $when;
   global $how;
   global $notes;
?>

<table border=0>
   <tr>
      <td width='922'>
<table border='1' width='100%'>
  <tr bgcolor='#ACC0CA'>
    <td width='100%'><center><font color='black' size='18'><?php echo $title; ?></font></center></td>
  </tr>
  <tr bgcolor=#EEEEEE>
    <td width='100%'><b>Why:</b> <?php echo $why; ?></td>
  </tr>
  <tr bgcolor=#EEEEEE>
    <td width='100%'><b>Where:</b> <?php echo $where; ?></td>
  </tr>
  <tr bgcolor=#EEEEEE>
    <td width='100%'><b>When:</b> <?php echo $when; ?></td>
  </tr>
  <tr bgcolor=#EEEEEE>
    <td width='100%'><b>How:</b> <?php echo $how; ?></a></td>
  </tr>
  <tr bgcolor=#EEEEEE>
    <td width='100%'><b>Notes:</b> <?php echo $notes; ?></td>
  </tr>
</table>
