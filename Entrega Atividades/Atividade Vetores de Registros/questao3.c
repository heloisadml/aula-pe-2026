/*
3ªQuestão: O Banco Dinheiro Certo deseja automatizar os cadastros de contas de seus
clientes. São dois cadastros: o de conta corrente e o de conta poupança. Nos cadastros
devem constar as seguintes informações: número da conta, nome e o cpf do cliente, um
telefone de contato e o saldo. Faça um programa para criar e manipular os cadastros de
conta do banco. Cada cadastro deve ser implementado como um vetor de estruturas. O
programa deve conter os seguintes subprogramas:

(a) Uma função de busca. Esta função irá receber como parâmetro o cadastro a ser
pesquisado e o número da conta procurada e irá retornar a posição no cadastro
onde a conta foi encontrada. Caso o cadastro esteja vazio, a função deve retornar
-1 e, caso não encontre o valor, a função deve retornar -2;
(b) Um procedimento para cadastrar uma nova conta. Este procedimento irá receber
como parâmetro o cadastro onde a conta será inserida e o número da nova conta.
O procedimento deverá certificar-se que aquele número de conta não consta no
cadastro. Para tal, ele irá utilizar a função definida no item (a). Caso já conste,
deve avisar ao usuário que não poderá fazer o cadastramento, pois se trata de um
número de conta repetido. Caso não conste, o procedimento deve prosseguir com
o cadastramento, solicitando o restante dos dados e inserindo a nova conta no
final do cadastro;
(c) Um procedimento para consultar o saldo de uma conta. Este procedimento irá
receber como parâmetro o cadastro a ser pesquisado e o número da conta a ser
consultada. Fará uma busca utilizando a função definida no item (a). Se a conta
existir no cadastro, o procedimento deverá informar seu saldo; caso contrário, o
procedimento deverá informar que a conta não está cadastrada.
(d) Um procedimento para fazer um depósito em uma conta. Este procedimento irá
receber como parâmetro o cadastro a ser pesquisado e o número da conta onde
será efetuado o depósito. Fará uma busca utilizando a função definida no item (a).
Se a conta existir no cadastro, o procedimento deverá solicitar o valor e efetuar o
depósito; caso contrário, o procedimento deverá informar que a conta não está
cadastrada.
(e) Um procedimento para fazer um saque em uma conta. Este procedimento irá
receber como parâmetro o cadastro a ser pesquisado e o número da conta onde
será efetuado o saque. Fará uma busca utilizando a função definida no item (a).
Se a conta não existir no cadastro, o procedimento deverá informar que a conta
não está cadastrada. Se a conta existir, o procedimento deverá solicitar o valor e,
caso haja saldo suficiente, efetuar o saque; caso contrário, o procedimento deverá
informar que não existe saldo suficiente.
(f) Um procedimento para exibir o número da conta, o nome do titular e o telefone
para contato de todas as contas de um determinado cadastro. Este procedimento
irá receber como parâmetro o cadastro cujos valores serão exibidos.
OBS: Suponha que cada cadastro pode armazenar, no máximo, os dados relativos a 100
(cem) contas.
*/