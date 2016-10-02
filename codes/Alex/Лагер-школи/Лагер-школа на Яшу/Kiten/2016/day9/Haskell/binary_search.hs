-- vim: et

binarySearch :: (Int -> Bool) -> Int -> Int -> Int
binarySearch f a b  | a == b - 1       = b
                    | (f mid)          = binarySearch f a mid
                    | otherwise        = binarySearch f mid b
                    where mid = (a + b) `div` 2

compareElement items value index = (items !! index) >= value
lowerBound :: Ord a => [a] -> a -> Int
lowerBound items value = binarySearch (compareElement items value) (-1) (length items)
