getTable :: Int -> Int -> String
getTable i n | (i > n) = ""
             | (mod i 2 == 1) = getTable (i+1) n
             | otherwise = show i ++ "^2 = " ++ show (i*i) ++ "\n" ++ getTable (i+1) n

main = do
    nstr <- getLine
    let n = (read nstr :: Int)
    putStr (getTable 1 n)