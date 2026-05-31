const statusExcluir = document.getElementById('status');
const formExcluir = document.getElementById('formExcluir');
const selectExcluir = document.getElementById('indice');

function renderStatus(texto) {
  statusExcluir.innerHTML = texto ? `<p>${texto}</p>` : '';
}

function carregarSelectExcluir(perguntas) {
  selectExcluir.innerHTML = '';
  perguntas.forEach((item, indice) => {
    const option = document.createElement('option');
    option.value = indice;
    option.textContent = buildPerguntaLabel(item, indice);
    selectExcluir.appendChild(option);
  });
}

function carregarPerguntas() {
  const payload = getStoragePayload();

  if (!payload.hasStorage) {
    renderStatus('Arquivo de perguntas nao encontrado.');
    formExcluir.classList.add('hidden');
    return;
  }

  if (payload.perguntas.length === 0) {
    renderStatus('Nenhuma pergunta cadastrada.');
    formExcluir.classList.add('hidden');
    return;
  }

  renderStatus('');
  formExcluir.classList.remove('hidden');
  carregarSelectExcluir(payload.perguntas);
}

formExcluir.addEventListener('submit', (event) => {
  event.preventDefault();

  const payload = getStoragePayload();
  if (payload.perguntas.length === 0) {
    renderStatus('Nenhuma pergunta cadastrada.');
    return;
  }

  const indice = Number(selectExcluir.value);
  payload.perguntas.splice(indice, 1);
  savePerguntas(payload.perguntas);
  alert('Pergunta excluida com sucesso!');

  if (payload.perguntas.length === 0) {
    renderStatus('Nenhuma pergunta cadastrada.');
    formExcluir.classList.add('hidden');
    selectExcluir.innerHTML = '';
    return;
  }

  carregarSelectExcluir(payload.perguntas);
});

carregarPerguntas();
