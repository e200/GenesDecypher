# GeneDecypher

GeneDecypher é um decifrador de código genético para amino ácidos, escrito em C, feito para um cliente estudante da Universidade Metodista de Angola.

## Como funciona o decifrador?

Primeiro compile o arquivo `decifrador_de_genes.c` e execute o arquivo compilado assim:

`./arquivo_compilado dados/proteina dados/sequencia_genetica`.

Este decifrador genético vai ler cada arquivo passado como parámetro (`dados/proteina` e `dados/sequencia_genetica`) e recolherá as amostras contidas neles.

Estas amostras serão analisadas internamente até não ser mais possível analisá-las ou o código genético ter cido decifrado.

## Como descobrir um código genético de um amino ácido?

Considere a seguinte proteína: `M  S  I  Q  H  M  R`.

Cada letra dessa proteína representa um amino ácido.

Cada amino ácido possui um códon.

Cada codón possui 3 nucleotide.

Um nucleotide é representado pelas letras {A, C, T, G}.

Perceba tudo isso nessa tabéla:

                   col

          | M | H | I | S | Y |          TODAS AS LETRAS FORMAM A PROTEÍNA.
    Lin   |AGT|TTT|GGA|AAG|ATA|          CADA LETRA TEM O SEU CODÓN.

Lembrando que cada amino ácido só pode conter 3 letras no seu código genético.

Vamos então decifrar o código genético dos nossos amino ácidos:

`M  S  I  Q  H  M  R`.

Essa é a nossa sequência genética:
`attgctagcaatgctagcaattgctagcaattcat`.

Para decifrar uma sequência genética, não podemos ter dois amino ácidos com codóns iguais:

```
attgctagcaatgctagcaattgctagcaattcat
M  S  I  Q  H  M  R.
```

Observe que neste caso **S** e **H** são iguais (têm os mesmos codóns), então tentamos novamente avançando uma letra:

```
attgctagcaatgctagcaattgctagcaattcat
 M  S  I  Q  H  M  R.
```

Observe que neste caso **S** e **H** são iguais, então tentamos novamente avançando mais uma letra:

```
attgctagcaatgctagcaattgctagcaattcat
  M  S  I  Q  H  M  R.
```

Observe que neste caso **MS** e **QH** são iguais, então, fazendo o mesmo processo várias e várias vezes chengamos a esta sequência:

```
attgctagcaatgctagcaattgctagcaattcat
          M  S  I  Q  H  M  R.
```

Neste caso não temos proteínas com codóns iguais? Todos codóns são diferentes. Isso significa que `atgctagcaattgctagcaat` é o nosso código genético decifrado.

Difícil e chato né??? Mas é o processo de decifrar um código genético e é o mesmo processo de biologia computacional que o GeneDecypher faz.
