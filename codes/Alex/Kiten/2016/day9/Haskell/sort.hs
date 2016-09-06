-- vim: et

quicksort [] = []
quicksort (x:xs) = (quicksort (filter (<x) xs)) ++ [x] ++ (quicksort (filter (>=x) xs))

mergesort [] = []
mergesort [a] = [a]
mergesort xs = merge (mergesort left) (mergesort right)
    where hlen = (length xs) `div` 2
          left = take hlen xs
          right = drop hlen xs

merge xs [] = xs
merge [] ys = ys
merge (x:xs) (y:ys) | x<=y      = x:(merge xs (y:ys))
                    | otherwise = y:(merge (x:xs) ys)

main = do
{
    putStrLn (show (quicksort [1,5,2,6,65,3,685]));
    putStrLn (show (mergesort [1,5,2,6,65,3,685]));
}
