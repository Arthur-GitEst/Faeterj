const formBusca = document.getElementById('formBusca');
const inputBusca = document.getElementById('perguntaBusca');
const resultado = document.getElementById('resultado');

function renderizarResultados(itens) {
  resultado.innerHTML = '';
  itens.forEach((item) => {
    const li = document.createElement('li');
    li.innerHTML =
      `<strong>ID:</strong> ${item.id}<br>` +
      `<strong>Tipo:</strong> ${item.tipo}<br>` +
      `<strong>Pergunta:</strong> ${item.pergunta}<br>` +
      `<strong>Resposta:</strong> ${item.resposta}`;
    resultado.appendChild(li);
  });
}

formBusca.addEventListener('submit', (event) => {
  event.preventDefault();

  const pergunta = inputBusca.value.trim();
  renderizarResultados([]);

  if (pergunta === '') {
    alert('Digite uma pergunta para buscar.');
    return;
  }

  fetch(`api.php?busca=${encodeURIComponent(pergunta)}`)
    .then((res) => {
      if (!res.ok) throw new Error('Erro ao realizar busca no servidor.');
      return res.json();
    })
    .then((encontrados) => {
      if (encontrados.length === 0) {
        alert('Pergunta não encontrada.');
        return;
      }

      renderizarResultados(encontrados);
    })
    .catch((err) => {
      alert('Erro: ' + err.message);
    });
});
