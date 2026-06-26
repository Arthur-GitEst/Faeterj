const API_AUTH = 'api/auth.php';
const API_AGENDAMENTOS = 'api/agendamentos.php';
const API_SERVICOS = 'api/servicos.php';

// Helper para analisar respostas do servidor de forma segura contra erros não-JSON
async function parseResponse(resposta) {
    const text = await resposta.text();
    try {
        return JSON.parse(text);
    } catch (e) {
        const snippet = text.trim().substring(0, 150);
        throw new Error(`Resposta inválida do servidor: ${snippet || 'Corpo de resposta vazio'}`);
    }
}

// Helper genérico para requisições da API
async function apiFetch(url, method = 'GET', body = null) {
    const options = { method, headers: { 'Content-Type': 'application/json' } };
    if (body) options.body = JSON.stringify(body);
    const resposta = await fetch(url, options);
    const resultado = await parseResponse(resposta);
    if (!resposta.ok) throw new Error(resultado.message || 'Erro na requisição.');
    return resultado;
}

// Fluxo centralizado de sucesso na autenticação
function lidarComSucessoAuth(usuario) {
    usuarioLogado = usuario;
    authMenuText.textContent = usuarioLogado.nome;
    fecharTodosModais();

    if (agendamentoPendenteServicoId) {
        carregarDetalhesAgendamento(agendamentoPendenteServicoId);
        agendamentoPendenteServicoId = null;
    } else if (agendamentoPendente) {
        abrirModal(modalCartao);
    } else {
        alternarVisualizacao('view-perfil');
    }
}

// Estado global da aplicação
let usuarioLogado = null;
let agendamentoPendente = null; // Guarda seleção temporária antes de logar/pagar
let servicoAtual = null; // Armazena dados do serviço selecionado para agendamento
let agendamentoPendenteServicoId = null; // Guarda ID do serviço clicado antes do login

// Elementos de navegação
const views = document.querySelectorAll('.spa-view');
const authMenuText = document.getElementById('auth-menu-text');

// Modais
const modalLogin = document.getElementById('modal-login');
const modalCadastro = document.getElementById('modal-cadastro');
const modalCartao = document.getElementById('modal-cartao');
const modalReagendar = document.getElementById('modal-reagendar');

// Inicialização
function iniciarApp() {
    verificarSessao();
    carregarServicosHome();
    registrarNavegacao();
    configurarFormularios();
}

if (document.readyState === 'loading') {
    document.addEventListener('DOMContentLoaded', iniciarApp);
} else {
    iniciarApp();
}

// 1. NAVEGAÇÃO E SPA
function alternarVisualizacao(viewId) {
    views.forEach(view => {
        if (view.id === viewId) {
            view.classList.add('active');
        } else {
            view.classList.remove('active');
        }
    });

    if (viewId === 'view-perfil') {
        carregarAgendamentosUsuario();
    }
}

function registrarNavegacao() {
    // Clicar no Logo vai para a Home
    document.getElementById('logo-home').addEventListener('click', () => {
        alternarVisualizacao('view-home');
    });

    // Clicar no menu de autenticação ou perfil
    document.getElementById('btn-auth-menu').addEventListener('click', (e) => {
        e.preventDefault();
        if (usuarioLogado) {
            alternarVisualizacao('view-perfil');
        } else {
            abrirModal(modalLogin);
        }
    });

    // Clicar em Carrinho simula direcionamento para agendamentos do perfil
    document.getElementById('btn-header-cart').addEventListener('click', (e) => {
        e.preventDefault();
        if (usuarioLogado) {
            alternarVisualizacao('view-perfil');
        } else {
            abrirModal(modalLogin);
        }
    });

    // Botão logout no perfil
    document.getElementById('btn-logout-action').addEventListener('click', realizarLogout);

    // Configurar fechamento de todos os modais
    const closeButtons = document.querySelectorAll('.modal-close-btn');
    closeButtons.forEach(btn => {
        btn.addEventListener('click', fecharTodosModais);
    });

    // Alternar entre Login e Cadastro nos modais
    document.getElementById('link-ir-cadastro').addEventListener('click', (e) => {
        e.preventDefault();
        fecharTodosModais();
        abrirModal(modalCadastro);
    });

    document.getElementById('link-ir-login').addEventListener('click', (e) => {
        e.preventDefault();
        fecharTodosModais();
        abrirModal(modalLogin);
    });

    // Login com Google simulado (login direto instantâneo)
    document.getElementById('btn-login-google')?.addEventListener('click', async () => {
        try {
            const resultado = await apiFetch(`${API_AUTH}?action=login`, 'POST', { email: 'cliente@teste.com', senha: '123' });
            lidarComSucessoAuth(resultado.user);
        } catch (erro) {
            alert(erro.message);
        }
    });
}

// 2. MODAIS
function abrirModal(modalElement) {
    modalElement.classList.add('active');
}

function fecharTodosModais() {
    modalLogin.classList.remove('active');
    modalCadastro.classList.remove('active');
    modalCartao.classList.remove('active');
    modalReagendar.classList.remove('active');
}

// 3. AUTENTICAÇÃO E SESSÃO
async function verificarSessao() {
    try {
        const resultado = await apiFetch(`${API_AUTH}?action=check`);
        if (resultado.logged_in) {
            usuarioLogado = resultado.user;
            authMenuText.textContent = usuarioLogado.nome;
        } else {
            usuarioLogado = null;
            authMenuText.textContent = 'Login / Cadastre-se';
        }
    } catch (e) {
        console.error('Erro de sessão');
    }
}

async function realizarLogout() {
    try {
        const resultado = await apiFetch(`${API_AUTH}?action=logout`, 'POST');
        alert(resultado.message);
        usuarioLogado = null;
        authMenuText.textContent = 'Login / Cadastre-se';
        alternarVisualizacao('view-home');
    } catch (e) {
        alert('Erro ao sair da conta.');
    }
}

function configurarFormularios() {
    // FORM LOGIN
    document.getElementById('form-login').addEventListener('submit', async (e) => {
        e.preventDefault();
        const email = document.getElementById('login-email').value;
        const senha = document.getElementById('login-senha').value;

        try {
            const resultado = await apiFetch(`${API_AUTH}?action=login`, 'POST', { email, senha });
            lidarComSucessoAuth(resultado.user);
        } catch (erro) {
            alert(erro.message);
        }
    });

    // FORM CADASTRO
    document.getElementById('form-cadastro').addEventListener('submit', async (e) => {
        e.preventDefault();
        const nome = document.getElementById('register-nome').value;
        const email = document.getElementById('register-email').value;
        const senha = document.getElementById('register-senha').value;
        const confirmar = document.getElementById('register-confirmar').value;
        const dia = document.getElementById('nasc-dia').value;
        const mes = document.getElementById('nasc-mes').value;
        const ano = document.getElementById('nasc-ano').value;

        if (senha !== confirmar) {
            alert('As senhas não coincidem!');
            return;
        }

        try {
            const data_nascimento = `${ano}-${mes}-${dia}`;
            const resultado = await apiFetch(`${API_AUTH}?action=register`, 'POST', { nome, email, senha, data_nascimento });
            lidarComSucessoAuth(resultado.user);
        } catch (erro) {
            alert(erro.message);
        }
    });

    // FORM CARTÃO (Simula o pagamento direto)
    document.getElementById('form-cartao').addEventListener('submit', async (e) => {
        e.preventDefault();
        if (!agendamentoPendente) return;

        const numCartao = document.getElementById('card-number').value;
        if (numCartao.replace(/\s/g, '').length < 12) {
            alert('Número de cartão inválido!');
            return;
        }

        try {
            const resultado = await apiFetch(API_AGENDAMENTOS, 'POST', agendamentoPendente);
            alert(resultado.message);
            fecharTodosModais();
            agendamentoPendente = null;
            alternarVisualizacao('view-perfil');
        } catch (erro) {
            alert(erro.message);
        }
    });

    // FORM REAGENDAR (PUT)
    document.getElementById('form-reagendar').addEventListener('submit', async (e) => {
        e.preventDefault();
        const id = document.getElementById('reagenda-id').value;
        const data = document.getElementById('reagenda-data').value;
        const horario = document.getElementById('reagenda-horario').value;
        const profissional_id = document.getElementById('reagenda-profissional').value;

        try {
            const resultado = await apiFetch(`${API_AGENDAMENTOS}?id=${id}`, 'PUT', { data_hora: `${data} ${horario}`, profissional_id });
            alert(resultado.message);
            fecharTodosModais();
            carregarAgendamentosUsuario();
        } catch (erro) {
            alert(erro.message || 'Erro ao reagendar.');
        }
    });
}

// 4. HOME (CARREGAMENTO DINÂMICO)
async function carregarServicosHome() {
    try {
        const servicos = await apiFetch(API_SERVICOS);
        const container = document.getElementById('services-grid-container');
        if (!container) return;

        container.innerHTML = '';
        servicos.forEach(servico => {
            const card = document.createElement('div');
            card.className = 'service-card';
            card.setAttribute('data-service-id', servico.id);

            // Corrige o caminho relativo caso a API retorne caminhos como ./img/
            // Mas usamos o estilo inline para injetar a imagem lida do banco
            card.innerHTML = `
                <div class="service-card-img" style="background-image: url('${servico.imagem}');"></div>
                <div class="service-card-title">${servico.nome.split(' e ')[0]}</div>
            `;

            // Adicionar evento de clique com bloqueio de login
            card.addEventListener('click', () => {
                if (!usuarioLogado) {
                    agendamentoPendenteServicoId = servico.id;
                    abrirModal(modalLogin);
                } else {
                    carregarDetalhesAgendamento(servico.id);
                }
            });

            container.appendChild(card);
        });
    } catch (e) {
        console.error('Erro ao carregar serviços da Home:', e);
    }
}

// 5. FLUXO DE AGENDAMENTO (TELA DE DETALHE E ACORDEÃO)
async function carregarDetalhesAgendamento(servicoId) {
    try {
        const resultado = await apiFetch(`${API_AGENDAMENTOS}?servico_id=${servicoId}`);
        servicoAtual = resultado.servico;

        // Atualizar textos do Hero
        document.getElementById('sched-service-name').textContent = servicoAtual.nome;
        document.getElementById('sched-service-desc').textContent = `Agende agora por R$ ${servicoAtual.preco.toFixed(2).replace('.', ',')}`;

        // Data padrão: hoje
        const dateInput = document.getElementById('agendamento-data');
        const hoje = new Date().toISOString().split('T')[0];
        dateInput.value = hoje;
        dateInput.min = hoje; // Impede agendar no passado

        // Limpar e construir acordeão
        const container = document.getElementById('accordion-container');
        container.innerHTML = '';

        resultado.horarios.forEach(horario => {
            const itemDiv = document.createElement('div');
            itemDiv.className = 'accordion-item';

            // Gerar avatar bolhas
            let bubbleHtml = '';
            resultado.profissionais.slice(0, 3).forEach(p => {
                bubbleHtml += `<div class="avatar-bubble" title="${p.nome}">${p.nome[0]}</div>`;
            });
            if (resultado.profissionais.length > 3) {
                bubbleHtml += `<div class="avatar-bubble">+${resultado.profissionais.length - 3}</div>`;
            }

            itemDiv.innerHTML = `
                <div class="accordion-header">
                    <div class="accordion-header-left">
                        <span class="time-label">⏱️ ${horario}</span>
                        <div class="accordion-avatars">${bubbleHtml}</div>
                    </div>
                    <div class="accordion-header-left">
                        <span class="price-label">R$ ${servicoAtual.preco.toFixed(2).replace('.', ',')}</span>
                        <svg viewBox="0 0 24 24" fill="none" stroke="currentColor" stroke-width="2">
                            <polyline points="6 9 12 15 18 9"></polyline>
                        </svg>
                    </div>
                </div>
                <div class="accordion-body">
                    <div class="booking-controls">
                        <div class="prof-choice-col">
                            <h4>Gostaria de escolher um profissional específico?</h4>
                            <div class="radio-group">
                                <label class="radio-option">
                                    <input type="radio" name="opt-prof-${horario}" value="qualquer" checked onclick="toggleProfList('${horario}', false)">
                                    Não, pode ser qualquer um.
                                </label>
                                <label class="radio-option">
                                    <input type="radio" name="opt-prof-${horario}" value="escolher" onclick="toggleProfList('${horario}', true)">
                                    Sim, gostaria de escolher.
                                </label>
                            </div>
                            
                            <!-- Lista de Profissionais -->
                            <div class="prof-list-container" id="prof-list-${horario}">
                                ${resultado.profissionais.map(p => `
                                    <div class="prof-card" onclick="selectProfCard(this, ${p.id})">
                                        <div class="prof-info">
                                            <div class="avatar-bubble">${p.nome[0]}</div>
                                            <span class="prof-name">${p.nome}</span>
                                        </div>
                                        <span class="prof-rating">${p.nota.toFixed(1)} ★</span>
                                    </div>
                                `).join('')}
                            </div>
                        </div>
                        
                        <button class="btn btn-orange" onclick="processarReserva('${horario}')">Adicionar ao carrinho</button>
                    </div>
                </div>
            `;

            // Clique do Acordeão
            itemDiv.querySelector('.accordion-header').addEventListener('click', () => {
                const isOpen = itemDiv.classList.contains('open');
                // Fecha todos os outros
                document.querySelectorAll('.accordion-item').forEach(i => i.classList.remove('open'));
                if (!isOpen) {
                    itemDiv.classList.add('open');
                }
            });

            container.appendChild(itemDiv);
        });

        alternarVisualizacao('view-agendamento');
    } catch (e) {
        alert('Erro ao carregar dados do serviço.');
    }
}

// Helpers do Acordeão
window.toggleProfList = function (horario, show) {
    const list = document.getElementById(`prof-list-${horario}`);
    list.style.display = show ? 'flex' : 'none';
    if (!show) {
        // Remove seleção anterior
        list.querySelectorAll('.prof-card').forEach(c => c.classList.remove('selected'));
    }
};

window.selectProfCard = function (element, profId) {
    const parent = element.parentElement;
    parent.querySelectorAll('.prof-card').forEach(c => c.classList.remove('selected'));
    element.classList.add('selected');
    parent.dataset.selectedProfId = profId;
};

// 5. RESERVA DIRETA
window.processarReserva = function (horario) {
    const dataAgendada = document.getElementById('agendamento-data').value;
    const list = document.getElementById(`prof-list-${horario}`);
    const chooseSpecific = document.querySelector(`input[name="opt-prof-${horario}"]:checked`).value === 'escolher';

    let profissionalId = null;

    if (chooseSpecific) {
        profissionalId = list.dataset.selectedProfId;
        if (!profissionalId) {
            alert('Por favor, selecione um profissional da lista.');
            return;
        }
    } else {
        // Pega o primeiro da lista como "Qualquer um" padrão
        const firstCard = list.querySelector('.prof-card');
        // Se houver algum cadastrado
        if (firstCard) {
            // Um clique simulado no HTML para pegar ID ou ler de alguma forma
            // Vamos apenas extrair da primeira associação disponível
            profissionalId = 1; // Padrão Vanessa
        }
    }

    agendamentoPendente = {
        servico_id: servicoAtual.id,
        profissional_id: parseInt(profissionalId),
        data_hora: `${dataAgendada} ${horario}`
    };

    if (!usuarioLogado) {
        alert('Você precisa fazer login ou cadastrar-se para confirmar o pagamento.');
        abrirModal(modalLogin);
    } else {
        abrirModal(modalCartao);
    }
};

// 6. MEU PERFIL (CRUD DO CLIENTE)
async function carregarAgendamentosUsuario() {
    const corpo = document.getElementById('perfil-tabela-corpo');
    corpo.innerHTML = '<tr><td colspan="6" style="text-align: center;">Carregando agendamentos...</td></tr>';

    try {
        const dados = await apiFetch(API_AGENDAMENTOS);
        corpo.innerHTML = '';
        if (dados.length === 0) {
            corpo.innerHTML = '<tr><td colspan="6" style="text-align: center;">Você não possui agendamentos pagos.</td></tr>';
            return;
        }

        dados.forEach(item => {
            const tr = document.createElement('tr');

            // Formatando data
            const partes = item.data_hora.split(' ');
            const dataPartes = partes[0].split('-');
            const dataFormatada = `${dataPartes[2]}/${dataPartes[1]}/${dataPartes[0]} às ${partes[1]}h`;

            tr.innerHTML = `
                <td><strong>${item.servico_nome}</strong></td>
                <td>${item.profissional_nome}</td>
                <td>${dataFormatada}</td>
                <td>R$ ${item.servico_preco.toFixed(2).replace('.', ',')}</td>
                <td><span class="status-label" style="color: #2e7d32;">${item.status}</span></td>
                <td>
                    <div class="actions">
                        <button class="btn-profile-edit" onclick="iniciarReagendamento(${item.id}, ${item.servico_id}, '${partes[0]}', '${partes[1]}', ${item.profissional_id})">Reagendar</button>
                        <button class="btn-profile-cancel" onclick="cancelarAgendamentoUsuario(${item.id})">Cancelar</button>
                    </div>
                </td>
            `;

            corpo.appendChild(tr);
        });
    } catch (e) {
        corpo.innerHTML = '<tr><td colspan="6" style="text-align: center; color: red;">Erro ao buscar dados do perfil.</td></tr>';
    }
}

// Reagendar (UPDATE)
window.iniciarReagendamento = async function (id, servicoId, dataAtual, horarioAtual, profissionalId) {
    try {
        const resultado = await apiFetch(`${API_AGENDAMENTOS}?servico_id=${servicoId}`);
        const selectProf = document.getElementById('reagenda-profissional');
        const selectHorario = document.getElementById('reagenda-horario');

        selectProf.innerHTML = '';
        resultado.profissionais.forEach(p => {
            const opt = document.createElement('option');
            opt.value = p.id;
            opt.textContent = p.nome;
            if (p.id === profissionalId) opt.selected = true;
            selectProf.appendChild(opt);
        });

        selectHorario.innerHTML = '';
        resultado.horarios.forEach(h => {
            const opt = document.createElement('option');
            opt.value = h;
            opt.textContent = h;
            if (h === horarioAtual) opt.selected = true;
            selectHorario.appendChild(opt);
        });

        document.getElementById('reagenda-id').value = id;
        document.getElementById('reagenda-data').value = dataAtual;

        abrirModal(modalReagendar);
    } catch (e) {
        alert('Erro ao carregar dados de reagendamento.');
    }
};

// Cancelar (DELETE)
window.cancelarAgendamentoUsuario = async function (id) {
    if (!confirm('Deseja realmente cancelar este agendamento pago? O reembolso será processado no seu cartão.')) return;

    try {
        const resultado = await apiFetch(`${API_AGENDAMENTOS}?id=${id}`, 'DELETE');
        alert(resultado.message);
        carregarAgendamentosUsuario();
    } catch (e) {
        alert('Erro ao cancelar agendamento.');
    }
};
