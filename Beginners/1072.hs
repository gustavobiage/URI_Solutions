getInputList :: Int -> [IO String]
getInputList n | (n == 0) = []
               | otherwise = getLine : getInputList (n-1)

value :: IO String -> IO Int
value v = do
    str <- v
    let i = (read str :: Int)
    return (inRange i) 

inRange :: Int -> Int
inRange n | (n >= 10 && n <= 20) = 1
          | otherwise = 0

iosum :: IO Int -> IO Int -> IO Int
iosum ioa iob = do
    a <- ioa
    b <- iob
    return (a + b)

count :: Int -> [IO String] -> IO Int
count n (h:t) | (n == 1) = value h
              | otherwise = iosum (value h) (count (n-1) t)

main = do
    nstr <- getLine
    let n = (read nstr :: Int)
    let list = getInputList n
    inside <- count n list
    putStr (show inside ++ " in\n")
    putStr (show (n - inside) ++ " out\n")
