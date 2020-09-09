main = do
    a_str <- getLine
    b_str <- getLine
    let a = (read a_str :: Int)
    let b = (read b_str :: Int)
    print (mod a b)