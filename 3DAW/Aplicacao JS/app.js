const STORAGE_KEY = 'perguntas';

function getStoragePayload() {
  const raw = localStorage.getItem(STORAGE_KEY);
  if (!raw) {
    return { hasStorage: false, perguntas: [] };
  }

  try {
    const payload = JSON.parse(raw);
    if (!payload || !Array.isArray(payload.perguntas)) {
      return { hasStorage: true, perguntas: [] };
    }
    return { hasStorage: true, perguntas: payload.perguntas };
  } catch (error) {
    return { hasStorage: true, perguntas: [] };
  }
}

function savePerguntas(perguntas) {
  const payload = { perguntas };
  localStorage.setItem(STORAGE_KEY, JSON.stringify(payload));
}

function buildPerguntaLabel(pergunta, indice) {
  const texto = pergunta && pergunta.pergunta ? pergunta.pergunta : 'registro incorreto';
  const tipo = pergunta && pergunta.tipo ? pergunta.tipo : 'registro incorreto';
  return `${indice + 1} - ${tipo} - ${texto}`;
}

function sanitizeText(value) {
  return String(value || '').trim();
}
