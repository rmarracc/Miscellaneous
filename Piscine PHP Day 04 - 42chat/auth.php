<?php
function auth($login, $passwd)
{
	$hash = hash("whirlpool", $passwd);
	$unset = unserialize(file_get_contents("../private/passwd"));
	foreach ($unset as $user) 
		if ($user['login'] === $login && $user['passwd'] === $hash)
			return (TRUE);
	return (FALSE);
}
?>
