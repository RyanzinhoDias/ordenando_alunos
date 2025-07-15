#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct {
    char nome[50];
    int matricula;
    float media;
} Aluno;

void ordenacao_media(Aluno *vetor, int tamanho){
    int menor_indice;

    for(int indice = 0; indice < tamanho; indice++){
        menor_indice = indice;
        
        for(int segundo_indice = menor_indice; segundo_indice < tamanho; segundo_indice++){
            if(vetor[menor_indice].media > vetor[segundo_indice].media){
                menor_indice = segundo_indice;
            }
        }
        
        if(vetor[indice].media > vetor[menor_indice].media){
            Aluno auxiliar = vetor[menor_indice];
            vetor[menor_indice] = vetor[indice];
            vetor[indice] = auxiliar;
        }

    }

}

void ordenacao_alfabetica(Aluno *vetor, int tamanho){

    for(int indice = 0; indice < tamanho; indice++){
        int result;
        
        for(int segundo_indice = indice+1; segundo_indice < tamanho; segundo_indice++){
            result = strcmp(vetor[indice].nome, vetor[segundo_indice].nome);
        
            if(result > 0){
                Aluno auxiliar = vetor[indice];
                vetor[indice] = vetor[segundo_indice];
                vetor[segundo_indice] = auxiliar;
            }
        }
    }
}

void menu(){
    printf("\n1-Ordenação Alfabetica;\n2-Ordenação por média\n");
}
void exibir(Aluno *vetor, int tamanho){
    for (int p = 0; p < tamanho; p++){
        printf("\n%s || %d || %.2f\n", vetor[p].nome, vetor[p].matricula, vetor[p].media);
    }
}

int main(){
    Aluno aluno;
    int tamanho;

    printf("Digite quantos alunos serão cadastrados: ");
    scanf("%d", &tamanho);
    
    Aluno *vetor_aluno = (Aluno*) malloc(tamanho * sizeof(aluno));
    
    if(vetor_aluno == NULL){
        printf("Alocação de memória falhou.");
        return 1;
    }
    
    for(int i = 0; i < tamanho; i++){
        printf("Digite o primeiro nome: ");
        scanf("%s", vetor_aluno[i].nome);
        getchar();
        printf("Digite a matricula: ");
        scanf("%d", &vetor_aluno[i].matricula);
        printf("Digite a média: ");
        scanf("%f", &vetor_aluno[i].media);  
    }

    int opcao;
    do {
        menu();
        printf("Digite a opção desejada: ");
        scanf("%d", &opcao);

        switch (opcao){
        case 1:
            ordenacao_alfabetica(vetor_aluno, tamanho);
            exibir(vetor_aluno, tamanho);
            break;
        case 2:
            ordenacao_media(vetor_aluno, tamanho);
            exibir(vetor_aluno, tamanho);
            break;
        default:
            printf("Finalizando programa...\n\n");
            break;
        }
    } while (opcao != 0);

    return 0;
}