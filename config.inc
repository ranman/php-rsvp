<?php
//This function creates a random password
function createRandomPassword() {
	$chars = "abcdefghijkmnopqrstuvwxyz023456789";
	srand ( ( double ) microtime () * 1000000 );
	$i = 0;
	$pass = '';
	while ( $i <= 7 ) {
		$num = rand () % 33;
		$tmp = substr ( $chars, $num, 1 );
		$pass = $pass . $tmp;
		$i ++;
	}
	return $pass;
}
// Name of the server that SQL is listening on (you might need to change this)
$db_server = "localhost";

// Database to connect to (you need to change this)
$db_name = "rsvp";

// Username for the database (you need to change this)
$db_user = "username";

//Password for the user above (you need to change this)
$db_pass = "password";

// This is the email address of the RSVP administrator that can create and delete people from the invite.
$admin_mail = "yourname@email.com";

// Who the invitation will be sent out as after you create the user
$from = "Your Name <$admin_mail>";
$form_name = $_POST ["form_name"];
$form_email = $_POST ["form_email"];
$form_pass = createRandomPassword();

// This is the body of the email that is sent out to the invited people
$body = "Hello $form_name! You have been invited to go ice skating with .
Goto website and let me know if you are going to make
it or not. All the details are on the site. Log in with the following information:

Email: $form_email
Code: $form_pass

If you have any questions, send an email to $admin_mail. We look forward to seeing
you there.";

/*--------------------------------------------------*/
/*   BEGIN INFO FOR THE HEADER FILE - header.inc    */
/*--------------------------------------------------*/

// This should be pretty self explanitory
$title = "Ice Palace Party";
$why = "Because we need to celebrate and I want to go ice skating";
$where = "Ice Palace, free rides to senior sing afterwards";
$when = "12-3:00 so seniors can get to senior sing in time...<br />Monday, June 1st<br /> or June 2nd<br /> or June 3rd<br /> June 3rd works because it's not Heidi's BD<br /> June 4th works too...";
$how = "Goto Ice Palace or let me pick you up from somewhere... preferably somewhere windwardy...";
$notes = "Bring some extra cash for food, admission is $8 <br />
<img src='1.JPG'><br />
lets bring back the old days before we graduate!";

/*--------------------------------------------------*/
/*    END INFO FOR THE HEADER FILE - header.inc     */
/*--------------------------------------------------*/
/*--------------------------------------------------*/
/*   BEGIN INFO FOR THE FOOTER FILE - footer.inc    */
/*--------------------------------------------------*/

// This is the contact info that shows up at the bottom of the page
$contact = "Contact <a href='mailto:$admin_mail'>Randall Hunt</a> for questions and comments";

?>