const tipoSelect = document.getElementById('tipo');
const btnSelecionarTipo = document.getElementById('btnSelecionarTipo');
const formPergunta = document.getElementById('formPergunta');
const blocoMultipla = document.getElementById('blocoMultipla');
const blocoDiscursiva = document.getElementById('blocoDiscursiva');
const perguntaInput = document.getElementById('pergunta');
const falsa1Input = document.getElementById('falsa1');
const falsa2Input = document.getElementById('falsa2');
const falsa3Input = document.getElementById('falsa3');
const respostaMultiplaInput = document.getElementById('respostaMultipla');
const respostaDiscursivaInput = document.getElementById('respostaDiscursiva');

function atualizarCamposPorTipo() {
  const tipo = tipoSelect.value;
  const isMultipla = tipo === 'multipla';

  blocoMultipla.classList.toggle('hidden', !isMultipla);
  blocoDiscursiva.classList.toggle('hidden', isMultipla);

  falsa1Input.required = isMultipla;
  falsa2Input.required = isMultipla;
  falsa3Input.required = isMultipla;
  respostaMultiplaInput.required = isMultipla;
  respostaDiscursivaInput.required = !isMultipla;

  falsa1Input.disabled = !isMultipla;
  falsa2Input.disabled = !isMultipla;
  falsa3Input.disabled = !isMultipla;
  respostaMultiplaInput.disabled = !isMultipla;
  respostaDiscursivaInput.disabled = isMultipla;
}

function limparFormulario() {
  perguntaInput.value = '';
  falsa1Input.value = '';
  falsa2Input.value = '';
  falsa3Input.value = '';
  respostaMultiplaInput.value = '';
  respostaDiscursivaInput.value = '';
  perguntaInput.focus();
}

function validarDiscursiva(pergunta, resposta) {
  return pergunta !== '' && resposta !== '';
}

function validarMultipla(pergunta, resposta, falsas) {
  return pergunta !== '' && resposta !== '' && falsas.length === 3;
}

btnSelecionarTipo.addEventListener('click', atualizarCamposPorTipo);

tipoSelect.addEventListener('change', atualizarCamposPorTipo);

formPergunta.addEventListener('submit', (event) => {
  event.preventDefault();

  const tipo = tipoSelect.value;
  const pergunta = perguntaInput.value.trim();
  let payload = {};

  if (tipo === 'discursiva') {
    const resposta = respostaDiscursivaInput.value.trim();
    if (!validarDiscursiva(pergunta, resposta)) {
      alert('Preencha todos os campos obrigatórios para o tipo selecionado.');
      return;
    }
    payload = { tipo, pergunta, resposta, falsas: [] };
  } else {
    const falsas = [
      falsa1Input.value.trim(),
      falsa2Input.value.trim(),
      falsa3Input.value.trim(),
    ].filter((item) => item !== '');
    const resposta = respostaMultiplaInput.value.trim();

    if (!validarMultipla(pergunta, resposta, falsas)) {
      alert('Preencha todos os campos obrigatórios para o tipo selecionado.');
      return;
    }
    payload = { tipo, pergunta, resposta, falsas };
  }

  fetch('api.php', {
    method: 'POST',
    headers: {
      'Content-Type': 'application/json'
    },
    body: JSON.stringify(payload)
  })
  .then((res) => {
    if (!res.ok) throw new Error('Erro ao salvar pergunta no servidor.');
  })
  .then(() => {
    alert('Pergunta salva com sucesso!');
    limparFormulario();
  })
  .catch((err) => {
    alert('Erro: ' + err.message);
  });
});

atualizarCamposPorTipo();
