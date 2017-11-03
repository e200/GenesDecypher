/**
 * Este arquivo é parte do programa GeneDecypher.
 * 
 * Este arquivo contém uma função que lê os bytes
 * de um arquivo.
 * 
 * Data: 01/11/2017
 *
 * Autor: Eleandro Duzentos <eleandro@inbox.ru>
 * Repositório: https://github.com/e200/GenesDecypher/blob/master/
 */

#include <stdio.h>
#include <stdlib.h>

/**
 * Lê todos os bytes de um ficheiro
 * e armazena à saída.
 * 
 * O valor de retorno desta função
 * é o número de bytes lidos.
 */
int leia_amostra(char nome_arquivo[], char *saida)
{
    // Ponteiro para o ficheiro a ser lido.
    FILE *ptr_ficheiro;

    // Abrindo o arquivo,
    ptr_ficheiro = fopen(nome_arquivo, "r");

    // Aqui armazenaremos cada byte lido no arquivo.
    char byte;

    // Contador do número de bytes lidos.
    int num_bytes = 0;

    /**
     * Enquanto ouver bytes, leia e armazene.
     */
    while ((byte = getc(ptr_ficheiro)) != EOF)
    {
        // Armazenando o byte lido à daída.
        saida[num_bytes] = byte;

        // Contando o número de bytes.
        num_bytes++;
    }

    // Sempre limpe a casa (memória).
    fclose(ptr_ficheiro);

    // Está função retornará o número de bytes lidos.
    return num_bytes;
}