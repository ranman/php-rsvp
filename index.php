<html>
   <head>
      <title>R.S.V.P.</title>
   </head>
   <body link='blue' vlink='blue'>
      <center>
         <?php
            require_once ('config.inc');
            $db = mysql_connect ( $db_server, $db_user, $db_pass ) or die ( "SQL not found");
            $db = mysql_select_db ( $db_name ) or die ( "DB not found" );
            if ($_POST ["submit"]) {
               $address = mysql_real_escape_string($_POST["address"]);
               $pass = mysql_real_escape_string($_POST["pass"]);
               $sql = "SELECT * FROM rsvp WHERE email='$address' and password='$pass'";
               $result = mysql_query ( $sql );
               $num = mysql_numrows ( $result );
               $row = mysql_fetch_array ( $result );
               $email = $row ["email"];
               if ($num == '1') {
                  global $email;
                  if ($email == "$admin_mail") {
                     show_all ();
                  } else {
                     show_normal ();
                  }
               } else { echo "Go back and try again"; }
            } elseif ($_POST ["insert"]) {
               if($form_email != $admin_mail) {
                  $sql_insert = "INSERT INTO rsvp (email, password, rsvp, comments, name) VALUES ('$form_email', '$form_pass', 'U', 'Still thinking apparently...', '$form_name')";
                  $result = mysql_query($sql_insert);
                  show_all ();
                  $to = "$form_email";
                  mail ( $to, "You're invited to party", $body, "From: $from\r\n" . "Reply-To: $from\r\n" . "X-Mailer: PHP/" . phpversion () );
               } else { echo "Sorry you can't use the admin email!"; }
            } elseif ($_POST["delete"]) {
               $email = mysql_real_escape_string($_POST['email']);
               $name = mysql_real_escape_string($_POST['name']);
               $sql = "DELETE FROM rsvp WHERE email='$email' AND name='$name'";
               $result = mysql_query($sql);
               show_all ();		

            } elseif ($_POST ["update"]) {
               $email_user = mysql_real_escape_string($_POST['email_user']);
               $rsvp_user= mysql_real_escape_string($_POST['rsvp_user']);
               $comments_user = mysql_real_escape_string($_POST['comments_user']);
               $code = mysql_real_escape_string($_POST['code']);
               $sql = "UPDATE rsvp SET rsvp='$rsvp_user', comments='$comments_user' WHERE email = '$email_user'";
               $result = mysql_query($sql);
               if(mysql_affected_rows() != 0) {
                  show_normal();
               } else { print "Hey that's not the right code! Check your email!"; }

            } else {
               echo "Please enter your email and code to see more information:";
               echo "<form action='$PHP_SELF' method='post'>";
               echo "<P>Email address<br>";
               echo "<input type='text' name='address' size='25'>";
               echo "</P>";
               echo "<P>Code:<br>";
               echo "<input type='password' name='pass' size='8'>";
               echo "</P>";
               echo "<input type='submit' name='submit' value='RSVP'>";
               echo "</form>";
            }

            function show_all() {
               include ("header.inc");
               global $email;
               global $db;
               include ("admin.inc");
               include ("normal.inc");
               include ("footer.inc");
            }

            function show_normal() {
               include ("header.inc");
               global $email;
               global $db;
               include ("normal.inc");
               include ("footer.inc");
            }
         ?>
      </center>
   </body>
</html>
