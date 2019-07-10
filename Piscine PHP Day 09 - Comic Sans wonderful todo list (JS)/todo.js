var ft_list;
var cookies = [];
var keep = [];
var i = 0;
var data;

window.onload = (function ()
{
    document.querySelector( "#new" ).addEventListener( "click" , getTask); //On set l'event "click -> fonction getTask" au bouton "New"
    ft_list = document.querySelector( "#ft_list" ); //On fait pointer ft_list le premier element de la liste de taches
    data = document.cookie; //On récupere le fichier cookies du document courrant et on le stocke dans une variable
    if (data)
	{
        cookies = JSON.parse(data); //On parse les cookies contenus dans data et on les stocke dans la variable cookies
        cookies.forEach(function (task) { pushTask(task); }); //On récupere les taches à l'aide d'un foreach et on ajoute toute les taches contenues dans les cookies dans ft_list
    }
});

window.onunload = (function ()
{
    var task = ft_list.children; //On récupere tout les div enfants de ft_list et on les stocke dans un tableau
	var nb = task.length; //On calcule le nombre de taches contenues dans le tableau task
	while (i < nb)
	{
		keep.unshift(task[i].innerHTML); //on ajoute a la fin du tableau de retour (avec unshift) la tache présente en texte brut
		i++;
	}
    document.cookie = JSON.stringify(keep); //On (re)construit le fichier cookies à partir de nos données traitées précedement
});

function getTask()
{
    var task = prompt("What is your plan ?", "(Write your plan here)"); //On crée une "alerte" avec un prompt permettant à l'utilisateur d'envoyer du texte qui sera stocké dans la variable task
	if (task === null)
		task = '';
	if (task.trim() !== '') //On trim la chaine (pour s'assurer que les taches contenant uniquement des espaces soient aussi ignorées) puis on verifie si elle est vide, si elle n'est pas vite on l'ajoute aux taches
		pushTask(task.trim())
	else
		alert("It is because your life is boring ? :(");
}

function pushTask(task)
{
    var div = document.createElement("div"); //On crée une balise div qui contiendra les informations de notre task
    div.innerHTML = task; //On insere la chaine précédement traitée dans notre balise div
    div.addEventListener("click", popTask); //On ajoute la détection d'evenement qui nous permettera de supprimer notre task au clic
    ft_list.insertBefore(div, ft_list.firstChild); //On insere la balise div fraichement créee au début de la liste de tasks
	console.log(task, ": Task added successfully !");
}

function popTask()
{
    if (confirm("Do you really want to delete me ? :(")) //On envoie une petite alerte pour avoir la confirmation de l'utilisateur quant à la suppression de la task
	{
        this.parentElement.removeChild(this); //On supprime la task courrante en appellant le parent de la DOM (ft_list pointé a la tete précedement) et en supprimant l'enfant "this" qui est le node selectionné
		console.log(this.innerHTML, ": Task removed successfully !");
	}
	else
		console.log(this.innerHTML, ": Task removing cancelled.");
}
