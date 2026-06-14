const formSelecionar = document.getElementById('formSelecionar');
const selectIndice = document.getElementById('indice');
const blocoEdicao = document.getElementById('blocoEdicao');
const tipoAtual = document.getElementById('tipoAtual');
const formEdicao = document.getElementById('formEdicao');
const perguntaEditar = document.getElementById('perguntaEditar');
const respostaEditar = document.getElementById('respostaEditar');

let perguntasMemoria = [];
let perguntaSelecionada = null;

function carregarSelect(perguntas) {
  selectIndice.innerHTML = '';
  perguntas.forEach((item) => {
    const option = document.createElement('option');
    option.value = item.id;
    option.textContent = `[ID: ${item.id}] - ${item.tipo.toUpperCase()} - ${item.pergunta}`;
    selectIndice.appendChild(option);
  });
}

function carregarPerguntas() {
  formSelecionar.classList.add('hidden');
  blocoEdicao.classList.add('hidden');

  fetch('api.php')
    .then((res) => {
      if (!res.ok) throw new Error('Erro ao buscar as perguntas no servidor.');
      return res.json();
    })
    .then((data) => {
      perguntasMemoria = data;
      if (perguntasMemoria.length === 0) {
        alert('Nenhuma pergunta cadastrada.');
        return;
      }

      formSelecionar.classList.remove('hidden');
      carregarSelect(perguntasMemoria);
    })
    .catch((err) => {
      alert('Erro: ' + err.message);
    });
}

formSelecionar.addEventListener('submit', (event) => {
  event.preventDefault();

  if (perguntasMemoria.length === 0) {
    alert('Nenhuma pergunta cadastrada.');
    return;
  }

  const idSelecionado = Number(selectIndice.value);
  perguntaSelecionada = perguntasMemoria.find((item) => Number(item.id) === idSelecionado);

  if (!perguntaSelecionada) {
    alert('Selecione uma pergunta válida.');
    return;
  }

  blocoEdicao.classList.remove('hidden');
  tipoAtual.textContent = `Tipo: ${perguntaSelecionada.tipo.toUpperCase()}`;
  perguntaEditar.value = perguntaSelecionada.pergunta;
  respostaEditar.value = perguntaSelecionada.resposta;
});

formEdicao.addEventListener('submit', (event) => {
  event.preventDefault();

  if (!perguntaSelecionada) {
    alert('Selecione uma pergunta válida.');
    return;
  }

  const novaPergunta = perguntaEditar.value.trim();
  const novaResposta = respostaEditar.value.trim();

  if (novaPergunta === '' || novaResposta === '') {
    alert('Preencha pergunta e resposta para salvar.');
    return;
  }

  fetch('api.php', {
    method: 'PUT',
    headers: {
      'Content-Type': 'application/json'
    },
    body: JSON.stringify({
      id: perguntaSelecionada.id,
      pergunta: novaPergunta,
      resposta: novaResposta
    })
  })
    .then((res) => {
      if (!res.ok) throw new Error('Erro ao atualizar a pergunta no servidor.');
    })
    .then(() => {
      alert('Pergunta alterada com sucesso!');
      carregarPerguntas();
    })
    .catch((err) => {
      alert('Erro: ' + err.message);
    });
});

carregarPerguntas();
