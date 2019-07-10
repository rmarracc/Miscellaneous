<?php
if ($_POST['login'] === "" || $_POST['oldpw'] === "" || $_POST['submit'] !== "OK" || $_POST['newpw'] === "")
{
	echo "Login or password cannot be empty\n";
	return ;
}
$nhash = hash('whirlpool', $_POST['newpw']);
$ohash = hash("whirlpool", $_POST['oldpw']);
$unset = unserialize(file_get_contents("../private/passwd"));
$tmpkey = -1;
foreach ($unset as $key=>$user)
{
		if ($user['login'] === $_POST['login'] && $user['passwd'] === $ohash)
		{
			$tmpkey = $key;
			break ;
		}
}
if ($tmpkey === -1)
	echo "Invalid password or account doen't exist\n";
else
{
	$unset[$tmpkey]['passwd'] = $nhash;
	file_put_contents("../private/passwd", serialize($unset));
	echo "OK\n";
	header('Location: index.html');
}
return ;
?>