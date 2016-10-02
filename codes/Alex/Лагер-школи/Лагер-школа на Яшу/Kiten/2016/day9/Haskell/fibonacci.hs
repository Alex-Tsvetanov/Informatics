-- vim: et

fib = (1 : 1 : zipWith (+) fib (drop 1 fib))

addLists [] [] = []
addLists (x:xs) (y:ys) = (x + y) : (addLists xs ys)
fib1 = 1 : 1 : (addLists fib1 (drop 1 fib1))

fib2 a | a == 0     = 1
       | a == 1     = 1
       | otherwise  = fib2 (a - 1) + fib2 (a - 2)

fib3 0 = (1, 1)
fib3 i = (b, a + b)
    where (a, b) = fib3 (i - 1)

main = do
{
    putStrLn (show (fib !! 5));
    putStrLn (show (fib1 !! 5));
    putStrLn (show (fib2 5));
    putStrLn (show (fib3 5));
}
