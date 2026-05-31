const statusAlterar = document.getElementById('status');
const formSelecionar = document.getElementById('formSelecionar');
const selectIndice = document.getElementById('indice');
const blocoEdicao = document.getElementById('blocoEdicao');
const tipoAtual = document.getElementById('tipoAtual');
const formEdicao = document.getElementById('formEdicao');
const perguntaEditar = document.getElementById('perguntaEditar');
const respostaEditar = document.getElementById('respostaEditar');

let indiceAtual = null;

function renderStatus(texto) {
  statusAlterar.innerHTML = texto ? `<p>${texto}</p>` : '';
}

function carregarSelect(perguntas) {
  selectIndice.innerHTML = '';
  perguntas.forEach((item, indice) => {
    const option = document.createElement('option');
    option.value = indice;
    option.textContent = buildPerguntaLabel(item, indice);
    selectIndice.appendChild(option);
  });
}

function carregarPerguntas() {
  const payload = getStoragePayload();

  if (!payload.hasStorage) {
    renderStatus('Arquivo de perguntas nao encontrado.');
    formSelecionar.classList.add('hidden');
    return;
  }

  if (payload.perguntas.length === 0) {
    renderStatus('Nenhuma pergunta cadastrada.');
    formSelecionar.classList.add('hidden');
    return;
  }

  renderStatus('');
  formSelecionar.classList.remove('hidden');
  carregarSelect(payload.perguntas);
}

formSelecionar.addEventListener('submit', (event) => {
  event.preventDefault();

  const payload = getStoragePayload();
  if (payload.perguntas.length === 0) {
    renderStatus('Nenhuma pergunta cadastrada.');
    return;
  }

  indiceAtual = Number(selectIndice.value);
  const item = payload.perguntas[indiceAtual];

  if (!item) {
    renderStatus('Selecione uma pergunta valida.');
    return;
  }

  blocoEdicao.classList.remove('hidden');
  tipoAtual.textContent = `Tipo: ${item.tipo}`;
  perguntaEditar.value = item.pergunta;
  respostaEditar.value = item.resposta;
});

formEdicao.addEventListener('submit', (event) => {
  event.preventDefault();

  if (indiceAtual === null) {
    renderStatus('Selecione uma pergunta valida.');
    return;
  }

  const novaPergunta = sanitizeText(perguntaEditar.value);
  const novaResposta = sanitizeText(respostaEditar.value);

  if (novaPergunta === '' || novaResposta === '') {
    alert('Preencha pergunta e resposta para salvar.');
    return;
  }

  const payload = getStoragePayload();
  const item = payload.perguntas[indiceAtual];
  if (!item) {
    renderStatus('Selecione uma pergunta valida.');
    return;
  }

  item.pergunta = novaPergunta;
  item.resposta = novaResposta;
  payload.perguntas[indiceAtual] = item;
  savePerguntas(payload.perguntas);
  alert('Pergunta alterada com sucesso!');

  carregarSelect(payload.perguntas);
});

carregarPerguntas();
