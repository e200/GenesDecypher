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
    ptr_prot     = fopen("dados/proteinas", "r");
    ptr_gene_seq = fopen("dados/sequencia_de_genes", "r");

    /**
     * Uma vez que iremos pegar cada carácter
     * de uma proteína carácter por carácter,
     * vamos armazenar cada carácter na variável
     * `c`.
     */
    char c;

    /**
     * Precisamos também de um contandor,
     * só assim saberemos qual carácter estamos
     * a ler actualmente.
     */
    int i = 0;

    /**
     * Aqui lemos cada carácter da nossa proteína,
     * e armazenamos no nosso vector `proteínas`.
     */
    while ((c = getc(ptr_prot)) != EOF)
    {
        proteinas[i] = c;

        i++;
    }
    
    /**
     * Já lemos o arquivo, vamos fechá-lo
     * para poupar memória.
     *
     * Dica: Esse é um dos motivos que faz
     * a maioria fugir do C, garbage colector.
     */
    fclose(ptr_prot);

    /**
     * Até aqui já temos as nossas proteínas.
     *
     * Vamos agora pegar os nossos codóns.
     */
    fclose(ptr_gene_seq);
    
    return 0;
}