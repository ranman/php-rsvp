<table border='1'>
  <tr>
    <td width='300' bgcolor='#ACC0CA'>Do you wish to join in the festivities?</td>
    <td width='300' bgcolor='#EEEEEE'>
      <form action='<?php echo $PHP_SELF ?>' method='post'>
		Code:<br />
        <input type='radio' name='rsvp_user' value='Y'>Yes, I want to attend.<br />
        <input type='radio' name='rsvp_user' value='N'>No, and I better have an excuse.<br />
        <input type='radio' name='rsvp_user' value='U'>I dunno yet.</td>
        <td width='300' bgcolor='#ACC0CA'>Comments?(256 Character Max)
        <input type='text' name='comments_user'> 
        <input type='hidden' name='email_user' value='<?php echo "$email"; ?>'> 
        <input type='submit' name='update' value='Update'>
</form>
    </td>
  </tr>
</table>
