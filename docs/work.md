\[[Volta](../../ci057.html)\]

CI 057 - Algoritmos e Estrutura de Dados III
============================================

Trabalho prático - AVL
----------------------

2020-ERE

### Objetivo

Neste exercício relativamente simples iremos implementar a inclusão e exclusão de valores de árvore AVL vista em sala de aula.

### Entrada:

A entrada deve ser feita pela entrada padrão (`stdin`). O arquivo é formado por uma sequência de linhas, onde cada linha representa uma operação com uma chave inteira chegando. A ordem das operações é aleatória. Cada operação pode ser de inclusão (i) ou remoção (r). Portanto, o primeiro campo é o tipo da operação e o segundo campo é a chave. Por exemplo, "i 10" significa a inclusão da chave 10 na AVL.

### Saída:

A saída deve ser feita pela saída padrão (`stdout`). A escrita na saída pode acontecer quando a árvore toda for criada. O arquivo será composto por uma sequência de linhas. Uma linha para cada valor lido no formato (valor, nivel). Portanto, cada linha tem 2 campos separados por vírgula. O primeiro campo é o valor lido "inorder". O segundo campo é o nivel da árvore na qual o valor se encontra de acordo com o algoritmo AVL. A saida será ordenada pelo primeiro campo e em seguida pelo segundo campo em caso de chaves duplicadas na árvore.

Exemplo de arquivos com uma entrada e uma saída válida:

Entrada

AVL esperada

Saída

****

i 4

i 6

i 1

i 2

i 7

i 3

i 5

i 8

r 8

**

**

4

/ \\

2 6

/ \\ / \\

1 3 5 7

1,2

2,1

3,2

4,0

5,2

6,1

7,2

### Casos de teste:

[teste1.in](teste1.in) [teste1.out](teste1.out) [teste2.in](teste2.in) [teste2.out](teste2.out) [teste3.in](teste3.in) [teste3.out](teste3.out) [teste4.in](teste4.in) [teste4.out](teste4.out)

### Requisitos mínimos:

O trabalho deve ser feito de forma que possa ser compilado e executado nas servidoras de computação do Departamento de Informática. Além disso, o executável não deve ter nenhuma opção de linha comando. O nome do executável deve ser: **myavl.**

**IMPORTANTE:** **Mesmo que a implementação seja em alguma linguagem interpretada deve-se gerar um comando executável "myavl" (e.g., criar alias via bash).**

O que deve ser entregue:
------------------------

Além dos arquivos fonte, deve acompanhar um `makefile` e um relatório com no máximo 2 páginas contendo a documentação sintetizada do sistema implementado. Qualquer particularidade deve estar descrita neste texto, como: algoritmo de busca e ordenação utilizados.

Para compilar será usado o comando `make` (sem nenhum parâmetro), portanto preparem o Makefile para fazer isso mesmo que o programa seja implementado em linguagens interpretadas (e.g., Java).

Para testar será executado um script como o abaixo.

$ ./myavl < teste.in > teste.out
$ diff teste.sol teste.out

Onde `teste.in` é o arquivo de entrada do teste e `teste.sol` é o esperado como saída.  
Caso o teste seja positivo (não imprime nada) será analisado o código fonte e o relatório.  
Os fontes também devem ser comentados para uma possível análise (e.g., Javadoc).

Forma de entrega:
-----------------

O trabalho deve ser empacotado em um arquivo login.tar.gz, onde "login" é uma string com o login do aluno nas servidoras do DInf. Ao descompactar este arquivo deverá ser criado um diretório de nome "login" que conterá todos os demais arquivos. O `make` e o script acima deverão funcionar dentro deste diretório (não em subdiretórios).

Este arquivo deve ser enviado por e-mail ao endereço do professor com o assunto "CI057-trab" (exatamente). IMPORTANTE: Minha caixa de email usa o assunto do email como filtro.

Equipe:
-------

O trabalho pode ser realizado em equipe de até 2 alunos.