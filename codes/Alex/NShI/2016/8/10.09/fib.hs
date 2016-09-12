-- vim: et

fib = (0 : 1 : zipWith (+) fib (drop 1 fib))

main = do
{
    putStrLn (show (fib !! 5));
}
