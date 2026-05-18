const inputMat = document.getElementById('mat');
const inputNome = document.getElementById('nome');
const inputEmail = document.getElementById('email');
const btnSalvar = document.getElementById('btnSalvar');
const btnCarregar = document.getElementById('btnCarregar');
const listaAlunos = document.getElementById('listaAlunos');

const chaveStorage = 'alunos';
let alunos = [];

function salvarNoStorage() {
	localStorage.setItem(chaveStorage, JSON.stringify(alunos));
}

function carregarDoStorage() {
	const dados = localStorage.getItem(chaveStorage);
	alunos = dados ? JSON.parse(dados) : [];
	atualizarLista();
}

function limparCampos() {
	inputMat.value = '';
	inputNome.value = '';
	inputEmail.value = '';
	inputMat.focus();
}

function atualizarLista() {
	listaAlunos.innerHTML = '';

	alunos.forEach((aluno) => {
		const item = document.createElement('li');
		item.textContent = `${aluno.mat} - ${aluno.nome} - ${aluno.email}`;
		listaAlunos.appendChild(item);
	});
}

function adicionarAluno() {
	const mat = inputMat.value.trim();
	const nome = inputNome.value.trim();
	const email = inputEmail.value.trim();

	if (!mat || !nome || !email) {
		alert('Preencha matrícula, nome e email.');
		return;
	}

	alunos.push({ mat, nome, email });
	salvarNoStorage();
	atualizarLista();
	limparCampos();
}

function recarregarLista() {
	carregarDoStorage();
}

btnSalvar.addEventListener('click', adicionarAluno);
btnCarregar.addEventListener('click', recarregarLista);

carregarDoStorage();
