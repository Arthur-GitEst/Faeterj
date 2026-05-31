const statusContainer = document.getElementById('status');
const listaPerguntas = document.getElementById('listaPerguntas');

function renderStatus(message) {
  statusContainer.innerHTML = message ? `<p>${message}</p>` : '';
}

function renderPerguntas() {
  const payload = getStoragePayload();

  if (!payload.hasStorage) {
    renderStatus('Arquivo de perguntas nao encontrado.');
    return;
  }

  if (payload.perguntas.length === 0) {
    renderStatus('Nenhuma pergunta cadastrada.');
    return;
  }

  renderStatus('');
  listaPerguntas.innerHTML = '';

  payload.perguntas.forEach((item) => {
    const li = document.createElement('li');
    const tipo = item.tipo;

    if (tipo === 'multipla' && item.falsas && item.falsas.length === 3) {
      const falsasTexto = item.falsas.join(',');
      li.innerHTML =
        `<strong>Tipo:</strong> multipla<br>` +
        `<strong>Pergunta:</strong> ${item.pergunta}<br>` +
        `<strong>Alternativas Falsas:</strong> ${falsasTexto}<br>` +
        `<strong>Resposta Correta:</strong> ${item.resposta}`;
    } else if (tipo === 'discursiva') {
      li.innerHTML =
        `<strong>Tipo:</strong> discursiva<br>` +
        `<strong>Pergunta:</strong> ${item.pergunta}<br>` +
        `<strong>Resposta:</strong> ${item.resposta}`;
    } else {
      li.innerHTML = `<strong>Registro invalido:</strong> ${item}`;
    }

    listaPerguntas.appendChild(li);
  });
}

renderPerguntas();
