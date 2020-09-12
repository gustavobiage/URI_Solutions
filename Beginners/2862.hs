getInputValue :: Int -> [IO String]
getInputValue n | (n == 0) = []
                | otherwise = getLine : (getInputValue (n-1))

concatenate :: IO String -> IO String -> IO String
concatenate a c = do
    astr <- a
    cstr <- c
    return (astr ++ "\n" ++ cstr)

convertAndEvaluate :: Int -> [IO String] -> IO String
convertAndEvaluate n (h:t) | (n == 1) = evaluate h
                           | otherwise = concatenate (evaluate h) (convertAndEvaluate (n-1) t)

evaluate :: IO String -> IO String
evaluate v = do
    str <- v
    let i = (read str :: Int)
    return (value i)

value :: Int -> String
value v | (v > 8000) = "Mais de 8000!"
        | otherwise = "Inseto!"

main = do    
    n_str <- getLine
    let n = (read n_str :: Int)
    let list = getInputValue (n)
    prt <- convertAndEvaluate n list
    putStrLn (prt)