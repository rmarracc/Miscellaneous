<?php
if ($_POST['login'] === "" || $_POST['passwd'] === "" || $_POST['submit'] !== "OK")
{
	echo "Login or password cannot be empty\n";
	return ;
}
if (!file_exists("../private"))
	mkdir("../private", 0777, true);
if (!file_exists("../private/passwd"))
{
	$hash = hash('whirlpool', $_POST['passwd']);
	$unset = array();
	$set = array('login' => $_POST['login'], 'passwd' => $hash);
	$unset[] = $set;
	file_put_contents("../private/passwd", serialize($unset));
}
else
{
	$hash = hash('whirlpool', $_POST['passwd']);
	$unset = unserialize(file_get_contents("../private/passwd"));
	foreach ($unset as $user)
	{
		if ($user['login'] === $_POST['login'])
		{
			echo "Username is already taken\n";
			return ;
		}
	}
	$set = array('login' => $_POST['login'], 'passwd' => $hash);
	$unset[] = $set;
	file_put_contents("../private/passwd", serialize($unset));
}
echo "OK\n";
header('Location: index.html');
?>
