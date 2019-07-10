<html><head>
<script langage="javascript">top.frames['chat'].location = 'chat.php';</script>
</head>
<body>
    <form method="post" action="speak.php">
        <input type="text" name="msg" value="" width="100%" />
     </form>
</html></body>
<?php
date_default_timezone_set('Europe/Paris');
session_start();
if ($_SESSION['loggued_on_user'] === NULL || $_POST['msg'] === NULL)
	return ;
if ($_SESSION['loggued_on_user'] === "" || $_POST['msg'] === "")
	return ;
if (!file_exists("../private"))
    mkdir("../private",0777, true);
if (!file_exists("../private/chat"))
    file_put_contents("../private/chat", "");
else
{
    $fd = fopen("../private/chat", "r+");
    if (flock($fd, LOCK_EX | LOCK_SH))
    {
		$unset = unserialize(file_get_contents("../private/chat"));
		$set = array('login'=>$_SESSION['loggued_on_user'], 'time'=>time(), 'msg'=>$_POST['msg']);
		$unset[] = $set;
		file_put_contents("../private/chat", serialize($unset));
        flock($fd, LOCK_UN);
    }
    else
        echo "File locking exception\n";
	fclose($fd);
}
?>
