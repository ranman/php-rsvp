<?php
require_once('config.inc');
global $contact;
?>

<table border='1'>
	<tr>
		<td valign='top' width='300' bgcolor='#ACC0CA'>
			<table>
				<tr>
					<td><b><u><font color='green'>People Attending</font></u></b></td>
					<?php
				$sql_foot = "SELECT * FROM rsvp WHERE rsvp='Y'";
				$result_foot = mysql_query($sql_foot);
				while ($row = mysql_fetch_array ($result_foot)) {
					$name = stripslashes($row["name"]);
					$email = stripslashes($row["email"]);
					$comments = stripslashes($row["comments"]);
					printf("<tr><td><b>$name</b><br><i>$comments</i></td></tr>");
				}
				?>
			</table>
		</td>
		<td valign='top' width='300' bgcolor=#EEEEEE>
			<table>
				<tr>
					<td><b><u><font color='Red'>People Not Attending</font></u></b></td>
					<?php
				$sql_foot = "SELECT * FROM rsvp WHERE rsvp='N'";
				$result_foot = mysql_query($sql_foot);
				while ($row = mysql_fetch_array($result_foot)) {
					$name = stripslashes($row["name"]);
					$email = stripslashes($row["email"]);
					$comments = stripslashes($row["comments"]);
					printf("<tr><td><b>$name</b><br><i>$comments</i></td></tr>");
				}
				?>
			</table>
		</td>
		<td valign='top' width='300' bgcolor='#ACC0CA'>
			<table>
				<tr>
					<td><b><u><font color='Blue'>People Not Yet Responded</font></u></b></td>
					<?php
				$sql = "SELECT * FROM rsvp WHERE rsvp !='Y' AND rsvp !='N'";
				$result = mysql_query($sql);
				while ($row = mysql_fetch_array ($result)) {
					$name = stripslashes($row["name"]);
					$email = stripslashes($row["email"]);
					$comments = stripslashes($row["comments"]);
					printf("<tr><td><b>$name</b><br><i>$comments</i></td></tr>");
				}
				?>
			</table>
		</td>
	</tr>
</table>
<table border='1'>
	<tr>
		<td width='912' height='24' bgcolor='#ACC0CA'><center><?php echo $contact ?></center></td>
	</tr>
</table>
</td>
</tr>
</table>
