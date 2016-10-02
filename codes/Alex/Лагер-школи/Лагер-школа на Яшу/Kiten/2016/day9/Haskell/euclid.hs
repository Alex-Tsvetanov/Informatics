-- vim: et

euclid :: Integral a => a -> a -> a
euclid a b | a < b     = euclid b a
           | b == 0    = a
           | otherwise = euclid b (mod a b)

main = do
{
    putStrLn (show (euclid 10 6))
}


