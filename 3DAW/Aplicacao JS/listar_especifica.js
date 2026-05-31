const formBusca = document.getElementById('formBusca');
const inputBusca = document.getElementById('perguntaBusca');
const mensagem = document.getElementById('mensagem');
const resultado = document.getElementById('resultado');

function renderMensagem(texto) {
  mensagem.innerHTML = texto ? `<p>${texto}</p>` : '';
}

function renderResultados(itens) {
  resultado.innerHTML = '';
  itens.forEach((item) => {
    const li = document.createElement('li');
    li.innerHTML =
      `<strong>Tipo:</strong> ${item.tipo}<br>` +
      `<strong>Pergunta:</strong> ${item.pergunta}<br>` +
      `<strong>Resposta:</strong> ${item.resposta}`;
    resultado.appendChild(li);
  });
}

formBusca.addEventListener('submit', (event) => {
  event.preventDefault();

  const pergunta = sanitizeText(inputBusca.value);
  const payload = getStoragePayload();
  renderResultados([]);

  if (!payload.hasStorage) {
    renderMensagem('Arquivo de perguntas nao encontrado.');
    return;
  }

  if (pergunta === '') {
    renderMensagem('Digite uma pergunta para buscar.');
    return;
  }

  const encontrados = payload.perguntas.filter((item) => item.pergunta === pergunta);

  if (encontrados.length === 0) {
    renderMensagem('Pergunta nao encontrada.');
    return;
  }

  renderMensagem('');
  renderResultados(encontrados);
});
