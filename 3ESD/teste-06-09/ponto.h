typedef struct ponto Ponto;

Ponto* ptoCria (float x, float y);

void ptoLibera (Ponto* p);

void ptoAcessa (Ponto* p, float* x, float* y);

void ptoAtribui (Ponto* p, float x, float y);

float ptoDistancia (Ponto* p1, Ponto* p2);

char* ptoGetPonto (Ponto* p);

void ptoExibe (Ponto* p);

int ptoCompara (Ponto* p1, Ponto* p2);

Ponto* ptoSoma (Ponto* p1, Ponto* p2);

Ponto* ptoCopia (Ponto* p);