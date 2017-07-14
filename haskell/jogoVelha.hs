initialArray :: [String]

initialArray = ["1", "2", "3", "4", "5", "6", "7", "8", "9"]

changeArray :: [String] -> String -> String -> [String]

changeArray currentArray position move = [if x == position then move else x | x <- currentArray]

verificaVitoria :: [String] -> String -> Bool

verificaVitoria currentArray checkingPlayer = 
		((currentArray !! 0 == checkingPlayer && currentArray !! 1 == checkingPlayer && currentArray !! 2 == checkingPlayer) || --primeiralinha
		 (currentArray !! 3 == checkingPlayer && currentArray !! 4 == checkingPlayer && currentArray !! 5 == checkingPlayer) || --segundalinha
		 (currentArray !! 6 == checkingPlayer && currentArray !! 7 == checkingPlayer && currentArray !! 8 == checkingPlayer) || --terceiralinha
		 (currentArray !! 0 == checkingPlayer && currentArray !! 4 == checkingPlayer && currentArray !! 8 == checkingPlayer) || --diagonalprincipal
		 (currentArray !! 2 == checkingPlayer && currentArray !! 4 == checkingPlayer && currentArray !! 6 == checkingPlayer) || --diagonalsecundaria
		 (currentArray !! 0 == checkingPlayer && currentArray !! 3 == checkingPlayer && currentArray !! 6 == checkingPlayer) || --primeiracoluna
		 (currentArray !! 1 == checkingPlayer && currentArray !! 4 == checkingPlayer && currentArray !! 7 == checkingPlayer) || --segundacoluna
		 (currentArray !! 2 == checkingPlayer && currentArray !! 5 == checkingPlayer && currentArray !! 8 == checkingPlayer) --terceiracoluna
		 )

gameplay :: [String] -> Bool -> String -> String -> IO()

gameplay currentArray vezX playerX playerO = do

	if verificaVitoria currentArray "X" then do putStrLn (playerX ++ " VENCEU!")
		else if verificaVitoria currentArray "O" then do putStrLn (playerO ++ " VENCEU!")
			else do {
				putStrLn ""
				;putStrLn "Estas sao as posicoes que estao disponiveis para jogo."

				;printArray currentArray

				;putStrLn ""
				;if vezX 
					then do putStrLn ("Vez de " ++ playerX)
					else putStrLn ("Vez de " ++ playerO)

				;putStrLn "Em que posição deseja jogar? "

				;position <- getLine

				;let positionString = position
				;let positionNumber = read position :: Int

				;let playedPosition = currentArray !! (positionNumber - 1)

				;if (playedPosition == "X" || playedPosition == "O") then do {
						putStr "\ESC[2J"
						;putStrLn ""
						;putStrLn "Esta posição não está disponível"
						;gameplay currentArray vezX playerX playerO
					} 
					;else do { 
						putStrLn ""

						;let newArray = if vezX then changeArray currentArray positionString "X"
										else changeArray currentArray positionString "O"

						;printArray newArray
						;putStr "\ESC[2J"
						;gameplay newArray (not vezX) playerX playerO }
			}


printArray :: [String] -> IO()

printArray currentArray = do
	putStrLn ""
	putStrLn "+---+---+---+"
	let firstLine = "| " ++ currentArray !! 0 ++ " | " ++ currentArray !! 1 ++ " | " ++ currentArray !! 2 ++ " |"
	putStrLn firstLine
	let secondLine = "| " ++ currentArray !! 3 ++ " | " ++ currentArray !! 4 ++ " | " ++ currentArray !! 5 ++ " |"
	putStrLn secondLine
	let thirdLine = "| " ++ currentArray !! 6 ++ " | " ++ currentArray !! 7 ++ " | " ++ currentArray !! 8 ++ " |"
	putStrLn thirdLine
	putStrLn "+---+---+---+"

main = do 
	putStrLn "Bem vindo ao jogo da Velha!"

	putStrLn "Digite o nome do Jogador 1"

	player1 <- getLine

	putStrLn "Digite o nome do Jogador 2"

	player2 <- getLine

	putStr "\ESC[2J"

	let player1Option = player1 ++ " joga com X"
	let player2Option = player2 ++ " joga com O"

	putStrLn player1Option
	putStrLn player2Option

	gameplay initialArray True player1 player2