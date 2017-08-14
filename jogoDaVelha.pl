%Tabuleiro.
newBoard([["1","2","3"], ["4","5","6"], ["7","8", "9"]]).
drawBoard([A,B,C]) :- write(A), nl, write(B), nl, write(C).

%Operações na matriz.
writeXOnBoard(1, [[H11|T1]|T], [["X"|T1]|T]).
writeXOnBoard(2, [[H11,H12|T1]|T], [[H11,"X"|T1]|T]).
writeXOnBoard(3, [[H11,H12,H13]|T], [[H11, H12, "X"]|T]).
writeXOnBoard(4, [H1,[H21|T2]|T], [H1,["X"|T2]|T]).
writeXOnBoard(5, [H1,[H21,H22|T2]|T], [H1,[H21, "X"|T2]|T]).
writeXOnBoard(6, [H1,[H21,H22,H23]|T], [H1,[H21,H22,"X"]|T]).
writeXOnBoard(7, [H1,H2,[H31|T3]], [H1,H2,["X"|T3]]).
writeXOnBoard(8, [H1,H2,[H31,H32|T3]], [H1,H2,[H31,"X"|T3]]).
writeXOnBoard(9, [H1,H2,[H31,H32,H33]], [H1,H2,[H31,H32,"X"]]).
writeOOnBoard(1, [[H11|T1]|T], [["O"|T1]|T]).
writeOOnBoard(2, [[H11,H12|T1]|T], [[H11,"O"|T1]|T]).
writeOOnBoard(3, [[H11,H12,H13]|T], [[H11, H12, "O"]|T]).
writeOOnBoard(4, [H1,[H21|T2]|T], [H1,["O"|T2]|T]).
writeOOnBoard(5, [H1,[H21,H22|T2]|T], [H1,[H21, "O"|T2]|T]).
writeOOnBoard(6, [H1,[H21,H22,H23]|T], [H1,[H21,H22,"O"]|T]).
writeOOnBoard(7, [H1,H2,[H31|T3]], [H1,H2,["O"|T3]]).
writeOOnBoard(8, [H1,H2,[H31,H32|T3]], [H1,H2,[H31,"O"|T3]]).
writeOOnBoard(9, [H1,H2,[H31,H32,H33]], [H1,H2,[H31,H32,"O"]]).

%Verificação de se o jogo acabou.
gameOver([[H11,H12,H13],[H21,H22,H23],[H31,H32,H33]]) :-
  H11\="1",H12\="2",H13\="3",
  H21\="4",H22\="5",H23\="6",
  H31\="7",H32\="8",H33\="9",
  write("Deu velha!").
gameOver([["X","X","X"]|T]) :- write("O primeiro jogador ganhou.").
gameOver([H11,["X","X","X"],H13]) :- write("O primeiro jogador ganhou.").
gameOver([H11,H12["X","X","X"]) :- write("O primeiro jogador ganhou.").
gameOver([["X"|T1],["X"|T2],["X"|T3]]) :- write("O primeiro jogador ganhou.").
gameOver([[H11,"X"|T1],[H21,"X"|T2],[H31,"X"|T3]]) :- write("O primeiro jogador ganhou.").
gameOver([[H11,H12,"X"],[H21,H22,"X"],[H31,H32,"X"]]) :- write("O primeiro jogador ganhou.").
gameOver([["X"|T1],[H21,"X"|T2],[H31,H32,"X"]]) :- write("O primeiro jogador ganhou.").
gameOver([[H11, H12, "X"],[H21,"X"|T2],["X"|T3]]) :- write("O primeiro jogador ganhou.").
gameOver([["O","O","O"]|T]) :- write("O segundo jogador ganhou.").
gameOver([H11,["O","O","O"],H13]) :- write("O segundo jogador ganhou.").
gameOver([H11,H12["O","O","O"]) :- write("O segundo jogador ganhou.").
gameOver([["O"|T1],["O"|T2],["O"|T3]]) :- write("O segundo jogador ganhou.").
gameOver([[H11,"O"|T1],[H21,"O"|T2],[H31,"O"|T3]]) :- write("O segundo jogador ganhou.").
gameOver([[H11,H12,"O"],[H21,H22,"O"],[H31,H32,"O"]]) :- write("O segundo jogador ganhou.").
gameOver([["O"|T1],[H21,"O"|T2],[H31,H32,"O"]]) :- write("O segundo jogador ganhou.").
gameOver([[H11, H12, "O"],[H21,"O"|T2],["O"|T3]]) :- write("O segundo jogador ganhou.").

%Verificações requeridas na especificação.
validateX(X) :- ganharX(X).
validateO(X) :- ganharO(X).
validateX(X).
validateO(X).

ganharX([[H11,"X","X"]|T]) :- H11\="O", write("O melhor lugar para jogar eh o 1."),nl,nl.
ganharX([["X",H12,"X"]|T]) :- H12\="O", write("O melhor lugar para jogar eh o 2."),nl,nl.
ganharX([["X","X",H13]|T]) :- H13\="O", write("O melhor lugar para jogar eh o 3."),nl,nl.
ganharX([H11,[H21,"X","X"]|T]) :- H21\="O", write("O melhor lugar para jogar eh o 4."),nl,nl.
ganharX([H11,["X",H22,"X"]|T]) :- H22\="O", write("O melhor lugar para jogar eh o 5."),nl,nl.
ganharX([H11,["X","X",H23]|T]) :- H23\="O", write("O melhor lugar para jogar eh o 6."),nl,nl.
ganharX([H11,H21,[H31,"X","X"]]) :- H31\="O", write("O melhor lugar para jogar eh o 7."),nl,nl.
ganharX([H11,H21,["X",H32,"X"]]) :- H32\="O", write("O melhor lugar para jogar eh o 8."),nl,nl.
ganharX([H11,H21,["X","X",H33]]) :- H33\="O", write("O melhor lugar para jogar eh o 9."),nl,nl.
ganharX([[H11|T1],["X"|T2],["X"|T3]]) :- H11\="O", write("O melhor lugar para jogar eh o 1."),nl,nl.
ganharX([["X"|T1],[H21|T2],["X"|T3]]) :- H21\="O", write("O melhor lugar para jogar eh o 4."),nl,nl.
ganharX([["X"|T1],["X"|T2],[H31|T3]]) :- H31\="O", write("O melhor lugar para jogar eh o 7."),nl,nl.
ganharX([[H11,H12|T1],[H21,"X"|T2],[H31,"X"|T3]]) :- H12\="O", write("O melhor lugar para jogar eh o 2."),nl,nl.
ganharX([[H11,"X"|T1],[H21,H22|T2],[H31,"X"|T3]]) :- H22\="O", write("O melhor lugar para jogar eh o 5."),nl,nl.
ganharX([[H11,"X"|T1],[H21,"X"|T2],[H31,H32|T3]]) :- H32\="O", write("O melhor lugar para jogar eh o 8."),nl,nl.
ganharX([[H11,H12,H13],[H21,H22,"X"],[H31,H32, "X"]]) :- H13\="O", write("O melhor lugar para jogar eh o 3."),nl,nl.
ganharX([[H11,H12,"X"],[H21,H22,H23],[H31,H32, "X"]]) :- H23\="O", write("O melhor lugar para jogar eh o 6."),nl,nl.
ganharX([[H11,H12,"X"],[H21,H22,"X"],[H31,H32,H33]]) :- H33\="O", write("O melhor lugar para jogar eh o 9."),nl,nl.

ganharO([[H11,"O","O"]|T]) :- H11\="X", write("O melhor lugar para jogar eh o 1."),nl,nl.
ganharO([["O",H12,"O"]|T]) :- H12\="X", write("O melhor lugar para jogar eh o 2."),nl,nl.
ganharO([["O","O",H13]|T]) :- H13\="X", write("O melhor lugar para jogar eh o 3."),nl,nl.
ganharO([H11,[H21,"O","O"]|T]) :- H21\="X", write("O melhor lugar para jogar eh o 4."),nl,nl.
ganharO([H11,["O",H22,"O"]|T]) :- H22\="X", write("O melhor lugar para jogar eh o 5."),nl,nl.
ganharO([H11,["O","O",H23]|T]) :- H23\="X", write("O melhor lugar para jogar eh o 6."),nl,nl.
ganharO([H11,H21,[H31,"O","O"]]) :- H31\="X", write("O melhor lugar para jogar eh o 7."),nl,nl.
ganharO([H11,H21,["O",H32,"O"]]) :- H32\="X", write("O melhor lugar para jogar eh o 8."),nl,nl.
ganharO([H11,H21,["O","O",H33]]) :- H33\="X", write("O melhor lugar para jogar eh o 9."),nl,nl.
ganharO([[H11|T1],["O"|T2],["O"|T3]]) :- H11\="X", write("O melhor lugar para jogar eh o 1."),nl,nl.
ganharO([["O"|T1],[H21|T2],["O"|T3]]) :- H21\="X", write("O melhor lugar para jogar eh o 4."),nl,nl.
ganharO([["O"|T1],["O"|T2],[H31|T3]]) :- H31\="X", write("O melhor lugar para jogar eh o 7."),nl,nl.
ganharO([[H11,H12|T1],[H21,"O"|T2],[H31,"O"|T3]]) :- H12\="X", write("O melhor lugar para jogar eh o 2."),nl,nl.
ganharO([[H11,"O"|T1],[H21,H22|T2],[H31,"O"|T3]]) :- H22\="X", write("O melhor lugar para jogar eh o 5."),nl,nl.
ganharO([[H11,"O"|T1],[H21,"O"|T2],[H31,H32|T3]]) :- H32\="X", write("O melhor lugar para jogar eh o 8."),nl,nl.
ganharO([[H11,H12,H13],[H21,H22,"O"],[H31,H32, "O"]]) :- H13\="X", write("O melhor lugar para jogar eh o 3."),nl,nl.
ganharO([[H11,H12,"O"],[H21,H22,H23],[H31,H32, "O"]]) :- H23\="X", write("O melhor lugar para jogar eh o 6."),nl,nl.
ganharO([[H11,H12,"O"],[H21,H22,"O"],[H31,H32,H33]]) :- H33\="X", write("O melhor lugar para jogar eh o 9."),nl,nl.

%Jogadas
firstPlayer(X) :-
  gameOver(X);
  validateX(X),
  write("Primeiro jogador, escolha um lugar para jogar: "),
  read_line_to_codes(user_input, Y2),
  string_to_atom(Y2,Y1),
  atom_number(Y1,Y), nl,
  writeXOnBoard(Y, X, R),
  drawBoard(R),nl,nl,
  secondPlayer(R).

secondPlayer(X) :-
  gameOver(X);
  validateO(X),
  write("Segundo jogador, escolha um lugar para jogar: "),
  read_line_to_codes(user_input, Y2),
  string_to_atom(Y2,Y1),
  atom_number(Y1,Y), nl,
  writeOOnBoard(Y, X, R),
  drawBoard(R),nl,nl,
  firstPlayer(R).

:- initialization main.

main:-
  %Primeira impressão do jogo.
  write("PLP Project - Jogo da Velha"), nl,nl,
  write("O jogador 1 utiliza o X"), nl,
  write("O jogador 2 utiliza o O"), nl,nl,
  newBoard(X),
  drawBoard(X), nl, nl,
  firstPlayer(X).
