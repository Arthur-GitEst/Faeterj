function esconder (element) {
    element.style.display = "none";
}

function mostrar (element) {
    element.style.display = "block"
}

function esconderCards () {
    let cardTexto = document.querySelectorAll(".card-titulo, .card-duracao"), cardOptions = document.querySelectorAll(".card div"), cardGradient = document.querySelectorAll(".card");
    
    cardTexto.forEach(element => esconder(element));
    cardOptions.forEach(element => esconder(element));
    cardGradient.forEach(element => element.style.background = "none")
}

function mostrarCard (element) {
    let cardTexto = element.querySelectorAll(".card-titulo, .card-duracao"), cardOptions = element.querySelector(".card div"), cardGradient = element;

    cardTexto.forEach(texto => mostrar(texto));
    cardOptions.style.display = "flex";
    cardGradient.style.background = "linear-gradient(90deg, rgb(129 129 129) 0%, rgba(22, 20, 25, 0) 70%)";
}

function esconderCardUnico (element) {
    let cardTexto = element.querySelectorAll(".card-titulo, .card-duracao"), cardOptions = element.querySelector(".card div"), cardGradient = element;

    cardTexto.forEach(texto => texto.style.display = "none");
    cardOptions.style.display = "none";
    cardGradient.style.background = "none";
}

function redirecionarMain () {
    window.location.href = './main.html';
}

function redirecionarTitulo () {
    window.location.href = './titulo.html';
}

function sideBarOpenClose () {
    let sideBar = document.querySelector(".side-bar");

    if (sideBar.style.display != 'none') {
        sideBar.style.display = "none";
    } else {
        sideBar.style.display = "flex";
    }

}

function sideBarConfig () {
    let closeIcon = document.querySelector(".close-icon"), menuIcon = document.querySelector(".menu-icon"), cardInfo = document.getElementsByClassName("card-info");

    closeIcon.addEventListener("click", function() {sideBarOpenClose()});
    menuIcon.addEventListener("click", function() {sideBarOpenClose()});
    cardInfo[0].addEventListener("click", function() {redirecionarTitulo()});
}


 