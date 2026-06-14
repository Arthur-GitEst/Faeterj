const formExcluir = document.getElementById('formExcluir');
const selectExcluir = document.getElementById('indice');

let perguntasMemoria = [];

function carregarSelectExcluir(perguntas) {
  selectExcluir.innerHTML = '';
  perguntas.forEach((item) => {
    const option = document.createElement('option');
    option.value = item.id;
    option.textContent = `[ID: ${item.id}] - ${item.tipo.toUpperCase()} - ${item.pergunta}`;
    selectExcluir.appendChild(option);
  });
}

function carregarPerguntas() {
  formExcluir.classList.add('hidden');

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

      formExcluir.classList.remove('hidden');
      carregarSelectExcluir(perguntasMemoria);
    })
    .catch((err) => {
      alert('Erro: ' + err.message);
    });
}

formExcluir.addEventListener('submit', (event) => {
  event.preventDefault();

  if (perguntasMemoria.length === 0) {
    alert('Nenhuma pergunta cadastrada.');
    return;
  }

  const idExcluir = Number(selectExcluir.value);

  if (confirm('Tem certeza de que deseja excluir esta pergunta?')) {
    fetch(`api.php?id=${idExcluir}`, {
      method: 'DELETE'
    })
      .then((res) => {
        if (!res.ok) throw new Error('Erro ao excluir a pergunta no servidor.');
      })
      .then(() => {
        alert('Pergunta excluida com sucesso!');
        carregarPerguntas();
      })
      .catch((err) => {
        alert('Erro: ' + err.message);
      });
  }
});

carregarPerguntas();
