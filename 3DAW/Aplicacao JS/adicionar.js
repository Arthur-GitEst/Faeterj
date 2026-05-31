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
  const pergunta = sanitizeText(perguntaInput.value);

  if (tipo === 'discursiva') {
    const resposta = sanitizeText(respostaDiscursivaInput.value);
    if (!validarDiscursiva(pergunta, resposta)) {
      alert('Preencha todos os campos obrigatorios para o tipo selecionado.');
      return;
    }

    const { perguntas } = getStoragePayload();
    perguntas.push({ tipo, pergunta, resposta, falsas: [] });
    savePerguntas(perguntas);
    alert('Pergunta salva com sucesso!');
    limparFormulario();
    return;
  }

  const falsas = [
    sanitizeText(falsa1Input.value),
    sanitizeText(falsa2Input.value),
    sanitizeText(falsa3Input.value),
  ].filter((item) => item !== '');
  const resposta = sanitizeText(respostaMultiplaInput.value);

  if (!validarMultipla(pergunta, resposta, falsas)) {
    alert('Preencha todos os campos obrigatorios para o tipo selecionado.');
    return;
  }

  const { perguntas } = getStoragePayload();
  perguntas.push({ tipo, pergunta, resposta, falsas });
  savePerguntas(perguntas);
  alert('Pergunta salva com sucesso!');
  limparFormulario();
});

atualizarCamposPorTipo();
