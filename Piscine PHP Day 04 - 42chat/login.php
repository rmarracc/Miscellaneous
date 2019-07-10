<?php
include ('auth.php');
session_start();
if (auth($_POST['login'], $_POST['passwd']) === TRUE)
{
	$_SESSION['loggued_on_user'] = $_POST['login'];
	echo '<iframe name="chat" src="chat.php" width="100%" height="550px"></iframe><iframe name="speak" src="speak.php" width="100%" height="50px"></iframe>';
	echo '<form method="post" action="logout.php"><input type="submit" name="quit" value="Logout"></form>';
}
else
{
	$_SESSION['loggued_on_user'] = "";
	echo "Wrong password or account doesn't exists\n";
}
?>
