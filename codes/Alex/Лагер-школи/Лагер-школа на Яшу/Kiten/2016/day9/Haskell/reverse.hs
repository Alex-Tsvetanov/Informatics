-- vim: et

numbers = [1, 2, 3, 4, 5]

myReverse [] = []
myReverse arr = myReverse ((drop 1 arr)) ++ [(arr !! 0)]

myReverse1 [] = []
myReverse1 arr = (arr !! ((length arr) - 1)) : myReverse1 ((take ((length arr) - 1) arr))

myReverse2 [] = []
myReverse2 [a,b] = [b,a]
myReverse2 (x:xs) = myReverse2 (xs) ++ [x] 

reverser [] others = others
reverser (x:xs) others = reverser (xs) (x:others)
myReverse3 arr = reverser arr []

main = do
{
    putStrLn (show (myReverse numbers));
    putStrLn (show (myReverse1 numbers));
    putStrLn (show (myReverse2 numbers));
    putStrLn (show (myReverse3 numbers));
}
