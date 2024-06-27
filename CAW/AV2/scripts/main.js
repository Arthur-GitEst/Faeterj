function esconderCards () {
    let cardTexto = document.querySelectorAll(".card-titulo, .card-duracao"), cardOptions = document.querySelectorAll(".card div"), cardGradient = document.querySelectorAll(".card");
    
    cardTexto.forEach(element => element.style.display = "none");
    cardOptions.forEach(element => element.style.display = "none");
    cardGradient.forEach(element => element.style.background = "none")
}

function mostrarCard (element) {
    let cardTexto = element.querySelectorAll(".card-titulo, .card-duracao"), cardOptions = element.querySelector(".card div"), cardGradient = element;

    console.log(cardTexto);
    console.log(cardOptions);

    cardTexto.forEach(texto => texto.style.display = "block");
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

 