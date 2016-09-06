-- vim: et

factorial :: Integer -> Integer
factorial 0 = 1
factorial n = n * (factorial (n - 1))

factorial2 n | n == 1    = 1
             | n > 1     = n * (factorial2 (n - 1))

area :: Num a => a -> a -> a -> a -> a -> a -> a
area x1 y1 x2 y2 x3 y3 = xa * yb - ya * xb
                         where
                         {
                               xa = x1 - x2;
                               xb = x2 - x3;
                               ya = y1 - y2;
                               yb = y2 - y3;
                         }
cross :: Num a => a -> a -> a -> a -> a
cross a b c d = area 0 0 a b c d

--
main :: IO ()
main = do
{
    putStrLn ((show (factorial 10)));
    putStrLn ((show (factorial2 5)));
    putStrLn ((show (area 1 2 3 4 5 7)));
}

