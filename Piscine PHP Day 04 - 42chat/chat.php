<?php
date_default_timezone_set('Europe/Paris');
if (!file_exists("../private"))
	mkdir("../private", 0777, true);
if (!file_exists("../private/chat"))
	file_put_contents("../private/chat", "");
else
{
	$fd = fopen("../private/chat", "r+");
	if (flock($fd, LOCK_EX | LOCK_SH))
	{
		$unset = unserialize(file_get_contents("../private/chat"));
		foreach ($unset as $msg)
			if ($msg['msg'] != NULL)
				if ($msg['msg'] !== "")
					echo "[".date("H:i", $msg['time'])."] <b>".$msg['login']."</b>: ".$msg['msg']."<br />";
		flock($fd, LOCK_UN);
	}
	else
		echo "File locking exception\n";
	fclose($fd);
}
?>
