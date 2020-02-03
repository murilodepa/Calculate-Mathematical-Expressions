# Calcular Expressões Matemáticas

## Projeto baseado em uma calculadora de expressões matemáticas, utilizando pilha e lista ligada para resolução dos cálculos e manipulação dos dados lidos.

### Descrição do Projeto
   * Esse projeto tem o intuito realizar operações matemáticas e de aprender e aprimorar os conhecimentos relacionados a lista ligada e pilha, Primeiramente o usuário digita uma expressão matemática, contendo apenas letras ou uso de parênteses, as letras podendo ser negativas ou não, em relação aos parênteses, pode-se dizer que esse é o grande diferencial do projeto, ele consegue realizar operações respeitando as leis matemáticas e as prioridades de operações. 
  * Após o usuário pressionar *ENTER*, o programa executará uma função, responsável por *desempilhar a expressão* para verificar sua validade, pois precisa analisar a formatação dos parênteses digitadas e ocorrências ne número, alertando o usuário e permitindo que ele reescreva a expressão corretamente. Após a verificação, a expressão no formato *INFIXA*, como nós descrevemos, considerada um notação tradicional, onde o operador aparece entre os seus dois operandos, é transformada em *PÓS-FIXA* com um auxílio de uma pilha. A notação *PÓS-FIXA*, conhecida também, como notação polonesa inversa, o operador é colocado após os seus dois operandos. Precisa-se realizar essa transformação, pois é através da função *PÓS-FIXA* que o programa irá realizar os cálculos e respeitas as prioridades da expressão, abaixo podemos estar observando uma simulação do programa em tempo de execução:
   
* Abaixo pode ser observado a "entrada dos dados", o comportamento do programa e o que é impresso:
![calculadora](https://user-images.githubusercontent.com/56207941/66770722-aefb9200-ee8e-11e9-9303-2bf02e41e7dc.PNG)

* Agora pode-se observar o que ocorre caso o usuário digita uma expressão inválida, o programa verifica essas 3 condições e retorna a mensagem de erro:
![Erro Calculadora](https://user-images.githubusercontent.com/56207941/66770871-0f8acf00-ee8f-11e9-8cb9-c8338761692c.PNG)

* <a> [Entenda a diferença e transformação de *INFIXA* para *PÓS-FIXA*](http://www.vision.ime.usp.br/~pmiranda/mac122_2s14/aulas/aula13/aula13.html)

 ### Pré-requisitos

#### Sistema Operacional
* Foi utilizado o Windows 10, mas pode ser realizado em outro sistema operacional, necessita instalar o compilador compatível com o sistema operacional.

 #### Compilador
* Foi utilizado o ambiente integrado de desenvolvimento Code::Blocks e a implementação Mingw do GCC (GNU Compiler Collection) como seu compilador.
* <a> [Code::Blocks: Necessário para desenvolvimento do projeto](http://www.codeblocks.org/downloads/26)
  
 #### Bibliotecas
* #include <iostream>
* #include <stdio.h>
* #include <stdlib.h>
* #include <conio.h>
* #include <ctype.h>
* #include <windows.h> 
* #stackld-1.h //Anexada neste repositório

   * **Observação:** Para desenvolver este projeto, precisa apenas de conhecimentos básicos sobre lógica de programação e linguagem de programação C++.

### Guia de instalação
* Para executar o programa na linguagem C++, no qual o algoritmo foi realizado, necessita apenas de um compilador e uma IDE que compile e execute essa linguagem de programação, no caso do projeto, foi utilizado o Code::Blocks e o compilador Mingw do GCC como já descrito, não precisando de nenhuma outra ferramenta adicional ou especial, esse programa pode ser obtido no link acima, mas também, pode estar sendo utilizado outros softwares para o desenvolvimento deste projeto ou similar.

### Desenvolvimento
* Git clone https://github.com/murilodepa/Calculate-Mathematical-Expressions.git
* Se realizar "Download ZIP", necessita de um descompactador de arquivos.
* Após ter instalado o Code::Blocks ou outro programa similar, execute-o e selecione "arquivo" e depois "abrir projeto".
* Selecione o diretório onde está salvo o arquivo e depois selecione a opção abrir.
* Logo em seguida, selecione a opção executar e o programa começará a ser executado.

### Contribuições
- Contribuições e possíveis melhorias, no meu ponto de vista são sempre bem-vindas.

