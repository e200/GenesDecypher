/**
 * Autor: Eleandro Duzentos <eleandro@inbox.ru>
 * Repositório: https://github.com/e200
 *
 * Data: 
 */
#include <stdio.h>
#include <stdlib.h>

/**
  * Este é o número de combinações de codóns.
  * Vejam a tabela de codóns para entenderem.
  */
#define LIMITE_DE_CODONS 64

/**
 * Uma vez que não sabemos o número de proteinas
 * nem o número de carácteres das sequências, vamos
 * usar um array com 10000 índices cada, só para garantir.
 */
#define LIMITE_DE_PROTEINAS          1000
#define LIMITE_DA_SEQUENCIA_DE_GENES 10000

/**
 * O parámetro `argc` indica o número
 * de parámetros passados via terminal.
 *
 * O parámetro `argv` contem os parámetros
 * passados via terminal.
 */
int main(int argc, char *argv[])
{
    char
        // Vetor que armazenará os codons encontrados.
        codons[LIMITE_DE_CODONS],
        // Vetor que armazenara as proteinas extraídas.
        proteinas[LIMITE_DE_PROTEINAS],
        // Vetor que armazenara a sequência de gênes.
        sequencia_de_genes[LIMITE_DA_SEQUENCIA_DE_GENES];
        
    /**
      * Pointeiros que referenciarão os arquivos
      * contendo as proteínas e a sequência de gênes.
      */
    FILE
        *ptr_prot,
        *ptr_gene_seq;

    /**
    * Aqui vamos ler o conteúdo de cada arquivo
    * correspondente ao seu ponteiro.
    */
    ptr_prot     = fopen("proteinas", "r");
    ptr_gene_seq = fopen("sequencia_de_genes", "r");

    while (fgets(proteinas, 1000, ptr_prot))
    {
        printf("%s\n", proteinas);
    }

    while (fgets(sequencia_de_genes, 10000, ptr_gene_seq))
    {
        printf("%s\n", sequencia_de_genes);
    }

    fclose(ptr_prot);
    fclose(ptr_gene_seq);
    
    return 0;
}