prt :: Int -> Int -> Int -> String
prt n c l | (c <= l) = show (n) ++ " " ++ show (n+1) ++ " " ++ show (n+2) ++ " PUM" ++ "\n" ++ prt (n+4) (c+1) l
          | otherwise = "" 

main = do
    n_str <- getLine
    let n = (read n_str :: Int)
    putStr(prt 1 1 n)