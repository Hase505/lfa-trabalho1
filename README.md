# Simulador de AFD (Autômato Finito Determinístico)

Projeto desenvolvido como parte da disciplina **Linguagens Formais e Autômatos**, do curso de Ciência da Computação (campus Foz do Iguaçu), sob orientação do professor Rômulo Silva.

## 🧠 Objetivo

Este projeto tem como objetivo implementar um **simulador de AFD** que:

- Lê a definição de um autômato a partir de um arquivo de texto;
- Permite ao usuário testar cadeias, mostrando o passo a passo do processamento;
- Imprime a gramática regular equivalente ao AFD carregado.

## 💡 Especificações

- Linguagem utilizada: **C++**
- Interface: **linha de comando (prompt do sistema operacional)**
- O alfabeto de entrada pode conter **letras minúsculas** e/ou **dígitos**
- O símbolo **`@`** representa a **palavra vazia**

## 📄 Formato do Arquivo de Entrada

O autômato deve ser descrito em um arquivo `.txt` com o seguinte formato:

```
alfabeto={a,b,c,0,1,2}
estados={q0,q1,q2,q3,q4,q5}
finais={q2,q5}
(q0,a)=q1
(q1,a)=q2
(q1,b)=q1
(q1,0)=q4
(q2,c)=q3
(q3,b)=q2
(q3,0)=q5
(q4,0)=q2
(q4,1)=q5
(q5,2)=q4
```

- A primeira linha define o alfabeto.
- A segunda linha define os estados.
- A terceira linha define os estados finais.
- A partir da quarta linha são listadas as transições, uma por linha.

## ⚙️ Funcionalidades

- Carrega a especificação do AFD a partir de um arquivo `.txt`
- Permite entrada de cadeias para teste
- Mostra o passo a passo do processamento de cada cadeia
- Informa se a cadeia foi **aceita** ou **rejeitada**
- Imprime a **gramática regular equivalente**

## 📋 Exemplo de Saída

### Cadeia: `ab00cb`

```
[q0]ab00cb
[q1]b00cb
[q1]00cb
[q4]0cb
[q2]cb
[q3]b
[q2]
ACEITA
```

### Cadeia: `abbac`

```
[q0]abbac
[q1]bbac
[q1]bac
[q1]ac
[q2]c
[q3]
REJEITA
```

### Cadeia vazia: `@`

```
[q0]@
REJEITA
```

### Gramática regular equivalente:

```
S -> aA
A -> bA | aB | 0C
B -> cD | @
C -> 0B | 1E
D -> bB | 0E
E -> 2C | @
```