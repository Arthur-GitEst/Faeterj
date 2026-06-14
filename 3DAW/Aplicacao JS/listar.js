const listaPerguntas = document.getElementById('listaPerguntas');

function renderizarPerguntas() {
  fetch('api.php')
    .then((res) => {
      if (!res.ok) throw new Error('Erro ao buscar as perguntas no servidor.');
      return res.json();
    })
    .then((perguntas) => {
      listaPerguntas.innerHTML = '';

      if (perguntas.length === 0) {
        alert('Nenhuma pergunta cadastrada.');
        return;
      }

      perguntas.forEach((item) => {
        const li = document.createElement('li');
        const tipo = item.tipo;

        if (tipo === 'multipla' && item.falsas && item.falsas.length === 3) {
          const falsasTexto = item.falsas.join(', ');
          li.innerHTML =
            `<strong>ID:</strong> ${item.id}<br>` +
            `<strong>Tipo:</strong> multipla<br>` +
            `<strong>Pergunta:</strong> ${item.pergunta}<br>` +
            `<strong>Alternativas Falsas:</strong> ${falsasTexto}<br>` +
            `<strong>Resposta Correta:</strong> ${item.resposta}`;
        } else if (tipo === 'discursiva') {
          li.innerHTML =
            `<strong>ID:</strong> ${item.id}<br>` +
            `<strong>Tipo:</strong> discursiva<br>` +
            `<strong>Pergunta:</strong> ${item.pergunta}<br>` +
            `<strong>Resposta:</strong> ${item.resposta}`;
        } else {
          li.innerHTML = `<strong>Registro inválido:</strong> ${JSON.stringify(item)}`;
        }

        listaPerguntas.appendChild(li);
      });
    })
    .catch((err) => {
      alert('Erro: ' + err.message);
    });
}

renderizarPerguntas();
