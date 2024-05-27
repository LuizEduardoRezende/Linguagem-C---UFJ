
#include<stdio.h> 
#include<stdlib.h> 
#define tamanhoDoEspaco 10 
//usada para definir os espacos entre os item da arvore na impressão da arvore 

int rot_dir = 0, rot_esq = 0;

typedef struct ITEM
{
	int valor;
}tipoItem;

typedef struct NOH
{
	tipoItem item;
	struct NOH *esquerda;
	struct NOH *direita;
}tipoNoh;

tipoItem criarItem(int valor){

	tipoItem item;
	item.valor = valor;
	return item;
}

tipoNoh *alocar(){

		tipoNoh *novoNoh = (tipoNoh*) malloc(sizeof(tipoNoh));
		if (novoNoh != NULL)
		{
			return novoNoh;
		}else{
			printf("Erro ao criar novo nó\n");
			exit(1); //interrompe o programa
		}
}

tipoNoh *inicializar(){
	return NULL;
}


tipoNoh *minimo(tipoNoh *raiz){

	if (raiz != NULL)
	{
		tipoNoh *nohAuxiliar = raiz;
		while(nohAuxiliar->esquerda != NULL){
			nohAuxiliar = nohAuxiliar->esquerda;
		}
		return nohAuxiliar;
	}
	return NULL;
}

tipoNoh *rotacaoDireita(tipoNoh *raiz) 
{ 
    rot_dir++;
	tipoNoh *nohAuxiliar = raiz->esquerda; 
	raiz->esquerda = nohAuxiliar->direita; 
	nohAuxiliar->direita = raiz; 
	return nohAuxiliar; 
} 

tipoNoh *rotacaoEsquerda(tipoNoh *raiz) 
{ 
    rot_esq++;
	tipoNoh *nohAuxiliar = raiz->direita;
	raiz->direita = nohAuxiliar->esquerda; 
	nohAuxiliar->esquerda = raiz; 
	return nohAuxiliar;
} 

tipoNoh *splay(tipoNoh *raiz, int valor) 
{ 
    // Caso base: Se a raiz for nula ou o valor já está na raiz, retorna a raiz atual.
    if (raiz == NULL || raiz->item.valor == valor) 
        return raiz; 

    // Verifica se o valor está na subárvore esquerda.
    if (raiz->item.valor > valor) 
    { 
        // Caso o valor não esteja na subárvore, retorna a raiz atual.
        if (raiz->esquerda == NULL) 
            return raiz; 

        // Zig-Zig (esquerda esquerda): Faz rotação para a direita.
        if (raiz->esquerda->item.valor > valor)  
        {  
            // Splay no neto (esquerdo) da esquerda (zig-zig)
            raiz->esquerda->esquerda = splay(raiz->esquerda->esquerda, valor);  
            // Rotação para a direita para trazer o neto (esquerdo) para a raiz.
            raiz = rotacaoDireita(raiz); 
        } 
        else if (raiz->esquerda->item.valor < valor) // Zig-Zag (esquerda direita): Faz duas rotações.
        { 
            // Splay no filho (direito) da esquerda (zig-zag)
            raiz->esquerda->direita = splay(raiz->esquerda->direita, valor); 
            // Rotação para a esquerda na subárvore esquerda.
            if (raiz->esquerda->direita != NULL) 
                raiz->esquerda = rotacaoEsquerda(raiz->esquerda); 
        } 

        // Retorna a nova raiz após a operação Splay.
        return (raiz->esquerda == NULL) ? raiz : rotacaoDireita(raiz);	
    } 
    // Se o valor está na subárvore direita.
    else if (raiz->item.valor < valor) 
    { 
        // Caso o valor não esteja na subárvore, retorna a raiz atual.
        if (raiz->direita == NULL) 
            return raiz; 

        // Zag-Zig (direita esquerda): Faz duas rotações.
        if (raiz->direita->item.valor > valor) 
        { 
            // Splay no filho (esquerdo) da direita (zag-zig)
            raiz->direita->esquerda = splay(raiz->direita->esquerda, valor); 
            // Rotação para a direita na subárvore direita.
            if (raiz->direita->esquerda != NULL) 
                raiz->direita = rotacaoDireita(raiz->direita); 
        } 
        // Zag-Zag (direita direita): Faz rotação para a esquerda.
        else if (raiz->direita->item.valor < valor) 
        { 
            // Splay no filho (direito) da direita (zag-zag)
            raiz->direita->direita = splay(raiz->direita->direita, valor); 
            // Rotação para a esquerda para trazer o filho (direito) para a raiz.
            raiz = rotacaoEsquerda(raiz); 
        } 

        // Retorna a nova raiz após a operação Splay.
        return (raiz->direita == NULL) ? raiz : rotacaoEsquerda(raiz);
    } 
} 



tipoNoh *pesquisar(tipoNoh *raiz, int valor) 
{ 
	return splay(raiz, valor); 
} 

tipoNoh *inserir(tipoNoh *raiz, tipoItem item){
	
	if (raiz == NULL)
	{
		//inserir na árvore vazia
		tipoNoh *novoNoh = alocar();
		novoNoh->item = item;
		novoNoh->esquerda = NULL;
		novoNoh->direita = NULL;
		return novoNoh;
	}else{

		if (item.valor > raiz->item.valor)
		{
			//inserir na direita se for maior que a raiz
			raiz->direita = inserir(raiz->direita, item);

		}else if(item.valor < raiz->item.valor){
			//inserir na esquerda se for menor 
			raiz->esquerda = inserir(raiz->esquerda, item);
		}

	}
		return raiz;
}


tipoNoh *remover(tipoNoh *raiz, int valor){

	if (raiz != NULL)
	{
		if (valor > raiz->item.valor)
		{
			//busca na direita 
			raiz->direita = remover(raiz->direita, valor);
		
		}else if (valor < raiz->item.valor)
		{
			//busca na esquerda 
			raiz->esquerda = remover(raiz->esquerda, valor);
		}
		else //encontrou o elemento a ser removido
		{
			//removendo nó folha
			if (raiz->esquerda == NULL && raiz->direita == NULL)
			{
				free(raiz);
				raiz = NULL;

				return NULL;
			}
			else if (raiz->esquerda == NULL && raiz->direita != NULL)
			{
				//faz a ponte de ligação com a sub Arvore direita
				tipoNoh *nohAuxiliar = raiz->direita; //salva  a sub Arvore direita
				free(raiz); //apaga o nó onde a fun está no momento
				raiz = NULL;
				return nohAuxiliar; //retorna pro ant do nó excluido a subArv dir
			}
			else if (raiz->esquerda != NULL && raiz->direita == NULL)
			{
				//faz a ponte de ligação com a sub Arvore esquerda
				tipoNoh *nohAuxiliar = raiz->esquerda;
				free(raiz);
				raiz = NULL;
				return nohAuxiliar;
			}
			else{
				//remover quando tiver 2 filhos
				tipoNoh *nohAuxiliar = minimo(raiz->direita); //descobre o minimo da sub Arvore direita
				tipoItem itemAuxiliar = nohAuxiliar->item; //faz uma cópia do item minimo (que será a nova raiz)
				raiz = remover(raiz, itemAuxiliar.valor); //remove a nó minimo
				raiz->item = itemAuxiliar; //faz a raiz receber a cópia do novo nó raiz
			}
		}

		return raiz;

	}
	else{

		return NULL;

	}

}

void imprimir(tipoNoh *raiz, int espaco) 
{ 
    //Caso base 
    if (raiz == NULL){ 
        return; 
    }else{
    //Aumentar a distância entre os níveis 
    espaco += tamanhoDoEspaco; 

    //Trabalhando com a sub Arvore direita 
    imprimir(raiz->direita, espaco); 
  
    // Imprimir nó após o espaço 
    printf("\n"); 
    for (int i = tamanhoDoEspaco; i < espaco; i++) {
        printf(" "); 
    }

    printf("%d\n", raiz->item.valor); 
  
    //Trabalhando com a sub Arvore direita
    imprimir(raiz->esquerda, espaco); 
	}
}
 
void apagarArvore(tipoNoh *raiz)
{
	//Funcao para liberar a memoria utilizada pela arvore
	if (raiz != NULL)
	{
		apagarArvore(raiz->esquerda);
		apagarArvore(raiz->direita);
		free(raiz);
		raiz = NULL;
	}

}

int main() 
{ 
	 
	tipoNoh *raiz = inicializar();
	int opcao=-1;
	int valor=0;

	while(opcao!=0){

		printf("\n---Arvore atual---\n");
		imprimir(raiz, tamanhoDoEspaco);

		
		valor=0;
		printf("\n---------------MENU---------------\n");
		printf("1: Inserir \n");
		printf("2: Remover \n");
		printf("3: Pesquisar \n");
		printf("0: SAIR \n");
		scanf("%d", &opcao);

		switch(opcao){

			case 1:
			printf("\n------INSERINDO------\n");
			printf("Digite um valor\n");
			scanf("%d",&valor);
			raiz = inserir(raiz,criarItem(valor) );
			raiz = splay(raiz, valor);

			break;

			case 2:
			printf("\n------REMOVENDO------\n");
			printf("Digite um valor\n");
			scanf("%d",&valor);
			raiz = splay(raiz, valor);
			raiz = remover(raiz, valor);
			break;

			case 3:
			printf("\n------PESQUISANDO------\n");
			printf("Digite um valor\n");
			scanf("%d",&valor);

			raiz = pesquisar(raiz, valor);
			if (raiz->item.valor == valor)
			{
				printf("\nElemento encontrado com sucesso!\n");
			}else {
				printf("\nElemento nao encontrado! \n");
			}
			break;

			case 0:
            printf("Rotacoes para direita: %d\n", rot_dir);
            printf("Rotacoes para esquerda: %d\n", rot_esq);
			printf("\nTchau! Ate a proxima\n");
			break;

			default:
			printf("\nOpcao inválida! \n");
			break;
		}


	}
		apagarArvore(raiz);

	return 0; 
}