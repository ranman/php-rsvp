<table border='1'>
	<tr bgcolor='#ACC0CA'>
		<td width='300'>Name</td>
		<td width='300'>Email</td>
		<td width='300'>Delete?</td>
	</tr>
	<?php
$sql_select = "SELECT * FROM rsvp";
$result = mysql_query($sql_select);
while ($row = mysql_fetch_array($result)) {
	$name = $row["name"];
	$email = $row["email"];
	print("<tr><td>$name</td><td>$email</td><td>
		<form action='$PHP_SELF' method='post'>
		<input type='hidden' name='email' value='$email'>
		<input type='hidden' name='name' value='$name'>
		<input type='submit' name='delete' value='Delete'>
		</form>
		</td>
		</tr>");
}
?>
<table border='1'>
	<tr bgcolor='#ACC0CA'>
		<td width='300'>Full Name</td>
		<td width='300'>Email address</td>
		<td width='300'>Insert?</td>
	</tr>
	<tr bgcolor='#EEEEEE'>
		<td>
			<form action='<?php echo $PHP_SELF ?>' method='post'>
				<input type='text' name='form_name'>
			</td>
			<td>
				<input type='text' name='form_email'>
			</td>
			<td>
				<input type='submit' name='insert' value='Insert'>
			</form>
		</td>
	</tr>
</table>    
